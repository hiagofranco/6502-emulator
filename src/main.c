
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include <stdio.h>

#include "../include/6502.h"
#include "../include/memory.h"

/* Main Function */
int main()
{
    MEMORY ram;

    memory_ctor(&ram);
    
    write_data(&ram, 0x0000, 0xff);
    write_data(&ram, 0xffff, 0xfd);
    
    read_data(&ram, 0x0000);
    read_data(&ram, 0xffff);
    read_data(&ram, 0xfdfd);

    print_memory(&ram);

    memory_dtor(&ram);
    
    return 0;
} /* End of main */
