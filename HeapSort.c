#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

void swap(PNode p, PNode q)
{
    DataType temp = p->data;
    p->data = q->data;
    q->data = temp;
}

void Down(int array[], int i, int n)
{
    int parent = i;
    int child = 2 * i + 1;
    while (child < n)
    {
        if (child + 1 < n && array[child] < array[child + 1])
        {
            child++;
        }
        if (array[parent] < array[child])
        {
            swap();
            parent = child;
        }
        child = child * 2 + 1;
    }
}

void BuildHeap(int array[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Down(array, i, size);
    }
}

void HeapSort(int array[], int size)
{
}