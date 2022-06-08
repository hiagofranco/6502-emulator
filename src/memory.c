
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include <stdio.h>
#include "../include/memory.h"

MEMORY ram;

/* Initialize memory with zeros */
void init_memory()
{
    int i;
    for (i = 0; i < MEM_CAP; i++)
        ram.space[i] = 0;

}

/* Write data to memory address */
void write_data(TWO_BYTES address, BYTE data)
{
    // Check if address is invalid
    if ( (address < 0) || (address > (MEM_CAP - 1)) )
        return;
    // Check if data is invalid
    else if ( (data < 0) || (data > 255) )
        return;
    else
        ram.space[address] = data;

}

/* Read data from memory */
BYTE read_data(TWO_BYTES address)
{
    // Return zero if address is invalid
    if ( (address < 0) || (address > (MEM_CAP - 1)) )
        return 0;
    else
        return ram.space[address];

}

/* Print all memory addresses */
void print_memory()
{
    printf("-------------\n");
    printf("RAM MEMORY DATA\n");
    printf("-------------\n");
    
    int i;
    for (i = 0; i < MEM_CAP; i++)
        printf("%.4x %.2x\n", i, ram.space[i]);
    printf("-------------\n");

}
