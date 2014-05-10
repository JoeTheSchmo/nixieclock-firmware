/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>
#include <string.h>

/** Reusable DMA descriptor initialized with the driver. */
dma_transfer_descriptor_t hv5530_dmac_tx;

/** Local copy of the registers to be sent through SPI via the DMA controller. */
uint8_t hv5530_registers[8] = {
	0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF
};

/** Enumeration describing the state of the hv5530 driver */
volatile enum {
	hv5530_state_init = 1,  ///< If flag is set, the driver has been initialized
	hv5530_state_tx = 2,    ///< If flag is set, DMA is in progress
	hv5530_state_glow = 3   ///< If flag is set, brightness is intensifying
} hv5530_state = 0;

/** \brief Interrupt Handler for DMA Operations
 *
 * This function handles DMA interrupts related to our channel.
 *
 * \param status Copy of the DMAC Status Register
 */
void hv5530_dma_interrupt(uint32_t status) {
	// Wait for the transmission to complete
	while (!spi_is_tx_empty(SPI));

	// Allow the shift registers to settle
	delay_us(1);

	// Latch the output
	gpio_set_pin_low(PIO_PC1_IDX);
	delay_us(1);
	gpio_set_pin_high(PIO_PC1_IDX);

	// Clear the tx flag in the state register
	hv5530_state &= ~hv5530_state_tx;
}


/** \brief Interrupt Handler for TC0
 *
 * This function handles interrupts from the TC0 Module. Currently it receives
 * a counter overflow and match on counter C. When the overflow status is
 * received, the blank line is driven low, turning on the display. The RC
 * register is set determing the overall duty cycle for the display. Varying
 * slightly at every overflow to form a glowing effect. When the match on
 * coutner C in encountered, the blanking line is driven high turning the
 * display off until the next overflow occurs.
 */
void TC0_Handler(void) {
	static uint32_t status;
	status = tc_get_status(TC0, 0);

	if (status & TC_SR_COVFS) {
		// clock overflow, turn on the display
		gpio_set_pin_low(PIO_PC0_IDX);

		// read the current rc register
		static uint32_t rc;
		rc = tc_read_rc(TC0, 0);

		// determine if we need to change fading in / fading out
		if (rc > 0xB000) {
			hv5530_state &= ~hv5530_state_glow;
		} else if (rc < 0x5000) {
			hv5530_state |= hv5530_state_glow;
		}

		// calculate the new duty cycle
		if (hv5530_state & hv5530_state_glow) {
			rc += 0x200;
		} else {
			rc -= 0x200;
		}

		// write the rc register
		tc_write_rc(TC0, 0, rc);
	} else if (status & TC_SR_CPCS) {
		// rc match, turn off the display
		gpio_set_pin_high(PIO_PC0_IDX);
	}
}

/** \brief Write and Latch the Shift Registers
 *
 * This function starts a DMA transfer to the SPI peripheral in order to load
 * the shift registers with 64bits of data stored in memory.
 */
void hv5530_write_registers() {
	// Set the tx flag in the state register
	hv5530_state |= hv5530_state_tx;

	// Start a new DMA transfer
	dmac_channel_disable(DMAC, HV5530_DMA_CH);
	dmac_channel_single_buf_transfer_init(DMAC, HV5530_DMA_CH, &hv5530_dmac_tx);
	dmac_channel_enable(DMAC, HV5530_DMA_CH);
}

/** \brief Update Clock with specified Time of Day
 *
 * This function converts a time of day to a register map and updates the
 * shift registers.
 *
 * \param ul_hour Time of Day, Hours
 * \param ul_minute Time of Day, Minutes
 * \param ul_second Time of Day, Seconds
 */
void hv5530_set_digits(uint32_t ul_hour, uint32_t ul_minute, uint32_t ul_second) {
	memset(hv5530_registers, 0xFF, 8);

	switch(ul_second % 10) {
	case 0: hv5530_registers[0] &= 0b01111111; break; // 64: SEC_ONE_0
	case 9: hv5530_registers[0] &= 0b10111111; break; // 63: SEC_ONE_9
	case 8: hv5530_registers[0] &= 0b11011111; break; // 62: SEC_ONE_8
	case 7: hv5530_registers[0] &= 0b11101111; break; // 61: SEC_ONE_7
	case 6: hv5530_registers[0] &= 0b11110111; break; // 60: SEC_ONE_6
	case 5: hv5530_registers[0] &= 0b11111011; break; // 59: SEC_ONE_5
	case 4: hv5530_registers[0] &= 0b11111101; break; // 58: SEC_ONE_4
	case 3: hv5530_registers[0] &= 0b11111110; break; // 57: SEC_ONE_3
	case 2: hv5530_registers[1] &= 0b01111111; break; // 56: SEC_ONE_2
	case 1: hv5530_registers[1] &= 0b10111111; break; // 55: SEC_ONE_1
	}

	switch(ul_second / 10) {
	case 0: hv5530_registers[1] &= 0b11011111; break; // 54: SEC_TEN_0
	case 9: hv5530_registers[1] &= 0b11101111; break; // 53: SEC_TEN_9
	case 8: hv5530_registers[1] &= 0b11110111; break; // 52: SEC_TEN_8
	case 7: hv5530_registers[1] &= 0b11111011; break; // 51: SEC_TEN_7
	case 6: hv5530_registers[1] &= 0b11111101; break; // 50: SEC_TEN_6
	case 5: hv5530_registers[1] &= 0b11111110; break; // 49: SEC_TEN_5
	case 4: hv5530_registers[2] &= 0b01111111; break; // 48: SEC_TEN_4
	case 3: hv5530_registers[2] &= 0b10111111; break; // 47: SEC_TEN_3
	case 2: hv5530_registers[2] &= 0b11011111; break; // 46: SEC_TEN_2
	case 1: hv5530_registers[2] &= 0b11101111; break; // 45: SEC_TEN_1
	}

	hv5530_registers[2] &= 0b11110111; // 44: RCOL_TOP
	hv5530_registers[2] &= 0b11111011; // 43: RCOL_BOT

	switch(ul_minute % 10) {
	case 0: hv5530_registers[2] &= 0b11111101; break; // 42: MIN_ONE_0
	case 9: hv5530_registers[2] &= 0b11111110; break; // 41: MIN_ONE_9
	case 8: hv5530_registers[3] &= 0b01111111; break; // 40: MIN_ONE_8
	case 7: hv5530_registers[3] &= 0b10111111; break; // 39: MIN_ONE_7
	case 6: hv5530_registers[3] &= 0b11011111; break; // 38: MIN_ONE_6
	case 5: hv5530_registers[3] &= 0b11101111; break; // 37: MIN_ONE_5
	case 4: hv5530_registers[3] &= 0b11110111; break; // 36: MIN_ONE_4
	case 3: hv5530_registers[3] &= 0b11111011; break; // 35: MIN_ONE_3
	case 2: hv5530_registers[3] &= 0b11111101; break; // 34: MIN_ONE_2
	case 1: hv5530_registers[3] &= 0b11111110; break; // 33: MIN_ONE_1
	}

	switch(ul_minute / 10) {
	case 0: hv5530_registers[4] &= 0b01111111; break; // 32: MIN_TEN_0
	case 9: hv5530_registers[4] &= 0b10111111; break; // 31: MIN_TEN_9
	case 8: hv5530_registers[4] &= 0b11011111; break; // 30: MIN_TEN_8
	case 7: hv5530_registers[4] &= 0b11101111; break; // 29: MIN_TEN_7
	case 6: hv5530_registers[4] &= 0b11110111; break; // 28: MIN_TEN_6
	case 5: hv5530_registers[4] &= 0b11111011; break; // 27: MIN_TEN_5
	case 4: hv5530_registers[4] &= 0b11111101; break; // 26: MIN_TEN_4
	case 3: hv5530_registers[4] &= 0b11111110; break; // 25: MIN_TEN_3
	case 2: hv5530_registers[5] &= 0b01111111; break; // 24: MIN_TEN_2
	case 1: hv5530_registers[5] &= 0b10111111; break; // 23: MIN_TEN_1
	}

	switch(ul_hour % 10) {
	case 0: hv5530_registers[5] &= 0b11011111; break; // 22: HOUR_ONE_0
	case 9: hv5530_registers[5] &= 0b11101111; break; // 21: HOUR_ONE_9
	case 8: hv5530_registers[5] &= 0b11110111; break; // 20: HOUR_ONE_8
	case 7: hv5530_registers[5] &= 0b11111011; break; // 19: HOUR_ONE_7
	case 6: hv5530_registers[5] &= 0b11111101; break; // 18: HOUR_ONE_6
	case 5: hv5530_registers[5] &= 0b11111110; break; // 17: HOUR_ONE_5
	case 4: hv5530_registers[6] &= 0b01111111; break; // 16: HOUR_ONE_4
	case 3: hv5530_registers[6] &= 0b10111111; break; // 15: HOUR_ONE_3
	case 2: hv5530_registers[6] &= 0b11011111; break; // 14: HOUR_ONE_2
	case 1: hv5530_registers[6] &= 0b11101111; break; // 13: HOUR_ONE_1
	}

	hv5530_registers[6] &= 0b11110111; // 12: LCOL_TOP
	hv5530_registers[6] &= 0b11111011; // 11: LCOL_BOT

	switch(ul_hour / 10) {
	case 0: hv5530_registers[6] &= 0b11111101; break; // 10: HOUR_TEN_0
	case 9: hv5530_registers[6] &= 0b11111110; break; // 09: HOUR_TEN_9
	case 8: hv5530_registers[7] &= 0b01111111; break; // 08: HOUR_TEN_8
	case 7: hv5530_registers[7] &= 0b10111111; break; // 07: HOUR_TEN_7
	case 6: hv5530_registers[7] &= 0b11011111; break; // 06: HOUR_TEN_6
	case 5: hv5530_registers[7] &= 0b11101111; break; // 05: HOUR_TEN_5
	case 4: hv5530_registers[7] &= 0b11110111; break; // 04: HOUR_TEN_4
	case 3: hv5530_registers[7] &= 0b11111011; break; // 03: HOUR_TEN_3
	case 2: hv5530_registers[7] &= 0b11111101; break; // 02: HOUR_TEN_2
	case 1: hv5530_registers[7] &= 0b11111110; break; // 01: HOUR_TEN_1
	}

	hv5530_write_registers();
}

/** \brief Update Clock with Time of Day from RTC
 *
 * This function reads the time of day from the RTC and writes it to the
 * shift registers.
 */
void hv5530_set_from_rtc(void) {
	uint32_t ul_hour, ul_minute, ul_second;
	rtc_get_time(RTC, &ul_hour, &ul_minute, &ul_second);
	hv5530_set_digits(ul_hour, ul_minute, ul_second);
}

/** \brief Initialize the DMA Channel for the SPI Controller
 *
 * This function sets up the DMA channel that it will be used to asyncronously
 * load the shift registers via the SPI controller
 */
static void hv5530_init_dma(void) {
	// Global DMA Initialize
	dma_init();

	// Disable the DMA Channel
	dmac_channel_disable(DMAC, HV5530_DMA_CH);

	// Configure DMA TX channel
	uint32_t flags = 0;
	flags |= DMAC_CFG_DST_PER(HV5530_DMA_CH);
	flags |= DMAC_CFG_DST_H2SEL;
	flags |= DMAC_CFG_SOD;
	flags |= DMAC_CFG_FIFOCFG_ALAP_CFG;
	dmac_channel_set_configuration(DMAC, HV5530_DMA_CH, flags);

	// Store the DMA Transfer Parameters (for future use)
	hv5530_dmac_tx.ul_source_addr = (uint32_t)&hv5530_registers;
	hv5530_dmac_tx.ul_destination_addr = (uint32_t) &SPI->SPI_TDR;

	hv5530_dmac_tx.ul_ctrlA  = 8;
	hv5530_dmac_tx.ul_ctrlA |= DMAC_CTRLA_SRC_WIDTH_BYTE;
	hv5530_dmac_tx.ul_ctrlA |= DMAC_CTRLA_SCSIZE_CHK_1;
	hv5530_dmac_tx.ul_ctrlA |= DMAC_CTRLA_DST_WIDTH_BYTE;
	hv5530_dmac_tx.ul_ctrlA |= DMAC_CTRLA_DCSIZE_CHK_1;

	hv5530_dmac_tx.ul_ctrlB  = DMAC_CTRLB_SRC_DSCR | DMAC_CTRLB_DST_DSCR;
	hv5530_dmac_tx.ul_ctrlB |= DMAC_CTRLB_FC_MEM2PER_DMA_FC;
	hv5530_dmac_tx.ul_ctrlB |= DMAC_CTRLB_SRC_INCR_INCREMENTING;
	hv5530_dmac_tx.ul_ctrlB |= DMAC_CTRLB_DST_INCR_FIXED;

	hv5530_dmac_tx.ul_descriptor_addr = 0;

	// Register interupt handler with DMA Service for this Channel
	dma_register_interrupt_handler(HV5530_DMA_CH, hv5530_dma_interrupt);
	dmac_enable_interrupt(DMAC, (DMAC_EBCIER_CBTC0 << HV5530_DMA_CH));
}

/** \brief Initialize the SPI Controller
 *
 * This function sets up the SPI controller with the proper mode for driving
 * the hv5530 shift registers.
 */
static void hv5530_init_spi(void) {
	struct spi_device device = {
		.id = 0
	};

	// Initialize the SPI controller
	spi_disable(SPI);
	spi_master_init(SPI);
	spi_master_setup_device(SPI, &device, SPI_MODE_3, 800000, 0);
	spi_enable(SPI);
}

/** \brief Initialize the TC Module
 *
 * This function sets up the TC module for fading.
 */
static void hv5530_init_tc(void) {
	// Configure PMC
	pmc_enable_periph_clk(ID_TC0);

	// Configure TC for MCK/8
	tc_init(TC0, 0, TC_CMR_TCCLKS_TIMER_CLOCK3 | TC_CMR_WAVE);

	// start with a duty cycle of ~5%
	tc_write_rc(TC0, 0, 0x100);

	// Configure and enable interrupt on overflow and RC compare
	NVIC_DisableIRQ(TC0_IRQn);
	NVIC_ClearPendingIRQ(TC0_IRQn);
	NVIC_SetPriority(TC0_IRQn, 0x1);
	NVIC_EnableIRQ(TC0_IRQn);

	tc_enable_interrupt(TC0, 0, TC_IER_COVFS | TC_IER_CPCS);
}

/** \brief Initialize the Nixie Clock Display
 *
 * This function initializes all of the components required to drive the hv5530
 * shift registers as well as properly drive the Nixie Tubes. Once the DMA
 * Channel, SPI Controller, and Timer Counter Module are all setup. The display
 * will be initialized to a blank state and then the High-Voltage Power Supply
 * will be turned on.
 */
void hv5530_init(void) {
	// Initialize the DMA channel
	hv5530_init_dma();

	// Initialize the SPI controller
	hv5530_init_spi();

	// Write the default state
	hv5530_write_registers();

	// Initialize the Timer Counter
	hv5530_init_tc();

	// Wait for the data to be latched
	while (hv5530_state & hv5530_state_tx);

	// Start the glow sequence
	tc_start(TC0, 0);

	// Enable the HV PSU
	gpio_set_pin_high(PIO_PB0_IDX);

	// set the initialized flag
	hv5530_state |= hv5530_state_init;
}
