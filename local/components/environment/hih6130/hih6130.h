/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef HIH6130_H
#define HIH6130_H

#include "twi_master.h"

/**
 * TWI Safety Definitions
 */

#if !defined(TWI_HIH6130)
# warning The HIH6130 TWI instance has not been defined. Using default settings.
# define TWI_HIH6130 TWI0 /* TWI instance (TWI0) */
#endif
#if !defined(HIH6130_SLAVE_ADDRESS)
# warning The HIH6130 TWI address has not been defined. Using default settings.
# define HIH6130_SLAVE_ADDRESS 0x42 /* TWI address (0x42) */
#endif

// Register Access
extern uint32_t hih6130_read_register(uint8_t uc_reg_address, uint8_t uc_data_len, uint8_t *uc_data_ptr);

// Initialization Functions
extern void hih6130_init(void);

#endif // HIH6130_H
