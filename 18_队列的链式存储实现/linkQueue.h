#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct LinkNode
{
    struct LinkNode* next;
};

struct LQueue
{
    struct LinkNode pHeader; // 头节点,记录第一个队尾元素，方便头插
    int m_Size;
    struct LinkNode* pTail; // 尾指针 记录最后一个队尾元素，方便尾插
};

#define MAX 1024  // 队列最大大小
typedef void* LinkQueue;

// 初始化队列
LinkQueue init_LinkQueue();

// 返回队头元素
void* front_LinkQueue(LinkQueue queue);

// 返回队尾元素
void* back_LinkQueue(LinkQueue queue);

// 返回队列元素个数
int size_LinkQueue(LinkQueue queue);

// 返回队列是否为空
int isEmpty(LinkQueue queue);

// 出队
void pop_LinkQueue(LinkQueue queue);

// 入队
void push_LinkQueue(LinkQueue queue, void*);

// 销毁队列
void destory(LinkQueue queue);
