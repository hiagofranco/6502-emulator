
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#ifndef P6502_H
#define P6502_H

/* Includes */
#include "../include/memory.h"

/* Defines */
typedef unsigned char BYTE;
typedef unsigned short TWO_BYTES;

typedef struct {
    BYTE REG_IR;        // Instruction Register
    BYTE ACC;           // Accumulator
    BYTE REG_X;         // Registers X and Y 
    BYTE REG_Y;
    BYTE PC;            // Program counter low byte
    BYTE STACK_P;       // Stack Pointer
    BYTE DATA_BUS;      // Data Bus (Write or read memory)
    TWO_BYTES ADDR_BUS; // Memory Address
} P_6502;

/* Constructor */
void proc_ctor(P_6502 *proc);

/* Methods */
void opcode_decode(MEMORY *ram, TWO_BYTES ram_address, BYTE opcode);

/* Instruction Headers */
void ADC(P_6502 *proc);
void AND(P_6502 *proc);
void DEC(MEMORY *ram, TWO_BYTES address);
void DEX(P_6502 *proc);
void DEY(P_6502 *proc);
void INC(MEMORY *ram, TWO_BYTES address);
void INX(P_6502 *proc);
void INY(P_6502 *proc);
void JMP(P_6502 *proc, TWO_BYTES address);
void LDA(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void LDX(P_6502 *proc ,MEMORY *ram, TWO_BYTES address);
void LDY(P_6502 *proc ,MEMORY *ram, TWO_BYTES address);
void NOP();
void ORA(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void STA(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void STX(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void STY(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void STZ(P_6502 *proc, MEMORY *ram, TWO_BYTES address);
void TSX(P_6502 *proc);
void TXA(P_6502 *proc);
void TXS(P_6502 *proc);
void TYA(P_6502 *proc);

#endif /* P6502_H */
