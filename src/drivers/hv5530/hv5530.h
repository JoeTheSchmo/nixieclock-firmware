/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef HV5530_H
#define HV5530_H

#include <conf_hv5530.h>

extern void hv5530_dma_interrupt(uint32_t status);
extern void hv5530_write_registers(void);
extern void hv5530_set_digits(uint32_t ul_hour, uint32_t ul_minute, uint32_t ul_second);
extern void hv5530_set_from_rtc(void);
extern void hv5530_init(void);

#endif // HV5530_H
