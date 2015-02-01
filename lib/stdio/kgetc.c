/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "uart.h"

/* Get Character from Console
 *
 * This function gets a single character from the UART.
 */
int kgetc(char *c) {
     while (!(UART->UART_SR & UART_SR_RXRDY));
     *c = UART->UART_RHR;
     return 0;
}
