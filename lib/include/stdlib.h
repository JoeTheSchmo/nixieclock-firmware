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

#include <stdint.h>

extern char *ltostr(long value, char *str, int base);
extern uint32_t strtoul(const char *nptr, const char **endptr, int base);
extern char *ultostr(unsigned long value, char *str, int base);

#endif // _STDLIB_H_
