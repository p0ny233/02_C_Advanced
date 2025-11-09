#include "linkQueue.h"

void checkNull(void* ptr, char* msg)
{
    if(ptr == NULL)
    {
        perror(msg);
        exit(-1);
    }
}

// 初始化队列
LinkQueue init_LinkQueue()
{
    struct LQueue* myQueue = malloc(sizeof(struct LQueue));
    checkNull(myQueue, "malloc error");
    memset(myQueue, 0, sizeof(struct LQueue));
    
    return myQueue;
}

// 返回队头元素
void* front_LinkQueue(LinkQueue queue)
{
    checkNull(queue, "queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;

    if (myQ->m_Size)
        return myQ->pHeader.next;
    return NULL;
}

// 返回队尾元素
void* back_LinkQueue(LinkQueue queue)
{
    checkNull(queue, "queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;
    if(myQ->m_Size)
        return myQ->pTail;
    return NULL;
}

// 返回队列元素个数
int size_LinkQueue(LinkQueue queue)
{
    checkNull(queue, "queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;
    return myQ->m_Size;
}

// 返回队列是否为空
int isEmpty(LinkQueue queue)
{
    checkNull(queue, "queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;
    return myQ->m_Size == 0;
}

// 出队，头删
void pop_LinkQueue(LinkQueue queue)
{
    checkNull(queue, "pop_LinkQueue queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;
    if(myQ->m_Size)
    {
        struct LQueue* cur = myQ->pHeader.next->next;
        free(myQ->pHeader.next);
        myQ->pHeader.next = cur;
        myQ->m_Size--;
    }
}

// 入队, 尾插
void push_LinkQueue(LinkQueue queue, void* data)
{
    checkNull(queue, "push_LinkQueue queue is null");
    // 转换为真实的数据结构
    struct LQueue* myQ = queue;
    struct LinkNode* newNode = data;
    if (myQ->m_Size > 0)
        myQ->pTail->next = data;
    newNode->next = NULL;
    myQ->pTail = newNode;
    if(myQ->m_Size == 0)  // 注意这里，头节点需要指向第一个节点，头节点只维护 指针域，数据域不维护
        myQ->pHeader.next = myQ->pTail;
    myQ->m_Size++;
}

// 销毁队列
void destory(LinkQueue queue)
{
    // 转换为真实的结构
    struct LQueue* myQ = queue;

    if(size_LinkQueue(queue))
    {
        struct LinkNode* pre = myQ->pHeader.next;
        struct LinkNode* next = pre->next;
        while(next != NULL)
        {
            free(pre);
            pre = next;
            next = next->next;
            myQ->m_Size--;
        }
        free(pre);
    }
}
