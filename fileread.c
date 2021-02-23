#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

PNode fileread(void)
{
    char y;
    PNode hand = NULL;
    FILE *user_login = fopen("C:\\Users\\Administrator.DESKTOP-53KMUVB\\Desktop\\code\\Training-program-1\\user_login.txt", "r");
    if (user_login == NULL)
        exit(1);
    while (!feof(user_login))
    {
        int x = 0;
        DataType *a = (DataType *)malloc(sizeof(DataType));
        char *s = (char *)malloc(LENGTH * sizeof(char));
        fgets(s, LENGTH, user_login);
        while (1)
        {
            y = s[x];
            if (y == ',')
                break;
            a->name[x] = y;
            x++;
        }
        a->totalcount = 1;
        PushBack(&hand, *a);
        free(s);
        free(a);
    }
    fclose(user_login);
    return hand;
}