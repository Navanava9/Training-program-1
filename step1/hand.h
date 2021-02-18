#define LENGTH 30
#define CANT_FIND_FILE -1
#define MALLOC_ERROR -2
#define CREATE_FILE_ERROR -3;

PNode CreateNode(DataType data);
void PushBack(PNode *Head, DataType data);
void PopBack(PNode *Head);
void DestroyList(PNode *Head);
void ListTraverse(PNode head);
void CombineList(PNode *head);

int fileread(void);
int filewrite(void);
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