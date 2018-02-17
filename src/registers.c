#include "registers.h"

eRegister registers[8] = { 0,0,0,0,0,0,0,0 };

eret 
lookup_register(eu32 offset, eRegisterSize size, eu8 *reg)
{

    eRegister e = registers[offset];
    switch (size)
    {
    case REGISTER_SIZE_8:
        reg[0] = e.reg8;
        reg[1] = offset & 0b100 ? 'h' : 'l';
        break;
    case REGISTER_SIZE_16:
        reg[0] = e.reg;
        if (offset & 0b100)
        {
            reg[1] = offset & 0b10 ? 'i' : 'p';
        }
        else
        {
            reg[1] = 'x';
        }
        break;
    case REGISTER_SIZE_32:
        reg[0] = 'e';
        reg[1] = e.reg;
        if (offset & 0b100)
        {
            reg[1] = offset & 0b10 ? 'i' : 'p';
        }
        else
        {
            reg[1] = 'x';
        }
        break;
    }

    return EE_OK;

}
