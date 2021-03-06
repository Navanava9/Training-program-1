#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hand.h"

void swap(DataType *a, DataType *b)
{
    DataType tmp = *a;
    *a = *b;
    *b = tmp;
}
//定位
PNode partion(PNode begin, PNode end)
{
    if (begin == end || begin->next == end)
        return begin;
    int key = begin->data.totalcount;
    PNode p = begin;
    PNode q = begin;
    while (q != end)
    {
        if (q->data.totalcount > key)
        {
            p = p->next;
            swap(&p->data, &q->data);
        }
        q = q->next;
    }
    swap(&p->data, &begin->data);
    return p;
}
void quick_sort(PNode begin, PNode end)
{
    if (begin == end || begin->next == end)
        return;
    PNode mid = partion(begin, end);
    quick_sort(begin, mid);
    quick_sort(mid->next, end);
}

void QuickSort(PNode *hand)
{
    PNode begin, end, temp;
    begin = temp = *hand;
    while (temp->next != NULL)
        temp = temp->next;
    end = temp;
    quick_sort(begin, end->next);
}