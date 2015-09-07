// vim: set tabstop=4 shiftwidth=4 expandtab
//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2015 Joe Ciccone
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <string.h>

extern void *bss_start;
extern void *bss_end;
extern void *data_start;
extern void *data_end;
extern void *data_load;

void reset_handler() {
    if (bss_end - bss_start > 0) {
        memset(bss_start, 0, bss_end - bss_start);
    }

    if (data_start != data_load) {
        memcpy(data_start, data_load, data_end - data_start);
    }

    while (1) {}
}
