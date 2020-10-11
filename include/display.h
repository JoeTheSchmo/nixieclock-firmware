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

#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#include <types.h>

typedef enum _display_state {
    display_state_init   = 1,
    display_state_invert = 2,
    display_state_on     = 4,
    display_state_dimm   = 8,
    display_state_menu   = 16,
} display_state_t;
extern display_state_t display_state;

extern ssize_t dputc(const char c);
extern ssize_t dputs(const char *s);
extern ssize_t dprintf(const char *format, ...)
  __attribute__ ((format (printf, 1, 2)));
extern ssize_t dprintfr(const uint8_t row, const char *format, ...)
  __attribute__ ((format (printf, 2, 3)));

extern void display_invert_font(int8_t invert);

extern void display_wakeup();
extern void display_event_menu(int open);
extern void display_event_clock(void);
extern int display_erase_pages(uint8_t page_start, uint8_t page_count);
extern void display_init(void);

#endif // __DISPLAY_H_
