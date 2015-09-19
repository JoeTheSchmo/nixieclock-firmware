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

// A non-maskable interrupt can be signalled by a peripheral or triggered by
// software. This is the highest priority exception other than reset. It is
// permanently enabled and has a fixed priority of -2.
void __attribute__((naked)) nmi_handler(void) {
    while(1) {}
}

// A hard fault is an exception that occurs because of an error during
// exception processing, or because an exception cannot be managed by any
// other exception mechanism. Hard faults have a fixed priority of -1,
// meaning they have higher priority than any exception with configurable
// priority.
void __attribute__((naked)) hardfault_handler(void) {
    while(1) {}
}

// A memory management fault is an exception that occurs because of a memory
// protection related fault. The MPU or the fixed memory protection
// constraints determines this fault, for both instruction and data memory
// transactions. This fault is used to abort instruction accesses to Execute
// Never (XN) memory regions, even if the MPU is disabled.
void __attribute__((naked)) memmanage_handler(void) {
    while(1) {}
}

// A bus fault is an exception that occurs because of a memory related fault
// for an instruction or data memory transaction. This might be from an error
// detected on a bus in the memory system.
void __attribute__((naked)) busfault_handler(void) {
    while(1) {}
}

// A usage fault is an exception that occurs because of a fault related to
// instruction execution. This includes:
//   - an undefined instruction
//   - an illegal unaligned access
//   - invalid state on instruction execution
//   - an error on exception return.
// The following can cause a usage fault when the core is configured to report
// them:
//   - an unaligned address on word and halfword memory access
//   - division by zero.
void __attribute__((naked)) usagefault_handler(void) {
    while(1) {}
}
