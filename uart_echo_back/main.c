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
#define MU_LSR_TX_IDLE  (1U << 6) /* Transmitter idle のビットマスク */
#define MU_LSR_TX_EMPTY (1U << 5) /* Transmitter empty のビットマスク */
#define MU_LSR_RX_RDY   (1U << 0) /* Data ready のビットマスク*/

int main(void) {

    // 受信文字列格納用
    volatile char ch;

    while (1) {
        // 受信するまでビジーループ
        while (!(MU_LSR & MU_LSR_RX_RDY));
        // 受信データ記録
        ch = (char)MU_IO;

        // 送信受付可能状態になるまでビジーループ
        while (!(MU_LSR & MU_LSR_TX_IDLE) && !(MU_LSR & MU_LSR_TX_EMPTY));

        // IO レジスタにデータ書き込み
        MU_IO = (unsigned int)ch;
    }

    return 0;
}

