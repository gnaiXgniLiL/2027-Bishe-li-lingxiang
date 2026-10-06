#include "util.h"
#include "perf.h"

/* ===== CFU 指令封装（与 cfu.v 的 funct3 编码一一对应） =====
   funct3 由预处理器字符串化拼进指令文本，-O0/-Os/-O2 全兼容；
   块内前置 1 条 nop：规避 proc.v 的 load-use 冒险缺陷
   （custom-0 未被停顿逻辑覆盖，lw 与 CFU 指令须至少隔 1 拍） */
#define CFU_OP(f3, a, b) ({ \
    int r; \
    asm volatile("nop\n nop\n nop\n .insn r 0x0B, " #f3 ", 0, %0, %1, %2" \
        : "=r" (r) : "r" (a), "r" (b)); \
    r; \
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
static int out_c[OUT*OUT], out_f[OUT*OUT];

static void init_data(void) {
    for (int i = 0; i < IN*IN; i++) img[i] = (i *  7 + 13) % 251 - 125;
    for (int i = 0; i < K*K;  i++) kern[i] = (i * 11 + 29) % 241 - 120;
}

/* 版本 A：纯软件卷积（Baseline，对照组） */
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

/* 版本 B：CFU 卷积——每个输出点：LOAD 清场 + 8 次 MAC + READ */
static void conv3x3_cfu(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            /* 预取：9 对操作数全部先加载（纯 C，编译器成批调度 lw） */
            const int *p = in + r*IN + c;
            int a0=p[0],  b0=k[0];  int a1=p[1],  b1=k[1];  int a2=p[2],  b2=k[2];
            int a3=p[8],  b3=k[3];  int a4=p[9],  b4=k[4];  int a5=p[10], b5=k[5];
            int a6=p[16], b6=k[6];  int a7=p[17], b7=k[7];  int a8=p[18], b8=k[8];
            /* 计算：9 条 CFU 指令连续发射，中间无 load */
            CFU_LOAD(a0,b0);
            CFU_MAC(a1,b1); CFU_MAC(a2,b2);
            CFU_MAC(a3,b3); CFU_MAC(a4,b4); CFU_MAC(a5,b5);
            CFU_MAC(a6,b6); CFU_MAC(a7,b7); CFU_MAC(a8,b8);
            out[r*OUT + c] = CFU_READ();
        }
}

int main(void) {
    init_data();

    /* 正确性：36 个输出点逐个对拍 */
    conv3x3_c(img, kern, out_c);
    conv3x3_cfu(img, kern, out_f);
    int bad = 0;
    for (int i = 0; i < OUT*OUT; i++)
        if (out_c[i] != out_f[i]) bad++;
    pg_prints("check: "); pg_printd(OUT*OUT - bad);
    pg_prints("/");       pg_printd(OUT*OUT);
    pg_prints(bad ? " FAIL\n" : " OK\n");
    if (bad) { pg_exit(); return 0; }

    volatile int sink = 0;

    pg_perf_reset(); pg_perf_enable(); pg_perf_disable();
    int overhead = (int)pg_perf_cycle();

    pg_perf_reset(); pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) { conv3x3_c(img, kern, out_c); sink = out_c[0]; }
    pg_perf_disable();
    int cyc_c = (int)pg_perf_cycle() - overhead;

    pg_perf_reset(); pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) { conv3x3_cfu(img, kern, out_f); sink = out_f[0]; }
    pg_perf_disable();
    int cyc_f = (int)pg_perf_cycle() - overhead;

    pg_prints("overhead= ");    pg_printd(overhead);       pg_prints("\n");
    pg_prints("c    total= ");  pg_printd(cyc_c);
    pg_prints(" avg= ");        pg_printd(cyc_c / REPEAT); pg_prints("\n");
    pg_prints("cfu  total= ");  pg_printd(cyc_f);
    pg_prints(" avg= ");        pg_printd(cyc_f / REPEAT); pg_prints("\n");
    pg_prints("speedup x100= "); pg_printd(cyc_c * 100 / cyc_f); pg_prints("\n");

    pg_exit();
    return 0;
}