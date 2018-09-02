#include <string.h>
#include <uart.h>

#include "core.h"

#define PRINT_CORE_ID 0
#define BUF_LENGTH 2

int main(void) {

    const char* pre = "core_id: ";
    const char* post = ".";
    char cbuf[BUF_LENGTH];

    // コア ID 取得
    uint8 core_id = get_core_id();

    // 指定したコア ID かを確認し、該当するならばコア ID を出力する
    if (core_id == PRINT_CORE_ID) {
        ltoa(core_id, cbuf, BUF_LENGTH, 10);
        print(pre);
        print(cbuf);
        println(post);
    } else {
        while (1) {
            // WFI と WFE の違いがよくわからないけれどとりあえず WFI で...
            // 今のところ割り込みを有効にしていないから、
            // 割込み待機を抜けることはないはずだが、
            // 何となく不安なので while(1) で囲む。
            wait_for_interrupt();
        }
    }


    return 0;
}

