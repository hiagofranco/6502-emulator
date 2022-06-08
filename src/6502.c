
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include "../include/6502.h"
#include <memory.h>

P_6502 proc;

/* Initialize processor */
void init_proc()
{
    proc.REG_IR     = 0;
    proc.ACC        = 0;
    proc.REG_X      = 0;
    proc.REG_Y      = 0;
    proc.PC         = 0;
    proc.STACK_P    = 0;
    proc.ADDR_BUS   = 0;
}

void opcode_decode(MEMORY *ram, TWO_BYTES ram_address, BYTE opcode)
{
    switch (opcode)
    {

        case 0x6d:
            ADC();
            break;
        
        case 0x2d:
            AND();
            break;

        case 0xce:
            DEC(ram, ram_address);
            break;

        case 0xca:
            DEX();
            break;
        
        case 0x88:
            DEY();
            break;

        case 0xee:
            INC(ram, ram_address);
            break;

        case 0xe8:
            INX();
            break;
        
        case 0xc8:
            INY();
            break;
        
        default:
            NOP();
            break;
    }
}

/* Instructions */
void ADC()
{
    proc.ACC = (proc.REG_X + proc.REG_Y) & 0xff;
}

void AND()
{
    proc.ACC = (proc.REG_X & proc.REG_Y) & 0xff;
}

void DEC(MEMORY *ram, TWO_BYTES address)
{
    BYTE res = (ram->space[address] - 1) & 0xff;
    if ( res < 0 )
        ram->space[address] = 0x00;
    else
        ram->space[address] = res;
}

void DEX()
{
    BYTE res = (proc.REG_X - 1) & 0xff;
    if ( res < 0 )
        proc.REG_X = 0x00;
    else
        proc.REG_X = res;
}

void DEY()
{
    BYTE res = (proc.REG_Y - 1) & 0xff;
    if ( res < 0 )
        proc.REG_Y = 0x00;
    else
        proc.REG_Y = res;
}

void INC(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = (ram->space[address] + 1) & 0xff;
}

void INX()
{
    proc.REG_X = (proc.REG_X + 1) & 0xff;
}

void INY()
{
    proc.REG_Y = (proc.REG_Y + 1) & 0xff;
}

void JMP(TWO_BYTES address)
{
    proc.PC = address;
}

void LDA(MEMORY *ram, TWO_BYTES address)
{
    proc.ACC = ram->space[address];
}

void LDX(MEMORY *ram, TWO_BYTES address)
{
    proc.REG_X = ram->space[address];
}

void LDY(MEMORY *ram, TWO_BYTES address)
{
    proc.REG_Y = ram->space[address];
}

void NOP() {};

void ORA(MEMORY *ram, TWO_BYTES address)
{
    proc.ACC = (proc.ACC | ram->space[address]) & 0xff;
}

void STA(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc.ACC;
}

void STX(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc.REG_X;
}

void STY(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc.REG_Y;
}

void STZ(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = 0x00;
}

void TSX()
{
    proc.REG_X = proc.STACK_P;
}

void TXA()
{
    proc.ACC = proc.REG_X;
}

void TXS()
{
    proc.STACK_P = proc.REG_X;
}

void TYA()
{
    proc.ACC = proc.REG_Y;
}
