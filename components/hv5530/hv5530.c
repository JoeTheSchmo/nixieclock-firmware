/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "board/pins.h"
#include "cpu/cortex-m3/nvic.h"
#include "cpu/peripherals/pio.h"
#include "cpu/peripherals/rtc.h"
#include "cpu/peripherals/spi.h"
#include "cpu/peripherals/tc.h"
#include "hv5530.h"
#include "types.h"

//! Local copy of the registers to be sent through the SPI Controller
volatile uint8_t hv5530_registers[8] = {
	0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0xFF, 0xFF
};
volatile uint8_t hv5530_tx_pos = 8;

//! Enumeration describing the state of the hv5530 driver
volatile enum {
        hv5530_state_init = 1,  //!< If flag is set, the driver has been initialized
        hv5530_state_tx = 2,    //!< If flag is set, TX is in progress
        hv5530_state_glow = 3   //!< If flag is set, brightness is intensifying
} hv5530_state = 0;

/** \brief Interrupt Handler for TC0
 *
 * This function handles interrupts from the TC0 Module. Currently it receives
 * a counter overflow and match on counter C. When the overflow status is
 * received, the blank line is driven low, turning on the display. The RC
 * register is set determine the overall duty cycle for the display. Varying
 * slightly at every overflow to form a glowing effect. When the match on
 * counter C is encountered, the blanking line is driven high turning the
 * display off until the next overflow occurs.
 */
void tc0_handler() {
	uint32_t status = TC_SR(TC0);

	if (status & TC_SR_COVFS) {
		// Clock Overflow, Turn On The Display
		PIO_CODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX);

		// Read the RC Register
		uint32_t rc;
		rc = TC_RC(TC0);

		// Determine if we need to change fading in / fading out
		if (rc > 0xB000) {
			hv5530_state &= ~hv5530_state_glow;
		} else if (rc < 0x5000) {
			hv5530_state |= hv5530_state_glow;
		}

		// Calculate the new duty cycle
		if (hv5530_state & hv5530_state_glow) {
			rc += 0x200;
		} else {
			rc -= 0x200;
		}

		// Write the RC register
		TC_RC(TC0) = rc;
	} else if (status & TC_SR_CPCS) {
		// RC Match, Blank the Display
		PIO_SODR(PIN_HV5530_BLANK_PIO) = (1 << PIN_HV5530_BLANK_IDX);
	}
}

/** \brief Interrupt Handler for SPI
 *
 * This function shifts the next byte into the transmit data register of the
 * SPI controller and latches the display once all 64bits have been loaded
 * into the HV5530 shift registers.
 */
void spi_handler() {

	if (SPI_SR & SPI_SR_TDRE) {
		if (hv5530_tx_pos < 8) {
			// Place the next byte in the Transmit Data Register
			SPI_TDR = SPI_TDR_TD(hv5530_registers[hv5530_tx_pos++]);
		} else {
			// Disable the Transmit Data Empty Interrupt
			SPI_IDR = SPI_IDR_TDRE;
		}
	}

	if (SPI_SR & SPI_SR_TXEMPTY) {
		// Latch the Shift Registers (Part 1)
		PIO_CODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX);

		// Disable the Transmit Empty Interrupt
		SPI_IDR = SPI_IDR_TXEMPTY;

        // Clear the TX Flag
        hv5530_state &= ~hv5530_state_tx;

		// Delay
		uint32_t i;
		for (i = 0; i < 0xA; i++);

		// Latch the Shift Registers (Part 2)
		PIO_SODR(PIN_HV5530_LATCH_PIO) = (1 << PIN_HV5530_LATCH_IDX);
	}
}

/** \brief Begin Transmission of Data
 *
 * This function starts the data transfer using the SPI peripheral in order
 * to load the shift registers with 64bits of data stored in memory.
 */
void hv5530_write_registers(void) {
	// Set the TX Flag
	hv5530_state |= hv5530_state_tx;

	// Set the position of the next byte to transfer
	hv5530_tx_pos = 0;

	// Enable the TDRE and TXEMPTY Interrupts
	SPI_IER = SPI_IER_TDRE | SPI_IER_TXEMPTY;
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
	uint32_t i;
	for (i = 0; i < 8; i++) {
		hv5530_registers[i] = 0xFF;
	}

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

/** \brief Initialize the Nixie Clock Display
 *
 * This function initializes all of the components required to drive the hv5530
 * shift registers as well as properly drive the Nixie Tubes. Once the SPI
 * Controller and Timer Counter Module are setup. The display will be
 * initialized to a blank state and then the High-Voltage Power Supply
 * will be turned on.
 */
void hv5530_init(void) {
	// Disable SPI
	SPI_CR = SPI_CR_SPIDIS;
    // Reset the controller
	SPI_CR = SPI_CR_SWRST;
	// Set master mode and disable mode fault detection
	SPI_MR |= SPI_MR_MSTR | SPI_MR_MODFDIS;
	// Set SPI Mode 3 with clock divisor of 64
	SPI_CSR0 = SPI_CSR_CPOL | SPI_CSR_SCBR(64);
	// Enable the SPI controller
	SPI_CR = SPI_CR_SPIEN;
	// Enable the SPI Interrupt in the NVIC
	ICER0 = (1 << PMC_ID_SPI); // Disable Interrupt
	ICPR0 = (1 << PMC_ID_SPI); // Clear Pending
	IPR5  = (IPR5 & 0xFFFFFF00) | (0x00 << 0); // Set the Priority to 0
	ISER0 = (1 << PMC_ID_SPI); // Enable Interrupt

	// Disable TC0 Clock
	TC_CCR(TC0) = TC_CCR_CLKDIS;
	// Configure TC0 for MCK/8 and Waveform Mode
	TC_CMR(TC0) = TC_CMR_WM_TCCLKS_TIMER_CLOCK3 | TC_CMR_WM_WAVE;
	// Start with a Duty Cycle of ~5%
	TC_RC(TC0) = 0x100;
	// Enable the TC0 Interrupt in the NVIC
	ICER0 = (1 << PMC_ID_TC0); // Disable Interrupt
	ICPR0 = (1 << PMC_ID_TC0); // Clear Pending
	IPR5  = (IPR5 & 0xFF00FFFF) | (0x10 << 16); // Set the Priority to 1
	ISER0 = (1 << PMC_ID_TC0); // Enable Interrupt
	// Enable Interrupts for TC0
	TC_IER(TC0) = TC_IER_COVFS | TC_IER_CPCS;
	// Enable TC0 Clock and Start Counters
	TC_CCR(TC0) = TC_CCR_CLKEN | TC_CCR_SWTRG;

	// Enable the HV PSU
	PIO_SODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);

	// Set the Initialized Flag
	hv5530_state |= hv5530_state_init;

	// Write the initial state of the display
	hv5530_write_registers();
}
