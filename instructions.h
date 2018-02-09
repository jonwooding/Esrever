#include "types.h"

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

eInstruction instructions[256] = {0};

instructions[0x00] =
{
    .inst = "add",
    .size = b,
    .mrrm = true,
};

instructions[0x01] =
{
    .inst = "add",
    .size = v,
    .mrrm = true,
};

instructions[0x02] =
{
    .inst = "add",
    .size = b,
    .mrrm = true,
};

instructions[0x03] =
{
    .inst = "add",
    .size = v,
    .mrrm = true,
};

instructions[0x04] =
{
    .inst = "add",
    .size = b,
    .mrrm = true,
};

instructions[0x05] =
{
    .inst = "add",
    .size = v,
    .mrrm = true,
};

instructions[0x06] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x07] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x08] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x09] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x0a] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x0b] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x0c] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x0d] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

instructions[0x0f] =
{
    .inst = NULL,
    .size = 0,
    .mrrm = false,
};

#endif
