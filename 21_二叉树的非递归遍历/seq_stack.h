#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

struct Seq_Stack
{
    int length;
    void* array[SIZE];
};

typedef void* SStack;

SStack* init_stack();
void push_Stack(struct SStack* stk, void* data);
void* top_Stack(struct SStack* stk);
void pop_Stack(struct SStack* stk);
int size_Stack(struct SStack* stk);
void destroy_Stack(struct SStack* stk);


