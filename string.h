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
extern int32_t strcmp(const char *s1, const char *s2);
extern size_t strlen(const char *s);
extern char *strncat(char *d, const char *s, size_t n);
extern int32_t strncmp(const char *s1, const char *s2, size_t n);

#endif // _STRING_H_
