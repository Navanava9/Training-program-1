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

void QuickSort(PNode hand, PNode tail)
{
    if (hand == tail || hand == NULL || hand == tail->next)
        return;
    PNode p, q, pre;
    p = q = pre = hand;
    while (q != tail)
    {
        q = q->next;
        if (q->data.totalcount < hand->data.totalcount)
        {
            pre = p;
            p = p->next;
            swap(p, q);
        }
    }
    swap(hand, p);
    QuickSort(hand, pre);
    QuickSort(p->next, tail);
}