/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2011 - 2013 Atmel Corporation. All rights reserved.
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * \mainpage Nixie Clock Firmware
 *
 * \section Purpose
 *
 * This is a pre-release firmware for the Nixie Clock designed by Ed Koloski and
 * Joe Ciccone. The firmware, hardware, documentation, and any other associated
 * items should be considered unstable and subject to change without notice.
 *
 * This has been a test of the emergency broadcast system.
 *
 * \section Usage
 *
 * -# Build the program and download it inside the evaluation board.
 * -# On the computer, open and configure a terminal application
 *    (e.g. HyperTerminal on Microsoft Windows) with these settings:
 *   - 115200 bauds
 *   - 8 bits of data
 *   - No parity
 *   - 1 stop bit
 *   - No flow control
 * -# Start the application.
 *
 */

#include "asf.h"
#include "stdio_serial.h"

#include "conf_board.h"
#include "conf_clock.h"
#include "conf_wm8731.h"

/**
 * Convert 24-bits color to 16-bits color
 */
static hx8347a_color_t rgb24_to_rgb16(uint32_t ul_color)
{
	hx8347a_color_t result_color;
	result_color = (((ul_color >> 8) & 0xF800) | ((ul_color >> 5) & 0x7E0) | ((ul_color >> 3) & 0x1F));
	return result_color;
}

/**
 *  Configure UART console.
 */
static void configure_console(void)
{
	const usart_serial_options_t uart_serial_options = {
		.baudrate = CONF_UART_BAUDRATE,
		.paritytype = CONF_UART_PARITY
	};

	/* Configure console UART. */
	sysclk_enable_peripheral_clock(CONSOLE_UART_ID);
	stdio_serial_init(CONF_UART, &uart_serial_options);
}

/**
 *  Configure Display.
 */
static void configure_display(void)
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

/**
 * Init TWI interface for WM8731 .
 */
static void init_twi_wm8731(void)
{
	twi_options_t opt;

	/* Configure the options of TWI driver */
	opt.master_clk = sysclk_get_peripheral_hz();
	opt.speed	   = TWI_WM8731_CLK;
	opt.chip	   = WM8731_SLAVE_ADDRESS;
	twi_master_setup(TWI_WM8731, &opt);
}

/**
 * \brief  Initial the WM8731 to play back the sample WAV file.
 */
static void init_dac(void)
{
	uint32_t ul_value;
	/* First, disable programmable clock */
	pmc_disable_pck(PMC_PCK_0);
	/* Then, configure PMC Programmable Clock */
	pmc_switch_pck_to_mainck(PMC_PCK_0, PMC_MCKR_PRES_CLK_1);
	/* Finally, enable programmable clock */
	pmc_enable_pck(PMC_PCK_0);
	/* init control interface */
	init_twi_wm8731();
	/* reset the WM8731 */
	wm8731_reset();
	/* Select the WM8731 DAC */
	wm8731_dac_select(1);
	/* Set the WM8731 to usb mode and 48K DAC */
	wm8731_set_sampling_control(1,0,0);
	/* Set the WM8731 audio interface to I2S mode */
	ul_value = WM8731_REG_DIGITAL_AUDIO_INTERFACE_FORMAT_I2S;
	wm8731_set_digital_audio_data_bit_length(ul_value);
	/* Set the WM8731 audio data bit length to 16bit */
	ul_value = WM8731_REG_DIGITAL_AUDIO_INTERFACE_FORMAT_IWL_16_BIT;
	wm8731_set_digital_audio_data_bit_length(ul_value);
	/* Disable the WM8731 DAC soft mute */
	wm8731_set_dac_soft_mute(0);
	/* Power up the WM8731 DAC */
	wm8731_power_mode_dac();
	/* Active the WM8731 */
	wm8731_set_active(1);
}

/**
 * \brief  Initial the ssc interface.
 */
static void init_ssc(void)
{
	clock_opt_t tx_clk_option;
	data_frame_opt_t tx_data_frame_option;

	/* Initialize clock */
	pmc_enable_periph_clk(ID_SSC);

	/* Reset SSC */
	ssc_reset(SSC);
	/* Configure SSC */
	ssc_set_clock_divider(SSC, WM8731_SAMPLE_RATE * (WM8731_BITS_BY_SLOT + 1) * 2, sysclk_get_peripheral_hz());

	/* Transmitter clock mode configuration. */
	tx_clk_option.ul_cks = SSC_TCMR_CKS_MCK;
	tx_clk_option.ul_cko = SSC_TCMR_CKO_CONTINUOUS;
	tx_clk_option.ul_cki = 0;
	tx_clk_option.ul_ckg = SSC_TCMR_CKG_NONE;
	tx_clk_option.ul_start_sel = SSC_TCMR_START_RF_EDGE;
	tx_clk_option.ul_sttdly = 1;
	tx_clk_option.ul_period = WM8731_BITS_BY_SLOT - 1;
	/* Transmitter frame mode configuration. */
	tx_data_frame_option.ul_datlen = WM8731_BITS_BY_SLOT - 1;
	tx_data_frame_option.ul_msbf = SSC_TFMR_MSBF;
	tx_data_frame_option.ul_datnb = 0;
	tx_data_frame_option.ul_fslen = WM8731_BITS_BY_SLOT - 1;
	tx_data_frame_option.ul_fslen_ext = 0;
	tx_data_frame_option.ul_fsos = SSC_TFMR_FSOS_NEGATIVE;
	tx_data_frame_option.ul_fsedge = SSC_TFMR_FSEDGE_POSITIVE;
	/* Configure the SSC transmitter to I2S mode. */
	ssc_set_transmitter(SSC, &tx_clk_option, &tx_data_frame_option);

	/* Disable transmitter first */
	ssc_disable_tx(SSC);

	/* Disable All Interrupt */
	ssc_disable_interrupt(SSC, 0xFFFFFFFF);
}

/**
 * \brief DMA driver configuration
 */
static void init_dma(void)
{
	uint32_t cfg;

	/* Enable DMA controller */
	dmac_enable(DMAC);

	/* Initialize and enable DMA controller */
	pmc_enable_periph_clk(ID_DMAC);
	dmac_init(DMAC);
	dmac_set_priority_mode(DMAC, DMAC_PRIORITY_ROUND_ROBIN);
	dmac_enable(DMAC);

	/* Disable the DMA channel for SSC */
	dmac_channel_disable(DMAC, DMA_WM8731_CH);

	/* Set channel configuration register */
	cfg = DMAC_CFG_SOD_ENABLE |        /* Enable stop on done */
			DMAC_CFG_DST_H2SEL |       /* Hardware Selection for the Destination */
			DMAC_CFG_DST_PER(3) | /* Destination with Peripheral identifier */
			DMAC_CFG_AHB_PROT(1) |     /* Set AHB Protection */
			DMAC_CFG_FIFOCFG_ALAP_CFG; /* FIFO Configuration */

	dmac_channel_set_configuration(DMAC, DMA_WM8731_CH, cfg);

	/* Set interrupt */
	NVIC_EnableIRQ(DMAC_IRQn);
	dmac_enable_interrupt(DMAC, (DMAC_EBCIER_CBTC0 << DMA_WM8731_CH));
}

/**
 * Configure the Audio Driver and Peripherals
 */
static void configure_audio(void) {
	/* Initialize the WM8731 to DAC */
	init_dac();

	/* Initialize the SSC Interface */
	init_ssc();

	/* Configure DMA */
	init_dma();
}

/**
 *  \brief Application entry point.
 *
 *  \return Unused (ANSI-C compatibility).
 */
int main(void)
{
	/* Prepare interrupts */
	irq_initialize_vectors();
	cpu_irq_enable();

	/* Initialize the SAM system */
	sysclk_init();
	board_init();

	/* Initialize the console uart */
	configure_console();

	/* Enable peripheral clock */
	pmc_enable_periph_clk(ID_SMC);

	/* Initialize the clock display shift registers */
	hv5530_init();

	/* Initialize the display */
	configure_display();

	/* Initialize SD MMC stack */
	sd_mmc_init();

	/* Initialze the Audio Driver */
	configure_audio();

	/* Output version information */
	printf("\r\n" \
		"-- Nixie Clock Firmware v"VERSION" --\r\n" \
		"-- "BOARD_NAME" --\r\n" \
		"-- Compiled: "__DATE__" "__TIME__" --\r\n");

	/* Write the version on the LCD */
	hx8347a_set_foreground_color(rgb24_to_rgb16(COLOR_WHITE));
	hx8347a_draw_string(0, 0, (uint8_t *)"Nixie Clock FW");
	hx8347a_draw_string(10, 16, (uint8_t *)"v"VERSION);

	/* Test output to the hv5530 shift registers */
	hv5530_test();

	/* Main Loop */
	while(1) {
		/* Do Something */
	};

	return 0;
}