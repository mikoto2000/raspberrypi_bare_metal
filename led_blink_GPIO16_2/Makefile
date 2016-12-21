CC=aarch64-linux-gnu-gcc
LD=aarch64-linux-gnu-ld
AS=aarch64-linux-gnu-as
OBJCOPY=aarch64-linux-gnu-objcopy

OBJECTS=boot.o main.o

all: build link objcopy

objcopy: kernel8.img

kernel8.img: kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf kernel8.img


link: kernel8.elf

kernel8.elf: $(OBJECTS)
	$(LD) -o kernel8.elf $(OBJECTS) -T linker.ld


build: $(OBJECTS)

boot.o: boot.S
	$(AS) -o boot.o boot.S

main.o: main.c
	$(CC) -c -o main.o main.c


clean:
	rm *.o *.elf *.img

