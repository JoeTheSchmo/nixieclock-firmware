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

int count = 256;

void console_invoke(char *cmd) {
    kputs("running command: ");
    kputs(cmd);
    kputs("\r\n");
    kprintf
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
