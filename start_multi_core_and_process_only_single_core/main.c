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
    }

    while (1);

    return 0;
}

