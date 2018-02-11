#include "files.h"

#include <stdio.h>

es32
e_fileOpenAndRead(es8 *filename, eu8 *pMem)
{
    es32 filesize = E_FILE_PAGE_SIZE;

    pMem = (eu8*) calloc(sizeof(eu8) * filesize);
    eu8 *pByte = NULL;
    es32 bytes_read = 0;
    if (NULL == pMem)
    {
        printf("failed to allocate %d bytes of ram\n", filesize);
        return -1;
    }

    printf("opening %s\n", filename);
    FILE fd = fopen(filename, E_FILE_RDONLY);
    if (0 > fd)
    {
        printf("failed to open file: %s\n", filename);
        goto cleanup;
    }

    bytes_read += fread(pMem, sizeof(eu8), filesize, fd);
    while (bytes_read == filesize)
    {
        filesize += E_FILE_PAGE_SIZE;
        pMem = (eu8*) realloc((void*) pMem, filesize);
        if (NULL == pMem)
        {
            printf("failed to allocate %d bytes of ram\n", filesize);
            return -1;
        }
        pByte = pMem + bytes_read + 1; // @Check for off by one error 
        bytes_read += fread(pByte, E_FILE_PAGE_SIZE);
    }

    fclose(fd);
    
    return bytes_read;

cleanup:
    free(pMem);
    return -1;

}

eret
e_fileProcess(eFileStructure *fStructure, eu8 *pMem)
{
    // @Incomplete
    return EE_OK;

}
