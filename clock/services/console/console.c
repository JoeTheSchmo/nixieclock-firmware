/**
 * \file
 *
 * \brief Nixie Clock Firmware
 *
 * Copyright (c) 2013 - 2015 Joe Ciccone. All rights reserved.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clock.h"
#include "ds3231.h"

#include "compiler.h"
#include "efc.h"
#include "interrupt.h"
#include "ioport.h"
#include "uart.h"
#include "rstc.h"
#include "sysclk.h"

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
	newtime.year = strtoul(p, &p, 10);
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
				kprintf(" %04lu/%02lu/%02lu", clock.year, clock.month, clock.date);
				kprintf(" %lu", clock.day);
				kprintf(" %02lu:%02lu:%02lu\r\n", clock.hour, clock.minute, clock.second);

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
			kputs("psu {name} show\t\tShow the power supplies status\r\n");
			kputs("\twhere {name} = 5v or hv or xbee\r\n");
			kputs("\twhere {cmd} = on or off or show\r\n");
		} else {
			kputs("invalid arguments specified\r\n");
		}
	} else if (argc == 3) {
		if (strcmp(argv[1], "5v") == 0) {
			if (strcmp(argv[2], "on") == 0) {
				// Turn on the 5v power supply (low enable = on)
				ioport_set_pin_level(PIN_5VPSU_EN, IOPORT_PIN_LEVEL_LOW);
			} else if (strcmp(argv[2], "off") == 0) {
				// Turn off the 5v power supply (high enable = off)
				ioport_set_pin_level(PIN_5VPSU_EN, IOPORT_PIN_LEVEL_HIGH);
			} else if (strcmp(argv[2], "show") == 0) {
				if (!ioport_get_pin_level(PIN_5VPSU_EN)) {
					if (ioport_get_pin_level(PIN_5VPSU_PG)) {
						kputs("5v psu is on, power is good\r\n");
					} else {
						kputs("5v psu is on, power is bad\r\n");
					}
				} else {
					if (ioport_get_pin_level(PIN_5VPSU_PG)) {
						kputs("5v psu is off, power is good (unexpected)\r\n");
					} else {
						kputs("5v psu is off, power is bad (expected)\r\n");
					}

				}
			} else {
				kputs("unrecognized psu command\r\n");
			}
		} else if (strcmp(argv[1], "hv") == 0) {
			if (strcmp(argv[2], "on") == 0) {
				// Turn on the high voltage power supply
				ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_HIGH);
			} else if (strcmp(argv[2], "off") == 0) {
				// Turn off the high voltage power supply
				ioport_set_pin_level(PIN_HV5530_HVEN, IOPORT_PIN_LEVEL_LOW);
			} else if (strcmp(argv[2], "show") == 0) {
				if (ioport_get_pin_level(PIN_HV5530_HVEN)) {
					kputs("hv psu is on\r\n");
				} else {
					kputs("hv psu is off\r\n");
				}
			} else {
				kputs("unrecognized psu command\r\n");
			}
		} else if (strcmp(argv[1], "xbee") == 0) {
			if (strcmp(argv[2], "on") == 0) {
				// Turn on the XBee module
				ioport_set_pin_level(PIN_XBEE_SHDN, IOPORT_PIN_LEVEL_HIGH);
			} else if (strcmp(argv[2], "off") == 0) {
				// Shutdown the XBee module
				ioport_set_pin_level(PIN_XBEE_SHDN, IOPORT_PIN_LEVEL_LOW);
			} else if (strcmp(argv[2], "show") == 0) {
				if (ioport_get_pin_level(PIN_XBEE_SHDN)) {
					kputs("xbee is on\r\n");
				} else {
					kputs("xbee is off\r\n");
				}
			} else {
				kputs("unrecognized psu command\r\n");
			}
		} else {
			kputs("unrecognized power supply name\r\n");
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
		rstc_start_software_reset(RSTC);
	} else if (argc == 2) {
		// one argument should be present
		if (strcmp(argv[1], "help") == 0) {
			kputs("reset help\t\tPrint this message\r\n");
			kputs("reset\t\t\tReset the CPU\r\n");
			kputs("reset sam-ba\t\tReset the CPU into SAM-BA\r\n");
		} else if (strcmp(argv[1], "sam-ba") == 0) {
			kputs("clearing the boot mode bit and resetting the cpu\r\n");

			// Disable Interrupts, We're about to change vector tables
			cpu_irq_disable();

			// Clear the GPNVM Boot Mode Bit
			if (efc_perform_command(EFC0, EFC_FCMD_CGPB, 1) & EEFC_FSR_FCMDE) {
				kputs("flash command error, unable to clear boot mode bit\r\n");
			}

			// Reset the CPU
			rstc_reset_extern(RSTC);
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
void UART_Handler(void) {
	// buffer to hold the command string
	#define console_buf_max 80
	static char console_buf[console_buf_max] = {0, };
	static int32_t console_len = 0;

	// check if this is a rx interrupt
	if (UART->UART_SR & UART_SR_RXRDY) {
		// read the character from the receive holding register
		char c = UART->UART_RHR;

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
	// Prepare UART Options
	sam_uart_opt_t opt;
	opt.ul_mck = sysclk_get_peripheral_hz();
	opt.ul_baudrate = 115200;
	opt.ul_mode = UART_MR_PAR_NO | UART_MR_CHMODE_NORMAL;

	// Initialize UART
	sysclk_enable_peripheral_clock(ID_UART);
	uart_init(UART, &opt);

	// Enable UART Interrupt (Priority 12)
	irq_register_handler(ID_UART, 12);
	uart_enable_interrupt(UART, UART_IER_RXRDY);
}
