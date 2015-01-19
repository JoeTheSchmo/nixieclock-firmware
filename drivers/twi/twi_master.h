/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _DRIVERS_TWI_TWI_MASTER_H_
#define _DRIVERS_TWI_TWI_MASTER_H_

#include "types.h"

extern int32_t twi_master_write(uint8_t saddr, uint8_t iaddr, uint8_t len, uint8_t *ptr);
extern int32_t twi_master_read(uint8_t saddr, uint8_t iaddr, uint8_t len, uint8_t *ptr);

#endif // _DRIVERS_TWI_TWI_MASTER_H_