/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_

#include "types.h"

extern char *ltostr(int32_t value, char *str, int8_t base);
extern uint32_t strtoul(const char *nptr, const char **endptr, int8_t base);
extern char *ultostr(uint32_t value, char *str, int8_t base);

#endif // _STDLIB_H_
