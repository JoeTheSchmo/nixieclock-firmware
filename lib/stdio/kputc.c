/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "uart.h"

/* Put Character on Console
 *
 * This function writes a single character to the UART.
 */
int kputc(const char c) {
     while (!(UART->UART_SR & UART_SR_TXRDY));
     UART->UART_THR = c;
     return 0;
}
