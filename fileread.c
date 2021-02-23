#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char ch;
    int k = 0;
    PNode hand;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\code\\Training-program-1\\jkl.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        DataType a;
        while (ch != '\n')
        {
            ch = fgetc(user_login);
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                a.name[k] = ch;
                k++;
            }
        }
        a.totalcount = 1;
        k = 0;
        PushBack(&hand, a);
    }
    fclose(user_login);
    return hand;
}