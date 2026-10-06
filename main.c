#include "util.h"
#include "perf.h"

#define CFU_OP(f3, a, b) ({ \
    int r; \
    asm volatile (".insn r 0x0B, " #f3 ", 0, %0, %1, %2" \
        : "=r" (r) : "r" (a), "r" (b)); \
    r; \
})
#define CFU_MUL(a,b)   CFU_OP(0, a, b)
#define CFU_LOAD(a,b)  CFU_OP(1, a, b)
#define CFU_READ()     CFU_OP(2, 0, 0)
#define CFU_MAC(a,b)   CFU_OP(3, a, b)

static int img[64], kern[9];

int main(void) {
    for (int i = 0; i < 64; i++) img[i] = (i *  7 + 13) % 251 - 125;
    for (int i = 0; i <  9; i++) kern[i] = (i * 11 + 29) % 241 - 120;

    /* T1：不碰 acc——纯组合 MUL，操作数是"刚从内存加载、随 r 变化"的值 */
    pg_prints("T1: ");
    for (int r = 0; r < 6; r++) { pg_printd(CFU_MUL(img[r*8], kern[0])); pg_prints(" "); }
    pg_prints("\nE1: ");
    for (int r = 0; r < 6; r++) { pg_printd(img[r*8] * kern[0]);       pg_prints(" "); }

    /* T2：碰 acc 但不用 MAC——每行 LOAD 后立刻 READ */
    pg_prints("\nT2: ");
    for (int r = 0; r < 6; r++) { CFU_LOAD(img[r*8], kern[0]); pg_printd(CFU_READ()); pg_prints(" "); }
    pg_prints("\n");

    pg_exit();
    return 0;
}