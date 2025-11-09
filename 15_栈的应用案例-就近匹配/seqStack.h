#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct seqStack
{
    void* addr[1024];  // 这里定义指针数组，存储元素
    int m_size;
};

typedef void* SeqStack;

void* init_SeqStack();

int len_SeqStack(SeqStack stk);

void push_SeqStack(SeqStack, void*);
void pop_SeqStack(SeqStack stk);
void* top_SeqStack(SeqStack stk);
void destroy_SeqStack(SeqStack stk);
