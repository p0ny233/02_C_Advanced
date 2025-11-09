#include "seqQueue.h"

void checkNull(void* ptr ,char* msg)
{
    if(ptr == NULL)
    {
        perror(msg);
        exit(-1);
    }
}

// 初始化队列
SeqQueue init_SeqQueue()
{
    // 使用动态数组
    SeqQueue queue = init_dynamicArray(MAX);
    checkNull(queue, "init_SeqQueue malloc error");

    return queue;
}

// 出队
void pop_SeqQueue(SeqQueue queue)
{
    // 头删，删除头部元素
    checkNull(queue, "pop_SeqQueue queue is null");

    // 如果空了就不删除元素
    struct dynamicArray* arr = queue;
    if(arr->m_Size == MAX)
        return;
    removeEleByPos_dynamicArray(queue, 0);
}

// 入队
void push_SeqQueue(SeqQueue queue, void* data)
{
    // 尾插，往尾部插入元素
    checkNull(queue, "push_SeqQueue queue is null");
    checkNull(data, "push_SeqQueue data is null");

    // 如果满了就不插入元素
    struct dynamicArray* arr = queue;
    if (arr->m_Size == MAX)
        return;
    insert_dynamicArray(queue, data, MAX+1);  // 直接尾插
}



// 返回队头元素
void* front_SeqQueue(SeqQueue queue)
{
    // 返回首部元素
    checkNull(queue, "front_SeqQueue queue is null");

    // 转换为真实结构
    struct dynamicArray* arr = queue;
    if (arr->m_Size > 0)
        return arr->pAddr[0];
    return NULL;
    
}

// 返回队尾元素
void* back_SeqQueue(SeqQueue queue)
{
    // 返回尾部元素
    checkNull(queue, "back_SeqQueue queue is null");

    // 转换为真实结构
    struct dynamicArray* arr = queue;
    if(arr->m_Size > 0)
        return arr->pAddr[arr->m_Size-1];
    return NULL;
}

// 返回队列元素个数
int size_SeqQueue(SeqQueue queue)
{
    checkNull(queue, "size_SeqQueue queue is null");

    // 转换为真实结构
    struct dynamicArray* arr = queue;

    return arr->m_Size;
}

// 返回队列是否为空
int isEmpty(SeqQueue queue)
{
    checkNull(queue, "isEmpty queue is null");

    // 转换为真实结构
    struct dynamicArray* arr = queue;

    return arr->m_Size == 0;
}

void destory(SeqQueue queue)
{
    checkNull(queue, "destory queue is null");
    destory_dynamicArray(queue);
}
