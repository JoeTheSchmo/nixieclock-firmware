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

#include <types.h>

// svcall wrapper for _internal_twi_write
int32_t __attribute__((naked)) _svcall_twi_write(uint8_t code, uint32_t a0, uint32_t a1, uint32_t a2) {
    asm volatile (
        "mov r0, r1"    "\n\t"  // move a0 to caddr
        "mov r1, r2"    "\n\t"  // move a1 to raddr
        "mov r2, r3"    "\n\t"  // move a2 to dptr
        "mov r3, r0"    "\n\t"  // move a0 to dlen
        // r4 is already saved by svcall_handler
        "mov r4, #0xFF" "\n\t"  // create mask 0xFF
        "lsr r0, #0x10" "\n\t"  // move 23:16 from a0 to 7:0
        "and r0, r4"    "\n\t"  // apply mask to a0 to get caddr
        "lsl r4, #8"    "\n\t"  // create mask 0xFF00
        "orr r4, #0xFF" "\n\t"  // creaet mask 0xFFFF
        "and r3, r4"    "\n\t"  // apply mask to a0 to get 
        "b _internal_twi_write" // call twi_master_write(r0, r1, r2, r3)
    );
}

// svcall wrapper for _internal_twi_read
int32_t __attribute__((naked)) _svcall_twi_read(uint8_t code, uint32_t a0, uint32_t a1, uint32_t a2) {
    asm volatile (
        "mov r0, r1"    "\n\t"  // move a0 to caddr
        "mov r1, r2"    "\n\t"  // move a1 to raddr
        "mov r2, r3"    "\n\t"  // move a2 to dptr
        "mov r3, r0"    "\n\t"  // move a0 to dlen
        // r4 is already saved by svcall_handler
        "mov r4, #0xFF" "\n\t"  // create mask 0xFF
        "lsr r0, #0x10" "\n\t"  // move 23:16 from a0 to 7:0
        "and r0, r4"    "\n\t"  // apply mask to a0 to get caddr
        "lsl r4, #8"    "\n\t"  // create mask 0xFF00
        "orr r4, #0xFF" "\n\t"  // creaet mask 0xFFFF
        "and r3, r4"    "\n\t"  // apply mask to a0 to get 
        "b _internal_twi_read" // call twi_master_read(r0, r1, r2, r3)
    );
}

// vector table for the svcall interrupt handler
typedef int32_t (*svcall_t)(uint8_t, uint32_t, uint32_t, uint32_t);
const svcall_t svcall_vectors[256] __attribute__ ((section(".rodata"))) = {
    _svcall_twi_write,
    _svcall_twi_read,
    0
};

// dispatch the software interrupt
void __attribute__((naked)) svcall_handler(void) {
    // restore the code from the stack
    // they may already be there, but if a late arriving interrupt
    // was processed in-between the svc instruction and this handler
    // being executed then the contents are unpredictable
    asm volatile (
        "ldr r0, [sp, #0x00]" "\n\t"
        "ldr r1, [sp, #0x04]" "\n\t"
        "ldr r2, [sp, #0x08]" "\n\t"
        "ldr r3, [sp, #0x0C]"
    );

    // sanity, code should only ever be between 0 - 255
    asm volatile ("and r0, r0, #0xFF");

    // now that we've finished restoring the stack to registers
    // save the link register on the stack for when we are done
    // also save r4 which will be clobbered
    asm volatile ("push {r4, lr}");

    // calculate the offset in the vector table and branch to the address
    // stored in the vector table if its not 0. if it is zero, set the
    // return value to -1 and continue
    asm volatile (
        "ldr r4, =svcall_vectors" "\n\t"
        "ldr r4, [r4, r0, LSL 2]" "\n\t"
        "cmp r4, #0x00000000" "\n\t"
        "ite eq" "\n\t"
        "moveq r0, #0xFFFFFFFF" "\n\t"
        "blxne r4"
    );

    // we returned from the vector handler, write the return value into the
    // copy of r0 on the stack so it is popped into r0 when svcall() ends
    asm volatile ("str r0, [sp, #0x08]");

    // return to the source
    asm volatile ("pop {r4, pc}");
}

// generate a software interrupt
int32_t __attribute__((naked)) svcall(uint8_t code, uint32_t a0, uint32_t a1, uint32_t a2) {
    // branch to exception handler (software interrupt)
    asm volatile ("svc 0x00");

    // return to caller
    asm volatile ("bx lr");
}
