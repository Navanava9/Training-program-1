#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int main(void)
{
    PNode hand;
    hand = fileread();
    hand = CombineList(&hand);
    filewrite(hand);
    return 0;
}