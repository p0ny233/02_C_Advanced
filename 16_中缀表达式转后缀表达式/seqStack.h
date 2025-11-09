#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

struct seqStack
{
    void* addr[SIZE];
    int m_size;
};

typedef void* SeqStack;

void* init_seqStack();

int len_seqStack(SeqStack stk);

void* top_seqStack(SeqStack stk);

void pop_seqStack(SeqStack stk);

void push_seqStack(SeqStack stk, void* data);
