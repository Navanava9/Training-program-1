#define LENGTH 30
#define CANT_FIND_FILE -1
#define MALLOC_ERROR -2


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