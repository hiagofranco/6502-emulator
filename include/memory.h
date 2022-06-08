
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#ifndef MEMORY_H
#define MEMORY_H

// 65536 bytes of addressable memory (16 bits)
#define MEM_CAP 65536

typedef unsigned char BYTE;
typedef unsigned short TWO_BYTES;

typedef struct {
    BYTE space[MEM_CAP];
} MEMORY;

// Initialize memory with zeros
void init_memory();

// Write data to memeory Address
void write_data(TWO_BYTES address, BYTE data);

// Read data from memory
BYTE read_data(TWO_BYTES address);

// Print all memory addresses
void print_memory();

#endif /* MEMORY_H */
