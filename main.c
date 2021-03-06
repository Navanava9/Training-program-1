#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

int main(void)
{
    PNode hand;
    PNode p = (Node *)malloc(sizeof(Node));
    hand = fileread();
    hand = CombineList(&hand);
    p->next = hand;

    //BubbleSort(&p);
    QuickSort(&hand);
    //HeapSort(&p);

    filewrite(p->next);
    DestroyList(&p);
    return 0;
}