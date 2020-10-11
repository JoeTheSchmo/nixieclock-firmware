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

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TARGET_TRIPLET arm-none-eabi)

find_program(CMAKE_ASM_COMPILER ${TARGET_TRIPLET}-gcc)
set(CMAKE_ASM_COMPILER_TARGET ${TARGET_TRIPLET})
set(CMAKE_ASM_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_ASM_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_ASM_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "-O2 -ggdb -DNDEBUG")

find_program(CMAKE_C_COMPILER ${TARGET_TRIPLET}-gcc)
set(CMAKE_C_COMPILER_TARGET ${TARGET_TRIPLET})
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_C_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -ggdb -DNDEBUG")

find_program(CMAKE_CXX_COMPILER ${TARGET_TRIPLET}-g++)
set(CMAKE_CXX_COMPILER_TARGET ${TARGET_TRIPLET})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -ggdb -DNDEBUG")

find_program(TARGET_OBJCOPY ${TARGET_TRIPLET}-objcopy)
find_program(TARGET_OBJDUMP ${TARGET_TRIPLET}-objdump)
find_program(TARGET_SIZE ${TARGET_TRIPLET}-size)

find_program(TARGET_GDB NAMES ${TARGET_TRIPLET}-gdb gdb-multiarch gdb)

# Don't run the linker on compiler check
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_ASM_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3 -mthumb -ffreestanding -nostdinc -Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=cortex-m3 -mthumb -ffreestanding -nostdinc -Wall -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=cortex-m3 -mthumb -ffreestanding -nostdinc -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/system/flash.ld -Wl,--entry=reset_handler -Wl,--gc-sections")
