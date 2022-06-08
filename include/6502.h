
/*
 * 6502 Processor Emulator
 * Author: Hiago De Franco
 * Date: june-05-2022
*/

#include "../include/memory.h"

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

/* Instruction Headers */
void ADC();
void AND();
void DEC(MEMORY *ram, TWO_BYTES address);
void DEX();
void DEY();
void INC(MEMORY *ram, TWO_BYTES address);
void INX();
void INY();
void JMP(TWO_BYTES address);
void LDA(MEMORY *ram, TWO_BYTES address);
void LDX(MEMORY *ram, TWO_BYTES address);
void LDY(MEMORY *ram, TWO_BYTES address);
void NOP();
void ORA(MEMORY *ram, TWO_BYTES address);
void STA(MEMORY *ram, TWO_BYTES address);
void STX(MEMORY *ram, TWO_BYTES address);
void STY(MEMORY *ram, TWO_BYTES address);
void STZ(MEMORY *ram, TWO_BYTES address);
void TSX();
void TXA();
void TXS();
void TYA();
