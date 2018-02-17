#ifndef ABBREV_H
#define ABBREV_H
// 16  32  64
// AX EAX RAX

// Offset specs
// Base + (Index * Scale) + Displacement
// EAX      EAX     1           None
// EBX      EBX
// ECX      ECX     2           8-bit
// EDX      EDX
// ESP      ESP     4           16
// EBP      EBP
// ESI      ESI     8           32
// EDI      EDI

// ModR/M Byte
// 00       Mod
//   000    REG
//      000 RM

// REG high bit determins L vs H
// Mod lower 2 determines A/C/D/B
// (REG & 0x3) == 0 -> A
// (REG & 0x3) == 1 -> C
// (REG & 0x3) == 2 -> D
// (REG & 0x3) == 3 -> B

// RM byte map
// 000 [BX+SI]
// 001 [BX+DI]
// 010 [BP+SI]
// 011 [BP+SI]
// 100 [SI]
// 101 [DI]
// 110 [BP] // exception when mod == 00, disp16
// 111 [BX]


// reg map
// 000 a, a    *l, *x, e*x
// 001 c, c    *l, *x, e*x 
// 010 d, d    *l, *x, e*x
// 011 b, b    *l, *x, e*x
// 100 a, b    *h, *p, e*p
// 101 c, s    *h, *p, e*p
// 110 d, s    *h, *i, e*i
// 111 b, d    *h, *i, e*i

/*
mod rm addressing mode
00  000  [ eax ]
01  000  [ eax + disp8 ]  // points to +-127 offset from eax
10  000  [ eax + disp32 ] // points to +- 2^31 offset from eax
11  000  $eax 

when rm == 100 it implies SIB mode
00  100  SIB
01  100  SIB + disp8
10  100  SIB + disp32
11  100  $esp

00  101  32-bit displacement mode only

SIB mode
scale index base
  00   000   000
mod specified displacement

// handling SIB
scale = (SIB & 0b11000000) >> 6; 
index = lookup_register( (SIB & 0b00111000) >> 3 );
base  = lookup_register( (SIB & 0b00000111) );

if (base == EBP && mod == 0x00)
{
    set_displacement_only();
}

wherever sib belongs would be
[base + index*scale]

*/

// Mod determines displacement
// 00   none
// 01   disp8
// 10   disp16
// 11   **registers**

// Addressing Method
#define A   // Direct address: the instruction has no ModR/M byte; the address of the operand is encoded in the instruction. No base register, index register, or scaling factor can be applied (for example, far JMP (EA)).
#define B   // The VEX.vvvv field of the VEX prefix selects a general purpose register.
#define C   // The reg field of the ModR/M byte selects a control register (for example, MOV (0F20, 0F22)).
#define D   // The reg field of the ModR/M byte selects a debug register (for example, MOV (0F21,0F23)).
#define E   // A ModR/M byte follows the opcode and specifies the operand. The operand is either a general-purpose register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, a displacement.
#define F   // EFLAGS/RFLAGS Register.
#define G   // The reg field of the ModR/M byte selects a general register (for example, AX (000)).
#define H   // The VEX.vvvv field of the VEX prefix selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type. For legacy SSE encodings this operand does not exist, changing the instruction to destructive form.
#define I   // Immediate data: the operand value is encoded in subsequent bytes of the instruction.
#define J   // The instruction contains a relative offset to be added to the instruction pointer register (for example, JMP (0E9), LOOP).
#define L   // The upper 4 bits of the 8-bit immediate selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type. (the MSB is ignored in 32-bit mode)
#define M   // The ModR/M byte may refer only to memory (for example, BOUND, LES, LDS, LSS, LFS, LGS, CMPXCHG8B).
#define N   // The R/M field of the ModR/M byte selects a packed-quadword, MMX technology register.
#define O   // The instruction has no ModR/M byte. The offset of the operand is coded as a word or double word (depending on address size attribute) in the instruction. No base register, index register, or scaling factor can be applied (for example, MOV (A0 A3)).
#define P   // The reg field of the ModR/M byte selects a packed quadword MMX technology register.
#define Q   // A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement.
#define R   // The R/M field of the ModR/M byte may refer only to a general register (for example, MOV (0F20 0F23)).
#define S   // The reg field of the ModR/M byte selects a segment register (for example, MOV (8C,8E)).
#define U   // The R/M field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type.
#define V   // The reg field of the ModR/M byte selects a 128-bit XMM register or a 256-bit YMM register, determined by operand type.
#define W   // A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register, a 256-bit YMM register (determined by operand type), or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement.
#define X   // Memory addressed by the DS:rSI register pair (for example, MOVS, CMPS, OUTS, or LODS).
#define Y   // Memory addressed by the ES:rDI register pair (for example, MOVS, CMPS, INS, STOS, or SCAS). 

// Operand Type
#define a   // Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute (used only by the BOUND instruction).
#define b   // Byte, regardless of operand-size attribute.
#define c   // Byte or word, depending on operand-size attribute.
#define d   // Doubleword, regardless of operand-size attribute.
#define dq  // Double-quadword, regardless of operand-size attribute.
#define p   // 32-bit, 48-bit, or 80-bit pointer, depending on operand-size attribute.
#define pd  // 128-bit or 256-bit packed double-precision floating-point data.
#define pi  // Quadword MMX technology register (for example: mm0).
#define ps  // 128-bit or 256-bit packed single-precision floating-point data.
#define q   // Quadword, regardless of operand-size attribute.
#define qq  // Quad-Quadword (256-bits), regardless of operand-size attribute.
#define s   // 6-byte or 10-byte pseudo-descriptor.
#define sd  // Scalar element of a 128-bit double-precision floating data.
#define ss  // Scalar element of a 128-bit single-precision floating data.
#define si  // Doubleword integer register (for example: eax).
#define v   // Word, doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
#define w   // Word, regardless of operand-size attribute.
#define x   // dq or qq based on the operand-size attribute.
#define y   // Doubleword or quadword (in 64-bit mode), depending on operand-size attribute.
#define z   // Word for 16-bit operand-size or doubleword for 32 or 64-bit operand-size.


#endif
