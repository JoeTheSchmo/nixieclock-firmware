/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 */

#ifndef HV5530_H
#define HV5530_H

extern void hv5530_init(void);
extern void hv5530_set_registers(uint8_t *data);
extern void hv5530_set_from_rtc(void);

#endif // HV5530_H
