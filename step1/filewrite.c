#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int filewrite(void)
{
    FILE *out;
    out = fopen("result.txt", "w");
    if (out == NULL)
        return CREATE_FILE_ERROR;
    while (1)
    {
    }
    fclose(out);
}