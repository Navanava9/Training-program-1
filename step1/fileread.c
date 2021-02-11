#include <stdio.h>
#include <string.h>
#include <hand.h>

PNode CreateNode(DataType data);

int fileread(void)
{
    char ch;
    int k = 0;
    DataType a;
    FILE *user_login = fopen("text.txt", "r");
    if (user_login == NULL)
        return CANT_FIND_FILE;
    while (1)
    {
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
                PNode n = CreateNode(a);
                break;
            }
        }
        k = 0;
    }
}