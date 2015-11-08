// vim: set tabstop=4 shiftwidth=4 expandtab :
//
// nixieclock-firmware - Nixie Clock Main Firmware Program
// Copyright (C) 2013 - 2015 Joe Ciccone
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <clock.h>
#include <ctype.h>
#include <ds3231.h>
#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <system.h>

int8_t console_clock_set(int8_t argc, char *argv[]) {
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

    // Set the Date/Time
    if (clock_set(&newtime) < 0) {
        kputs("Failed to Set the Date/Time.\r\n");
    }

    return 0;
}

void console_clock_show(void) {
    // Display the Date/Time from the External RTC
    uint8_t ds3231[7];
    if (twi_read(DS3231_TWI_ADDR, 0x01000000, ds3231, 7) < 0) {
        kputs("Failed to Read Date/Time from External RTC.\r\n");
    } else {
        kputs("External Time: ");
        kprintf(" %02d%02x/%02x/%02x", (((ds3231[5] & 0x80) >> 7) ? 20 : 19), ds3231[6], ds3231[5] & 0x1F, ds3231[4] & 0x3F);
        kprintf(" %d", ds3231[3] & 0x07);
        if (ds3231[2] & 0x40) {
            // 12 hour mode
            kprintf(" %02x:%02x:%02x\r\n", ds3231[2] & 0x1F, ds3231[1] & 0x7F, ds3231[0] & 0x7F);
        } else {
            // 24 hour mode
            kprintf(" %02x:%02x:%02x\r\n", ds3231[2] & 0x3F, ds3231[1] & 0x7F, ds3231[0] & 0x7F);
        }
    }

    // Display the Date/Time from the Internal RTC
    kputs("Internal Time: ");
    kprintf(" %04u/%02u/%02u", clock.year, clock.month, clock.date);
    kprintf(" %u", clock.day);
    kprintf(" %02u:%02u:%02u\r\n", clock.hour, clock.minute, clock.second);
}

void console_clock(int8_t argc, char *argv[]) {
    if ((argc > 0)&&(strcmp(argv[1], "help")) == 0) {
        kputs("clock help                          Display this message\r\n");
        kputs("clock set YYYY/MM/DD W HH:MM:SS     Sets the Date/Time\r\n");
        kputs("    Where YYYY = 4 Digit Year\r\n");
        kputs("    Where   MM = 2 Digit Month\r\n");
        kputs("    Where   DD = 2 Digit Day of Month\r\n");
        kputs("    Where    W = 1 Digit Week of Day (1 = Sunday, 7 = Saturday)\r\n");
        kputs("    Where   HH = 2 Digit Hours (24-Hour Mode)\r\n");
        kputs("    Where   MM = 2 Digit Minutes\r\n");
        kputs("    Where   SS = 2 Digit Seconds\r\n");
        kputs("clock show                          Display the Internal and External Date/Time\r\n");
    } else if ((argc > 0)&&(strcmp(argv[1], "set") == 0)) {
        console_clock_set(argc, argv);
    } else if ((argc > 0)&&(strcmp(argv[1], "show") == 0)) {
        console_clock_show();
    } else {
        kputs("Error: Unrecognized Command, Type \"license help\" for more information\r\n");
    }
}

void console_license(int8_t argc, char *argv[]) {
    if ((argc > 0)&&(strcmp(argv[1], "help")) == 0) {
        kputs("license help                        Display this message\r\n");
        kputs("license show                        Display the License for this Firmware\r\n");
    } else if ((argc > 0)&&(strcmp(argv[1], "show") == 0)) {
        kputs("\r\n");
        kputs("nixieclock-firmware - Nixie Clock Main Firmware Program\r\n");
        kputs("Copyright (C) 2013 - 2015 Joe Ciccone\r\n");
        kputs("\r\n");
        kputs("This program is free software: you can redistribute it and/or modify\r\n");
        kputs("it under the terms of the GNU General Public License as published by\r\n");
        kputs("the Free Software Foundation, either version 3 of the License, or\r\n");
        kputs("(at your option) any later version.\r\n");
        kputs("\r\n");
        kputs("This program is distributed in the hope that it will be useful,\r\n");
        kputs("but WITHOUT ANY WARRANTY; without even the implied warranty of\r\n");
        kputs("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\r\n");
        kputs("GNU General Public License for more details.\r\n");
        kputs("\r\n");
        kputs("You should have received a copy of the GNU General Public License\r\n");
        kputs("along with this program.  If not, see <http://www.gnu.org/licenses/>.\r\n");
        kputs("\r\n");
    } else {
        kputs("Error: Unrecognized Command, Type \"license help\" for more information\r\n");
    }
}

void console_psu(int8_t argc, char *argv[]) {
    if (argc == 1) {
        kputs("Error: Incomplete command specified\r\n");
    } else if (argc == 2) {
        if (strcmp(argv[1], "help") == 0) {
            kputs("psu help                            Display this message\r\n");
            kputs("psu {name} on                       Turn on the requested power supply\r\n");
            kputs("psu {name} off                      Turn off the requested power supply\r\n");
            kputs("psu {name} show                     Show the power supplies status\r\n");
            kputs("    where {name} = 5v or hv or zb\r\n");
            kputs("    where {cmd} = on or off or show\r\n");
        } else {
            kputs("Error: Invalid arguments specified\r\n");
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
                if (PIO_PDSR(PIN_5VPSU_EN_PIO) & (1 << PIN_5VPSU_EN_IDX)) {
                    if (PIO_PDSR(PIN_5VPSU_PG_PIO) & (1 << PIN_5VPSU_PG_IDX)) {
                        kputs("5v is off, power is good (unexpected)\r\n");
                    } else {
                        kputs("5v is off, power is bad (expected)\r\n");
                    }
                } else {
                    if (PIO_PDSR(PIN_5VPSU_PG_PIO) & (1 << PIN_5VPSU_PG_IDX)) {
                        kputs("5v is on, power is good\r\n");
                    } else {
                        kputs("5v is on, power is bad\r\n");
                    }
                }
            } else {
                kputs("Error: Unrecognized power supply command\r\n");
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
                    kputs("hv is on\r\n");
                } else {
                    kputs("hv is off\r\n");
                }
            } else {
                kputs("Error: Unrecognized power supply command\r\n");
            }
        } else if (strcmp(argv[1], "zb") == 0) {
            if (strcmp(argv[2], "on") == 0) {
                // Turn on the ZigBee module (SHDN High)
                PIO_SODR(PIN_ZIGBEE_SHDN_PIO) = (1 << PIN_ZIGBEE_SHDN_IDX);
            } else if (strcmp(argv[2], "off") == 0) {
                // Shutdown the ZigBee module (SHDN Low)
                PIO_CODR(PIN_ZIGBEE_SHDN_PIO) = (1 << PIN_ZIGBEE_SHDN_IDX);
            } else if (strcmp(argv[2], "show") == 0) {
                if (PIO_PDSR(PIN_ZIGBEE_SHDN_PIO) & (1 << PIN_ZIGBEE_SHDN_IDX)) {
                    kputs("zb is on\r\n");
                } else {
                    kputs("zb is off\r\n");
                }
            } else {
                kputs("Error: Unrecognized power supply command\r\n");
            }
        } else {
            kputs("Error: Unrecognized power supply name\r\n");
        }
    } else {
        kputs("Error: Invalid arguments specified\r\n");
    }

}

void console_reset(int8_t argc, char *argv[]) {
    if ((argc < 1)||(argc > 2)) {
        // Should always be 1 or 2
        kputs("Error: Invalid arguments specified\r\n");
    } else if (argc == 1) {
        // No argument, just do a plain reset
        kputs("Resetting the CPU\r\n");
        RSTC_CR = RSTC_CR_KEY | RSTC_CR_PROCRST | RSTC_CR_PERRST;
    } else if (argc == 2) {
        // One argument present
        if (strcmp(argv[1], "help") == 0) {
            kputs("reset help                          Display this message\r\n");
            kputs("reset                               Reset the CPU\r\n");
            kputs("reset sam-ba                        Reset the CPU into SAM-BA\r\n");
        } else if (strcmp(argv[1], "sam-ba") == 0) {
            kputs("Clearing the Boot-Mode Bit and Resetting the CPU\r\n");

            // We're about to change vector tables
            asm volatile ("cpsid i"); // Disable Interrupts
            asm volatile ("cpsid f"); // Disable Exceptions
            asm volatile ("dmb");     // Data Memory Barrier

            // Wait for EEFC0 to be ready for a command
            while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));
            // Clear the GPNVM boot mode bit
            EEFC_FCR(EEFC0) = EEFC_FCR_FKEY | EEFC_FCR_FCMD_CGPB | (1 << EEFC_FCR_FARG_Off);
            asm volatile ("dsb"); // Data Syncronization Barrier
            asm volatile ("dmb"); // Data Memory Barrier

            // Wait for EEFC0 to complete the command
            while (!(EEFC_FSR(EEFC0) & EEFC_FSR_FRDY));

            // Check for an error
            if (EEFC_FSR(EEFC0) & EEFC_FSR_FCMDE) {
                kputs("Flash Command Error: Unable to Clear Boot-Mode Bit\r\n");
            }

            // Reset the CPU (External Reset)
            RSTC_CR = RSTC_CR_KEY | RSTC_CR_EXTRST;
        } else {
            kputs("Error: Invalid arguments specified\r\n");
        }
    }
}

void console_uptime(int8_t argc, char *argv[]) {
    if (argc == 1) {
        uint32_t vr = RTT_VR;
        while (vr != RTT_VR) {
            vr = RTT_VR;
        }

        uint16_t days; uint8_t hours, mins, secs;

        secs = vr % 60;
        vr /= 60;
        mins = vr % 60;
        vr /= 60;
        hours = vr % 24;
        vr /= 60;
        days = vr;

        kputs("Uptime: ");
        if (days > 0) {
            kprintf("%u days %u hours %u mins %u secs\r\n", days, hours, mins, secs);
        } else if (hours > 0) {
            kprintf("%u hours %u mins %u secs\r\n", hours, mins, secs);
        } else if (mins > 0) {
            kprintf("%u mins %u secs\r\n", mins, secs);
        } else {
            kprintf("%u secs\r\n", secs);
        }
    } else if (argc == 2) {
        if (strcmp(argv[1], "help") == 0) {
            kputs("uptime help                         Display this message\r\n");
            kputs("uptime                              Display the System Uptime\r\n");
        } else {
            kputs("Error: Invalid arguments specified\r\n");
        }
    } else {
        kputs("Error: Invalid arguments specified\r\n");
    }
}
void console_invoke(char *cmd) {
    // pointers to the tokenized command string
    #define argv_max 8
    int8_t argc = 0;
    char *argv[argv_max] = {0, };

    // Trim leading space from the command
    while (isspace(*cmd)) {
        cmd++;
    }

    // bail on an empty command
    if (*cmd == '\0') {
        return;
    }

    // separate arguments into the pointer array argv
    while (*cmd != '\0') {
        // check if we are in-between arguments
        if (!argv[argc]) {
           if (isspace(*cmd)) {
                // skip white-space and replace with null
                *cmd++ = '\0';
            } else {
                // start argument
                argv[argc] = cmd;
            }
        } else {
            // we are filling an argument
            if (isspace(*cmd)) {
                // reached delimiter, terminate and next argument
                *cmd = '\0';
                if (argc + 1 < argv_max) {
                    argc++;
                } else {
                    kputs("Error: Command has too many arguments!\r\n");
                    return;
                }
            }
            cmd++;
        }
    }

    // if we didn't end on a null, increment argc
    if (argv[argc]) {
        argc++;
    }

    // Match the command to its top level handler
    if (strcmp(argv[0], "help") == 0) {
        kputs("Run the commands below for more information\r\n");
        kputs("\r\n");
        kputs("clock help\r\n");
        kputs("license help\r\n");
        kputs("psu help\r\n");
        kputs("reset help\r\n");
        kputs("uptime help\r\n");
        kputs("\r\n");
    } else if (strcmp(argv[0], "clock") == 0) {
        console_clock(argc, argv);
    } else if (strcmp(argv[0], "license") == 0) {
        console_license(argc, argv);
    } else if (strcmp(argv[0], "psu") == 0) {
        console_psu(argc, argv);
    } else if (strcmp(argv[0], "reset") == 0) {
        console_reset(argc, argv);
    } else if (strcmp(argv[0], "uptime") == 0) {
        console_uptime(argc, argv);
    } else {
        kputs("Error: Unrecognized Command, Type \"help\" for more information\r\n");
    }
}

void uart_handler(void) {
    // Buffer to hold the command string
    #define console_buf_max 80
    static char console_buf[console_buf_max] = {0, };
    static int32_t console_len = 0;

    // Check if this is a RX Interrupt
    if (UART_SR & UART_SR_RXRDY) {
        // Read the char from the receive holding register
        char c = UART_RHR;

        switch (c) {
        case '\r':
            // user pressed return, get a new line on the terminal
            kputs("\r\n");
            // evaluate the buffered command string
            console_invoke(console_buf);
            // clean the buffer
            console_buf[0] = '\0';
            console_len = 0;
            // print a new prompt
            kputs("# ");
            break;
        case 127:
            // check if there's a command in the buffer
            if (console_len > 0) {
                // remove the last char from the buffer and terminal
                console_buf[--console_len] = '\0';
                kputs("\b \b");
            }
            break;
        default:
            // check if this is a printable character
            if (isprint(c)) {
                // check for room to store the character
                if (console_len + 2 < console_buf_max) {
                    // echo back the character
                    kputc(c);
                    // store the character on the command buffer
                    console_buf[console_len++] = c;
                    console_buf[console_len] = '\0';
                } else {
                    // command buffer is full, bailing
                    kputs("\r\nconsole: buffer is full\r\n# ");
                    console_buf[0] = '\0';
                    console_len = 0;
                }
            }
            break;
        }
    }
}

void console_init(void) {
    // Configure UART Pins
    PIO_PDR(PIN_UART_RXD_PIO)   =  (1 << PIN_UART_RXD_IDX); // Disable PIO to Enable Peripheral
    PIO_ABSR(PIN_UART_RXD_PIO) &= ~(1 << PIN_UART_RXD_IDX); // Select Peripheral A
    PIO_PDR(PIN_UART_TXD_PIO)   =  (1 << PIN_UART_TXD_IDX); // Disable PIO to Enable Peripheral
    PIO_ABSR(PIN_UART_TXD_PIO) &= ~(1 << PIN_UART_TXD_IDX); // Select Peripheral A

    // Enable the UART Peripheral Clock
    PMC_PCER = (1 << PMC_ID_UART);

    // Reset and Disable the UART
    UART_CR = UART_CR_RSTRX | UART_CR_RSTTX | UART_CR_RXDIS | UART_CR_TXDIS | UART_CR_RSTSTA;
    // Set No Parity and Normal Mode
    UART_MR = UART_MR_PAR_NO | UART_MR_CHMODE_NORMAL;

    // Set the UART BAUD rate to 115200bps (96MHz / (16 * 52) = 115384)
    UART_BRGR = 52;

    // Enable the UART Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_UART); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_UART); // Clear Pending
    IPR(PMC_ID_UART) = (IPR(PMC_ID_UART) & ~(IPR_IP_Msk(PMC_ID_UART))) | IPR_IP(PMC_ID_UART, 0xC); // Set the Priority to 12
    ISER0 = (1 << PMC_ID_UART); // Enable Interrupt
    // Enable RX Interrupt for the UART
    UART_IER = UART_IER_RXRDY;

    // Enable the UART TX
    UART_CR = UART_CR_TXEN;
}

void console_start(void) {
    kputs("\r\nPress ENTER for a prompt\r\n");
    UART_CR = UART_CR_RXEN;
}
