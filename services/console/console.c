/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2014 Joe Ciccone. All rights reserved.
 *
 */

#include "board/pins.h"
#include "console.h"
#include "ctype.h"
#include "cpu/peripherals/eefc.h"
#include "cpu/peripherals/pio.h"
#include "cpu/peripherals/rstc.h"
#include "cpu/peripherals/supc.h"
#include "cpu/peripherals/uart.h"
#include "services/clock/clock.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/** Console Service Initialization
 *
 * Initialize the UART for use with the \ref kgetc and \ref kputc functions.
 */
void console_init(void) {
	// Reset and disable the UART
	UART_CR = UART_CR_RSTRX | UART_CR_RSTTX | UART_CR_RXDIS | UART_CR_TXDIS;
	// Set the BAUD rate to 115200bps (96MHz / (16 * 52) = 115385)
	UART_BRGR = UART_BRGR_CD(52);
	// Set no Parity and normal mode
	UART_MR = UART_MR_PAR(UART_MR_PAR_NO) | UART_MR_CHMODE(0);
	// Enable the UART
	UART_CR = UART_CR_RXEN | UART_CR_TXEN;
}

/** Console Shell Interface
 *
 * This function blocks providing an interactive shell for the user.
 */
void console_shell(void) {
	kputs("starting shell...\r\n");

	char buffer[64];
	int32_t cmd_len = 0;
	buffer[0] = '\0';

	char c;
	while (1) {
		if (cmd_len == 0) {
			// Print a prompt
			kputs("# ");
		}

		// Echo back the serial console
		if (0 == kgetc(&c)) {
			if (isprint(c)) {
				// Append the character to the buffer
				buffer[cmd_len++] = c;
				buffer[cmd_len] = '\0';
				// Echo back the character to the user
				kputc(c);

				// Check if we're at the end of the buffer
				if (cmd_len == 64) {
					// Notify the user
					kputs("\r\nCLI Buffer Overflow, Try Again.\r\n");

					// Reset the command buffer
					cmd_len = 0;
					buffer[0] = '\0';
				}
			} else {
				// Process control characters
				switch (c) {
				case '\r':
					// Acknowledge the carriage return
					kputs("\r\n");

					// Process the command
					if (*buffer == '\0') {
						// Do nothing, empty line
					} else if (strcmp(buffer, "reset") == 0) {
						// Reset the CPU
						RSTC_CR = RSTC_CR_PROCRST | RSTC_CR_PERRST | RSTC_CR_KEY;
					} else if (strcmp(buffer, "reset samba") == 0) {
						// Disable Interrupts, We're about to change vector tables
						asm volatile("cpsid f");
						asm volatile("dmb");

						// Wait for EEFC0 to be ready for a command
						while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));
						// Clear the GPNVM boot mode bit
						EEFC_FCR(EEFC0) = EEFC_FCR_FKEY | EEFC_FCR_FCMD(EEFC_FCR_FCMD_CGPB) | EEFC_FCR_FARG(1);
						asm volatile("dsb");
						while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));

						// Check for an error
						if (EEFC_FSR(EEFC0) & EEFC_FSR_FCMDE) {
							kputs("flash command error, unable to clear boot mode bit\r\n");
						}

						// Reset the CPU into SAM-BA
						RSTC_CR = RSTC_CR_EXTRST | RSTC_CR_KEY;
					} else if (strcmp(buffer, "clk32") == 0) {
						// Switch to the external 32kHz clock
						kputs("changing slow clock to external 32kHz reference.\r\n");
						SUPC_MR |= SUPC_MR_KEY | SUPC_MR_OSCBYPASS;
						SUPC_CR = SUPC_CR_KEY | SUPC_CR_XTALSEL;
					} else if (strcmp(buffer, "hvoff") == 0) {
						// Turn off the high voltage power supply
						PIO_CODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);
					} else if (strcmp(buffer, "hvon") == 0) {
						// Turn on the high voltage power supply
						PIO_SODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);
					} else if (strncmp(buffer, "peek ", 5) == 0) {
						// peek at a memory address
						uint32_t *addr = (uint32_t *)strtoul(buffer + 5, 0, 0);
						kprintf("(*(uint32_t*)(0x%08lX)) == 0x%08lX\r\n", (uint32_t)addr, *addr);
					} else if (strncmp(buffer, "poke ", 5) == 0) {
						// poke into a memory address
						const char *p = buffer + 5;
						uint32_t *addr = (uint32_t *)strtoul(p, &p, 0);
						if (*p++ != ' ') {
							break;
						}
						uint32_t value = strtoul(p, &p, 0);
						kprintf("(*(uint32_t*)(0x%08lX)) = 0x%08lX\r\n", (uint32_t)addr, value);
						*addr = value;
					} else if (strncmp(buffer, "clock set ", 10) == 0) {
						const char *p = buffer + 10;
						timespec_t t;

						// Parse the date from the CLI
						uint32_t year = strtoul(p, &p, 10);
						t.cent = year / 100;
						t.year = year % 100;
						if (*p++ != '/') {
							break;
						}
						t.month = strtoul(p, &p, 10);
						if (*p++ != '/') {
							break;
						}
						t.date = strtoul(p, &p, 10);
						if (*p++ != ' ') {
							break;
						}

						// Parse the day of week
						t.day = strtoul(p, &p, 10);
						if (*p++ != ' ') {
							break;
						};

						// Parse the time from the CLI
						t.hour = strtoul(p, &p, 10);
						if (*p++ != ':') {
							break;
						}
						t.minute = strtoul(p, &p, 10);
						if (*p++ != ':') {
							break;
						}
						t.second = strtoul(p, &p, 10);

						// Tell the Clock Service the new Date and Time
						if (clock_set(&t) < 0) {
							kputs("Failed to set the new time.\r\n");
						}
					} else {
						kputs("Invalid Command\r\n");
					}
					break;
				}

				if (c == '\r') {
					// Clear the Buffer
					cmd_len = 0;
					buffer[0] = '\0';
				}
			}
		}
	}	
}