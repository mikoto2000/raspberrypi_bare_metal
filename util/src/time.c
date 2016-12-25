#include "time.h"

/*
 * @fn wait_count だけビジーウェイトする
 * @param (wait_count) このカウント数だけビジーウェイトする
 */
void busy_wait(int wait_count) {
    volatile unsigned int i;

    for (i = 0; i < wait_count; i++);
}
