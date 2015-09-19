# vim: set tabstop=8 noexpandtab :
#
# nixieclock-firmware - Nixie Clock Main Firmware Program
# Copyright (C) 2013 - 2015 Joe Ciccone
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

DEBUG_HOST	= 127.0.0.1
DEBUG_PORT	= 2331

CROSS_COMPILE	= arm-none-eabi-

CC		= $(CROSS_COMPILE)gcc
LD		= $(CROSS_COMPILE)ld
GDB		= $(CROSS_COMPILE)gdb
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump
SIZE		= $(CROSS_COMPILE)size

RM		= rm
ECHO		= echo

DEBUG_SCRIPT	= system/flash.gdb
LINK_SCRIPT	= system/flash.ld

CFLAGS		+= -mcpu=cortex-m3 -mthumb
CFLAGS		+= -ffreestanding -nostdinc
CFLAGS		+= -O0 -g3 -ggdb
CFLAGS		+= -Wall -Werror
CFLAGS		+= -isystem include

LDFLAGS		+= --script=$(LINK_SCRIPT)
LDFLAGS		+= --entry=reset_handler
LDFLAGS		+= --gc-sections

BINFILE		= nixieclock-firmware.bin
ELFFILE		= nixieclock-firmware.elf

OBJS		+= lib/ctype/isprint.o
OBJS		+= lib/ctype/isspace.o
OBJS		+= lib/ctype/tolower.o
OBJS		+= lib/ctype/toupper.o
OBJS		+= lib/stdio/kgetc.o
OBJS		+= lib/stdio/kprintf.o
OBJS		+= lib/stdio/kputc.o
OBJS		+= lib/stdio/kputs.o
OBJS		+= lib/stdlib/ltostr.o
OBJS		+= lib/stdlib/strtoul.o
OBJS		+= lib/stdlib/ultostr.o
OBJS		+= lib/string/memcpy.o
OBJS		+= lib/string/memset.o
OBJS		+= lib/string/strcat.o
OBJS		+= lib/string/strchr.o
OBJS		+= lib/string/strchrnul.o
OBJS		+= lib/string/strcmp.o
OBJS		+= lib/string/strlen.o
OBJS		+= lib/string/strncat.o
OBJS		+= lib/string/strncmp.o
OBJS		+= lib/string/strrchr.o
OBJS		+= system/console.o
OBJS		+= system/exceptions.o
OBJS		+= system/reset.o
OBJS		+= system/svcall.o
OBJS		+= system/vectors.o

-include local.mk

.PHONY: all
all: $(ELFFILE) $(BINFILE)
	@$(ECHO)
	$(SIZE) -x -B $(ELFFILE)
	@$(ECHO)
	$(SIZE) -x -A $(ELFFILE)

-include $(OBJS:%.o=%.d)
%.o: %.c Makefile
	$(CC) -MD $(CFLAGS) $< -c -o $@

$(ELFFILE): $(OBJS) $(LINK_SCRIPT)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

$(BINFILE): $(ELFFILE)
	$(OBJCOPY) -O binary $(ELFFILE) $(BINFILE)

.PHONY: debug
debug: $(ELFFILE)
	$(GDB) -ex "target remote $(DEBUG_HOST):$(DEBUG_PORT)" -x $(DEBUG_SCRIPT) $(ELFFILE)

.PHONY: disasm
disasm: $(ELFFILE)
	$(OBJDUMP) -drS --show-raw-insn $(ELFFILE)

.PHONY: clean
clean:
	$(RM) -f $(BINFILE) $(ELFFILE) $(OBJS) $(OBJS:%.o=%.d)
