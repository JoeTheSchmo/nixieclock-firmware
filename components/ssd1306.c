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

#include <ssd1306.h>
#include <stdio.h>
#include <system.h>
#include <types.h>

// Set Contrast Control
//
// This command sets the Contrast Setting of the display. The chip has 256
// contrast steps from 0x00 to 0xFF. The segment output current increases as
// the contrast step value increases.
//
// constrast = The new contrast value
int32_t ssd1306_set_contrast(uint8_t contrast) {
    uint8_t data[2] = {
        0x81,
        contrast
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Entire Display ON
//
// This command sets the segment driver to output according to the GDDRAM
// contents or to force the entire display ON.
//
// display_on = {
//     0 = Display RAM Content,
//     1 = Entire Display ON
// }
int32_t ssd1306_set_entire_display_on(uint8_t display_on) {
    uint8_t data[1] = {
        (0xA4 + (display_on & 0x01))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Normal/Inverse Display
//
// This command sets the display to be either normal or inverse. In normal
// display a RAM data of 1 indicates an “ON” pixel while in inverse display a
// RAM data of 0 indicates an “ON” pixel.
//
// display_invert = {
//     0 = Normal Display Output,
//     1 = Invert Display Output
// }
int32_t ssd1306_set_display_invert(uint8_t display_invert) {
    uint8_t data[1] = {
        (0xA6 + (display_invert & 0x01))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Display ON/OFF
//
// This command is used to turn the OLED panel display ON or OFF. When the
// display is ON, the selected circuits by Set Master Configuration command
// will be turned ON. When the display is OFF, those circuits will be turned
// OFF and the segment and common output are in VSS state and high impedance
// state, respectively.
//
// display_on = {
//     0 = Display Off,
//     1 = Display On, Normal Mode
// }
int32_t ssd1306_set_display_on(uint8_t display_on) {
    uint8_t data[1] = {
        (0xAE + (display_on & 0x01))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Lower Column Start Address for Page Addressing Mode
//
// This command specifies the lower nibble of the 8-bit column start address
// for the display data RAM under Page Addressing Mode. The column address will
// be incremented by each data access.
//
// low_nib = Lower Nibble of the 8-bit Column Start Address
int32_t ssd1306_set_column_start_addr_low(uint8_t low_nib) {
    uint8_t data[1] = {
        (0x00 + (low_nib & 0x0F))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Higher Column Start Address for Page Addressing Mode
//
// This command specifies the higher nibble of the 8-bit column start address
// for the display data RAM under Page Addressing Mode. The column address will
// be incremented by each data access.
//
// high_nib = Higher Nibble of the 8-bit Column Start Address
int32_t ssd1306_set_column_start_addr_high(uint8_t high_nib) {
    uint8_t data[1] = {
        (0x10 + (high_nib & 0x0F))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Column Start Address for Page Addressing Mode
//
// This function sends two commands. One to set the higher nibble of the 8-bit
// column start address, and a second to set the lower nibble of the 8-bit
// column start address.
//
// addr = The 8-bit Column Address
int32_t ssd1306_set_column_start_addr(uint8_t addr) {
    uint8_t data[2] = {
        (0x10 + ((addr >> 4) & 0x0F)),
        (0x00 + (addr & 0x0F)),
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set Memory Addressing Mode
//
// There are 3 different memory addressing modes in the SSD1306; page
// addressing mode, horizontal addressing mode and vertical addressing mode.
// This command sets the way of memory addressing into one of the above three
// modes.
//
// In page addressing mode, after the display RAM is read/written, the column
// address pointer is increased automatically by 1. If the column address
// pointer reaches column end address, the column address pointer is reset to
// column start address and page address pointer is not changed. Users have to
// set the new page and column addresses in order to access the next page RAM
// content.
//
// In horizontal addressing mode, after the display RAM is read/written, the
// column address pointer is increased automatically by 1. If the column
// address pointer reaches column end address, the column address pointer is
// reset to column start address and page address pointer is increased by 1.
// When both column and page address pointers reach the end address, the
// pointers are reset to column start address and page start address.
//
// In vertical addressing mode, after the display RAM is read/written, the page
// address pointer is increased automatically by 1. If the page address pointer
// reaches the page end address, the page address pointer is reset to page
// start address and column address pointer is increased by 1. When both column
// and page address pointers reach the end address, the pointers are reset to
// column start address and page start address.
//
// mode = {
//     0x00 = Horizontal Addressing Mode,
//     0x01 = Vertical Addressing Mode,
//     0x02 = Page Addressing Mode (RESET)
// }
int32_t ssd1306_set_mem_addr_mode(uint8_t mode) {
    uint8_t data[2] = {
        0x20,
        (0x00 + (mode & 0x03))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set Column Address
//
// This command specifies column start address and end address of the display
// data RAM. This command also sets the column address pointer to column start
// address. This pointer is used to define the current read/write column
// address in graphic display data RAM. If horizontal address increment mode is
// enabled by command 20h, after finishing read/write one column data, it is
// incremented automatically to the next column address. Whenever the column
// address pointer finishes accessing the end column address, it is reset back
// to start column address and the row address is incremented to the next row.
//
// start = Column Start Address, Range 0 - 127 (RESET = 0)
// end = Column End Address, Range 0 - 127 (RESET = 127)
int32_t ssd1306_set_column_addr(uint8_t start, uint8_t end) {
    uint8_t data[3] = {
        0x21,
        (start & 0x7F),
        (end & 0x7F)
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 3);
}

// Set Page Address
//
// This command specifies page start address and end address of the display
// data RAM. This command also sets the page address pointer to page start
// address. This pointer is used to define the current read/write page address
// in graphic display data RAM. If vertical address increment mode is enabled
// by command 20h, after finishing read/write one page data, it is incremented
// automatically to the next page address. Whenever the page address pointer
// finishes accessing the end page address, it is reset back to start page
// address.
//
// start = Page Start Address, Range 0 - 7 (RESET = 0)
// end = Page End Address, Range 0 - 7 (RESET = 7)
int32_t ssd1306_set_page_addr(uint8_t start, uint8_t end) {
    uint8_t data[3] = {
        0x22,
        (start & 0x07),
        (end & 0x07)
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 3);
}

// Set Page Start Address for Page Addressing Mode
//
// This command positions the page start address from 0 to 7 in GDDRAM under
// Page Addressing Mode.
//
// addr = Start Page Address, Range 0 to 7
int32_t ssd1306_set_page_start_addr(uint8_t addr) {
    uint8_t data[1] = {
        (0xB0 | (addr & 0x07))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Display Start Line
//
// This command sets the Display Start Line register to determine starting
// address of display RAM, by selecting a value from 0 to 63. With value equal
// to 0, RAM row 0 is mapped to COM0. With value equal to 1, RAM row 1 is
// mapped to COM0 and so on.
//
// register = Display Starting RAM Row, Range 0 to 63
int32_t ssd1306_set_display_start_line(uint8_t reg) {
    uint8_t data[1] = {
        (0x40 + (reg * 0x3F))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Segment Re-map
// 
// This command changes the mapping between the display data column address and
// the segment driver. It allows flexibility in OLED module design.
//
// This command only affects subsequent data input. Data already stored in
// GDDRAM will have no changes.
//
// map = {
//     0 = Column address 0 is mapped to SEG0 (RESET),
//     1 = Column address 127 is mapped to SEG0
// }
int32_t ssd1306_set_segment_remap(uint8_t map) {
    uint8_t data[1] = {
        (0xA0 + (map * 0x01))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Multiplex Ratio
//
// This command switches the default 63 multiplex mode to any multiplex ratio,
// ranging from 16 to 63. The output pads COM0~COM63 will be switched to the
// corresponding COM signal.
//
// Set Multiplex Ratio to N+1 where N is 6 bit value. Multiplex ratio must be
// between 16MUX and 64MUX
//
// ratio = MUX Setting
int32_t ssd1306_set_multiplex_ratio(uint8_t ratio) {
    uint8_t data[2] = {
        0xA8,
        (ratio & 0x3F)
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// SET COM Output Scan Direction
//
// This command sets the scan direction of the COM output, allowing layout
// flexibility in the OLED module design. Additionally, the display will show
// once this command is issued. For example, if this command is sent during
// normal display then the graphic display will be vertically flipped immediately.
//
// Where N is the Multiplex Ratio
//
// direction = {
//     0 = normal mode (RESET) : Scan from COM0 to COM[N-1],
//     1 = remapped mode : Scan from COM[N-1] to COM0
// }
int32_t ssd1306_set_com_scan_dir(uint8_t direction) {
    uint8_t data[1] = {
        (0xC0 + ((direction & 0x01) << 3))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 1);
}

// Set Display Offset
//
// This command specifies the mapping of the display start line to one of
// COM0~COM63 (assuming that COM0 is the display start line then the display
// start line register is equal to 0).
//
// For example, to move the COM16 towards the COM0 direction by 16 lines the
// 6-bit data in the second byte should be given as 010000b. To move in the
// opposite direction by 16 lines the 6-bit data should be given by 64 – 16,
// so the second byte would be 100000b.
//
// offset = Display Offset
int32_t ssd1306_set_display_offset(uint8_t offset) {
    uint8_t data[2] = {
        0xD3,
        (offset & 0x3F)
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set COM Pins Hardware Configuration
//
// This command sets the COM signal pin configuration to match the OLED panel
// hardware layout.
//
// remap =
// alt =
int32_t ssd1306_set_com_pins(uint8_t remap, uint8_t alt) {
    uint8_t data[2] = {
        0xDA,
        (0x02 | ((remap & 0x01) << 5) | ((alt & 0x01) << 4))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set Display Clock Divide Ratio and Oscillator Frequency
//
// This command consists of two functions:
//
// Display Clock Divide Ratio: Set the divide ratio to generate DCLK
// (Display Clock) from CLK. The divide ratio is from 1 to 16, with reset
// value = 1.
//
// Oscillator Frequency: Program the oscillator frequency Fosc that is the
// source of CLK if CLS pin is pulled high. The 4-bit value results in 16
// different frequency settings available. The default setting is 1000b.
//
// us_osc = Oscillator Frequency
// ratio = Display Clock Divide Ratio
int32_t ssd1306_set_clock_ratio(uint8_t osc, uint8_t ratio) {
    uint8_t data[2] = {
        0xD5,
        (((osc & 0x0F) << 4) | (ratio & 0x0F))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set Pre-charge Period
//
// This command is used to set the duration of the pre-charge period. The
// interval is counted in number of DCLK, where RESET equals 2 DCLKs.
//
// phase2 = Phase 2 Pre-charge Period
// phase1 = Phase 1 Pre-charge Period
int32_t ssd1306_set_precharge_period(uint8_t phase2, uint8_t phase1) {
    uint8_t data[2] = {
        0xD9,
        (((phase2 & 0x0F) << 4) | (phase1 & 0x0F))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Set Vcomh Deselect Level
//
// This command adjusts the Vcomh regulator output.
//
// deselect = {
//     000b = ~ 0.65 x Vcc,
//     010b = ~ 0.77 x Vcc (RESET),
//     011b = ~ 0.83 x Vcc
// }
int32_t ssd1306_set_vcomh(uint8_t deselect) {
    uint8_t data[2] = {
        0xDB,
        ((deselect & 0x07) << 4)
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Charge Pump Setting
//
// This command enables or disables the charge pump regulator function.
//
// enable = {
//     0 = Charge Pump Disable,
//     1 = Charge Pump Enable
// }
int32_t ssd1306_set_charge_pump_enable(uint8_t enable) {
    uint8_t data[2] = {
        0x8D,
        (0x10 + ((enable & 0x01) << 2))
    };

    return twi_write(SSD1306_TWI_ADDR, 0x01000000, data, 2);
}

// Write Data
//
// This function writes data into the internal memory.
//
// dptr = Data Pointer
// dlen = Data Length
int32_t ssd1306_write_data(uint8_t *dptr, uint8_t dlen) {
    return twi_write(SSD1306_TWI_ADDR, 0x01000040, dptr, dlen);
}
