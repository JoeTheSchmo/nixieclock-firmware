#
# nixieclock-firmware - Nixie Clock Main Firmware Program
# Copyright (c) 2020 Joe Ciccone and Ed Koloski
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

cmake_minimum_required(VERSION 3.16)

include(cmake/compiler.cmake)
include(cmake/jlink.cmake)

project(nixieclock_firmware C CXX ASM)

include_directories(include)

set(SOURCE_FILES
        components/max6656.c
        components/ssd1306.c
        components/wm8731.c
        drivers/twi.c
        include/arm/nvic.h
        include/arm/scb.h
        include/audio.h
        include/clock.h
        include/console.h
        include/ctype.h
        include/display.h
        include/ds1807.h
        include/ds3231.h
        include/keyboard.h
        include/max6656.h
        include/menu.h
        include/pca9534a.h
        include/pins.h
        include/sam3u4e.h
        include/sam/eefc.h
        include/sam/pdc.h
        include/sam/pio.h
        include/sam/pmc.h
        include/sam/rstc.h
        include/sam/rtc.h
        include/sam/rtt.h
        include/sam/spi.h
        include/sam/ssc.h
        include/sam/supc.h
        include/sam/tc.h
        include/sam/twi.h
        include/sam/uart.h
        include/sam/wdt.h
        include/ssd1306.h
        include/stdio.h
        include/stdlib.h
        include/string.h
        include/system.h
        include/timer.h
        include/types.h
        include/wm8731.h
        lib/ctype/isprint.c
        lib/ctype/isspace.c
        lib/ctype/tolower.c
        lib/ctype/toupper.c
        lib/stdio/kgetc.c
        lib/stdio/kprintf.c
        lib/stdio/kputc.c
        lib/stdio/kputs.c
        lib/stdio/vxprintf.c
        lib/stdlib/ltostr.c
        lib/stdlib/strtoul.c
        lib/stdlib/ultostr.c
        lib/string/memcpy.c
        lib/string/memset.c
        lib/string/strcat.c
        lib/string/strchr.c
        lib/string/strchrnul.c
        lib/string/strcmp.c
        lib/string/strlen.c
        lib/string/strncat.c
        lib/string/strncmp.c
        lib/string/strrchr.c
        services/audio.c
        services/clock.c
        services/console.c
        services/display.c
        services/keyboard.c
        services/menu.c
        services/timer.c
        system/exceptions.c
        system/reset.c
        system/svcall.c
        system/vectors.c
        )

add_executable(${PROJECT_NAME}.elf ${SOURCE_FILES})
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${TARGET_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
        COMMENT "Converting ${PROJECT_NAME}.elf to ${PROJECT_NAME}.bin")
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${TARGET_SIZE} -x -A ${PROJECT_NAME}.elf
        COMMENT "Displaying ${PROJECT_NAME}.elf section sizes in sysv format")
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${TARGET_SIZE} -x -G ${PROJECT_NAME}.elf
        COMMENT "Displaying ${PROJECT_NAME}.elf section sizes in gnu format")

add_custom_target(program
        COMMAND ${JLinkExe} ${CMAKE_CURRENT_SOURCE_DIR}/system/flash.jlink
        DEPENDS ${PROJECT_NAME}.elf
        COMMENT "Flashing the firmware")
