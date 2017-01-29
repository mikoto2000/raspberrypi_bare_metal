all: boot.scr

boot.scr: boot.txt
	./u-boot/tools/mkimage -A arm -O linux -T script -C none -a 0 -e 0 -n "PXE Boot" -d boot.txt ./boot.scr

clean:
	rm boot.scr

