/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _STRING_H_
#define _STRING_H_

#include "types.h"

extern char *strcat(char *d, const char *s);
extern char *strncat(char *d, const char *s, size_t n);
extern size_t strlen(const char *s);

#endif // _STRING_H_
