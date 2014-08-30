/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "types.h"
#include "drivers/twi/twi_master.h"
#include "ds3231.h"

//! Address of the Slave Device on the TWI Bus
#define DS3231_SLAVE_ADDRESS 0x68

/** \brief Write to the DS3231 RTC via the TWI Bus
 *
 * \param[in] addr 0x00 to 0x12
 * \param[in] len The length of the data to be sent
 * \param[in] ptr A pointer to the data to be sent
 *
 * \return 0 if all bytes were written, -1 if an error occurred.
 */
inline int32_t ds3231_write_register(uint8_t addr, uint8_t len, uint8_t *ptr) {
	return twi_master_write(DS3231_SLAVE_ADDRESS, addr, len, ptr);
}

/** \brief Read from the DS3231 RTC via the TWI Bus
 *
 * \param[in] addr 0x00 to 0x12
 * \param[in] len The length of the data to be sent
 * \param[in] ptr A pointer to the data to be sent
 *
 * \return 0 if all bytes were written, -1 if an error occurred.
 */
inline int32_t ds3231_read_register(uint8_t addr, uint8_t len, uint8_t *ptr) {
	return twi_master_read(DS3231_SLAVE_ADDRESS, addr, len, ptr);
}