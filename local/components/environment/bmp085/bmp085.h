/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef BMP085_H
#define BMP085_H

#include "twi_master.h"

/**
 * TWI Safety Definitions
 */

#if !defined(TWI_BMP085)
# warning The BMP085 TWI instance has not been defined. Using default settings.
# define TWI_BMP085 TWI0 /* TWI instance (TWI0) */
#endif
#if !defined(BMP085_SLAVE_ADDRESS)
# warning The BMP085 TWI address has not been defined. Using default settings.
# define BMP085_SLAVE_ADDRESS 0xEE /* TWI address (0xEE) */
#endif

// Register Access
extern uint32_t bmp085_read_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr);

// Initialization Functions
extern void bmp085_init(void);

#endif // BMP085_H
