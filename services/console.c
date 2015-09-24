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
        kputs("\r\n");
    } else if (strcmp(argv[0], "clock") == 0) {
        console_clock(argc, argv);
    } else if (strcmp(argv[0], "license") == 0) {
        console_license(argc, argv);
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
