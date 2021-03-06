//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2015 Joe Ciccone
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __STRING_H_
#define __STRING_H_

#include <types.h>

extern void *memcpy(void *d, void *s, size_t n);
extern void *memset(void *s, int c, size_t n);
extern char *strcat(char *d, const char *s);
extern char *strchr(const char *s, char c);
extern char *strchrnul(const char *s, char c);
extern int32_t strcmp(const char *s1, const char *s2);
extern size_t strlen(const char *s);
extern char *strncat(char *d, const char *s, size_t n);
extern int32_t strncmp(const char *s1, const char *s2, size_t n);
extern char *strrchr(const char *s, char c);

#endif // __STRING_H_
