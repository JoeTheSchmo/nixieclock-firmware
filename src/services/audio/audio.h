/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 Joe Ciccone. All rights reserved.
 *
 */

#ifndef AUDIO_H
#define AUDIO_H

extern void audio_dma_interrupt(uint32_t status);
extern void audio_init(void);

#endif // AUDIO_H
