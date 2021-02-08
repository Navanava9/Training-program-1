#include <stdio.h>
#include <string.h>
#include <hand.h>

int fileread(void)
{
    FILE *user_login = fopen("user_login.txt", "r");
    if (user_login == NULL)
        return CANT_FIND_FILE;
        
}