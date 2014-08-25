
MEMORY
{
        flash0 (w!rx) : ORIGIN = 0x00080000, LENGTH = 0x00020000 /* flash0, 128K */
        flash1 (w!rx) : ORIGIN = 0x00100000, LENGTH = 0x00020000 /* flash1, 128K */
        sram0  (w!rx) : ORIGIN = 0x20000000, LENGTH = 0x00008000 /*  sram0, 32K  */
        sram1  (w!rx) : ORIGIN = 0x20080000, LENGTH = 0x00004000 /*  sram1, 16K  */
        flash  (rx)   : ORIGIN = 0x000E0000, LENGTH = 0x00040000 /*  flash, 256K */
        sram   (rwx)  : ORIGIN = 0x20078000, LENGTH = 0x0000C000 /*   sram, 48K  */
}

SECTIONS
{
	.text : {
		 KEEP(*(.vectors))
		*(.text .text.*)
		*(.rodata .rodata.*)
		_flash_data = .;
	} > flash0
	.data : AT (_flash_data) {
		_data_start = .;
		*(.data .data.*)
		_data_end = .;
	} > sram0
	.bss : {
		_bss_start = .;
		*(.bss .bss.*)
		_bss_end = .;
	} > sram0
}

