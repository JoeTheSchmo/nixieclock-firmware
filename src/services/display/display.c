/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

/**
 * Convert 24-bits color to 16-bits color
 */
static hx8347a_color_t rgb24_to_rgb16(uint32_t ul_color)
{
	hx8347a_color_t result_color;
	result_color = (((ul_color >> 8) & 0xF800) | ((ul_color >> 5) & 0x7E0) | ((ul_color >> 3) & 0x1F));
	return result_color;
}

void display_hx8347a_test(void) {
	/* Write the version on the LCD */
	hx8347a_set_foreground_color(rgb24_to_rgb16(COLOR_WHITE));
	hx8347a_draw_string(0, 0, (uint8_t *)"Nixie Clock FW");
	hx8347a_draw_string(10, 16, (uint8_t *)"v"VERSION);
}

/**
 *  Configure Display.
 */
static void configure_hx8347a(void)
{
	/* Configure SMC interface for Lcd */
	smc_set_setup_timing(SMC, CONF_BOARD_HX8347A_LCD_CS, SMC_SETUP_NWE_SETUP(1) | SMC_SETUP_NCS_WR_SETUP(1) | SMC_SETUP_NRD_SETUP(9) | SMC_SETUP_NCS_RD_SETUP(9));
	smc_set_pulse_timing(SMC, CONF_BOARD_HX8347A_LCD_CS, SMC_PULSE_NWE_PULSE(4) | SMC_PULSE_NCS_WR_PULSE(4) | SMC_PULSE_NRD_PULSE(36) | SMC_PULSE_NCS_RD_PULSE(36));
	smc_set_cycle_timing(SMC, CONF_BOARD_HX8347A_LCD_CS, SMC_CYCLE_NWE_CYCLE(10) | SMC_CYCLE_NRD_CYCLE(45));
	smc_set_mode(SMC, CONF_BOARD_HX8347A_LCD_CS, SMC_MODE_READ_MODE | SMC_MODE_WRITE_MODE | SMC_MODE_DBW_BIT_16);

	/* Initialize display parameter */
	struct hx8347a_opt_t display_options = {
		.ul_width = HX8347A_LCD_WIDTH,
		.ul_height = HX8347A_LCD_HEIGHT,
		.foreground_color = rgb24_to_rgb16(COLOR_WHITE),
		.background_color = rgb24_to_rgb16(COLOR_BLACK)
	};

	/* Switch off backlight */
	aat31xx_disable_backlight();

	/* Configure the hx8347a display controller */
	hx8347a_init(&display_options);

	/* Set backlight level */
	aat31xx_set_backlight(AAT31XX_AVG_BACKLIGHT_LEVEL);

	/* Clear the screen */
	hx8347a_fill(rgb24_to_rgb16(COLOR_BLACK));

	/* Turn on LCD */
	hx8347a_display_on();
}

void display_init(void) {
	configure_hx8347a();
}