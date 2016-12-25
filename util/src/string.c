#include "string.h"

#ifdef __DEBUG_USE_STDIO_STRING_H__
#include <stdio.h>
#endif // __DEBUG_USE_STDIO_STRING_H__

/**
 * @fn 10 進数値を文字列へ変換する
 * @param (l)          変換対象数値
 * @param (str)        変換後の文字列を格納するバッファへのポインタ
 * @param (max_length) 変換後の文字列を格納するバッファの長さ
 * @return エラーコード
 *         0 : 正常終了
 *         1 : 変換後文字列を格納するバッファの長さが足りなかった
 */
unsigned char ltoa_10(const long l, char* str, const int max_length) {
    unsigned int  i;
    unsigned long tmp_long_value = l < 0 ? -l : l;
    unsigned char tmp_digit_value;
    unsigned int  length = 0;

#ifdef __DEBUG_USE_STDIO_STRING_H__
    printf("start ltoa_10.\n");
    printf("l             : %d\n", l);
    printf("str           : %p\n", str);
    printf("max_length    : %d\n", max_length);
    printf("tmp_long_value: %d\n", tmp_long_value);
#endif // __DEBUG_USE_STDIO_STRING_H__

    // 桁の数値と文字を対応付けする配列
    const char cmap[]
            = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    // ゼロ判定, ゼロならさっさと返却する
    if (l == 0) {
        if (max_length < 2) {
            return 1;
        }

        str[0] = '0';
        str[1] = '\0';

        return 0;
    }

    // 桁数判定
    while (tmp_long_value != 0) {
        tmp_long_value = tmp_long_value / 10;
        length++;
    }
    if (l < 0) {
        length++;
    }

#ifdef __DEBUG_USE_STDIO_STRING_H__
    printf("length: %d\n", length);
#endif // __DEBUG_USE_STDIO_STRING_H__

    // バッファ長上限判定(NULL 文字を含めるので +1 する)
    // 上限を超えていたら 1 を返却
    if (length + 1 > max_length) {
#ifdef __DEBUG_USE_STDIO_STRING_H__
        printf("length + 1 > max_length.\n");
#endif // __DEBUG_USE_STDIO_STRING_H__
        return 1;
    }

    // 文字列変換

    // 文字列変換開始インデックス
    i = length - 1;

    // NULL 文字追加
    str[length] = '\0';

    // 各桁の変換
    tmp_long_value = l < 0 ? -l : l;
    while (tmp_long_value != 0) {
        tmp_digit_value = tmp_long_value % 10;
#ifdef __DEBUG_USE_STDIO_STRING_H__
         printf("digit: %d\n", tmp_digit_value);
#endif // __DEBUG_USE_STDIO_STRING_H__
        str[i] = cmap[tmp_digit_value];
        i--;
        tmp_long_value = tmp_long_value / 10;
    }

    // 負数処理
    if (l < 0) {
        str[0] = '-';
    }

    return 0;
}
