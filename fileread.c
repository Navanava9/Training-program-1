#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char y;
    char *ch;
    PNode hand = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\code\\Training-program-1\\user_login.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        DataType a;
        int x = 0;
        ch = (char *)malloc(sizeof(char) * LENGTH);
        fgets(ch, LENGTH, user_login);
        while (1)
        {
            y = ch[x];
            if (y == ',')
                break;
            a.name[x] = y;
            x++;
        }
        a.totalcount = 1;
        PushBack(&hand, a);
        free(ch);
    }
    fclose(user_login);
    return hand;
}