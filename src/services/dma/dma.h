/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#ifndef DMA_H
#define DMA_H

extern void dma_register_interrupt_handler(uint32_t channel, void (*handler)(uint32_t));
extern void dma_init(void);

#endif // DMA_H
