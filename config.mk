#
# Copyright (c) 2011 Atmel Corporation. All rights reserved.
# Copyright (c) 2013 Joe Ciccone. All rights reserved.
#
# \asf_license_start
#
# \page License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an
#    Atmel microcontroller product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# \asf_license_stop
#

# Current version number for this firmware build
VERSION = HEAD

# Path to top level ASF directory relative to this project directory.
PRJ_PATH = asf

# Path the the top level build directory relative to this project directory.
BUILD_DIR = $(PRJ_PATH)

# Target CPU architecture: cortex-m3, cortex-m4
ARCH = cortex-m3

# Target part: none, sam3n4 or sam4l4aa
PART = sam3u4e

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET_FLASH = nixie1-$(VERSION)_flash.elf
TARGET_SRAM = nixie1-$(VERSION)_sram.elf

# List of C source files.
CSRCS = \
       common/components/memory/sd_mmc/sd_mmc.c \
       common/components/memory/sd_mmc/sd_mmc_mem.c \
       common/services/clock/sam3u/sysclk.c \
       common/services/delay/sam/cycle_counter.c \
       common/services/serial/usart_serial.c \
       common/services/spi/sam_spi/spi_master.c \
       common/services/storage/ctrl_access/ctrl_access.c \
       common/utils/interrupt/interrupt_sam_nvic.c \
       common/utils/stdio/read.c \
       common/utils/stdio/write.c \
       sam/components/audio/codec/wm8731/wm8731.c \
       sam/drivers/dmac/dmac.c \
       sam/drivers/ebi/smc/smc.c \
       sam/drivers/hsmci/hsmci.c \
       sam/drivers/pio/pio.c \
       sam/drivers/pio/pio_handler.c \
       sam/drivers/pmc/pmc.c \
       sam/drivers/pmc/sleep.c \
       sam/drivers/rtc/rtc.c \
       sam/drivers/spi/spi.c \
       sam/drivers/ssc/ssc.c \
       sam/drivers/tc/tc.c \
       sam/drivers/twi/twi.c \
       sam/drivers/uart/uart.c \
       sam/drivers/usart/usart.c \
       sam/utils/cmsis/sam3u/source/templates/exceptions.c \
       sam/utils/cmsis/sam3u/source/templates/gcc/startup_sam3u.c \
       sam/utils/cmsis/sam3u/source/templates/system_sam3u.c \
       sam/utils/syscalls/gcc/syscalls.c \
       thirdparty/fatfs/fatfs-port-r0.09/diskio.c \
       thirdparty/fatfs/fatfs-port-r0.09/sam/fattime_rtc.c \
       thirdparty/fatfs/fatfs-r0.09/src/ff.c \
       thirdparty/fatfs/fatfs-r0.09/src/option/ccsbcs.c \
       ../local/boards/user_board/init.c \
       ../local/components/display/hv5530/hv5530.c \
       ../local/components/display/ssd1306/ssd1306.c \
       ../local/components/display/ssd1306/ssd1306_font8x8.c \
       ../local/components/environment/bmp085/bmp085.c \
       ../local/components/environment/hih6130/hih6130.c \
       ../local/components/rtc/ds3231/ds3231.c \
       ../local/services/audio/audio.c \
       ../local/services/clock/clock.c \
       ../local/services/display/display.c \
       ../local/services/dma/dma.c \
       ../local/main.c

# List of assembler source files.
ASSRCS = 

# List of include paths.
INC_PATH = \
       common/boards \
       common/components/memory/sd_mmc \
       common/services/clock \
       common/services/delay \
       common/services/ioport \
       common/services/serial \
       common/services/serial/sam_uart \
       common/services/spi \
       common/services/spi/sam_spi \
       common/services/storage/ctrl_access \
       common/services/twi \
       common/services/twi/sam_twi \
       common/utils \
       common/utils/stdio/stdio_serial \
       sam/components/audio/codec/wm8731 \
       sam/drivers/dmac \
       sam/drivers/ebi/smc \
       sam/drivers/hsmci \
       sam/drivers/pio \
       sam/drivers/pmc \
       sam/drivers/rtc \
       sam/drivers/spi \
       sam/drivers/ssc \
       sam/drivers/tc \
       sam/drivers/twi \
       sam/drivers/uart \
       sam/drivers/usart \
       sam/utils \
       sam/utils/cmsis/sam3u/include \
       sam/utils/cmsis/sam3u/source/templates \
       sam/utils/header_files \
       sam/utils/preprocessor \
       thirdparty/CMSIS/Include \
       thirdparty/fatfs/fatfs-port-r0.09/sam \
       thirdparty/fatfs/fatfs-r0.09/src \
       ../local \
       ../local/boards \
       ../local/boards/user_board \
       ../local/config \
       ../local/components \
       ../local/components/display \
       ../local/components/display/hv5530 \
       ../local/components/display/ssd1306 \
       ../local/components/environment \
       ../local/components/environment/bmp085 \
       ../local/components/environment/hih6130 \
       ../local/components/rtc \
       ../local/components/rtc/ds3231 \
       ../local/services/audio \
       ../local/services/clock \
       ../local/services/display \
       ../local/services/dma

# Additional search paths for libraries.
LIB_PATH = \
       thirdparty/CMSIS/Lib/GCC                          

# List of libraries to use during linking.
LIBS = \
       arm_cortexM3l_math \
       m                                                 

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT_FLASH = sam/utils/linker_scripts/sam3u/sam3u4/gcc/flash.ld
LINKER_SCRIPT_SRAM  = sam/utils/linker_scripts/sam3u/sam3u4/gcc/sram.ld

# Path relative to top level directory pointing to a linker script.
DEBUG_SCRIPT_FLASH = ../src/boards/user_board/debug_scripts/gcc/sam3u_ek_flash.gdb
DEBUG_SCRIPT_SRAM  = ../src/boards/user_board/debug_scripts/gcc/sam3u_ek_sram.gdb

# Project type parameter: all, sram or flash
PROJECT_TYPE        = flash

# Additional options for debugging. By default the common Makefile.in will
# add -g3.
DBGFLAGS = 

# Application optimization used during compilation and linking:
# -O0, -O1, -O2, -O3 or -Os
OPTIMIZATION = -O1

# Extra flags to use when archiving.
ARFLAGS = 

# Extra flags to use when assembling.
ASFLAGS = 

# Extra flags to use when compiling.
CFLAGS = 

# Extra flags to use when preprocessing.
#
# Preprocessor symbol definitions
#   To add a definition use the format "-D name[=definition]".
#   To cancel a definition use the format "-U name".
#
# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
       -D VERSION=\"$(VERSION)\" \
       -D ARM_MATH_CM3=true \
       -D BOARD=USER_BOARD \
       -D VIRTUAL_MEMORY_ENABLE=false \
       -D AT45DBX_ENABLE=false \
       -D SD_MMC_SPI_ENABLE=false \
       -D SD_MMC_MCI_ENABLE=false \
       -D SD_MMC_ENABLE=true \
       -D USB_MASS_STORAGE_ENABLE=false \
       -D ACCESS_USB_ENABLED=false \
       -D ACCESS_MEM_TO_RAM_ENABLED=true \
       -D __SAM3U4E__ \
       -D printf=iprintf

# Extra flags to use when linking
LDFLAGS = \

