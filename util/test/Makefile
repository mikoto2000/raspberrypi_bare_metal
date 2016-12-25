CFLAGS=
#CFLAGS=-D __DEBUG_USE_STDIO_STRING_H__

all: test_gcc_string.exe test_gcc

test_gcc: test_gcc_string.exe
	./test_gcc_string

test_clang: test_gcc_string.exe
	./test_clang_string

test_gcc_string.exe: test_string.c
	gcc -I ../include/ $(CFLAGS) -o test_gcc_string.exe test_string.c ../src/string.c

test_clang_string.exe: test_string.c
	clang -I ../include/ $(CFLAGS) -o test_clang_string.exe test_string.c ../src/string.c -fPIC

clean:
	rm -rf ./*.exe ./*.stackdump
