DEVICE = 0483:df11
TOOLS = arm-none-eabi
AS = $(TOOLS)-as
CC = $(TOOLS)-gcc -mcpu=cortex-m3 -mthumb -Os
LD = $(TOOLS)-ld
OBJCOPY = $(TOOLS)-objcopy
OBJDUMP = $(TOOLS)-objdump -d

TARGET = main

OBJS = main.o boot.o

.PHONY: all
all: $(TARGET).elf $(TARGET).dump $(TARGET).bin

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

$(TARGET).dump: $(TARGET).elf
	$(OBJDUMP) $(TARGET).elf > $(TARGET).dump

main.elf: $(OBJS)
	$(LD) -T linker.ld -o $(TARGET).elf $(OBJS)

boot.o: boot.s
	$(AS) boot.s -o boot.o

main.o: main.c
	$(CC) -c main.c

.PHONY: clean
clean:
	rm -f *.o $(TARGET).elf $(TARGET).dump

.PHONY: flash
flash: $(TARGET).bin
	rm -f
	dfu-util -d $(DEVICE) -a 0 -s 0x08000000:leave -D $(TARGET).bin
