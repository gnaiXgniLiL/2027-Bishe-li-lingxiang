#include "util.h"
#include "perf.h"

#define CFU_OP(f3, a, b) ({ \
    int _cfu_ret; \
    asm volatile(".insn r 0x0B, " #f3 ", 0, %0, %1, %2" \
        : "=r" (_cfu_ret) : "r" (a), "r" (b)); \
    _cfu_ret; \
})
#define CFU_MUL(a,b)   CFU_OP(0, a, b)

static int img[64], kern[9];
static int res[6];

int main(void) {
    for (int i = 0; i < 64; i++) img[i] = (i *  7 + 13) % 251 - 125;
    for (int i = 0; i <  9; i++) kern[i] = (i * 11 + 29) % 241 - 120;

    /* L1: 循环，结果存数组，循环外统一打印（去掉循环内 printd） */
    for (int r = 0; r < 6; r++) res[r] = CFU_MUL(img[r*8], kern[0]);
    pg_prints("L1: ");
    for (int r = 0; r < 6; r++) { pg_printd(res[r]); pg_prints(" "); }

    /* L2: 循环，常量操作数（再去掉 load 和变化地址） */
    for (int r = 0; r < 6; r++) res[r] = CFU_MUL(6, 7);
    pg_prints("\nL2: ");
    for (int r = 0; r < 6; r++) { pg_printd(res[r]); pg_prints(" "); }

    /* L3: 手写展开 6 次（去掉循环控制流），操作数与 L1 完全相同 */
    res[0]=CFU_MUL(img[0],kern[0]);  res[1]=CFU_MUL(img[8],kern[0]);
    res[2]=CFU_MUL(img[16],kern[0]); res[3]=CFU_MUL(img[24],kern[0]);
    res[4]=CFU_MUL(img[32],kern[0]); res[5]=CFU_MUL(img[40],kern[0]);
    pg_prints("\nL3: ");
    for (int r = 0; r < 6; r++) { pg_printd(res[r]); pg_prints(" "); }

    pg_prints("\n(expect L1/L3: 10192 5096 0 -5096 -10192 7553, L2: 42 x6)\n");
    pg_exit();
    return 0;
}