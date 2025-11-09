#include "linklist.h"

// 初始化链表
struct LinkNode* init_LinkList()
{
    struct LinkNode* pHeader = NULL;
    pHeader = malloc(sizeof(struct LinkNode));  // 头节点，只维护 指针域
    if(pHeader == NULL)
    {
        perror("malloc:");
        return NULL;
    }
    pHeader->num = 0;
    pHeader->next = NULL;
    // 尾指针记录最后一个有效的节点
    struct LinkNode* pTail = pHeader;
    // 创建节点，模拟数据
    int val = -1;
    while(1)
    {
        printf("请输入数据\n");
        scanf("%d", &val);
        if(val == -1)
            break;

        // 创建新的节点
        struct LinkNode* new_node = malloc(sizeof(struct LinkNode));

        new_node->num = val;
        new_node->next = NULL;

        // 更新节点
        pTail->next = new_node;
        pTail = new_node;
        pHeader->num++;
    }
    return pHeader;
}


// 遍历链表
void foreach_LinkList(struct LinkNode* pHeader)
{
    if(pHeader == NULL)
    {
        perror("pHeader is NULL");
        return;
    }
    
    struct LinkNode *pCurr = pHeader->next;

    while(pCurr != NULL)
    {
        printf("%d, ", pCurr->num);
        pCurr = pCurr->next;
    }
}


// 销毁链表
void destroy_LinkList(struct LinkNode* pHeader)
{
    if (pHeader == NULL)
        return;
    struct LinkNode *pCurr = pHeader;
    struct LinkNode *next = NULL;
    int node_num = 0;
    do
    {
        next = pCurr->next;
        free(pCurr);
        node_num++;
        pCurr = next;
    }while (pCurr != NULL);
    if(node_num == (pHeader->num + 1))
    {
        perror("内存泄露");
        return;
    }
    printf("prefect free %d\n", node_num);
}

// 插入节点
// newVal插入到 oldVal 之前
void insert_LinkList(struct LinkNode *pHeader, int oldVal, int newVal)
{
    if(pHeader == NULL)
    {
        perror("insert: pHeader is NULL");
        return;
    }
    struct LinkNode *pre = pHeader;
    struct LinkNode *pCurrent = pHeader->next;
    while(pCurrent != NULL)
    {
        if(pCurrent->num == oldVal)
            break;

        // 两个辅助指针向后移动
        pre = pCurrent;
        pCurrent = pCurrent->next;
    }
    
    // 创建新的节点
    struct LinkNode *newNode= malloc(sizeof(struct LinkNode));
    if(newNode == NULL)
    {
        perror("malloc: insert element Faild");
        return;
    }
    newNode->num = newVal;
    newNode->next = NULL;

    // 插入新的节点
    newNode->next = pre->next;
    pre->next = newNode;
    pHeader->num++;
}

// 删除节点
void delete_Node(struct LinkNode* pHeader, int val)
{
    if (pHeader == NULL)
        return ;

    struct LinkNode* prevNode = pHeader;
    struct LinkNode* pCurrent = pHeader->next;

    while(pCurrent != NULL)
    {
        if (pCurrent->num == val)
            break;
        
        prevNode = pCurrent;
        pCurrent = pCurrent->next;
    }
    if(pCurrent != NULL)
    {
        prevNode->next = pCurrent->next;
        free(pCurrent);

        pHeader->num--;
    }
}

// 反转链表
void rever_LinkList(struct LinkNode* list)
{
    struct LinkNode* p1 = list->next;  // 指向第一个有效数据的节点
    struct LinkNode* p2 = p1->next;    // 指向第2个有效数据的节点
    struct LinkNode* p3 = NULL;
    p1->next = NULL;  // 第一个有效数据的节点的next指针域 指向NULL
    while(p2 != NULL)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    list->next = p1;
}

// 清空链表：只保留 pHeaer，其它节点释放内存
void clear_LinkList(struct LinkNode* pHeader)
{
    if (pHeader == NULL)
        return;
    
    struct LinkNode *node1 = pHeader;
    struct LinkNode *node2 = pHeader->next;

    while(node2 != NULL)
    {
        node1 = node2->next;
        free(node2);
        node2 = node1;
        pHeader->num--;
    }
    pHeader->next = NULL;

}
