#include "util.h"
#include "perf.h"

/* ===== CFU 指令封装 ===== */
#define CFU_OP(f3, a, b) ({ \
    int r; \
    asm volatile (".insn r 0x0B, " #f3 ", 0, %0, %1, %2" \
        : "=r" (r) : "r" (a), "r" (b)); \
    r; \
})
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

/* 版本 A：纯软件卷积 */
static void conv3x3_c(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            int s = in[r*IN + c] * k[0];
            for (int t = 1; t < K*K; t++) {
                int i = t / K, j = t % K;     /* 故意用除法 */
                s += in[(r+i)*IN + (c+j)] * k[t];
            }
            out[r*OUT + c] = s;
        }
}

/* 版本 B：CFU 卷积——每个输出点：LOAD 清场 + 8 次 MAC + READ */
static void conv3x3_cfu(const int *in, const int *k, int *out) {
    for (int r = 0; r < OUT; r++)
        for (int c = 0; c < OUT; c++) {
            CFU_LOAD(in[r*IN + c], k[0]);           /* 第 0 个乘积：装载 */
            for (int t = 1; t < K*K; t++) {         /* 第 1~8 个：累加 */
                int i = t / K, j = t % K;
                CFU_MAC(in[(r+i)*IN + (c+j)], k[t]);
            }
            out[r*OUT + c] = CFU_READ();
        }
}

int main(void) {
    init_data();

    /* 正确性：36 个输出点逐个对拍 */
    conv3x3_c(img, kern, out_c);
    conv3x3_cfu(img, kern, out_f);
    int bad = 0;
    for (int i = 0; i < OUT*OUT; i++) {
        if (out_c[i] != out_f[i]) bad++;
        pg_printd(i);                        /* 点序号：r = i/6, c = i%6 */
        pg_prints(": c=");  pg_printd(out_c[i]);
        pg_prints(" f=");   pg_printd(out_f[i]);
        pg_prints(out_c[i] == out_f[i] ? "\n" : "  <-- BAD\n");
    }
    pg_prints("check: "); pg_printd(OUT*OUT - bad); pg_prints("/36\n");
    pg_exit();
    return 0;
}