// vim: set tabstop=4 shiftwidth=4 expandtab :
//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2016 Joe Ciccone
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

#ifndef __TIMER_H_
#define __TIMER_H_

#include <types.h>

extern int8_t timer_rearm(int8_t id, uint32_t sec);
extern int8_t timer_set(void (*callback)(uint32_t *), uint32_t sec);
extern int8_t timer_del(int8_t id);
extern void timer_init(void);

#endif // __TIMER_H_

