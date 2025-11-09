#include "seq_stack.h"

void isNULL(struct SStack* ptr)
{
    if(ptr == NULL)
    {
        perror("is NULL\n");
        exit(-1);
    }
}

SStack* init_stack()
{
    SStack* addr = malloc(sizeof(struct Seq_Stack));
    isNULL(addr);
    memset(addr, 0, sizeof(struct Seq_Stack));
    return addr;
}


void push_Stack(struct SStack* stk, void* data)
{
    isNULL(stk);
    struct Seq_Stack* stack = (struct Seq_Stack*)stk;
    if (stack->length >= 1024)
        return;

    if (data == NULL)
        return;
    stack->array[stack->length] = data;
    stack->length++;
}

void* top_Stack(struct SStack* stk)
{
    isNULL(stk);
    struct Seq_Stack* stack = (struct Seq_Stack*)stk;
    return stack->array[stack->length-1];
}

void pop_Stack(struct SStack* stk)
{
    isNULL(stk);
    struct Seq_Stack* stack = (struct Seq_Stack*)stk;
    //free(stack->array[stack->length]);  // maybe error，because the addr may belong to stack region
    stack->length--;
}

int size_Stack(struct SStack* stk)
{
    if (stk == NULL)
        return 0;
    struct Seq_Stack* stack = (struct Seq_Stack*)stk;

    return stack->length;
}

void destroy_Stack(struct SStack* stk)
{
    if (stk != NULL)
        free(stk);
}