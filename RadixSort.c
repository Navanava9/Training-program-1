#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hand.h"

int SortNum(PNode hand)
{
    PNode p = hand;
    int x = 0, count = 0;
    for (; p != NULL; p = p->next)
        if (x < p->data.totalcount)
            x = p->data.totalcount;
    while (x)
    {
        x /= 10;
        count++;
    }
    return count;
}

int IsEmpty(PNode hand)
{
    return hand->next == NULL;
}

int IsLast(PNode hand)
{
    return hand->next == NULL;
}

void MoveNode(PNode L1, PNode L2)
{
    PNode temp;
    while (!IsLast(L1))
        L1 = L1->next;
    if (L2->next == NULL)
        exit(-1);
    temp = L2;
    L2 = L2->next;
    temp->next = L2->next;
    L1->next = L2;
    L2->next = NULL;
}

PNode Init_List(void)
{
    PNode p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        exit(0);
    p->next = NULL;
    return p;
}

void RadixSort(PNode hand)
{
    PNode b[10];
    int i, data, sum;
    for (i = 0; i < 10; i++)
    {
        b[i] = Init_List();
    }
    int num = SortNum(hand);
    for (i = 0; i < num; i++)
    {
        while (!IsEmpty(hand))
        {
            data = hand->next->data.totalcount;
            sum = (int)(data / pow(10, i)) % 10;
            MoveNode(b[sum], hand);
        }
        for (int j = 9; j >= 0; j--)
            while (!IsEmpty(b[j]))
                MoveNode(hand, b[j]);
    }
    for (int i = 0; i < 10; i++)
        free(b[i]);
}
