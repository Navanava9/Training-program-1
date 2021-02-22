#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char ch;
    int k = 0;
    PNode hand;
    FILE *user_login = fopen("text.txt", "r+");
    if (user_login == NULL)
        exit(1);
    while (1)
    {
        DataType a;
        while (1)
        {
            ch = fgetc(user_login);
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                a.name[k] = ch;
                k++;
            }
            else if (ch == '\n')
            {
                a.totalcount = 1;
                break;
            }
        }
        k = 0;
        PushBack(&hand, a);
        if (feof(user_login))
            break;
    }
    fclose(user_login);
    return hand;
}