#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int filewrite(PNode hand)
{
    FILE *out;
    PNode temp = hand;
    out = fopen("result.txt", "w");
    if (out == NULL)
        return CREATE_FILE_ERROR;
    while (temp->next != NULL)
    {
        fwrite(temp->data.name, strlen(temp->data.name), 1, out);
        fwrite(',', sizeof(char), 1, out);
        fwrite(temp->data.totalcount, strlen(temp->data.totalcount), 1, out);
        fwrite('\n', sizeof(char), 1, out);
        temp = temp->next;
    }
    fclose(out);
}