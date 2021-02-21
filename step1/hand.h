#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 30
#define CANT_FIND_FILE -1
#define MALLOC_ERROR -2
#define CREATE_FILE_ERROR -3;

typedef struct User
{
    char name[LENGTH];
    int totalcount;
} DataType;

//链表的节点
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
} Node, *PNode;

PNode CreateNode(DataType data);
void PushBack(PNode *hand, DataType data);
void PopBack(PNode *hand);
void DestroyList(PNode *hand);
void ListTraverse(PNode hand);
void CombineList(PNode *hand);

int fileread(void);
int filewrite(PNode hand);