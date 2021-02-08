#include <stdio.h>
#include <hand.h>

//创建结点
PNode CreateNode(DataType data)
{
    PNode node = (PNode)malloc(sizeof(Node)); //申请内存
    node->data = data;
    node->next = NULL;
    return node;
}

//创建链表
PNode CreatList()
{
    
}
