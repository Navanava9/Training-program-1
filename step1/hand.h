#define LENGTH 30
#define CANT_FIND_FILE -1

typedef struct User
{
    char name[LENGTH]; //用户名
    int totalcount;    //登录次数
} DataType;

//链表的节点
typedef struct ListNode
{
    DataType data;
    struct ListNode *next;
} Node, *PNode; //封装链表节点和next指针