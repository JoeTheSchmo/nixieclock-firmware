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

#ifndef __SSD1306_H_
#define __SSD1306_H_

#include <types.h>

#define SSD1306_TWI_ADDR             0x3C

// Fundamental Commands
extern int32_t ssd1306_set_contrast(uint8_t contrast);
extern int32_t ssd1306_set_entire_display_on(uint8_t display_on);
extern int32_t ssd1306_set_display_invert(uint8_t display_invert);
extern int32_t ssd1306_set_display_on(uint8_t display_on);

// Addressing Settings Commands
extern int32_t ssd1306_set_column_start_addr_low(uint8_t low_nib);
extern int32_t ssd1306_set_column_start_addr_high(uint8_t high_nib);
extern int32_t ssd1306_set_column_start_addr(uint8_t addr);
extern int32_t ssd1306_set_mem_addr_mode(uint8_t mode);
extern int32_t ssd1306_set_column_addr(uint8_t start, uint8_t end);
extern int32_t ssd1306_set_page_addr(uint8_t start, uint8_t end);
extern int32_t ssd1306_set_page_start_addr(uint8_t addr);

// Hardware Configuration Commands
extern int32_t ssd1306_set_display_start_line(uint8_t reg);
extern int32_t ssd1306_set_segment_remap(uint8_t map);
extern int32_t ssd1306_set_multiplex_ratio(uint8_t ratio);
extern int32_t ssd1306_set_com_scan_dir(uint8_t direction);
extern int32_t ssd1306_set_display_offset(uint8_t offset);
extern int32_t ssd1306_set_com_pins(uint8_t remap, uint8_t alt);

// Timing & Driving Scheme Settings Commands
extern int32_t ssd1306_set_clock_ratio(uint8_t osc, uint8_t ratio);
extern int32_t ssd1306_set_precharge_period(uint8_t phase2, uint8_t phase1);
extern int32_t ssd1306_set_vcomh(uint8_t deselect);

// Charge Pump Commands
extern int32_t ssd1306_set_charge_pump_enable(uint8_t enable);

// Data Commands
extern int32_t ssd1306_write_data(uint8_t *dptr, uint8_t dlen);

#endif // __SSD1306_H_
