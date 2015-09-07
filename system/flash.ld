/* vim: set tabstop=4 shiftwidth=4 expandtab

   nixieclock-firmware - Nixie Clock Main Firmware Program
   Copyright (C) 2013 - 2015 Joe Ciccone

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

OUTPUT_FORMAT(elf32-littlearm)

MEMORY {
    ROM (rx)  : ORIGIN = 0x000E0000, LENGTH = 0x00040000 /* flash, 256KB */
    RAM (!rx) : ORIGIN = 0x20078000, LENGTH = 0x0000C000 /* sram,   48KB */
}

HIDDEN(stack_size = 0x1000);

SECTIONS {
    .text : {
        KEEP(*(.vectors))
        *(.text)
    } > ROM

    .rodata : {
        *(.rodata)
        HIDDEN(rodata_end = .);
    } > ROM

    .stack : {
        . = . + stack_size;
        stack_bottom = .;
    } > RAM

    .data : AT (rodata_end) {
        data_start = .;
        *(.data)
        data_end = .;
    } > RAM
    data_load = LOADADDR(.data);

    .bss : {
        bss_start = .;
        *(.bss)
        bss_end = .;
    } > RAM
}
