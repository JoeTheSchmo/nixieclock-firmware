
CROSS_COMPILE   := arm-none-eabi-

DEBUG_HOST		:= localhost
DEBUG_PORT		:= 2331

CC              := $(CROSS_COMPILE)gcc
LD              := $(CROSS_COMPILE)ld
GDB             := $(CROSS_COMPILE)gdb
OBJCOPY         := $(CROSS_COMPILE)objcopy
OBJDUMP         := $(CROSS_COMPILE)objdump
SIZE            := $(CROSS_COMPILE)size

RM              := rm

DOXYGEN         := doxygen

LINK_SCRIPT     := asf/sam/utils/linker_scripts/sam3u/sam3u4/gcc/flash.ld
DBG_SCRIPT      := clock/boards/user_board/debug_scripts/gcc/user_board_flash.gdb

CFLAGS          := -mcpu=cortex-m3 -mthumb
CFLAGS          += -D__SAM3U4E__ -DBOARD=USER_BOARD
CFLAGS          += -ffreestanding -O0 -g3 -ggdb
CFLAGS          += -Wall -Werror
CFLAGS          += -I$(PWD)/asf/common/boards
CFLAGS          += -I$(PWD)/asf/common/services/clock
CFLAGS          += -I$(PWD)/asf/common/services/ioport
CFLAGS          += -I$(PWD)/asf/common/utils
CFLAGS          += -I$(PWD)/asf/sam/drivers/efc
CFLAGS          += -I$(PWD)/asf/sam/drivers/pio
CFLAGS          += -I$(PWD)/asf/sam/drivers/pmc
CFLAGS          += -I$(PWD)/asf/sam/drivers/rstc
CFLAGS          += -I$(PWD)/asf/sam/drivers/rtc
CFLAGS          += -I$(PWD)/asf/sam/drivers/spi
CFLAGS          += -I$(PWD)/asf/sam/drivers/ssc
CFLAGS          += -I$(PWD)/asf/sam/drivers/tc
CFLAGS          += -I$(PWD)/asf/sam/drivers/twi
CFLAGS          += -I$(PWD)/asf/sam/drivers/uart
CFLAGS          += -I$(PWD)/asf/sam/drivers/wdt
CFLAGS          += -I$(PWD)/asf/sam/utils
CFLAGS          += -I$(PWD)/asf/sam/utils/cmsis/sam3u/include
CFLAGS          += -I$(PWD)/asf/sam/utils/cmsis/sam3u/source/templates
CFLAGS          += -I$(PWD)/asf/sam/utils/header_files
CFLAGS          += -I$(PWD)/asf/sam/utils/preprocessor
CFLAGS          += -I$(PWD)/CMSIS/Include
CFLAGS          += -I$(PWD)/clock/config
CFLAGS          += -I$(PWD)/clock/boards/user_board
CFLAGS          += -I$(PWD)/clock/components/ds3231
CFLAGS          += -I$(PWD)/clock/components/hv5530
CFLAGS          += -I$(PWD)/clock/components/ssd1306
CFLAGS          += -I$(PWD)/clock/components/wm8731
CFLAGS          += -I$(PWD)/clock/services/audio
CFLAGS          += -I$(PWD)/clock/services/clock
CFLAGS          += -I$(PWD)/clock/services/console
CFLAGS          += -I$(PWD)/clock/services/display
CFLAGS          += -I$(PWD)/clock/utils
CFLAGS          += -I$(PWD)/lib/include

LDFLAGS         := --script=$(LINK_SCRIPT)
LDFLAGS         += --entry=Reset_Handler
LDFLAGS         += --gc-sections

OBJS            :=
OBJS            += asf/common/services/clock/sam3u/sysclk.o
OBJS            += asf/common/utils/interrupt/interrupt_sam_nvic.o
OBJS            += asf/sam/drivers/efc/efc.o
OBJS            += asf/sam/drivers/pio/pio.o
OBJS            += asf/sam/drivers/pio/pio_handler.o
OBJS            += asf/sam/drivers/pmc/pmc.o
OBJS            += asf/sam/drivers/pmc/sleep.o
OBJS            += asf/sam/drivers/rstc/rstc.o
OBJS            += asf/sam/drivers/rtc/rtc.o
OBJS            += asf/sam/drivers/spi/spi.o
OBJS            += asf/sam/drivers/ssc/ssc.o
OBJS            += asf/sam/drivers/tc/tc.o
OBJS            += asf/sam/drivers/twi/twi.o
OBJS            += asf/sam/drivers/uart/uart.o
OBJS            += asf/sam/drivers/wdt/wdt.o
OBJS            += asf/sam/utils/cmsis/sam3u/source/templates/exceptions.o
OBJS            += asf/sam/utils/cmsis/sam3u/source/templates/system_sam3u.o
OBJS            += asf/sam/utils/cmsis/sam3u/source/templates/gcc/startup_sam3u.o
OBJS            += clock/boards/user_board/init.o
OBJS            += clock/components/ds3231/ds3231.o
OBJS            += clock/components/hv5530/hv5530.o
OBJS            += clock/components/ssd1306/ssd1306.o
OBJS            += clock/components/ssd1306/ssd1306_font8x8.o
OBJS            += clock/components/wm8731/wm8731.o
OBJS            += clock/services/audio/audio.o
OBJS            += clock/services/clock/clock.o
OBJS            += clock/services/console/console.o
OBJS            += clock/services/display/display.o
OBJS            += clock/utils/main.o
OBJS            += clock/utils/svcall.o
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

BIN             := nixie1.bin
ELF             := nixie1.elf

.PHONY: all
all: $(ELF) $(BIN)
	$(OBJDUMP) -h $(ELF)
	@echo
	$(SIZE) $(ELF)

-include $(OBJS:%.o=%.d)
%.o: %.c Makefile
	$(CC) -MD $(CFLAGS) $< -c -o $@	

$(ELF): $(OBJS) $(LINK_SCRIPT)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

.PHONY: debug
debug: $(ELF)
	$(GDB) -ex "target remote $(DEBUG_HOST):$(DEBUG_PORT)" -x $(DBG_SCRIPT) $(ELF)

.PHONY: disasm
disasm: $(ELF)
	$(OBJDUMP) -drS --show-raw-insn $(ELF)

.PHONY: doc docs doxygen
doc docs doxygen:
	$(DOXYGEN) doc/doxygen.config

.PHONY: clean
clean:
	$(RM) -f $(BIN) $(ELF) $(OBJS) $(OBJS:%.o=%.d)
