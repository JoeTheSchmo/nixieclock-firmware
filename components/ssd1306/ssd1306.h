/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _SSD1306_H_
#define _SSD1306_H_

#include "types.h"

/**
 * Variable Definitions
 */

extern uint8_t ssd1306_font8x8[0x80][8];

/**
 * Function Prototypes
 */

// Communication Functions
extern inline int32_t ssd1306_write_register(uint8_t addr, uint8_t len, uint8_t *ptr);

// Fundamental Commands
extern int32_t ssd1306_set_contrast(uint8_t uc_contrast);
extern int32_t ssd1306_set_entire_display_on(uint8_t uc_display_on);
extern int32_t ssd1306_set_display_invert(uint8_t uc_display_invert);
extern int32_t ssd1306_set_display_on(uint8_t uc_display_on);

// Addressing Settings Commands
extern int32_t ssd1306_set_column_start_addr_low(uint8_t uc_low_nib);
extern int32_t ssd1306_set_column_start_addr_high(uint8_t uc_high_nib);
extern int32_t ssd1306_set_column_start_addr(uint8_t uc_addr);
extern int32_t ssd1306_set_mem_addr_mode(uint8_t uc_mode);
extern int32_t ssd1306_set_column_addr(uint8_t uc_start, uint8_t uc_end);
extern int32_t ssd1306_set_page_addr(uint8_t uc_start, uint8_t uc_end);
extern int32_t ssd1306_set_page_start_addr(uint8_t uc_addr);

// Hardware Configuration Commands
extern int32_t ssd1306_set_display_start_line(uint8_t uc_register);
extern int32_t ssd1306_set_segment_remap(uint8_t uc_map);
extern int32_t ssd1306_set_multiplex_ratio(uint8_t uc_ratio);
extern int32_t ssd1306_set_com_scan_dir(uint8_t uc_direction);
extern int32_t ssd1306_set_display_offset(uint8_t uc_offset);
extern int32_t ssd1306_set_com_pins(uint8_t uc_remap, uint8_t uc_alt);

// Timing & Driving Scheme Settings Commands
extern int32_t ssd1306_set_clock_ratio(uint8_t uc_osc, uint8_t uc_ratio);
extern int32_t ssd1306_set_precharge_period(uint8_t uc_phase2, uint8_t uc_phase1);
extern int32_t ssd1306_set_vcomh(uint8_t uc_deselect);

// Charge Pump Commands
extern int32_t ssd1306_set_charge_pump_enable(uint8_t uc_enable);

// Output Functions
extern int32_t ssd1306_putc(const char c);
extern int32_t ssd1306_puts(const char *s);

// Initialization Functions
extern void ssd1306_init(void);

#endif // _SSD1306_H_