#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"

#define MAX 1024  // 队列最大大小
typedef void* SeqQueue;

// 初始化队列
SeqQueue init_SeqQueue();

// 返回队头元素
void* front_SeqQueue(SeqQueue queue);

// 返回队尾元素
void* back_SeqQueue(SeqQueue queue);

// 返回队列元素个数
int size_SeqQueue(SeqQueue queue);

// 返回队列是否为空
int isEmpty(SeqQueue queue);

// 出队
void pop_SeqQueue(SeqQueue queue);

// 入队
void push_SeqQueue(SeqQueue queue, void*);

// 销毁队列
void destory(SeqQueue queue);

