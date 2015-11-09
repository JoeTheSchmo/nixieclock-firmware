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
#include <display.h>
#include <menu.h>
#include <sam3u4e.h>
#include <ssd1306.h>
#include <string.h>
#include <timer.h>

enum _menu_state {
    menu_state_root = 1,
    menu_state_form = 2,
} menu_state = 0;

extern void menu_root(menu_key_e key);

void menu_setclock(menu_key_e key) {
    static timespec_t newtime;
    static uint8_t field;

    if (key == 0) {
        menu_state = menu_state_form;
        dprintfr(0, "Set Clock:");
        dprintfr(3, "Enter to Set");

        memcpy(&newtime, (timespec_t *)&clock, sizeof(newtime));
        field = 0;
    } else if (key == menu_key_back) {
        menu_root(0);
        return;
    } else if (key == menu_key_enter) {
        clock_set(&newtime);
        menu_root(menu_key_back);
        return;
    } else if (key == menu_key_east) {
        field = (field < 6  ? field + 1 : 0);
    } else if (key == menu_key_west) {
        field = (field > 0 ? field - 1 : 6);
    } else if (key == menu_key_north) {
        switch(field) {
        case 0: newtime.day = (newtime.day < 7 ? newtime.day + 1 : 1); break;
        case 1: newtime.month++; break;
        case 2: newtime.date++; break;
        case 3: newtime.year++; break;
        case 4: newtime.hour = (newtime.hour < 23 ? newtime.hour + 1 : 0); break;
        case 5: newtime.minute = (newtime.minute < 59 ? newtime.minute + 1 : 0); break;
        case 6: newtime.second = (newtime.second < 59 ? newtime.second + 1 : 0); break;
        }
    } else if (key == menu_key_south) {
        switch(field) {
        case 0: newtime.day = (newtime.day > 1 ? newtime.day - 1 : 7); break;
        case 1: newtime.month--; break;
        case 2: newtime.date--; break;
        case 3: newtime.year--; break;
        case 4: newtime.hour = (newtime.hour > 0 ? newtime.hour - 1 : 23); break;
        case 5: newtime.minute = (newtime.minute > 0 ? newtime.minute - 1 : 59); break;
        case 6: newtime.second = (newtime.second > 0 ? newtime.second - 1 : 59); break;
        }
    }

    // Sanity Check
    if (newtime.year > 2099) {
        newtime.year = 1900;
    } else
    if (newtime.year < 1900) {
        newtime.year = 2099;
    }

    if (newtime.month > 12) {
        newtime.month = 1;
    } else
    if (newtime.month < 1) {
        newtime.month = 12;
    }

    uint8_t days_in_month = clock_month_days[newtime.month];
    if ((newtime.year % 4) == 0) {
        days_in_month++;
    }
    if (newtime.date > days_in_month) {
        if (field != 2) {
            newtime.date = days_in_month;
        } else {
            newtime.date = 1;
        }
    } else
    if (newtime.date < 1) {
        newtime.date = days_in_month;
    }

    // Draw the Set Clock Form

    ssd1306_set_page_start_addr(0x01);
    ssd1306_set_column_start_addr(0x00);

    // Day of Week
    if (field == 0) {
        display_state |= display_state_invert;
        dprintf("%s", clock_day_name[newtime.day]);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%s", clock_day_name[newtime.day]);
    }

    dputs(", ");

    // Month
    if (field == 1) {
        display_state |= display_state_invert;
        dprintf("%s", clock_month_name[newtime.month]);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%s", clock_month_name[newtime.month]);
    }

    dputc(' ');

    // Date
    if (field == 2) {
        display_state |= display_state_invert;
        dprintf("%02u", newtime.date);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%02u", newtime.date);
    }

    dputc(' ');

    // Year
    if (field == 3) {
        display_state |= display_state_invert;
        dprintf("%04u", newtime.year);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%04u", newtime.year);
    }

    ssd1306_set_page_start_addr(0x02);
    ssd1306_set_column_start_addr(0x00);

    // Hour
    if (field == 4) {
        display_state |= display_state_invert;
        dprintf("%02u", newtime.hour);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%02u", newtime.hour);
    }

    dputc(':');

    // Minute
    if (field == 5) {
        display_state |= display_state_invert;
        dprintf("%02u", newtime.minute);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%02u", newtime.minute);
    }

    dputc(':');

    // Second
    if (field == 6) {
        display_state |= display_state_invert;
        dprintf("%02u", newtime.second);
        display_state &= ~display_state_invert;
    } else {
        dprintf("%02u", newtime.second);
    }
}

extern void menu_uptime(menu_key_e key);
void menu_uptime_refresh(uint32_t *again) {
    menu_uptime(menu_key_enter);
    *again = 1;
}

void menu_uptime(menu_key_e key) {
    static int8_t uptime_timer = -1;
    if (key == 0) {
        menu_state = menu_state_form;
        dprintfr(0, "Uptime:");
        uptime_timer = timer_set(menu_uptime_refresh, 1);
    } else if (key == menu_key_back) {
        if (uptime_timer >= 0) {
            timer_del(uptime_timer);
            uptime_timer = -1;
        }
        menu_root(0);
        return;
    } else if (key != menu_key_enter) {
        return;
    }

    // Draw the Uptime Form
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

    dprintfr(1, "  %u days", days);
    dprintfr(2, "  %02u:%02u:%02u", hours, mins, secs);
}

void menu_reset(menu_key_e key) {
    if (key == 0) {
        // Issue a Reset Command
        RSTC_CR = RSTC_CR_KEY | RSTC_CR_PROCRST | RSTC_CR_PERRST;
    }

    // Failed to Reset
    menu_root(0);
}

#define menu_size (sizeof(menu_form) / sizeof(menu_form[0]))
uint8_t menu_top = 0;
uint8_t menu_sel = 0;
struct _menu_form {
    char *title;
    void (*handler)(menu_key_e);
} menu_form[] = {
    { .title = "Set Clock",     .handler = menu_setclock, },
    { .title = "Show Uptime",   .handler = menu_uptime, },
    { .title = "Reset",         .handler = menu_reset, },
};

void menu_root(menu_key_e key) {
    // Process the Keystroke
    if (key == 0) {
        display_event_menu(1);
        menu_state = menu_state_root;
    } else if (key == menu_key_back) {
        // Close the Menu
        display_event_menu(0);
        menu_state = 0;
        return;
    } else if (key == menu_key_enter) {
        if (menu_form[menu_sel].handler) {
            menu_form[menu_sel].handler(0);
            return;
        }
    } else if (key == menu_key_north) {
        // Move Up One Item
        if (menu_sel > 0) { menu_sel--; }
        if (menu_sel < menu_top) { menu_top = menu_sel; }
    } else if (key == menu_key_south) {
        // Move Down One Item
        if (menu_sel < menu_size - 1) { menu_sel++; }
        if (menu_sel > menu_top + 3) { menu_top++; }
    }

    // Draw the Root Menu
    uint8_t i, j;
    for (i = menu_top, j = 0; (i < menu_size) && (j < 4); i++, j++) {
        if (i == menu_sel) {
            display_state |= display_state_invert;
            dprintfr(j, "%s", menu_form[i].title);
            display_state &= ~display_state_invert;
        } else {
            dprintfr(j, "%s", menu_form[i].title);
        }
    }

    if (j < 4) {
        display_erase_pages(j, 4 - j);
    }
}

void menu_key_press(menu_key_e key) {
    if (!(display_state & display_state_menu)) {
        // No menu is opened
        if (key == menu_key_enter) {
            // Not in Menu and Enter Key Pressed
            menu_root(0);
        }
    } else if (menu_state == menu_state_root) {
        menu_root(key);
    } else if (menu_state == menu_state_form) {
        if (menu_form[menu_sel].handler) {
            menu_form[menu_sel].handler(key);
        } else {
            menu_root(0);
        }
    }
}
