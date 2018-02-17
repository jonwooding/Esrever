#ifndef TYPES_H
#define TYPES_H

typedef unsigned char   eu8;
typedef char            es8;
typedef unsigned short  eu16; 
typedef short           es16;
typedef unsigned int    eu32;
typedef int             es32;
typedef enum { False=0, True } ebool;

// Global default operand-size attributes
// These can be modified by a prefix or by changing the
// D flag in the segment descriptor for the code segment
//eu8 b = 1;
//eu8 v = 4; 

// size prefix 0x66 operand 0x67 address

struct eListHead
{
    struct eListHead *next;
    struct eListHead *prev;
};
typedef struct eListHead eListHead;

typedef enum eret
{
    EE_OK = 0,
    EE_CRITICAL,
} eret;

typedef struct eRegister
{
    eu8     reg8;
    eu8     reg; 
} eRegister;

typedef enum eRegisterSize 
{
    REGISTER_SIZE_8 = 0,
    REGISTER_SIZE_16,
    REGISTER_SIZE_32,
} eRegisterSize;

typedef struct eInstruction
{
    eu8     inst[4]; 
    eu8     size;
    ebool   mrrm;
} eInstruction;

typedef struct eFileStructure
{
    // @Incomplete just a placeholder for now
    // will hold data about the executable's sections
    // ELF, PE, etc.
    eu8     *inst_start;
} eFileStructure;

typedef struct eStatement
{
    /**
    0x08000000 c4 ba 14 mov eax, 0x14
     **/
    eListHead   list;
    es8         *address;
    es8         *bytes;
    es8         *mnemonic;
    es8         *operands;
} eStatement;

typedef struct eState
{
    eListHead   statements;
} eState;

#endif
