
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include <stdio.h>
#include "../include/memory.h"

/* Constructor: Initialize memory with zeros */
void memory_ctor(MEMORY *mem)
{
    int i;
    for (i = 0; i < MEM_CAP; i++) mem->space[i] = 0;
}

/* Public Methods */

void write_data(MEMORY *mem, TWO_BYTES address, BYTE data)
{
    if ( (address < 0) || (address > (MEM_CAP - 1)) )
        return;
    else if ( (data < 0) || (data > 255) )
        return;
    else
        mem->space[address] = data;
}

BYTE read_data(MEMORY *mem, TWO_BYTES address)
{
    if ( (address < 0) || (address > (MEM_CAP - 1)) )
        return 0;
    else
        return mem->space[address];
}

void print_memory(MEMORY *mem)
{
    printf("-------------\n");
    printf("RAM MEMORY DATA\n");
    printf("-------------\n");
    int i;
    for (i = 0; i < MEM_CAP - 6; i++)
    {
        printf("|%.4x %.2x ",  i,   mem->space[i]);
        printf("%.4x %.2x ",   i+1, mem->space[i+1]);
        printf("%.4x %.2x ",   i+2, mem->space[i+2]);
        printf("%.4x %.2x ",   i+3, mem->space[i+3]);
        printf("%.4x %.2x ",   i+4, mem->space[i+4]);
        printf("%.4x %.2x ",   i+5, mem->space[i+5]);
        printf("%.4x %.2x|\n", i+6, mem->space[i+6]);
    }
    printf("-------------\n");
}

/* Destructor: does nothing */
void memory_dtor(MEMORY *mem) { }
