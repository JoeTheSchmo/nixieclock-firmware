
CROSS_COMPILE   := arm-none-eabi-

CC              := $(CROSS_COMPILE)gcc
LD              := $(CROSS_COMPILE)ld
GDB             := $(CROSS_COMPILE)gdb
OBJCOPY         := $(CROSS_COMPILE)objcopy
OBJDUMP         := $(CROSS_COMPILE)objdump

RM              := rm

DOXYGEN         := doxygen

LINK_SCRIPT     := flash.ld
DBG_SCRIPT      := flash.gdb

CFLAGS          := -mcpu=cortex-m3 -mthumb
CFLAGS          += -nostdinc -fno-builtin
CFLAGS          += -I$(PWD) -iquote
CFLAGS          += -O0 -g3 -ggdb
CFLAGS          += -Wall -Werror

LDFLAGS         := --script=$(LINK_SCRIPT)
LDFLAGS         += --entry=reset_handler
LDFLAGS         += --gc-sections

OBJS            := kmain.o
OBJS            += board/init.o
OBJS            += components/ds3231/ds3231.o
OBJS            += components/hv5530/hv5530.o
OBJS            += components/ssd1306/ssd1306.o
OBJS            += components/ssd1306/ssd1306_font8x8.o
OBJS            += components/wm8731/wm8731.o
OBJS            += cpu/svcall.o
OBJS            += cpu/vectors.o
OBJS            += drivers/twi/twi_master.o
OBJS            += lib/ctype/isprint.o
OBJS            += lib/ctype/isspace.o
OBJS            += lib/ctype/toupper.o
OBJS            += lib/ctype/tolower.o
OBJS            += lib/stdio/kgetc.o
OBJS            += lib/stdio/kprintf.o
OBJS            += lib/stdio/kputc.o
OBJS            += lib/stdio/kputs.o
OBJS            += lib/stdlib/ltostr.o
OBJS            += lib/stdlib/strtoul.o
OBJS            += lib/stdlib/ultostr.o
OBJS            += lib/string/memset.o
OBJS            += lib/string/strcat.o
OBJS            += lib/string/strchr.o
OBJS            += lib/string/strchrnul.o
OBJS            += lib/string/strcmp.o
OBJS            += lib/string/strlen.o
OBJS            += lib/string/strncat.o
OBJS            += lib/string/strncmp.o
OBJS            += lib/string/strrchr.o
OBJS            += services/audio/audio.o
OBJS            += services/clock/clock.o
OBJS            += services/console/console.o
OBJS            += services/display/display.o

BIN             := nixie1.bin
ELF             := nixie1.elf

.PHONY: all
all: $(ELF) $(BIN)

-include $(OBJS:%.o=%.d)
%.o: %.c Makefile
	$(CC) -MD $(CFLAGS) $< -c -o $@	

$(ELF): $(OBJS) $(LINK_SCRIPT)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

.PHONY: debug
debug: $(ELF)
	$(GDB) -x $(DBG_SCRIPT) $(ELF)

.PHONY: disasm
disasm: $(ELF)
	$(OBJDUMP) -drS --show-raw-insn $(ELF)

.PHONY: doxygen
doxygen:
	$(DOXYGEN) doxygen.config

.PHONY: clean
clean:
	$(RM) -f $(ELF) $(OBJS) $(OBJS:%.o=%.d)
