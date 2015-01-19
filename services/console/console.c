/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include "board/pins.h"
#include "console.h"
#include "ctype.h"
#include "components/ds3231/ds3231.h"
#include "cpu/cortex-m3/nvic.h"
#include "cpu/peripherals/eefc.h"
#include "cpu/peripherals/pio.h"
#include "cpu/peripherals/rstc.h"
#include "cpu/peripherals/supc.h"
#include "cpu/peripherals/uart.h"
#include "services/clock/clock.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/** Console Clock Set Command
 *
 * This function provides the guts of the clock set command. It was separated
 * out for ease of error parsing in the \ref console_invoke_clock function with
 * regards to this subcommand.
 */
int8_t console_invoke_clock_set(int8_t argc, char *argv[]) {
	timespec_t newtime;
	const char *p;

	// extract the year, month, date
	p = argv[2];
	uint32_t year = strtoul(p, &p, 10);
	newtime.cent = year / 100;
	newtime.year = year % 100;
	if ((*p++ != '/')&&(*p++ != '-')) {
		return -1;
	}
	newtime.month = strtoul(p, &p, 10);
	if ((*p++ != '/')&&(*p++ != '-')) {
		return -1;
	}
	newtime.date = strtoul(p, &p, 10);
	if (*p != '\0') {
		return -1;
	}

	// extract the day
	p = argv[3];
	newtime.day = strtoul(p, &p, 10);
	if (*p != '\0') {
		return -1;
	}

	// extract the hour, minutes, and seconds
	p = argv[4];
	newtime.hour = strtoul(p, &p, 10);
	if (*p++ != ':') {
		return -1;
	}
	newtime.minute = strtoul(p, &p, 10);
	if (*p++ != ':') {
		return -1;
	}
	newtime.second = strtoul(p, &p, 10);
	if (*p != '\0') {
		return -1;
	}

	// Tell the Clock Service the new Date and Time
	if (clock_set(&newtime) < 0) {
		kputs("Failed to set the new time.\r\n");
	}

	return 0;
}

/* Console Clock Command
 *
 * This function provides the ability to check the sanity of the clock and
 * set a new date/time.
 */
void console_invoke_clock(int8_t argc, char *argv[]) {
	if (argc == 2) {
		if (strcmp(argv[1], "help") == 0) {
			// print the help messages
			kputs("clock help\t\tPrint this message\r\n");
			kputs("clock resync\t\tForce a resync of the internal RTC\r\n");
			kputs("clock set YYYY/MM/DD W HH:MM:SS\tSets the time of day\r\n");
			kputs("\tWhere YYYY = 4 digit year\r\n");
			kputs("\tWhere MM = 2 digit month of year\r\n");
			kputs("\tWhere DD = 2 digit day of month\r\n");
			kputs("\tWhere W = 1 digit day of week (starting from Sunday)\r\n");
			kputs("\tWhere HH = 2 digit hour\r\n");
			kputs("\tWhere MM = 2 digit minutes\r\n");
			kputs("\tWhere SS = 2 digit seconds\r\n");
			kputs("clock show\t\tPrint the current time of the internal and external RTC\r\n");
		} else if (strcmp(argv[1], "resync") == 0) {
			// clear the sync flag in the clock service
			kputs("forcing a resync of the clock with the external rtc\r\n");
			clock_force_resync();
		} else if (strcmp(argv[1], "show") == 0) {
			// Read the time and date from the external ds3231
			uint8_t ds3231[7];
			if (ds3231_read_register(0x00, 7, ds3231) < 0) {
				kputs("ds3231: failed to read date and time registers\r\n");
			} else {
				// print the internal time
				kputs("Internal Time:");
				kprintf(" %02d%02d/%02d/%02d", clock.cent, clock.year, clock.month, clock.date);
				kprintf(" %d", clock.day);
				kprintf(" %02d:%02d:%02d\r\n", clock.hour, clock.minute, clock.second);

				// print the external time
				kputs("External Time:");
				kprintf(" %02d%02x/%02x/%02x", ((ds3231[5] & 0x80) >> 7) + 19, ds3231[6], ds3231[5] & 0x1F, ds3231[4] & 0x3F);
				kprintf(" %d", ds3231[3] & 0x07);
				if (ds3231[2] & 0x40) {
					// 12 hour mode
					kprintf(" %02x:%02x:%02x\r\n", ds3231[2] & 0x1F, ds3231[1] & 0x7F, ds3231[0] & 0x7F);

				} else {
					// 24 hour mode
					kprintf(" %02x:%02x:%02x\r\n", ds3231[2] & 0x3F, ds3231[1] & 0x7F, ds3231[0] & 0x7F);
				}
			}
		} else {
			kputs("invalid arguments specified\r\n");
		}
	} else if (argc == 5) {
		if (strcmp(argv[1], "set") == 0) {
			if (console_invoke_clock_set(argc, argv) < 0) {
				kputs("bad time provided");
			}
		} else {
			kputs("invalid arguments specified\r\n");
		}
	} else {
		kputs("invalid arguments specified\r\n");
	}
}


/** Console Peek Command
 *
 * This function provides the ability to write values in memory over the serial
 * console without requiring a debugger.
 */
void console_invoke_peek(int8_t argc, char *argv[]) {
	if (argc == 2) {
		if (strcmp(argv[1], "help") == 0) {
			kputs("peek help\t\tPrint this message\r\n");
			kputs("peek 0xBEEF\t\tPrint the 32bit value at the address 0xBEEF\r\n");
		} else {
			// peek at a memory address
			uint32_t *addr = (uint32_t *)strtoul(argv[1], 0, 0);
			kprintf("(*(uint32_t*)(0x%08lX)) == 0x%08lX\r\n", (uint32_t)addr, *addr);
		}
	} else {
		kputs("invalid arguments specified\r\n");
	}
}

/** Console Poke Command
 *
 * This function provides the ability to read values in memory over the serial
 * console without requiring a debugger.
 */
void console_invoke_poke(int8_t argc, char *argv[]) {
	if (argc == 2) {
		if (strcmp(argv[1], "help") == 0) {
			kputs("poke help\t\tPrint this message\r\n");
			kputs("poke 0xBEEF 0xDEAD\tWrite the value 0xDEAD into the address 0xBEEF\r\n");
		} else {
			kputs("invalid arguments specified\r\n");
		}
	} else if (argc == 3) {
			// poke into a memory address
			uint32_t *addr = (uint32_t *)strtoul(argv[1], 0, 0);
			uint32_t value = strtoul(argv[2], 0, 0);
			kprintf("(*(uint32_t*)(0x%08lX)) = 0x%08lX\r\n", (uint32_t)addr, value);
			*addr = value;
	} else {
		kputs("invalid arguments specified\r\n");
	}
}

/** Console PSU Command
 *
 * This command provides the ability to turn the 5v or high voltage power supply
 * on or off at runtime.
 */
void console_invoke_psu(int8_t argc, char *argv[]) {
	if (argc == 1) {
		kputs("you must specify an argument with psu\r\n");
	} else if (argc == 2) {
		if (strcmp(argv[1], "help") == 0) {
			kputs("psu help\t\tPrint this message\r\n");
			kputs("psu {name} on\t\tTurn on the requested power supply\r\n");
			kputs("psu {name} off\t\tTurn off the requested power supply\r\n");
			kputs("psu {name} off\t\tShow the power supplies status\r\n");
			kputs("\twhere {name} = 5v or hv\r\n");
			kputs("\twhere {cmd} = on or off or show\r\n");
		} else {
			kputs("invalid arguments specified\r\n");
		}
	} else if (argc == 3) {
		if (strcmp(argv[1], "5v") == 0) {
			if (strcmp(argv[2], "on") == 0) {
				// Turn on the 5v power supply (low enable = on)
				PIO_CODR(PIN_5VPSU_EN_PIO) = (1 << PIN_5VPSU_EN_IDX);
			} else if (strcmp(argv[2], "off") == 0) {
				// Turn off the 5v power supply (high enable = off)
				PIO_SODR(PIN_5VPSU_EN_PIO) = (1 << PIN_5VPSU_EN_IDX);
			} else if (strcmp(argv[2], "show") == 0) {
				if (!(PIO_PDSR(PIN_5VPSU_EN_PIO) & (1 << PIN_5VPSU_EN_IDX))) {
					if (PIO_PDSR(PIN_5VPSU_PG_PIO) & (1 << PIN_5VPSU_PG_IDX)) {
						kputs("5v psu is on, power is good\r\n");
					} else {
						kputs("5v psu is on, power is bad\r\n");
					}
				} else {
					if (PIO_PDSR(PIN_5VPSU_PG_PIO) & (1 << PIN_5VPSU_PG_IDX)) {
						kputs("5v psu is off, power is good (unexpected)\r\n");
					} else {
						kputs("5v psu is off, power is bad (expected)\r\n");
					}

				}
			} else {
				kputs("unrecognised psu command\r\n");
			}
		} else if (strcmp(argv[1], "hv") == 0) {
			if (strcmp(argv[2], "on") == 0) {
				// Turn on the high voltage power supply
				PIO_SODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);
			} else if (strcmp(argv[2], "off") == 0) {
				// Turn off the high voltage power supply
				PIO_CODR(PIN_HV5530_HVEN_PIO) = (1 << PIN_HV5530_HVEN_IDX);
			} else if (strcmp(argv[2], "show") == 0) {
				if (PIO_PDSR(PIN_HV5530_HVEN_PIO) & (1 << PIN_HV5530_HVEN_IDX)) {
					kputs("hv psu is on\r\n");
				} else {
					kputs("hv psu is off\r\n");
				}
			} else {
				kputs("unrecognised psu command\r\n");
			}
		} else {
			kputs("unrecognised power supply name\r\n");
		}
	} else {
		kputs("invalid arguments specified\r\n");
	}
}

/** Console Reset Command
 *
 * This function services the reset command on the console interface.
 */
void console_invoke_reset(int8_t argc, char *argv[]) {
	if ((argc < 1)||(argc > 2)) {
		// should always be 1 or 2
		kputs("invalid arguments specified\r\n");
		return;
	} else if (argc == 1) {
		// no argument, just do a plain reset
		kputs("resetting the cpu\r\n");
		RSTC_CR = RSTC_CR_PROCRST | RSTC_CR_PERRST | RSTC_CR_KEY;
	} else if (argc == 2) {
		// one argument should be present
		if (strcmp(argv[1], "help") == 0) {
			kputs("reset help\t\tPrint this message\r\n");
			kputs("reset\t\t\tReset the CPU\r\n");
			kputs("reset sam-ba\t\tReset the CPU into SAM-BA\r\n");
		} else if (strcmp(argv[1], "sam-ba") == 0) {
			kputs("clearing the boot mode bit and resetting the cpu\r\n");

			// Disable Interrupts, We're about to change vector tables
			asm volatile("cpsid f");
			asm volatile("dmb");

			// Wait for EEFC0 to be ready for a command
			while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));
			// Clear the GPNVM boot mode bit
			EEFC_FCR(EEFC0) = EEFC_FCR_FKEY | EEFC_FCR_FCMD(EEFC_FCR_FCMD_CGPB) | EEFC_FCR_FARG(1);
			asm volatile("dsb");
			asm volatile("dmb");

			// Wait for EEFC0 to complete the command
			while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));

			// Check for an error
			if (EEFC_FSR(EEFC0) & EEFC_FSR_FCMDE) {
				kputs("flash command error, unable to clear boot mode bit\r\n");
			}

			// Reset the CPU
			RSTC_CR = RSTC_CR_EXTRST | RSTC_CR_KEY;
		} else {
			kputs("unrecognised argument\r\n");
		}
	}
}

/** Console Command Parser
 *
 * This function parses the buffer generated by the \ref uart_handler and breaks
 * it down into argc and argv. Then evaluates argv[0] against a set of internal
 * calls and executes the requested one.
 */
void console_invoke(char *cmd) {
	// pointers to the tokenized command string
	#define console_argv_max 16
	int8_t console_argc = 0;
	char *console_argv[console_argv_max] = {0, };

	// separate arguments into the pointer array console_argv
	while (*cmd != '\0') {
		// check if we are in-between arguments
		if (!console_argv[console_argc]) {
			// we are in-between arguments
			if (isspace(*cmd)) {
				// skip white-space and replace with null
				*cmd++ = '\0';
			} else {
				// start argument
				console_argv[console_argc] = cmd;
			}
		} else {
			// we are filling an argument
			if (isspace(*cmd)) {
				// reached delimiter, terminate and next argument
				*cmd = '\0';
				if (console_argc + 1 < console_argv_max) {
					console_argc++;
				} else {
					kputs("console: command has too many arguments\r\n");
					return;
				}
			}
			cmd++;
		}
	}
	// if we didn't end on a null increment console_argc
	if (console_argv[console_argc]) {
		console_argc++;
	}

	// bail if the user didn't say anything important
	if (console_argc == 0) {
		return;
	}

	// match the command to its handler
	if (strcmp(console_argv[0], "help") == 0) {
		// general help
		kputs("run the commands below for more detailed help\r\n");
		kputs("clock help\t\tPrint help about showing and setting the date and time\r\n");
		kputs("peek help\t\tPrint help about peeking at memory\r\n");
		kputs("poke help\t\tPrint help about poking at memory\r\n");
		kputs("psu help\t\tPrint help about controlling various power supplies\r\n");
		kputs("reset help\t\tPrint help about resetting the cpu\r\n");
	} else if (strcmp(console_argv[0], "clock") == 0) {
		console_invoke_clock(console_argc, console_argv);
	} else if (strcmp(console_argv[0], "peek") == 0) {
		console_invoke_peek(console_argc, console_argv);
	} else if (strcmp(console_argv[0], "poke") == 0) {
		console_invoke_poke(console_argc, console_argv);
	} else if (strcmp(console_argv[0], "psu") == 0) {
		console_invoke_psu(console_argc, console_argv);
	} else if (strcmp(console_argv[0], "reset") == 0) {
		console_invoke_reset(console_argc, console_argv);
	} else {
		kputs("console: unrecognised command, type \"help\" for more information\r\n");
	}
}

/** Console Service Interrupt Handler
 *
 * This function builds a buffer of the characters received on the UART one at a
 * time until we've either filed the buffer or a carriage return is seen.
 */
void uart_handler(void) {
	// buffer to hold the command string
	#define console_buf_max 80
	static char console_buf[console_buf_max] = {0, };
	static int32_t console_len = 0;

	// check if this is a rx interrupt
	if (UART_SR & UART_SR_RXRDY) {
		// read the character from the receive holding register
		char c = UART_RHR;

		switch (c) {
		case '\r':
			// give the user a new line
			kputs("\r\n");

			// invoke the command
			console_invoke(console_buf);

			// clean the buffer for the next command
			console_buf[0] = '\0';
			console_len = 0;

			// print a prompt
			kputs("# ");
			break;
		case 127:
			// remove the last character from the buffer if its valid
			if (console_len > 0) {
				console_buf[--console_len] = '\0';

				// reflect the change on the prompt
				kputs("\b \b");
			}
			break;
		default:
			if (isprint(c)) {

				// check if we have room to store the character
				if (console_buf_max > console_len + 1) {
					// echo the character back to the user
					kputc(c);

					// store the character and terminate the string
					console_buf[console_len++] = c;
					console_buf[console_len] = '\0';
				} else {
					// print an error for the user
					kputs("\r\nconsole: buffer overflow\r\n# ");

					// valid commands should fit in the buffer
					console_buf[0] = '\0';
					console_len = 0;
				}
			}
		}
	}
}

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

	// Enable the RTC Interrupt in the NVIC
	ICER0 = (1 << PMC_ID_UART); // Disable Interrupt
	ICPR0 = (1 << PMC_ID_UART); // Clear Pending
	IPR(PMC_ID_UART)  = IPR_IP(0xF); // Set the Priority to 15
	ISER0 = (1 << PMC_ID_UART); // Enable Interrupt
	// Enable RX Interrupt for the UART
	UART_IER = UART_IER_RXRDY;

	// Enable the UART
	UART_CR = UART_CR_RXEN | UART_CR_TXEN;
}