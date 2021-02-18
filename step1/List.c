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
    PNode cur = *Head;
    NewNode = CreatNode(data);
    if (*Head == NULL)
        *Head = NewNode;
    else
    {
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = NewNode;
    }
}

void PopBack(PNode *Head)
{
    PNode cur = *Head;
    if (*Head == NULL)
    {
        printf("单链表为空，不能删除！！！\n");
        return;
    }
    else if ((*Head)->next == NULL)
    {
        free((*Head)->next);
        *Head = NULL;
    }
    else
    {
        while (cur->next->next != NULL)
        {
            cur = cur->next;
        }
        free(cur->next);
        cur->next = NULL;
    }
}

void DestroyList(PNode *Head)
{
    PNode cur = *Head;
    PNode del = NULL;
    while (cur)
    {
        del = cur;
        cur = cur->next;
        free(del);
        del = NULL;
    }
    *Head = NULL;
}

void link_print(PNode head)
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
    
}