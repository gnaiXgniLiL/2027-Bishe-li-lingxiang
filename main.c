#include "util.h"

/* 通用 CFU 调用：funct3 选择操作（编译期立即数），a/b 为两个操作数 */
static inline int cfu_op(int funct3, int a, int b) {
    int r;
    asm volatile (
        ".insn r 0x0B, %3, 0, %0, %1, %2"
        : "=r" (r)
        : "r" (a), "r" (b), "i" (funct3)
    );
    return r;
}

/* 操作编码——与 cfu.v 的 case 一一对应，这份对应关系就是指令定义本身 */
#define CFU_MUL(a,b)   cfu_op(0, a, b)   /* rslt = a*b        */
#define CFU_LOAD(a,b)  cfu_op(1, a, b)   /* acc <= a*b        */
#define CFU_READ()     cfu_op(2, 0, 0)   /* rslt = acc        */
#define CFU_MAC(a,b)   cfu_op(3, a, b)   /* acc <= acc + a*b  */

int main(void) {
    /* 测试1：单乘法（回归测试，确认 funct3=000 没改坏） */
    int r1 = CFU_MUL(7, 6), c1 = 7 * 6;
    pg_prints("mul : cfu="); pg_printd(r1);
    pg_prints(" c=");        pg_printd(c1);
    pg_prints((r1 == c1) ? " OK\n" : " FAIL\n");

    /* 测试2：4 维点积（带负数），CFU vs C 对拍 */
    int x[4] = {3, -5, 7, 2};
    int w[4] = {4, 6, -2, 8};

    CFU_LOAD(x[0], w[0]);                 /* 第一对必须装载——纪律 */
    for (int i = 1; i < 4; i++) CFU_MAC(x[i], w[i]);
    int r2 = CFU_READ();

    int c2 = 0;
    for (int i = 0; i < 4; i++) c2 += x[i] * w[i];

    pg_prints("dot4: cfu="); pg_printd(r2);
    pg_prints(" c=");        pg_printd(c2);
    pg_prints((r2 == c2) ? " OK\n" : " FAIL\n");

    /* 测试3：紧接第二段点积，验证"装载清场"不受上一段残值影响 */
    CFU_LOAD(2, 2);
    CFU_MAC(3, 3);
    int r3 = CFU_READ(), c3 = 2*2 + 3*3;
    pg_prints("dot2: cfu="); pg_printd(r3);
    pg_prints(" c=");        pg_printd(c3);
    pg_prints((r3 == c3) ? " OK\n" : " FAIL\n");

    pg_exit();
    return 0;
}