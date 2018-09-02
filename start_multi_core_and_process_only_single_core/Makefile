CC=aarch64-linux-gnu-gcc
LD=aarch64-linux-gnu-ld
AS=aarch64-linux-gnu-as
OBJCOPY=aarch64-linux-gnu-objcopy

CFLAGS=-I ../util/include

OBJECTS=boot_s.o system_register_s.o main_c.o core_c.o core_s.o uart_c.o string_c.o

all: build link objcopy

.PHONY: qemu
qemu: kernel8.elf
	qemu-system-aarch64 -kernel ./$^ -serial null -serial mon:stdio -nographic -machine raspi3

objcopy: kernel8.img

kernel8.img: kernel8.elf
	$(OBJCOPY) -O binary $^ $@


link: kernel8.elf

kernel8.elf: $(OBJECTS)
	$(LD) -o $@ $^ -T linker.ld


build: $(OBJECTS)

# カレントディレクトリのアセンブリコードコンパイル用のルール
%_s.o: ./%.S
	$(AS) -o $@ $^

# カレントディレクトリの C コードコンパイル用のルール
%_c.o: ./%.c
	$(CC) $(CFLAGS) -c -o $@ $^

# util のアセンブリコードコンパイル用のルール
%_s.o: ../util/src/%.S
	$(AS) -o $@ $^

# util の C コードコンパイル用のルール
%_c.o: ../util/src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm *.o *.elf *.img

