#include "util.h"   // pg_prints / pg_printd / pg_exit

/* CFU 乘法封装：一条 custom-0 指令 */
static inline int cfu_mul(int a, int b) {
    int r;
    asm volatile (
        ".insn r 0x0B, 0x0, 0x0, %0, %1, %2"
        : "=r" (r)
        : "r" (a), "r" (b)
    );
    return r;
}

int main() {
    int a = 7, b = 6;

    int r_cfu = cfu_mul(a, b);   // 走 CFU（你改的 Verilog）
    int r_c   = a * b;           // 走 CPU 自带乘法器（参照）

    pg_prints("cfu = ");
    pg_printd(r_cfu);
    pg_prints(", c = ");
    pg_printd(r_c);
    pg_prints((r_cfu == r_c) ? "  -> OK\n" : "  -> FAIL\n");

    pg_exit();      // 通知仿真结束（top.v 会打印 mcycle 统计）
    return 0;
}