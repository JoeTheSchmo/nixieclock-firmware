/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <stdint.h>

typedef struct _timespec_t {
	uint32_t year;
	uint32_t month;
	uint32_t date;
	uint32_t day;
	uint32_t hour;
	uint32_t minute;
	uint32_t second;
} timespec_t;

extern timespec_t clock;

extern int32_t clock_set(timespec_t *time);
extern void clock_force_resync(void);
extern void clock_init(void);

#endif // _CLOCK_H_
