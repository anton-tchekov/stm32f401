MEMORY
{
	flash(RX)  : ORIGIN = 0x08000000, LENGTH = 256K
	sram(WAIL) : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
	} > flash
	.bss  : { *(.bss*) } > sram
}
