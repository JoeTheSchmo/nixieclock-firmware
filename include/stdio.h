// vim: set tabstop=4 shiftwidth=4 expandtab :
//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2015 Joe Ciccone
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

#ifndef __STDIO_H_
#define __STDIO_H_

#include <types.h>

extern ssize_t kgetc(char *c);
extern ssize_t kputc(const char c);
extern ssize_t kputs(const char *s);
extern void vxprintf(
  ssize_t (*putc)(const char),
  ssize_t (*puts)(const char *),
  const char *format,
  __builtin_va_list args);
extern void kprintf(const char *format, ...)
  __attribute__ ((format (printf, 1, 2)));

#endif // __STDIO_H_
