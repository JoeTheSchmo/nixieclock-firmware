/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

/** \brief Write to the SSD1306 Controller via the TWI Bus
 *
 * \param[in] uc_reg_address Either 0x00 for a command or 0x40 for a data operation
 * \param[in] uc_data_len The length of the command or data to be sent
 * \param[in] uc_data_ptr A pointer to the command or data to be sent
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_write_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr) {
	// Prepare the packet
	twi_package_t packet = {
		.addr = {uc_reg_address, 0x00, 0x00},
		.addr_length = 0x01,
		.buffer = uc_data_ptr,
		.length = uc_data_len,
		.chip = SSD1306_SLAVE_ADDRESS,
	};

	// Transmit the packet on wire, ignore ACK/NACK
	return twi_master_write(TWI_SSD1306, &packet);
}

/** \brief Set Contrast Control
 *
 * This command sets the Contrast Setting of the display. The chip has 256
 * contrast steps from 0x00 to 0xFF. The segment output current increases as
 * the contrast step value increases.
 *
 * \param[in] uc_constrast The new contrast value
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_contrast(uint8_t uc_contrast) {
	uint8_t data[2] = {
		0x81,
		uc_contrast
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Entire Display ON
 *
 * This command sets the segment driver to output according to the GDDRAM
 * contents or to force the entire display ON.
 *
 * \param[in] uc_display_on {
 *     0 = Display RAM Content,
 *     1 = Entire Display ON
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_entire_display_on(uint8_t uc_display_on) {
	uint8_t data[1] = {
		(0xA4 + (uc_display_on & 0x01))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Normal/Inverse Display
 *
 * This command sets the display to be either normal or inverse. In normal
 * display a RAM data of 1 indicates an “ON” pixel while in inverse display a
 * RAM data of 0 indicates an “ON” pixel.
 *
 * \param[in] uc_display_invert {
 *     0 = Normal Display Output,
 *     1 = Invert Display Output
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_display_invert(uint8_t uc_display_invert) {
	uint8_t data[1] = {
		(0xA6 + (uc_display_invert & 0x01))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Display ON/OFF
 *
 * This command is used to turn the OLED panel display ON or OFF. When the
 * display is ON, the selected circuits by Set Master Configuration command
 * will be turned ON. When the display is OFF, those circuits will be turned
 * OFF and the segment and common output are in VSS state and high impedance
 * state, respectively.
 *
 * \param[in] uc_display_on {
 *     0 = Display Off,
 *     1 = Display On, Normal Mode
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_display_on(uint8_t uc_display_on) {
	uint8_t data[1] = {
		(0xAE + (uc_display_on & 0x01))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Lower Column Start Address for Page Addressing Mode
 *
 * This command specifies the lower nibble of the 8-bit column start address
 * for the display data RAM under Page Addressing Mode. The column address will
 * be incremented by each data access.
 *
 * \param[in] uc_low_nib Lower Nibble of the 8-bit Column Start Address
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_column_start_addr_low(uint8_t uc_low_nib) {
	uint8_t data[1] = {
		(0x00 + (uc_low_nib & 0x0F))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Higher Column Start Address for Page Addressing Mode
 *
 * This command specifies the higher nibble of the 8-bit column start address
 * for the display data RAM under Page Addressing Mode. The column address will
 * be incremented by each data access.
 *
 * \param[in] uc_high_nib Higher Nibble of the 8-bit Column Start Address
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_column_start_addr_high(uint8_t uc_high_nib) {
	uint8_t data[1] = {
		(0x10 + (uc_high_nib & 0x0F))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Column Start Address for Page Addressing Mode
 *
 * This function sends two commands. One to set the higher nibble of the 8-bit
 * column start address, and a second to set the lower nibble of the 8-bit
 * column start address.
 *
 * \param[in] uc_addr The 8-bit Column Address
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_column_start_addr(uint8_t uc_addr) {
	uint8_t data[2] = {
		(0x10 + ((uc_addr >> 4) & 0x0F)),
		(0x00 + (uc_addr & 0x0F)),
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set Memory Addressing Mode
 *
 * There are 3 different memory addressing modes in the SSD1306; page
 * addressing mode, horizontal addressing mode and vertical addressing mode.
 * This command sets the way of memory addressing into one of the above three
 * modes.
 *
 * In page addressing mode, after the display RAM is read/written, the column
 * address pointer is increased automatically by 1. If the column address
 * pointer reaches column end address, the column address pointer is reset to
 * column start address and page address pointer is not changed. Users have to
 * set the new page and column addresses in order to access the next page RAM
 * content.
 *
 * In horizontal addressing mode, after the display RAM is read/written, the
 * column address pointer is increased automatically by 1. If the column
 * address pointer reaches column end address, the column address pointer is
 * reset to column start address and page address pointer is increased by 1.
 * When both column and page address pointers reach the end address, the
 * pointers are reset to column start address and page start address.
 *
 * In vertical addressing mode, after the display RAM is read/written, the page
 * address pointer is increased automatically by 1. If the page address pointer
 * reaches the page end address, the page address pointer is reset to page
 * start address and column address pointer is increased by 1. When both column
 * and page address pointers reach the end address, the pointers are reset to
 * column start address and page start address.
 *
 * \param[in] uc_mode {
 *     0x00 = Horizontal Addressing Mode,
 *     0x01 = Vertical Addressing Mode,
 *     0x02 = Page Addressing Mode (RESET)
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_mem_addr_mode(uint8_t uc_mode) {
	uint8_t data[2] = {
		0x20,
		(0x00 + (uc_mode & 0x03))
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set Column Address
 *
 * This command specifies column start address and end address of the display
 * data RAM. This command also sets the column address pointer to column start
 * address. This pointer is used to define the current read/write column
 * address in graphic display data RAM. If horizontal address increment mode is
 * enabled by command 20h, after finishing read/write one column data, it is
 * incremented automatically to the next column address. Whenever the column
 * address pointer finishes accessing the end column address, it is reset back
 * to start column address and the row address is incremented to the next row.
 *
 * \param[in] uc_start Column Start Address, Range 0 - 127 (RESET = 0)
 * \param[in] uc_end Column End Address, Range 0 - 127 (RESET = 127)
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_column_addr(uint8_t uc_start, uint8_t uc_end) {
	uint8_t data[3] = {
		0x21,
		(uc_start & 0x7F),
		(uc_end & 0x7F)
	};

	return ssd1306_write_register(0x00, 3, data);
}

/** \brief Set Page Address
 *
 * This command specifies page start address and end address of the display
 * data RAM. This command also sets the page address pointer to page start
 * address. This pointer is used to define the current read/write page address
 * in graphic display data RAM. If vertical address increment mode is enabled
 * by command 20h, after finishing read/write one page data, it is incremented
 * automatically to the next page address. Whenever the page address pointer
 * finishes accessing the end page address, it is reset back to start page
 * address.
 *
 * \param[in] uc_start Page Start Address, Range 0 - 7 (RESET = 0)
 * \param[in] uc_end Page End Address, Range 0 - 7 (RESET = 7)
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_page_addr(uint8_t uc_start, uint8_t uc_end) {
	uint8_t data[3] = {
		0x22,
		(uc_start & 0x07),
		(uc_end & 0x07)
	};

	return ssd1306_write_register(0x00, 3, data);
}

/** \brief Set Page Start Address for Page Addressing Mode
 *
 * This command positions the page start address from 0 to 7 in GDDRAM under
 * Page Addressing Mode.
 *
 * \param[in] uc_addr Start Page Address, Range 0 to 7
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_page_start_addr(uint8_t uc_addr) {
	uint8_t data[1] = {
		(0xB0 | (uc_addr & 0x07))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Display Start Line
 *
 * This command sets the Display Start Line register to determine starting
 * address of display RAM, by selecting a value from 0 to 63. With value equal
 * to 0, RAM row 0 is mapped to COM0. With value equal to 1, RAM row 1 is
 * mapped to COM0 and so on.
 *
 * \param[in] uc_register Display Starting RAM Row, Range 0 to 63
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_display_start_line(uint8_t uc_register) {
	uint8_t data[1] = {
		(0x40 + (uc_register * 0x3F))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Segment Re-map
 * 
 * This command changes the mapping between the display data column address and
 * the segment driver. It allows flexibility in OLED module design.
 *
 * This command only affects subsequent data input. Data already stored in
 * GDDRAM will have no changes.
 *
 * \param[in] uc_map {
 *     0 = Column address 0 is mapped to SEG0 (RESET),
 *     1 = Column address 127 is mapped to SEG0
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_segment_remap(uint8_t uc_map) {
	uint8_t data[1] = {
		(0xA0 + (uc_map * 0x01))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Multiplex Ratio
 *
 * This command switches the default 63 multiplex mode to any multiplex ratio,
 * ranging from 16 to 63. The output pads COM0~COM63 will be switched to the
 * corresponding COM signal.
 *
 * Set Multiplex Ratio to N+1 where N is 6 bit value. Multiplex ratio must be
 * between 16MUX and 64MUX
 *
 * \param[in] uc_ratio MUX Setting
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_multiplex_ratio(uint8_t uc_ratio) {
	uint8_t data[2] = {
		0xA8,
		(uc_ratio & 0x3F)
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief SET COM Output Scan Direction
 *
 * This command sets the scan direction of the COM output, allowing layout
 * flexibility in the OLED module design. Additionally, the display will show
 * once this command is issued. For example, if this command is sent during
 * normal display then the graphic display will be vertically flipped immediately.
 *
 * Where N is the Multiplex Ratio
 *
 * \param[in] uc_direction {
 *     0 = normal mode (RESET) : Scan from COM0 to COM[N-1],
 *     1 = remapped mode : Scan from COM[N-1] to COM0
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_com_scan_dir(uint8_t uc_direction) {
	uint8_t data[1] = {
		(0xC0 + ((uc_direction & 0x01) << 3))
	};

	return ssd1306_write_register(0x00, 1, data);
}

/** \brief Set Display Offset
 *
 * This command specifies the mapping of the display start line to one of
 * COM0~COM63 (assuming that COM0 is the display start line then the display
 * start line register is equal to 0).
 *
 * For example, to move the COM16 towards the COM0 direction by 16 lines the
 * 6-bit data in the second byte should be given as 010000b. To move in the
 * opposite direction by 16 lines the 6-bit data should be given by 64 – 16,
 * so the second byte would be 100000b.
 *
 * \param[in] uc_offset Display Offset
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_display_offset(uint8_t uc_offset) {
	uint8_t data[2] = {
		0xD3,
		(uc_offset & 0x3F)
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set COM Pins Hardware Configuration
 *
 * This command sets the COM signal pin configuration to match the OLED panel
 * hardware layout.
 *
 * \param[in] uc_remap
 * \param[in] uc_alt
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_com_pins(uint8_t uc_remap, uint8_t uc_alt) {
	uint8_t data[2] = {
		0xDA,
		(0x02 | ((uc_remap & 0x01) << 5) | ((uc_alt & 0x01) << 4))
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set Display Clock Divide Ratio and Oscillator Frequency
 *
 * This command consists of two functions:
 *
 * Display Clock Divide Ratio: Set the divide ratio to generate DCLK
 * (Display Clock) from CLK. The divide ratio is from 1 to 16, with reset
 * value = 1.
 *
 * Oscillator Frequency: Program the oscillator frequency Fosc that is the
 * source of CLK if CLS pin is pulled high. The 4-bit value results in 16
 * different frequency settings available. The default setting is 1000b.
 *
 * \param[in] us_osc Oscillator Frequency
 * \param[in] uc_ratio Display Clock Divide Ratio
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_clock_ratio(uint8_t uc_osc, uint8_t uc_ratio) {
	uint8_t data[2] = {
		0xD5,
		(((uc_osc & 0x0F) << 4) | (uc_ratio & 0x0F))
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set Pre-charge Period
 *
 * This command is used to set the duration of the pre-charge period. The
 * interval is counted in number of DCLK, where RESET equals 2 DCLKs.
 *
 * \param[in] uc_phase2 Phase 2 Pre-charge Period
 * \param[in] uc_phase1 Phase 1 Pre-charge Period
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_precharge_period(uint8_t uc_phase2, uint8_t uc_phase1) {
	uint8_t data[2] = {
		0xD9,
		(((uc_phase2 & 0x0F) << 4) | (uc_phase1 & 0x0F))
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Set Vcomh Deselect Level
 *
 * This command adjusts the Vcomh regulator output.
 *
 * \param[in] uc_deselect {
 *     000b = ~ 0.65 x Vcc,
 *     010b = ~ 0.77 x Vcc (RESET),
 *     011b = ~ 0.83 x Vcc
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_vcomh(uint8_t uc_deselect) {
	uint8_t data[2] = {
		0xDB,
		((uc_deselect & 0x07) << 4)
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Charge Pump Setting
 *
 * This command enables or disables the charge pump regulator function.
 *
 * \param[in] uc_enable {
 *     0 = Charge Pump Disable,
 *     1 = Charge Pump Enable
 * }
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_set_charge_pump_enable(uint8_t uc_enable) {
	uint8_t data[2] = {
		0x8D,
		(0x10 + ((uc_enable & 0x01) << 2))
	};

	return ssd1306_write_register(0x00, 2, data);
}

/** \brief Draw a character at the current page and column
 *
 * This function draws a character on the display at the current column and
 * page. Currently it will draw an 8x8 character in vertical addressing mode.
 *
 * \param[in] c The character to be drawn on the display, Range 0 - 127
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_putc(char c) {
	return ssd1306_write_register(0x40, 8, ssd1306_font8x8[c & 0x7F]);
}

/** \brief Draw a string starting at the current page and column
 *
 * This function draws a string on the display at the current column and
 * page using the ssd1306_draw_char function.
 *
 * \param[in] str The string to be drawn on the display.
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t ssd1306_puts(char *s) {
	uint32_t ret;
	while (*s) {
		ret = ssd1306_putc(*s++);
		if (ret != TWI_SUCCESS)
			return ret;
	}
	return TWI_SUCCESS;
}

/** \brief Reset to the SSD1306 Controller.
 *
 * This function initializes the GPIO and provides the SSD1306 controller with
 * a RESET signal.
 */
static void ssd1306_init_reset(void) {
	// Initialize Reset GPIO
	gpio_configure_pin(PIO_PC2_IDX, PIO_TYPE_PIO_OUTPUT_0 | PIO_DEFAULT);

	// Issue a Reset to the controller
	gpio_set_pin_low(PIO_PC2_IDX);
	delay_ms(10);
	gpio_set_pin_high(PIO_PC2_IDX);
	delay_ms(10);
}

/** \brief Initialize the SSD1306 Driver and Controller
 * 
 * This function initializes the SSD1306 controller after a reset and enables
 * the display output
 */
void ssd1306_init(void) {
	ssd1306_init_reset();

	// Initialize the Display Controller
	ssd1306_set_display_on(0x0);
	ssd1306_set_multiplex_ratio(0x1F);
	ssd1306_set_display_offset(0x00);
	ssd1306_set_display_start_line(0x00);
	ssd1306_set_segment_remap(0x1);
	ssd1306_set_com_scan_dir(0x1);
	ssd1306_set_com_pins(0x0, 0x0);
	ssd1306_set_contrast(0x8F);
	ssd1306_set_precharge_period(0xF, 0x1);
	ssd1306_set_vcomh(0x4);
	ssd1306_set_entire_display_on(0x0);
	ssd1306_set_display_invert(0x0);

	// Clear the RAM
	uint8_t zerobuf[16] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	uint8_t page, col;
	for (page = 0; page < 8; page++) {
		ssd1306_set_page_start_addr(page);
		for (col = 0; col < 128; col += 16) {
			ssd1306_write_register(0x40, 16, zerobuf);
		}
	}
	ssd1306_set_page_start_addr(page);

	// Enable the Charge Pump and Turn On the Display
	ssd1306_set_clock_ratio(0x8, 0x0);
	ssd1306_set_charge_pump_enable(0x1);
	ssd1306_set_display_on(0x1);
}