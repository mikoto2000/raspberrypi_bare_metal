#define GPFSEL1 0x3F200004 /* GPIO のピン設定をするためのレジスタ */
#define GPSET0  0x3F20001C /* GPIO を HIGH にするためのレジスタ */
#define GPCLR0  0x3F200028 /* GPIO を LOW  にするためのレジスタ */

typedef unsigned char bool;

#define TRUE  1
#define FALSE 0

#define WAIT_COUNT 3000000

/*
 * @fn wait_count だけビジーウェイトする
 * @param (wait_count) このカウント数だけビジーウェイトする
 */
void busy_wait(int wait_count);

/*
 * @fn L チカする
 */
int main(void) {

    // GPIO 出力に設定。
    // Peripheral specification の
    // 92 ページ、Field Name が FSEL16 の行の
    // Bit(s) を見ると、18 から 20 ビット目までに
    // 0x001 を設定すればよいことがわかる感じ。
    *(volatile unsigned int*)GPFSEL1 = (1 << (18));

    // セットして待つ、クリアして待つ、を繰り返す。
    while (1) {
        *(volatile unsigned int*)GPSET0 = (1 << 16);
        busy_wait(WAIT_COUNT);
        *(volatile unsigned int*)GPCLR0 = (1 << 16);
        busy_wait(WAIT_COUNT);
    }

    return 0;
}

void busy_wait(int wait_count) {
    volatile unsigned int i;

    for (i = 0; i < WAIT_COUNT; i++);
}

