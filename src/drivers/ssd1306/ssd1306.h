/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef SSD1306_H
#define SSD1306_H

#include "twi_master.h"
#include "conf_ssd1306.h"

/**
 * TWI Safety Definitions
 */

#if !defined(TWI_SSD1306)
# warning The SSD1306 TWI instance has not been defined. Using default settings.
# define TWI_SSD1306 0 /* TWI instance (TWI0) */
#endif
#if !defined(SSD1306_SLAVE_ADDRESS)
# warning The SSD1306 TWI address has not been defined. Using default settings.
# define SSD1306_SLAVE_ADDRESS 0x3C /* TWI address (0x3C) */
#endif
#if !defined(SSD1306_LCDWIDTH)
# warning The SSD1306 LCD Width has not been defined. Using default settings.
# define SSD1306_LCDWIDTH 128 /* 32 Pixels Wide */
#endif
#if !defined(SSD1306_LCDHEIGHT)
# warning The SSD1306 LCD Height has not been defined. Using default settings.
# define SSD1306_LCDHEIGHT 32 /* 32 Pixels High */
#endif

/**
 * Variable Definitions
 */

extern uint8_t ssd1306_font8x8[0x80][8];

/**
 * Function Prototypes
 */

// Communication Functions
extern uint32_t ssd1306_write_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr);

// Fundamental Commands
extern uint32_t ssd1306_set_contrast(uint8_t uc_contrast);
extern uint32_t ssd1306_set_entire_display_on(uint8_t uc_display_on);
extern uint32_t ssd1306_set_display_invert(uint8_t uc_display_invert);
extern uint32_t ssd1306_set_display_on(uint8_t uc_display_on);

// Addressing Settings Commands
extern uint32_t ssd1306_set_column_start_addr_low(uint8_t uc_low_nib);
extern uint32_t ssd1306_set_column_start_addr_high(uint8_t uc_high_nib);
extern uint32_t ssd1306_set_column_start_addr(uint8_t uc_addr);
extern uint32_t ssd1306_set_mem_addr_mode(uint8_t uc_mode);
extern uint32_t ssd1306_set_column_addr(uint8_t uc_start, uint8_t uc_end);
extern uint32_t ssd1306_set_page_addr(uint8_t uc_start, uint8_t uc_end);
extern uint32_t ssd1306_set_page_start_addr(uint8_t uc_addr);

// Hardware Configuration Commands
extern uint32_t ssd1306_set_display_start_line(uint8_t uc_register);
extern uint32_t ssd1306_set_segment_remap(uint8_t uc_map);
extern uint32_t ssd1306_set_multiplex_ratio(uint8_t uc_ratio);
extern uint32_t ssd1306_set_com_scan_dir(uint8_t uc_direction);
extern uint32_t ssd1306_set_display_offset(uint8_t uc_offset);
extern uint32_t ssd1306_set_com_pins(uint8_t uc_remap, uint8_t uc_alt);

// Timing & Driving Scheme Settings Commands
extern uint32_t ssd1306_set_clock_ratio(uint8_t uc_osc, uint8_t uc_ratio);
extern uint32_t ssd1306_set_precharge_period(uint8_t uc_phase2, uint8_t uc_phase1);
extern uint32_t ssd1306_set_vcomh(uint8_t uc_deselect);

// Charge Pump Commands
extern uint32_t ssd1306_set_charge_pump_enable(uint8_t uc_enable);

// Output Functions
extern uint32_t ssd1306_putc(char c);
extern uint32_t ssd1306_puts(char *s);

// Initialization Functions
extern void ssd1306_init(void);

#endif // SSD1306_H