CC=aarch64-linux-gnu-gcc
LD=aarch64-linux-gnu-ld
AS=aarch64-linux-gnu-as
OBJCOPY=aarch64-linux-gnu-objcopy

OBJECTS=boot.o system_register.o main.o core_c.o core_s.o uart.o string.o

all: build link objcopy

.PHONY: qemu
qemu: kernel8.elf
	qemu-system-aarch64 -kernel ./kernel8.elf -serial null -serial mon:stdio -nographic -machine raspi3

objcopy: kernel8.img

kernel8.img: kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf kernel8.img


link: kernel8.elf

kernel8.elf: $(OBJECTS)
	$(LD) -o kernel8.elf $(OBJECTS) -T linker.ld


build: $(OBJECTS)

boot.o: boot.S
	$(AS) -o boot.o boot.S

system_register.o: ../util/src/system_register.S
	$(AS) -o system_register.o ../util/src/system_register.S

main.o: main.c
	$(CC) -I ../util/include -c -o main.o main.c

core_c.o: ../util/src/core.c
	$(CC) -I ../util/include -c -o core_c.o ../util/src/core.c

core_s.o: ../util/src/core.s
	$(CC) -I ../util/include -c -o core_s.o ../util/src/core.S

uart.o: ../util/src/uart.c
	$(CC) -I ../util/include -c -o uart.o ../util/src/uart.c

string.o: ../util/src/string.c
	$(CC) -I ../util/include -c -o string.o ../util/src/string.c

clean:
	rm *.o *.elf *.img

