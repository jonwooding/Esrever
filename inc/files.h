#include "types.h"

#ifndef FILES_H
#define FILES_H

#define E_FILE_RDONLY       "r"
#define E_FILE_PAGE_SIZE    4096 

es32
e_fileOpenAndRead(es8 *fName, eu8 *pMem);

eret
e_fileProcess(eFileStructure *fStructure, eu8 *pMem);

#endif
