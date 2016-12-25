#include "types.h"
#include "uart.h"

void println(const char* chars) {
    print(chars);
    print("\n\r");
}

void print(const char* chars) {
    char* char_ptr = (char*) chars;

    while (*char_ptr != '\0') {
        uart_put(*char_ptr);
        char_ptr++;
    }
}

void uart_put(const char c) {
    // 送信受付可能状態になるまでビジーループ
    while (!(MU_LSR & MU_LSR_TX_IDLE) && !(MU_LSR & MU_LSR_TX_EMPTY));

    // IO レジスタにデータ書き込み
    MU_IO = c;
}
