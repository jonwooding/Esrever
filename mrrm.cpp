#include "mrrm.h"
#include "registers.h"
#include <assert.h>

/*
void
handle_mrrm(eu8 mrrm)
{
    eu8 mod = (mrrm & 0b11000000) >> 6;
    eu8 reg = lookup_register( (mrrm & 0b00111000) >> 3 );
    eu8 rm  = lookup_register( (mrrm & 0b00000111) );
    ebool sib = False;
    if (rm == SIB)
    {
        sib = True;
    }

    switch (mod)
    {
    case 0b00:
        // register indirect addressing mode
        // unless sib
        if (sib)
        {
            // ?
        }
        break;
    case 0b01:
        if (sib)
        {
            // size += 1 ?
        }
        // 1 byte displacement  
        break;
    case 0b10:
        // 4 byte displacement
        if (sib)
        {
            // size += 4 ?
        }
        break;
    case 0b11:
        // register mode
        break;
    default:
        // mod should never be anything other than two bits
        ebool e = false;
        assert(e);
        break;
    }

}
*/