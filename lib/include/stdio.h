/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _STDIO_H_
#define _STDIO_H_

extern int kgetc(char *c);
extern int kputc(const char c);
extern int kputs(const char *s);
extern int kputd(int d);
extern void kprintf(const char *format, ...) __attribute__ ((format (printf, 1, 2)));

#endif // _STDIO_H_
