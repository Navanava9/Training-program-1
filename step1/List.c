#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hand.h"

PNode CreatNode(DataType data)
{
    PNode p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
        return MALLOC_ERROR;
    p->next = NULL;
    p->data = data;
    return p;
}

void PushBack(PNode *Head, DataType data)
{
    PNode NewNode = NULL;
    PNode temp = *Head;
    NewNode = CreatNode(data);
    if (*Head == NULL)
        *Head = NewNode;
    else
    {
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
    }
}

void PopBack(PNode *Head)
{
    PNode temp = *Head;
    if (*Head == NULL)
    {
        printf("单链表为空!\n");
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free((*Head)->next);
        *Head = NULL;
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

void DestroyList(PNode *Head)
{
    PNode temp = *Head;
    PNode del = NULL;
    while (temp)
    {
        del = temp;
        temp = temp->next;
        free(del);
        del = NULL;
    }
    *Head = NULL;
}

void ListTraverse(PNode head)
{
    PNode p = head;
    while (p != NULL)
    {
        printf("Name:%s times:%d\n", p->data.name, p->data.totalcount);
        p = p->next;
    }
}

void CombineList(PNode *head)
{
    PNode p = *head, temp = *head;
    PNode a = NULL;
    while (p->next != NULL)
    {
        while (temp->next != NULL)
        {
            if (strcmp(temp->next, p) == 0)
            {
                a = temp->next;
                temp->next = temp->next->next;
                free(a);
                p->data.totalcount++;
            }
        }
        p = p->next;
    }
