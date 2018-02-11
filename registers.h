#include "types.h"

#ifndef REGISTERS_H
#define REGISTERS_H

eret 
lookup_register(eu32 offset, eRegisterSize size, eu8 *reg);

extern eRegister registers[8];
/*

registers[0].reg8 = 'a';
registers[0].reg  = 'a';
= 
{
    .reg8 = 'a',
    .reg  = 'a',
};

registers[1] = 
{
    .reg8 = 'c',
    .reg  = 'c',
};

registers[2] = 
{
    .reg8 = 'd',
    .reg  = 'd',
};

registers[3] = 
{
    .reg8 = 'b',
    .reg  = 'b',
};

registers[4] = 
{
    .reg8 = 'a',
    .reg  = 's',
};

registers[5] = 
{
    .reg8 = 'c',
    .reg  = 'b',
};

registers[6] = 
{
    .reg8 = 'd',
    .reg  = 's',
};

registers[7] = 
{
    .reg8 = 'b',
    .reg  = 'd',
};
*/

#endif
