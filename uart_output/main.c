#include <string.h>
#include <uart.h>

#define MAX_COUNT 1000
#define BUF_LENGTH 5

int main(void) {

    int counter;
    const char* pre = "count: ";
    const char* post = ".";
    char cbuf[BUF_LENGTH];

    for (counter = 0; counter <= MAX_COUNT; counter++) {
        ltoa_10(counter, cbuf, BUF_LENGTH);
        print(pre);
        print(cbuf);
        println(post);
    }

    while (1);

    return 0;
}

