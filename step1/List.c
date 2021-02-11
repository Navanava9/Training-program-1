#include <stdio.h>
#include <stdlib.h>
#include <hand.h>

//创建结点
PNode CreateNode(DataType data)
{
    PNode node = (PNode)malloc(sizeof(Node)); //申请内存
    node->data = data;
    node->next = NULL;
    return node;
}
