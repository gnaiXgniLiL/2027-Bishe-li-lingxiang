#include "util.h"
#include "perf.h"

/* ===== CFU 指令封装（与 cfu.v 的 funct3 编码一一对应） ===== */
static inline int cfu_op(int funct3, int a, int b) {
    int r;
    asm volatile (
        ".insn r 0x0B, %3, 0, %0, %1, %2"
        : "=r" (r)
        : "r" (a), "r" (b), "i" (funct3)
    );
    return r;
}
#define CFU_LOAD(a,b)  cfu_op(1, a, b)   /* acc <= a*b       */
#define CFU_READ()     cfu_op(2, 0, 0)   /* rslt = acc       */
#define CFU_MAC(a,b)   cfu_op(3, a, b)   /* acc <= acc + a*b */

#define N       256   /* 点积维度 */
#define REPEAT  10    /* 每个版本重复计时次数 */

static int x[N], w[N];

/* 确定性初始化：固定公式，不用 rand，每次运行数据完全相同（可复现） */
static void init_data(void) {
    for (int i = 0; i < N; i++) {
        x[i] = (i *  7 + 13) % 251 - 125;   /* 约 [-125, 125]，含负数 */
        w[i] = (i * 11 + 29) % 241 - 120;   /* 约 [-120, 120] */
    }
}

/* 版本 A：纯软件点积（Baseline，对照组） */
static int dot_c(const int *a, const int *b) {
    int s = 0;
    for (int i = 0; i < N; i++) s += a[i] * b[i];
    return s;
}

/* 版本 B：CFU 点积（挑战者） */
static int dot_cfu(const int *a, const int *b) {
    CFU_LOAD(a[0], b[0]);                    /* 第一对必须 LOAD：清场纪律 */
    for (int i = 1; i < N; i++) CFU_MAC(a[i], b[i]);
    return CFU_READ();
}

int main(void) {
    init_data();

    /* ---- 先验证正确性：结果不对，测速无意义 ---- */
    int r_c   = dot_c(x, w);
    int r_cfu = dot_cfu(x, w);
    pg_prints("check: c="); pg_printd(r_c);
    pg_prints(" cfu=");     pg_printd(r_cfu);
    pg_prints((r_c == r_cfu) ? " OK\n" : " FAIL\n");
    if (r_c != r_cfu) { pg_exit(); return 0; }

    volatile int sink = 0;  /* 接收结果用：防止编译器发现结果没被用、把整个计时循环删掉 */

    /* ---- 测空夹开销：计时机制自身（MMIO 写+读）花多少拍 ---- */
    pg_perf_reset();
    pg_perf_enable();
    pg_perf_disable();
    int overhead = (int)pg_perf_cycle();

    /* ---- 纯 C 版：夹 10 次取总 cycle ---- */
    pg_perf_reset();
    pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) sink = dot_c(x, w);
    pg_perf_disable();
    int cyc_c = (int)pg_perf_cycle() - overhead;

    /* ---- CFU 版：同样夹 10 次 ---- */
    pg_perf_reset();
    pg_perf_enable();
    for (int t = 0; t < REPEAT; t++) sink = dot_cfu(x, w);
    pg_perf_disable();
    int cyc_cfu = (int)pg_perf_cycle() - overhead;

    /* ---- 输出：总 cycle、单次平均、加速比(×100 打印成整数) ---- */
    pg_prints("overhead= ");   pg_printd(overhead);          pg_prints("\n");
    pg_prints("c    total= "); pg_printd(cyc_c);
    pg_prints(" avg= ");       pg_printd(cyc_c / REPEAT);    pg_prints("\n");
    pg_prints("cfu  total= "); pg_printd(cyc_cfu);
    pg_prints(" avg= ");       pg_printd(cyc_cfu / REPEAT);  pg_prints("\n");
    pg_prints("speedup x100= "); pg_printd(cyc_c * 100 / cyc_cfu); pg_prints("\n");

    pg_exit();
    return 0;
}