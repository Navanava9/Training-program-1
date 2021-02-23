#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char ch[LENGTH];
    char y;
    PNode hand = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\code\\Training-program-1\\jkl.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        DataType a;
        int x = 0;
        fgets(ch, 100, user_login);
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
    }
    fclose(user_login);
    return hand;
}