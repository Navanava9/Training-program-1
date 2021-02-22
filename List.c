#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hand.h"

PNode CreateNode(DataType data)
{
    PNode p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        exit(1);
    p->next = NULL;
    p->data = data;
    return p;
}

void PushBack(PNode *hand, DataType data)
{
    PNode NewNode = NULL;
    PNode temp = *hand;
    NewNode = CreateNode(data);
    if (*hand == NULL)
        *hand = NewNode;
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}

void PopBack(PNode *hand)
{
    PNode temp = *hand;
    if (*hand == NULL)
    {
        printf("单链表为空!\n");
        return;
    }
    else if ((*hand)->next == NULL)
    {
        free((*hand)->next);
        *hand = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DestroyList(PNode *hand)
{
    PNode temp = *hand;
    PNode del = NULL;
    while (temp)
    {
        del = temp;
        temp = temp->next;
        free(del);
        del = NULL;
    }
    *hand = NULL;
}

void ListTraverse(PNode hand)
{
    PNode p = hand;
    while (p != NULL)
    {
        printf("Name:%s times:%d\n", p->data.name, p->data.totalcount);
        p = p->next;
    }
}

void CombineList(PNode *hand)
{
    PNode p = *hand, temp = *hand;
    PNode a = NULL;
    while (p->next != NULL)
    {
        while (temp->next != NULL)
        {
            if (strcmp(temp->next->data.name, p->data.name) == 0)
            {
                a = temp->next;
                temp->next = temp->next->next;
                free(a);
                p->data.totalcount++;
            }
            temp = temp->next;
        }
        p = p->next;
    }
}
