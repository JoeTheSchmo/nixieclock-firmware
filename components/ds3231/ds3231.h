/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _DS3231_H_
#define _DS3231_H_

#include "types.h"

/**
 * Function Prototypes
 */

// Communication Functions
extern inline int32_t ds3231_write_register(uint8_t addr, uint8_t len, uint8_t *ptr);
extern inline int32_t ds3231_read_register(uint8_t addr, uint8_t len, uint8_t *ptr);

// Initialization Functions
extern void ds3231_init(void);

#endif // _DS3231_H_