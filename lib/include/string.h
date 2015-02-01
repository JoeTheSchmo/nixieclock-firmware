/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>

extern void *memset(void *s, int c, size_t n);
extern char *strcat(char *d, const char *s);
extern char *strchr(const char *s, char c);
extern char *strchrnul(const char *s, char c);
extern int strcmp(const char *s1, const char *s2);
extern size_t strlen(const char *s);
extern char *strncat(char *d, const char *s, size_t n);
extern int strncmp(const char *s1, const char *s2, size_t n);
extern char *strrchr(const char *s, char c);

#endif // _STRING_H_
