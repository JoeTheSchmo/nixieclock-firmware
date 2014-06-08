/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include <asf.h>

enum {
	dma_state_init = 1
} dma_state = 0;

void (*dma_handlers[DMACCH_NUM_NUMBER])(uint32_t);
void DMAC_Handler(void) {
	static uint32_t status, i;

	// Read the DMAC Status Register
	status = dmac_get_status(DMAC);

	// Check which interupts have fired
	for (i = 0; i < DMACCH_NUM_NUMBER; i++) {
		if ((status & ((DMAC_EBCIER_BTC0 | DMAC_EBCIER_CBTC0 | DMAC_EBCIER_ERR0) << i))) {
			if (dma_handlers[i]) {
				dma_handlers[i](status);
			}
		}
	}
}

void dma_register_interrupt_handler(uint32_t channel, void (*handler)(uint32_t)) {
	if (channel < DMACCH_NUM_NUMBER) {
		// Enable the Interrupt
		NVIC_ClearPendingIRQ(DMAC_IRQn);
		NVIC_SetPriority(DMAC_IRQn, 0x0);
		NVIC_EnableIRQ(DMAC_IRQn);

		// Store the pointer for the handler in the table
		dma_handlers[channel] = handler;
	}
}

void dma_init(void) {
	if (dma_state & dma_state_init) {
		return;
	}

	// Enable DMA controller
	dmac_enable(DMAC);

	// Initialize and enable DMA controller
	pmc_enable_periph_clk(ID_DMAC);
	dmac_init(DMAC);
	dmac_set_priority_mode(DMAC, DMAC_PRIORITY_ROUND_ROBIN);
	dmac_enable(DMAC);

	// Only enable the IRQ if required
	NVIC_DisableIRQ(DMAC_IRQn);

	dma_state |= dma_state_init;
}
