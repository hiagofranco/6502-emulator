
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include <stdio.h>
#include "memory.h"

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
    else if ( (data < 0) || (data > 0xFF) )
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
    
    printf("Start -> | 0x0000 0x%.2X | 0x0001 0x%.2X | 0x0002 0x%.2X | 0x0003 0x%.2X |\n",  mem->space[0],
                                                                                            mem->space[1],
                                                                                            mem->space[2],
                                                                                            mem->space[3]);
    
    int i;
    char flag_print = 1; // Flag to check if * char was printed or not, this will
                         // print the whole memory in a better way.

    for (i = 4; i < MEM_CAP; i += 4)
    {
        if (mem->space[i] || mem->space[i+1] || mem->space[i+2] || mem->space[i+3])
        {
            printf("         | 0x%.4X 0x%.2X | 0x%.4X 0x%.2X | 0x%.4X 0x%.2X | 0x%.4X 0x%.2X |\n",  i,   mem->space[i],
                                                                                                    i+1, mem->space[i+1],
                                                                                                    i+2, mem->space[i+2],
                                                                                                    i+3, mem->space[i+3]);
            flag_print = 1;
        }
        else if (flag_print)
        {
            printf("         | *\n");
            flag_print = 0;
        }
    }
    printf("End   -> | 0xFFFC 0x%.2X | 0xFFFD 0x%.2X | 0xFFFE 0x%.2X | 0xFFFF 0x%.2X |\n",  mem->space[0xFFFC],
                                                                                            mem->space[0xFFFD],
                                                                                            mem->space[0xFFFE],
                                                                                            mem->space[0xFFFF]);
    printf("-------------\n");
}

/* Destructor: does nothing */
void memory_dtor(MEMORY *mem) { }
