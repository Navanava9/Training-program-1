#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    PNode p = hand;
    for (int i = 0; i < count; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = array[i];
        p = p->next;
    }
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
    int parent = i;
    int child = 2 * i + 1;
    while (child < n)
    {
        if (child + 1 < n && array[child].totalcount < array[child + 1].totalcount)
        {
            child++;
        }
        if (array[parent].totalcount < array[child].totalcount)
        {
            _swap(array, parent, child);
            parent = child;
        }
        child = child * 2 + 1;
    }
}

void BuildHeap(DataType array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Down(array, i, size);
    }
}

void HeapSort(PNode *hand)
{
    PNode p = *hand;
    DataType *array = Change_A_L(p);
    DestroyList(&((*hand)->next));
    int size = count;
    BuildHeap(array, size);
    for (int i = size - 1; i > 0; i--)
    {
        _swap(array, 0, i);
        Down(array, 0, i);
    }
    *hand = Change_L_A(array);

    free(array);
}