#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"
#include <time.h>

int main(void)
{
    PNode hand;
    PNode p = (Node *)malloc(sizeof(Node));
    hand = fileread();
    hand = CombineList(&hand);
    p->next = hand;

    //CutHalf(&hand);
    //CutHalf(&hand);
    //CutHalf(&hand);

    //clock_t star, end;
    //star = clock();

    //BubbleSort(&p);
    //QuickSort(&hand);
    HeapSort(&p);
    //RadixSort(p);
    //QSort(&p);

    //end = clock();

    filewrite(p->next);
    DestroyList(&p);
    return 0;
}