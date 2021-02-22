#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int filewrite(PNode hand)
{
    FILE *out;
    PNode temp = hand;
    char c[LENGTH];
    out = fopen("result.txt", "w+");
    if (out == NULL)
        return CREATE_FILE_ERROR;
    while (temp->next != NULL)
    {
        fwrite(temp->data.name, strlen(temp->data.name), 1, out);
        fputc(',', out);
        itoa(temp->data.totalcount, c, 10);
        fwrite(c, strlen(c), 1, out);
        fputc('\n', out);
        temp = temp->next;
    }
    fclose(out);
    return OK;
}