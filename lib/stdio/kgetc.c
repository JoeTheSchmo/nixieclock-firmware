/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "cpu/peripherals/uart.h"

/* Get Character from Console
 *
 * This function gets a single character from the UART.
 */
int kgetc(char *c) {
	while (!(UART_SR & UART_SR_RXRDY));
	*c = UART_RHR;
	return 0;
}