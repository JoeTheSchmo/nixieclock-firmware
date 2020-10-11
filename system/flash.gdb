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

define reset
    # Get the chip to a known state
    monitor reset
    monitor flash device = AT91SAM3U4E
    monitor flash download = 1

    # Load the program
    load

    # Peripheral Reset in RSTC_CR
    set *0x400e1200 = 0xA5000004

    # Initialize PC and SP
    mon reg sp=(0x000E0000)
    mon reg pc=(0x000E0004)

    # Print Registers
    info reg
end

# Rebuild, Load, and Run
define re
    make
    reset
    continue
end
