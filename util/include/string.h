#ifndef __STRING_H__
#define __STRING_H__
#include <types.h>

unsigned char ltoa(const uint64 l, char* str, const int max_length, const uint64 radix);
unsigned char ltoa_10(const uint64 l, char* str, const int max_length);

#endif // __STRING_H__
