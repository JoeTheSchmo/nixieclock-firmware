/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _SVCALL_H_
#define _SVCALL_H_

#include <stdint.h>

extern int32_t svcall(uint8_t code, uint32_t p1, uint32_t p2, uint32_t p3);
extern void svcall_init(void);

#endif // _SVCALL_H_
