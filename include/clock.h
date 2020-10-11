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

#ifndef __CLOCK_H_
#define __CLOCK_H_

#include <types.h>

typedef struct _timespec_t {
    uint16_t year;
    uint8_t  month;
    uint8_t  date;
    uint8_t  day;
    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
} timespec_t;
extern volatile timespec_t clock;

extern volatile uint8_t clock_display_24hr;

extern char clock_month_name[13][4];
extern uint8_t clock_month_days[13];
extern char clock_day_name[8][4];

extern int clock_set(timespec_t *time);
extern void clock_init(void);

#endif // __CLOCK_H_
