#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hand.h"

int count;

DataType *_Change_A_L(PNode hand)
{
    int N = 0;
    PNode p = hand;
    PNode temp = hand->next;
    while (p->next != NULL)
    {
        N++;
        p = p->next;
    }
    count = N;
    DataType *array = (DataType *)malloc(N * sizeof(DataType));
    for (int i = 0; i < N; i++)
    {
        array[i] = temp->data;
        temp = temp->next;
    }
    return array;
}

PNode _Change_L_A(DataType array[])
{
    PNode hand = NULL;
    for (int i = 0; i < count; i++)
        PushBack(&hand, array[i]);
    return hand;
}

int comp(const void *a, const void *b)
{
    return (*(PNode)b).data.totalcount > (*(PNode)a).data.totalcount ? 1 : -1;
}

void QSort(PNode *hand)
{
    DataType *array = _Change_A_L(*hand);
    int size = count;
    qsort(array, size, sizeof(DataType), comp);
    DestroyList(&((*hand)->next));
    (*hand)->next = _Change_L_A(array);
    free(array);
}