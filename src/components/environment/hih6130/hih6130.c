/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

/** \brief Read from the HIH6130 sensor via the TWI Bus
 *
 * \param[in] uc_reg_address Register address to read from
 * \param[in] uc_data_len The length of the command or data to be sent
 * \param[in] uc_data_ptr A pointer to the command or data to be sent
 *
 * \return TWI_SUCCESS if all bytes were written, error code otherwise.
 */
uint32_t hih6130_read_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr) {
	// Prepare the packet
	twi_package_t packet = {
		.addr = {uc_reg_address, 0x00, 0x00},
		.addr_length = 0x01,
		.buffer = uc_data_ptr,
		.length = uc_data_len,
		.chip = HIH6130_SLAVE_ADDRESS,
	};

	// Transmit the packet on wire, ignore ACK/NACK
	return twi_master_read(TWI_HIH6130, &packet);
}

void hih6130_init(void) {

}
