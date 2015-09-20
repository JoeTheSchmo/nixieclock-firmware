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

#include <ctype.h>
#include <pins.h>
#include <sam3u4e.h>
#include <stdio.h>
#include <string.h>
#include <system.h>

void console_invoke(char *cmd) {
    // Check for a valid command string
    if (!cmd) {
        return;
    }
    if (strlen(cmd) <= 0) {
        return;
    }

    // Trim leading space from the command
    while (isspace(*cmd)) {
        cmd++;
    }

    // Check for a valid command string

    if (strncmp(cmd, "show ", 5) == 0) {
        if (strcmp(cmd + 5, "license") == 0) {
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
            return;
        }
    }    

    kputs("Error: Unrecognized Command\r\n");
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
