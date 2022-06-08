
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
    // Testing memory
    init_memory();
    
    write_data(0x0000, 0xff);
    write_data(0xffff, 0xfd);
    
    printf("%x\n", read_data(0x0000));
    printf("%x\n", read_data(0xffff));
    printf("%x\n", read_data(0xfdfd));
    
    return 0;
} /* End of main */
