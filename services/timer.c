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

#include <sam3u4e.h>
#include <types.h>

#define TIMER_SLOTS 4

volatile struct _timer_slot {
    void (*cb)(uint32_t *);
    uint32_t at;
} timer_slots[TIMER_SLOTS] = {0, };

void rtt_handler(void) {
    if (!(RTT_SR & RTT_SR_RTTINC)) {
        return;
    }

    uint32_t vr;
    int8_t i;
    uint8_t future_event;

    // Get the current RTT value
    while (vr != RTT_VR) {
        vr = RTT_VR;
    }

    // Iterate through each timer slot
    future_event = 0;
    for (i = 0; i < TIMER_SLOTS; i++) {
        // Check for an elapsed time
        if (timer_slots[i].at <= vr) {
            // Invoke the handler
            uint32_t again = 0;
            void (*cb)(uint32_t *) = timer_slots[i].cb;
            if (cb) {
                cb(&again);
            }
            // Does it want to go again?
            if (again > 0) {
                timer_slots[i].at = vr + again;
                future_event = 1;
            } else {
                timer_slots[i].at = 0xFFFFFFFF;
                timer_slots[i].cb = 0;
            }
        } else if (timer_slots[i].cb) {
            future_event = 1;
        }
    }

    if (!future_event) {
        // Disable the interrupt
        RTT_MR &= ~(RTT_MR_RTTINCIEN);
    }
}

int8_t timer_set(void (*cb)(uint32_t *), uint32_t sec) {
    uint32_t at;
    int8_t i;

    // Calulate the time of the event
    while (at != RTT_VR) {
        at = RTT_VR;
    }
    at += sec;

    // Find an open slot and store the value
    for (i = 0; i < TIMER_SLOTS; i++) {
        if (timer_slots[i].cb == 0) {
            // Set the event details
            timer_slots[i].cb = cb;
            timer_slots[i].at = at;

            // Make sure the interrupt is enabled
            RTT_MR |= RTT_MR_RTTINCIEN;

            // Return the timer id to the caller
            return i;
        }
    }

    // Failed to find a slot
    return -1;
}

int8_t timer_del(int8_t id) {
    if (id < TIMER_SLOTS) {
        timer_slots[id].at = 0xFFFFFFFF;
        timer_slots[id].cb = 0;
        return 0;
    }
    return -1;
}

void timer_init(void) {
    // Enable the Peripheral Clock
    PMC_PCER = (1 << PMC_ID_RTT);

    // Reset the RTT for a Freq of 1Hz
    RTT_MR = RTT_MR_RTTRST | ((0x8000 << RTT_MR_RTPRES_Off) & RTT_MR_RTPRES_Msk);

    // Enable the RTT Interrupt in the NVIC
    ICER0 = (1 << PMC_ID_RTT); // Disable Interrupt
    ICPR0 = (1 << PMC_ID_RTT); // Clear Pending
    IPR(PMC_ID_RTT) = (IPR(PMC_ID_RTT) & ~(IPR_IP_Msk(PMC_ID_RTT))) | IPR_IP(PMC_ID_RTT, 0xF); // Set the Priority to 15
    ISER0 = (1 << PMC_ID_RTT); // Enable Interrupt
}
