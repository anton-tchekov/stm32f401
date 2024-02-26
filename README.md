# stm32f401

Guide and example code on how to use the "Black Pill" Board from AZ-Delivery.
(STM32F401 Development Board V 3.0 84Mhz 64KB SRAM 256KB Flash)

## Required software:

**For flashing the code to the board:**

`dfu-util` package (Extra)
https://archlinux.org/packages/extra/x86_64/dfu-util/

**C compiler for ARM:**

`arm-none-eabi-gcc` package (Extra)
https://archlinux.org/packages/extra/x86_64/arm-none-eabi-gcc/

## Compiling the code

Run `make`
It should create files `main.elf`, `main.dump` and `main.bin`

## Flashing the board

Connect the board to the computer using a USB-C cable.

Press both the `NRST` and the `BOOT0` button. Then first release the `NRST`
button and after that the `BOOT0` button.

Run command: `lsusb`

Make sure that the output contains the following line:

`Bus 001 Device 030: ID 0483:df11 STMicroelectronics STM Device in DFU Mode`

Run `make flash` to upload the code to the board.
