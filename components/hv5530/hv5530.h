/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _HV5530_H_
#define _HV5530_H_

#include "types.h"

extern void hv5530_write_registers(void);
extern void hv5530_set_digits(uint32_t ul_hour, uint32_t ul_minute, uint32_t ul_second);
extern void hv5530_init(void);

#endif // _HV5530_H_
