
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

/* Includes */
#ifndef MEMORY_H
#define MEMORY_H

/* Defines */
#define MEM_CAP 65536 //65536 bytes of addressable memory (16 bits)

typedef unsigned char BYTE;
typedef unsigned short TWO_BYTES;

/* Variable */
typedef struct {
    BYTE space[MEM_CAP];
} MEMORY;

/* Methods */
void memory_ctor(MEMORY *mem);

void write_data(MEMORY *mem, TWO_BYTES address, BYTE data);

BYTE read_data(MEMORY *mem, TWO_BYTES address);

void print_memory(MEMORY *mem);

void memory_dtor(MEMORY *mem);

#endif /* MEMORY_H */
