/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <stdint.h>

#include "board.h"
#include "compiler.h"
#include "hv5530.h"
#include "ioport.h"
#include "spi.h"
#include "tc.h"

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
        hv5530_state_glow = 4   //!< If flag is set, brightness is intensifying
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
void TC0_Handler() {
	uint32_t status = tc_get_status(TC0, 0);

	if (status & TC_SR_COVFS) {
		// Clock Overflow, Turn On The Display
		ioport_set_pin_level(PIN_HV5530_BLANK, IOPORT_PIN_LEVEL_LOW);

		// Read the RC Register
		uint32_t rc;
		rc = tc_read_rc(TC0, 0);

		// Determine if we need to change fading in / fading out
		if (rc > 0xB000) {
			hv5530_state &= ~hv5530_state_glow;
		} else if (rc < 0x8000) {
			hv5530_state |= hv5530_state_glow;
		}

		// Calculate the new duty cycle
		if (hv5530_state & hv5530_state_glow) {
			rc += 0x40;
		} else {
			rc -= 0x40;
		}

		// Set the next duty cycle
		tc_write_rc(TC0, 0, rc);
	} else if (status & TC_SR_CPCS) {
		// RC Match, Blank the Display
		ioport_set_pin_level(PIN_HV5530_BLANK, IOPORT_PIN_LEVEL_HIGH);
	}
}

/** \brief Interrupt Handler for SPI
 *
 * This function shifts the next byte into the transmit data register of the
 * SPI controller and latches the display once all 64bits have been loaded
 * into the HV5530 shift registers.
 */
void SPI_Handler() {

	if (spi_is_tx_ready(SPI)) {
		if (hv5530_tx_pos < 8) {
			// Place the next byte in the Transmit Data Register
			spi_put(SPI, hv5530_registers[hv5530_tx_pos++]);
		} else {
			// Disable the Transmit Data Empty Interrupt
			spi_disable_interrupt(SPI, SPI_IDR_TDRE);
		}
	}

	if (spi_is_tx_empty(SPI)) {
		// Latch the Shift Registers (Part 1)
		ioport_set_pin_level(PIN_HV5530_LATCH, IOPORT_PIN_LEVEL_LOW);

		// Disable the Transmit Empty Interrupt
		spi_disable_interrupt(SPI, SPI_IDR_TXEMPTY);

		// Clear the TX Flag
		hv5530_state &= ~hv5530_state_tx;

		// Delay
		uint32_t i;
		for (i = 0; i < 0xA; i++);

		// Latch the Shift Registers (Part 2)
		ioport_set_pin_level(PIN_HV5530_LATCH, IOPORT_PIN_LEVEL_HIGH);
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
	spi_enable_interrupt(SPI, SPI_IER_TDRE | SPI_IER_TXEMPTY);
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

	// Do not light the colons
	//hv5530_registers[2] &= 0b11110111; // 44: RCOL_TOP
	//hv5530_registers[2] &= 0b11111011; // 43: RCOL_BOT

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

	// Do not light the colons
	//hv5530_registers[6] &= 0b11110111; // 12: LCOL_TOP
	//hv5530_registers[6] &= 0b11111011; // 11: LCOL_BOT

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
	// Setup the SPI Controller
	spi_enable_clock(SPI);
	spi_reset(SPI);
	spi_set_master_mode(SPI);
	spi_disable_mode_fault_detect(SPI);
	spi_disable_loopback(SPI);
	spi_set_peripheral_chip_select_value(SPI, spi_get_pcs(0));
	spi_set_fixed_peripheral_select(SPI);
	spi_disable_peripheral_select_decode(SPI);
	spi_set_delay_between_chip_select(SPI, 0);
	spi_set_transfer_delay(SPI, 0, 0, 0);
	spi_set_bits_per_transfer(SPI, 0, 8);
	spi_set_baudrate_div(SPI, 0, 32);
	spi_configure_cs_behavior(SPI, 0, SPI_CS_KEEP_LOW);
	spi_set_clock_polarity(SPI, 0, 1);
	spi_set_clock_phase(SPI, 0, 0);
	spi_enable(SPI);
	// Enable SPI Interrupt (Priority 0)
	irq_register_handler(ID_SPI, 0);

	// Enable Peripheral Clock for TC0-0
	sysclk_enable_peripheral_clock(ID_TC0);
	// Setup TC0-0
	tc_init(TC0, 0, TC_CMR_TCCLKS_TIMER_CLOCK2 | TC_CMR_WAVE);
	// Start with a Duty Cycle of ~5%
	tc_write_rc(TC0, 0, 0x100);
	// Enable TC0 Interrupt (Priority 1)
	irq_register_handler(ID_TC0, 1);
	// Enable Interrupts for TC0
	tc_enable_interrupt(TC0, 0, TC_IER_COVFS | TC_IER_CPCS);
	// Start TC0-0
	tc_start(TC0, 0);

	// Enable the HV PSU
	ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_HIGH);

	// Set the Initialized Flag
	hv5530_state |= hv5530_state_init;

	// Write the initial state of the display
	hv5530_write_registers();
}
