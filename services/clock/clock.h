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

typedef struct _timespec_t {
	uint8_t cent;
	uint8_t year;
	uint8_t month;
	uint8_t date;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} timespec_t;

extern volatile timespec_t clock;

extern int32_t clock_set(timespec_t *time);
extern void clock_init(void);

#endif // _CLOCK_H_