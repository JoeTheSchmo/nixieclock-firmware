//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2015 Joe Ciccone
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

#ifndef __MENU_H_
#define __MENU_H_

#include <types.h>

typedef enum _menu_key_e {
    menu_key_enter  = 1,
    menu_key_back   = 2,
    menu_key_north  = 3,
    menu_key_south  = 4,
    menu_key_east   = 5,
    menu_key_west   = 6,
} menu_key_e;

extern void menu_key_press(menu_key_e key);

#endif // __MENU_H_
