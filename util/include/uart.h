#ifndef __UART_H__
#define __UART_H__

/**
 * Mini Uart 送受信に使用するレジスタ。
 *
 * 書き込むと送信 FIFO にプッシュ,
 * 読み込むと 受信 FIFO からポップしてくれる素敵仕様らしい。
 */
#define MU_IO (*(volatile unsigned int *)0x3F215040)

/**
 * Mini Uart 送信 FIFO の状態確認をするための情報が入ったレジスタ。
 *
 * 6 ビット目 : Transmitter idle, アイドル状態か？
 *              1: アイドル状態, 0: ビジー状態
 * 5 ビット目 : Transmitter empty, 1 バイト以上送信受付可能か？
 *              1: 可能, 0: 不可能
 * 0 ビット目 : Data ready, 1 バイト以上受信しているか？
 *              1: 受信している, 0: 受信していない
 */
#define MU_LSR          (*(volatile unsigned int *)0X3F215054)

/* Transmitter idle のビットマスク */
#define MU_LSR_TX_IDLE  (1U << 6)

/* Transmitter empty のビットマスク */
#define MU_LSR_TX_EMPTY (1U << 5)

/* Data ready のビットマスク*/
#define MU_LSR_RX_RDY   (1U << 0)

void println(const char* chars);
void print(const char* chars);
void uart_put(const char c);

#endif // __UART_H__
