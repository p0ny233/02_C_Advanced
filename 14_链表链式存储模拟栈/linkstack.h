#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LinkNode
{
    struct LinkNode* next;
};


struct LStack
{
    struct LinkNode pHeader;
    int m_Size;
};


struct Person
{
    struct LinkNode node;
    char name[64];
    int age;
};

typedef void* LinkStack;

// 1. 初始化栈
LinkStack init_LinkStack();

// 2. 入栈
void push_LinkStack(LinkStack sk, void* data);

// 3. 计算栈的大小
int sizeof_LinkStack();

// 4. 出栈
void pop_LinkStack(LinkStack sk);

// 5. 返回栈顶元素
void* top_LinkStack(LinkStack sk);

// 6. 判断栈是否为空
int isEmpty_LinkStack(LinkStack sk);

// 7. 销毁栈
void destroy_LinkStack(LinkStack sk);
