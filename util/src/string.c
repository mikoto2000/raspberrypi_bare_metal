#include "string.h"

#ifdef __DEBUG_USE_STDIO_STRING_H__
#include <stdio.h>
#define debugf(args...) printf(args)
#else // __DEBUG_USE_STDIO_STRING_H__
#define debugf(args...)
#endif // __DEBUG_USE_STDIO_STRING_H__

/**
 * @fn 10 進数値を文字列へ変換する
 * @param (l)          変換対象数値
 * @param (str)        変換後の文字列を格納するバッファへのポインタ
 * @param (max_length) 変換後の文字列を格納するバッファの長さ
 * @return エラーコード
 *         0 : 正常終了
 *         1 : 変換後文字列を格納するバッファの長さが足りなかった
 * @deprecated 互換性のために残してあります。ltoa() 関数を使用してください。
 * @see ltoa()
 */
unsigned char ltoa_10(const uint64 l, char* str, const int max_length) {
    debugf("start ltoa_10.\n");
    return ltoa(l, str, max_length, 10l);
}

/**
 * @fn 数値を、指定された基数の文字列へ変換する
 * @param (l)          変換対象数値
 * @param (str)        変換後の文字列を格納するバッファへのポインタ
 * @param (max_length) 変換後の文字列を格納するバッファの長さ
 * @param (radix)      基数(サポート範囲: 1 <= radix <= 16)
 * @return エラーコード
 *         0 : 正常終了
 *         1 : 変換後文字列を格納するバッファの長さが足りなかった
 *         2 : サポートしていない基数が指定された
 */
unsigned char ltoa(const uint64 l, char* str, const int max_length, const uint64 radix) {
    uint64  i;
    uint64 tmp_long_value = l < 0 ? -l : l;
    uint8 tmp_digit_value;
    uint64  length = 0;

    debugf("start ltoa.\n");
    debugf("l             : %d\n", l);
    debugf("str           : %p\n", str);
    debugf("max_length    : %d\n", max_length);
    debugf("radix         : %d\n", radix);
    debugf("tmp_long_value: %d\n", tmp_long_value);

    // 桁の数値と文字を対応付けする配列
    const char cmap[]
            = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    // 基数判定
    if (!(radix >= 1 && radix <= 16)) {
        debugf("invalid radix.\n");
        return 3;
    }

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
        tmp_long_value = tmp_long_value / radix;
        length++;
    }
    if (l < 0) {
        length++;
    }

    debugf("length: %d\n", length);

    // バッファ長上限判定(NULL 文字を含めるので +1 する)
    // 上限を超えていたら 1 を返却
    if (length + 1 > max_length) {
        debugf("length + 1 > max_length.\n");
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
        tmp_digit_value = tmp_long_value % radix;
        debugf("digit: %c\n", cmap[tmp_digit_value]);
        str[i] = cmap[tmp_digit_value];
        i--;
        tmp_long_value = tmp_long_value / radix;
    }

    // 負数処理
    if (l < 0) {
        str[0] = '-';
    }

    return 0;
}
