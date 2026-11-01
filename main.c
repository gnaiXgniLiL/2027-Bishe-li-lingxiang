#include "util.h"
#include "perf.h"

/* ===== CFU 指令封装（与 cfu.v 的 funct3 编码一一对应） =====
   funct3 由预处理器字符串化拼进指令文本，-O0/-Os/-O2 全兼容；
   宏内临时变量使用独立名称 _cfu_ret，避免遮蔽调用点变量；
   当前版本不插入 nop。 */
#define CFU_OP(f3, a, b) ({ \
    int _cfu_ret; \
    asm volatile(".insn r 0x0B, " #f3 ", 0, %0, %1, %2" \
        : "=r" (_cfu_ret) : "r" (a), "r" (b)); \
    _cfu_ret; \
})
#define CFU_MUL(a,b)   CFU_OP(0, a, b)   /* rslt = a*b       */
#define CFU_LOAD(a,b)  CFU_OP(1, a, b)   /* acc <= a*b       */
#define CFU_READ()     CFU_OP(2, 0, 0)   /* rslt = acc       */
#define CFU_MAC(a,b)   CFU_OP(3, a, b)   /* acc <= acc + a*b */

#define IN      8              /* 输入 8x8 */
#define K       3              /* 卷积核 3x3 */
#define OUT     (IN - K + 1)   /* 输出 6x6（valid 卷积，无 padding） */
#define REPEAT  10

static int img[IN*IN], kern[K*K];
static int out_c[OUT*OUT];
static int out_u[OUT*OUT];
static int out_f[OUT*OUT];

static void init_data(void) {
    for (int i = 0; i < IN*IN; i++)
        img[i] = (i * 7 + 13) % 251 - 125;

    for (int i = 0; i < K*K; i++)
        kern[i] = (i * 11 + 29) % 241 - 120;
}

/* 版本 A：纯软件卷积，naive baseline */
static void conv3x3_c(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            int s = 0;

            for (int i = 0; i < K; i++)
                for (int j = 0; j < K; j++)
                    s += in[(r+i)*IN + (c+j)] * k[i*K + j];

            out[r*OUT + c] = s;
        }
}

/* 版本 B：预加载 + 展开的 CFU 卷积
   每个输出点：LOAD 清场 + 8 次 MAC + READ */
static void conv3x3_cfu(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            /* 预加载：9 对操作数全部先取进局部变量 */
            const int *p = in + r*IN + c;
            int a0=p[0],  b0=k[0];
            int a1=p[1],  b1=k[1];
            int a2=p[2],  b2=k[2];
            int a3=p[8],  b3=k[3];
            int a4=p[9],  b4=k[4];
            int a5=p[10], b5=k[5];
            int a6=p[16], b6=k[6];
            int a7=p[17], b7=k[7];
            int a8=p[18], b8=k[8];

            /* 计算：9 条 CFU 指令连续发射，中间无 load */
            CFU_LOAD(a0,b0);
            CFU_MAC(a1,b1);
            CFU_MAC(a2,b2);
            CFU_MAC(a3,b3);
            CFU_MAC(a4,b4);
            CFU_MAC(a5,b5);
            CFU_MAC(a6,b6);
            CFU_MAC(a7,b7);
            CFU_MAC(a8,b8);

            out[r*OUT + c] = CFU_READ();
        }
}

/* 版本 C：预加载 + 展开的纯软件卷积
   与 CFU 版的唯一算法实现差异：乘加由普通 C 完成 */
static void conv3x3_unrolled(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            /* 与 CFU 版完全相同的预加载结构 */
            const int *p = in + r*IN + c;
            int a0=p[0],  b0=k[0];
            int a1=p[1],  b1=k[1];
            int a2=p[2],  b2=k[2];
            int a3=p[8],  b3=k[3];
            int a4=p[9],  b4=k[4];
            int a5=p[10], b5=k[5];
            int a6=p[16], b6=k[6];
            int a7=p[17], b7=k[7];
            int a8=p[18], b8=k[8];

            /* 第一个乘积对应 CFU LOAD */
            int s = a0 * b0;

            /* 后续 8 次累加对应 8 次 CFU MAC */
            s += a1 * b1;
            s += a2 * b2;
            s += a3 * b3;
            s += a4 * b4;
            s += a5 * b5;
            s += a6 * b6;
            s += a7 * b7;
            s += a8 * b8;

            out[r*OUT + c] = s;
        }
}

int main(void) {
    init_data();

    /* ===== 正确性：三版输出逐点对拍 ===== */
    conv3x3_c(img, kern, out_c);
    conv3x3_unrolled(img, kern, out_u);
    conv3x3_cfu(img, kern, out_f);

    int bad_u = 0;
    int bad_f = 0;

    for (int i = 0; i < OUT*OUT; i++) {
        if (out_c[i] != out_u[i])
            bad_u++;

        if (out_c[i] != out_f[i])
            bad_f++;
    }

    pg_prints("check unrolled: ");
    pg_printd(OUT*OUT - bad_u);
    pg_prints("/");
    pg_printd(OUT*OUT);
    pg_prints(bad_u ? " FAIL\n" : " OK\n");

    pg_prints("check cfu:      ");
    pg_printd(OUT*OUT - bad_f);
    pg_prints("/");
    pg_printd(OUT*OUT);
    pg_prints(bad_f ? " FAIL\n" : " OK\n");

    if (bad_u || bad_f) {
        pg_exit();
        return 0;
    }

    volatile int sink = 0;

    /* 测量 perf 开关自身的 cycle 开销 */
    pg_perf_reset();
    pg_perf_enable();
    pg_perf_disable();
    int overhead = (int)pg_perf_cycle();

    /* ===== C-naive ===== */
    pg_perf_reset();
    pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) {
        conv3x3_c(img, kern, out_c);
        sink = out_c[0];
    }
    pg_perf_disable();
    int cyc_c = (int)pg_perf_cycle() - overhead;

    /* ===== C-unrolled ===== */
    pg_perf_reset();
    pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) {
        conv3x3_unrolled(img, kern, out_u);
        sink = out_u[0];
    }
    pg_perf_disable();
    int cyc_u = (int)pg_perf_cycle() - overhead;

    /* ===== CFU ===== */
    pg_perf_reset();
    pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) {
        conv3x3_cfu(img, kern, out_f);
        sink = out_f[0];
    }
    pg_perf_disable();
    int cyc_f = (int)pg_perf_cycle() - overhead;

    /* ===== 输出原始 cycle 数据 ===== */
    pg_prints("overhead= ");
    pg_printd(overhead);
    pg_prints("\n");

    pg_prints("c    total= ");
    pg_printd(cyc_c);
    pg_prints(" avg= ");
    pg_printd(cyc_c / REPEAT);
    pg_prints("\n");

    pg_prints("u    total= ");
    pg_printd(cyc_u);
    pg_prints(" avg= ");
    pg_printd(cyc_u / REPEAT);
    pg_prints("\n");

    pg_prints("cfu  total= ");
    pg_printd(cyc_f);
    pg_prints(" avg= ");
    pg_printd(cyc_f / REPEAT);
    pg_prints("\n");

    /* ===== 输出三项加速比，放大 100 倍保留两位 =====
       software：naive -> unrolled，软件优化收益 X
       hardware：unrolled -> CFU，硬件净收益 Y
       total：naive -> CFU，总加速比，约等于 X * Y */
    pg_prints("software gain x100= ");
    pg_printd(cyc_c * 100 / cyc_u);
    pg_prints("\n");

    pg_prints("hardware gain x100= ");
    pg_printd(cyc_u * 100 / cyc_f);
    pg_prints("\n");

    pg_prints("total speedup x100= ");
    pg_printd(cyc_c * 100 / cyc_f);
    pg_prints("\n");

    pg_exit();
    return 0;
}