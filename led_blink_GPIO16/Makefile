CC=aarch64-linux-gnu-gcc
LD=aarch64-linux-gnu-ld
AS=aarch64-linux-gnu-as
OBJCOPY=aarch64-linux-gnu-objcopy

OBJECTS=start.o main.o

all: build link objcopy

objcopy: kernel8.img

kernel8.img: kernel8.elf
	$(OBJCOPY) -O binary kernel8.elf kernel8.img


link: kernel8.elf

kernel8.elf: $(OBJECTS)
	$(LD) -Ttext 0x80000 -o kernel8.elf $(OBJECTS)


build: $(OBJECTS)

start.o: start.S
	$(AS) -o start.o start.S

main.o: main.c
	$(CC) -c -o main.o main.c


clean:
	rm *.o *.elf *.img

