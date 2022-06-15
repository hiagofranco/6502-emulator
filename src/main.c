
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include <stdio.h>
#include "6502.h"
#include "memory.h"

/* Main Function */
int main()
{
    MEMORY ram;

    memory_ctor(&ram);
    
    write_data(&ram, 0x0000, 0xFF);
    write_data(&ram, 0x0003, 0xFF);
    write_data(&ram, 0x0010, 0xFD);
    
    print_memory(&ram);

    memory_dtor(&ram);
    
    return 0;

} /* End of main */
