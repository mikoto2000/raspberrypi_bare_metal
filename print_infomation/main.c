#include <string.h>
#include <uart.h>

#include "core.h"

#define PRINT_CORE_ID 0
#define BUF_LENGTH 255

int main(void) {

    char cbuf[BUF_LENGTH];

    // コア ID 取得
    uint8 core_id = get_core_id();

    // 指定したコア ID かを確認し、該当するならばコア ID を出力する
    if (core_id == PRINT_CORE_ID) {
        ltoa(core_id, cbuf, BUF_LENGTH, 10);
        print("core id: ");
        print(cbuf);
        println(".");

        uint32 currentel = get_currentel();
        ltoa((uint64)currentel, cbuf, BUF_LENGTH, 2);
        print("currentel: 0x");
        print(cbuf);
        println(".");

        uint32 nzcv = get_nzcv();
        ltoa((uint64)nzcv, cbuf, BUF_LENGTH, 2);
        print("nzcv: 0x");
        print(cbuf);
        println(".");

        uint32 daif = get_daif();
        ltoa((uint64)daif, cbuf, BUF_LENGTH, 2);
        print("daif: 0x");
        print(cbuf);
        println(".");

        uint32 spsr_el1 = get_spsr_el1();
        ltoa((uint64)spsr_el1, cbuf, BUF_LENGTH, 2);
        print("spsr_el1: 0x");
        print(cbuf);
        println(".");

        uint32 spsr_el2 = get_spsr_el2();
        ltoa((uint64)spsr_el2, cbuf, BUF_LENGTH, 2);
        print("spsr_el2: 0x");
        print(cbuf);
        println(".");

        uint32 spsr_el3 = get_spsr_el3();
        ltoa((uint64)spsr_el3, cbuf, BUF_LENGTH, 2);
        print("spsr_el3: 0x");
        print(cbuf);
        println(".");

        uint32 midr_el1 = get_midr_el1();
        ltoa((uint64)midr_el1, cbuf, BUF_LENGTH, 2);
        print("midr_el1: 0x");
        print(cbuf);
        println(".");

        uint32 revidr_el1 = get_revidr_el1();
        ltoa((uint64)revidr_el1, cbuf, BUF_LENGTH, 2);
        print("revidr_el1: 0x");
        print(cbuf);
        println(".");

        uint64 id_aa64pfr0_el1 = get_id_aa64pfr0_el1();
        ltoa((uint64)id_aa64pfr0_el1, cbuf, BUF_LENGTH, 2);
        print("id_aa64pfr0_el1: 0x");
        print(cbuf);
        println(".");

        uint64 id_aa64isar0_el1 = get_id_aa64isar0_el1();
        ltoa((uint64)id_aa64isar0_el1, cbuf, BUF_LENGTH, 2);
        print("id_aa64isar0_el1: 0x");
        print(cbuf);
        println(".");

        uint32 isr_el1 = get_isr_el1();
        ltoa((uint64)isr_el1, cbuf, BUF_LENGTH, 2);
        print("isr_el1: 0x");
        print(cbuf);
        println(".");

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

