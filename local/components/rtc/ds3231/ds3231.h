/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef DS3231_H
#define DS3231_H

#include "twi_master.h"

/**
 * TWI Safety Definitions
 */

#if !defined(TWI_DS3231)
# warning The DS3231 TWI instance has not been defined. Using default settings.
# define TWI_DS3231 TWI0 /* TWI instance (TWI0) */
#endif
#if !defined(DS3231_SLAVE_ADDRESS)
# warning The DS3231 TWI address has not been defined. Using default settings.
# define DS3231_SLAVE_ADDRESS 0xD0 /* TWI address (0xD0) */
#endif

// Register Access
extern uint32_t ds3231_read_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr);

// Initialization Functions
extern void ds3231_init(void);

#endif // DS3231_H
