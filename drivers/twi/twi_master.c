/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"
#include "cpu/peripherals/twi.h"
#include "drivers/twi/twi_master.h"

/** \brief Write to the TWI bus
 *
 * \param[in] saddr Slave address on the TWI bus
 * \param[in] iaddr Internal address in the slave device
 * \param[in] len The length of the command or data to be sent
 * \param[in] ptr A pointer to the command or data to be sent
 *
 * \return 0 if all bytes were written, -1 if an error occurred.
 */
int32_t twi_master_write(uint8_t saddr, uint8_t iaddr, uint8_t len, uint8_t *ptr) {
	// Set the Master Mode Register
	TWI_MMR(TWI0) = TWI_MMR_IADRSZ(TWI_MMR_IADRSZ_1_BYTE) | TWI_MMR_DADR(saddr);
	// Set the Slave Device Internal Address
	TWI_IADR(TWI0) = TWI_IADR_IADR(iaddr);

	// Send the data
	uint32_t status;
	while (len > 0) {
		// Wait until safe to load TWI_THR
		status = TWI_SR(TWI0);

		// Check for a NACK
		if (status & TWI_SR_NACK) {
			return -1;
		}

		// Check for Empty TWI_THR
		if (!(status & TWI_SR_TXRDY)) {
			continue;
		}

		// Shift the data into the register and decrement the remaining count
		TWI_THR(TWI0) = TWI_THR_TXDATA(*ptr++);
		len--;
	}

	while (1) {
		// Get the status
		status = TWI_SR(TWI0);

		// Check for a NACK
		if (status & TWI_SR_NACK) {
			return -1;
		}

		// Check the status of the last byte
		if (status & TWI_SR_TXRDY) {
			break;
		}
	}

	// Write a STOP Command and wait for TX Complete
	TWI_CR(TWI0) = TWI_CR_STOP;
	while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

	// Success
	return 0;
}

/** \brief Read from the TWI bus
 *
 * \param[in] saddr Slave address on the TWI bus
 * \param[in] iaddr Internal address in the slave device
 * \param[in] len The length of the data to be read
 * \param[in] ptr A pointer to receive the data
 *
 * \return 0 if all bytes were written, -1 if an error occurred.
 */
int32_t twi_master_read(uint8_t saddr, uint8_t iaddr, uint8_t len, uint8_t *ptr) {
	// Set the Master Mode Register
	TWI_MMR(TWI0) = TWI_MMR_MREAD | TWI_MMR_IADRSZ(TWI_MMR_IADRSZ_1_BYTE) | TWI_MMR_DADR(saddr);
	// Set the Slave Device Internal Address
	TWI_IADR(TWI0) = TWI_IADR_IADR(iaddr);

	// Set the START condition (STOP too if len == 1)
	uint32_t stop;
	if (len == 1) {
		TWI_CR(TWI0) = TWI_CR_START | TWI_CR_STOP;
		stop = 1;
	} else {
		TWI_CR(TWI0) = TWI_CR_START;
		stop = 0;
	}

	// Read the data
	uint32_t status;
	while (len > 0) {
		// Read the TWI Status
		status = TWI_SR(TWI0);

		// Check for a NACK
		if (status & TWI_SR_NACK) {
			return -1;
		}

		// Set a STOP condition
		if ((len == 1)&&(stop == 0)) {
			TWI_CR(TWI0) = TWI_CR_STOP;
			stop = 1;
		}

		// Check if the holding register is filled
		if (!(status & TWI_SR_RXRDY)) {
			continue;
		}

		// Read the data
		*ptr++ = TWI_RHR(TWI0);
		len--;
	}

	// Wait for STOP
	while (!(TWI_SR(TWI0) & TWI_SR_TXCOMP));

	// Success
	return 0;
}