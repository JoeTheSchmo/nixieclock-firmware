/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef _CLOCK_H_
#define _CLOCK_H_

extern volatile uint8_t clock_cal_cent;
extern volatile uint8_t clock_cal_year;
extern volatile uint8_t clock_cal_month;
extern volatile uint8_t clock_cal_date;

extern volatile uint8_t clock_time_hour;
extern volatile uint8_t clock_time_minute;
extern volatile uint8_t clock_time_second;

extern int32_t clock_set_time(uint8_t hour, uint8_t minute, uint8_t second);
extern int32_t clock_set_date(uint8_t cent, uint8_t year, uint8_t month, uint8_t day, uint8_t date);

extern void clock_init(void);

#endif // _CLOCK_H_