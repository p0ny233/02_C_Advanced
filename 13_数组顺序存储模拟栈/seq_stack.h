#pragma once
/*
    栈的对外接口
        入栈
        出栈
        返回栈顶元素
        返回栈大小
        判断栈是否为空
        销毁栈
*/
#include <stdio.h>
#include <stdlib.h>  // 若没有包含头文件。程序可以生成exe，会警告没有 malloc函数库的定义。
#include <memory.h>
#define MAX 1024

struct Person
{
    char name[64];
    int age;
};

struct SStack
{
    void* data[MAX];
    int m_Size;    
};

typedef void* SeqStack;

// 初始化栈
void* init_SeqStack();


// 入栈
void push_SeqStack(SeqStack stack, void* data);

// 出栈
void pop_SeqStack(SeqStack stack);

// 返回栈顶元素
void* top_SeqStack(SeqStack stack);

// 返回栈大小
int size_SeqStack(SeqStack stack);

// 判断栈是否为空
int isEmpty_SeqStack(SeqStack stack);

// 销毁栈
void destory_SeqStack(SeqStack stack);
