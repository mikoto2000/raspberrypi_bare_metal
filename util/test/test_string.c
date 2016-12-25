#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include "string.h"

int main() {
    // ltoa_10 正常系
    long l0     = 0;
    long l9     = 9;
    long l10    = 10;
    long l100   = 100;
    long l1000  = 1000;
    long l10000 = 10000;

    long l_1  = -1;
    long l_10 = -10;

    unsigned char err;

    char str[5];
    char str_max[21];

    err = ltoa_10(l0, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '0');
    assert(str[1] == '\0');
    assert(err == 0);
    err = ltoa_10(l9, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '9');
    assert(str[1] == '\0');
    assert(err == 0);
    err = ltoa_10(l10, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '1');
    assert(str[1] == '0');
    assert(str[2] == '\0');
    assert(err == 0);
    err = ltoa_10(l100, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '1');
    assert(str[1] == '0');
    assert(str[2] == '0');
    assert(str[3] == '\0');
    assert(err == 0);
    err = ltoa_10(l1000, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '1');
    assert(str[1] == '0');
    assert(str[2] == '0');
    assert(str[3] == '0');
    assert(str[4] == '\0');
    assert(err == 0);

    err = ltoa_10(l_1, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '-');
    assert(str[1] == '1');
    assert(str[2] == '\0');
    assert(err == 0);
    err = ltoa_10(l_10, str, (sizeof(str) / sizeof(str[0])));
    assert(str[0] == '-');
    assert(str[1] == '1');
    assert(str[2] == '0');
    assert(str[3] == '\0');
    assert(err == 0);

    err = ltoa_10(LONG_MAX, str_max, (sizeof(str_max) / sizeof(str_max[0])));
    assert(str_max[0] == '9');
    assert(str_max[1] == '2');
    assert(str_max[2] == '2');
    assert(str_max[3] == '3');
    assert(str_max[4] == '3');
    assert(str_max[5] == '7');
    assert(str_max[6] == '2');
    assert(str_max[7] == '0');
    assert(str_max[8] == '3');
    assert(str_max[9] == '6');
    assert(str_max[10] == '8');
    assert(str_max[11] == '5');
    assert(str_max[12] == '4');
    assert(str_max[13] == '7');
    assert(str_max[14] == '7');
    assert(str_max[15] == '5');
    assert(str_max[16] == '8');
    assert(str_max[17] == '0');
    assert(str_max[18] == '7');
    assert(str_max[19] == '\0');

    err = ltoa_10(LONG_MIN, str_max, (sizeof(str_max) / sizeof(str_max[0])));
    assert(str_max[0] == '-');
    assert(str_max[1] == '9');
    assert(str_max[2] == '2');
    assert(str_max[3] == '2');
    assert(str_max[4] == '3');
    assert(str_max[5] == '3');
    assert(str_max[6] == '7');
    assert(str_max[7] == '2');
    assert(str_max[8] == '0');
    assert(str_max[9] == '3');
    assert(str_max[10] == '6');
    assert(str_max[11] == '8');
    assert(str_max[12] == '5');
    assert(str_max[13] == '4');
    assert(str_max[14] == '7');
    assert(str_max[15] == '7');
    assert(str_max[16] == '5');
    assert(str_max[17] == '8');
    assert(str_max[18] == '0');
    assert(str_max[19] == '8');
    assert(str_max[20] == '\0');


    // ltoa_10 異常系
    err = ltoa_10(l10000, str, (sizeof(str) / sizeof(str[0])));
    assert(err == 1);
}
