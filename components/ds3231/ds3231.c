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
#include "stdio.h"

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

/** \brief Initialize the DS3231 RTC
 *
 * This function initializes the DS3231 RTC by setting the Control Registers.
 * Once the chip is initialized the main CPU is instructed to use the 32kHz
 * clock provided by the DS3231 RTC.
 */
void ds3231_init(void) {
	// Write the control registers at 0x0E
	// Clear status bits in 0x0F and enable 32Khz output
	uint8_t flags[2] = {0x00, 0x08};
	if (ds3231_write_register(0x0E, 2, flags) < 0) {
		kputs("failed to write ds3231 control registers\r\n");
		kputs("not changing slow clock to external 32kHz reference.\r\n");
		return;
	}

	// Read and inform the user of the register status
	if (ds3231_read_register(0x0E, 2, flags) < 0) {
		kputs("failed to read ds3231 control registers\r\n");
		kputs("not changing slow clock to external 32kHz reference.\r\n");
		return;
	} else {
		kprintf("ds3231[0x0E:0x0F] == {0x%02X,0x%02X}\r\n", flags[0], flags[1]);
	}

	//kputs("changing slow clock to external 32kHz reference.\r\n");
	//! \TODO Set XTALSEL in Supply Controller
}