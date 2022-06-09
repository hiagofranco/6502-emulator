
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include "../include/6502.h"
#include "../include/memory.h"
#include "../include/opcodes.h"

/* Initialize processor */
void proc_ctor(P_6502 *proc)
{
    proc->REG_IR     = 0;
    proc->ACC        = 0;
    proc->REG_X      = 0;
    proc->REG_Y      = 0;
    proc->PC         = 0;
    proc->STACK_P    = 0;
    proc->ADDR_BUS   = 0;
}

/* Methods */
void opcode_decode(P_6502 *proc, MEMORY *ram, TWO_BYTES ram_address, BYTE opcode)
{
    switch (opcode)
    {

        case OPCODE_ADC:
            ADC(proc);
            break;
        
        case OPCODE_AND:
            AND(proc);
            break;

        case OPCODE_DEC:
            DEC(ram, ram_address);
            break;

        case OPCODE_DEX:
            DEX(proc);
            break;
        
        case OPCODE_DEY:
            DEY(proc);
            break;

        case OPCODE_INC:
            INC(ram, ram_address);
            break;

        case OPCODE_INX:
            INX(proc);
            break;
        
        case OPCODE_INY:
            INY(proc);
            break;

        case OPCODE_NOP:
            NOP(proc);
            break;
        
        default:
            NOP(proc);
            break;
    }
}

/* Instructions */
void ADC(P_6502 *proc)
{
    proc->ACC = (proc->REG_X + proc->REG_Y) & 0xFF;
}

void AND(P_6502 *proc)
{
    proc->ACC = (proc->REG_X & proc->REG_Y) & 0xFF;
}

void DEC(MEMORY *ram, TWO_BYTES address)
{
    BYTE res = (ram->space[address] - 1) & 0xFF;
    if ( res < 0 )
        ram->space[address] = 0x00;
    else
        ram->space[address] = res;
}

void DEX(P_6502 *proc)
{
    BYTE res = (proc->REG_X - 1) & 0xFF;
    if ( res < 0 )
        proc->REG_X = 0x00;
    else
        proc->REG_X = res;
}

void DEY(P_6502 *proc)
{
    BYTE res = (proc->REG_Y - 1) & 0xFF;
    if ( res < 0 )
        proc->REG_Y = 0x00;
    else
        proc->REG_Y = res;
}

void INC(MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = (ram->space[address] + 1) & 0xFF;
}

void INX(P_6502 *proc)
{
    proc->REG_X = (proc->REG_X + 1) & 0xFF;
}

void INY(P_6502 *proc)
{
    proc->REG_Y = (proc->REG_Y + 1) & 0xFF;
}

void JMP(P_6502 *proc, TWO_BYTES address)
{
    proc->PC = address;
}

void LDA(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    proc->ACC = ram->space[address];
}

void LDX(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    proc->REG_X = ram->space[address];
}

void LDY(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    proc->REG_Y = ram->space[address];
}

void NOP() {};

void ORA(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    proc->ACC = (proc->ACC | ram->space[address]) & 0xFF;
}

void STA(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc->ACC;
}

void STX(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc->REG_X;
}

void STY(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = proc->REG_Y;
}

void STZ(P_6502 *proc, MEMORY *ram, TWO_BYTES address)
{
    ram->space[address] = 0x00;
}

void TSX(P_6502 *proc)
{
    proc->REG_X = proc->STACK_P;
}

void TXA(P_6502 *proc)
{
    proc->ACC = proc->REG_X;
}

void TXS(P_6502 *proc)
{
    proc->STACK_P = proc->REG_X;
}

void TYA(P_6502 *proc)
{
    proc->ACC = proc->REG_Y;
}
