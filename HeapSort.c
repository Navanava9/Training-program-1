#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "hand.h"

int count;

DataType *Change_A_L(PNode hand)
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

PNode Change_L_A(DataType array[])
{
    PNode hand = NULL;
    for (int i = 0; i < count; i++)
        PushBack(&hand, array[i]);
    return hand;
}

void _swap(DataType array[], int x, int y)
{
    DataType key = array[x];
    array[x] = array[y];
    array[y] = key;
}

void Down(DataType array[], int i, int n)
{
    int child = 2 * i + 1;
    int key = array[i].totalcount;
    while (child < n)
    {
        if (child + 1 < n && array[child].totalcount > array[child + 1].totalcount)
            child++;
        if (key > array[child].totalcount)
        {
            _swap(array, i, child);
            i = child;
        }
        else
            break;
        child = child * 2 + 1;
    }
}

void BuildHeap(DataType array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Down(array, i, size);
}

void HeapSort(PNode *hand)
{
    //time_t star, end;
    //star = clock();
    DataType *array = Change_A_L(*hand);
    //end = clock();
    int size = count;
    BuildHeap(array, size);
    for (int i = size - 1; i > 0; i--)
    {
        _swap(array, 0, i);
        Down(array, 0, i);
    }
    DestroyList(&((*hand)->next));
    (*hand)->next = Change_L_A(array);
    free(array);
}