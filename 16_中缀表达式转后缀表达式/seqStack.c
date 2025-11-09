#include "seqStack.h"

int checkNull(void* p, char* msg)
{
    if(p == NULL)
    {
        perror(msg);
        exit(-1);
    }
}

void* init_seqStack()
{
    SeqStack stack = malloc(sizeof(struct seqStack));
    checkNull(stack, "malloc error");
    memset(stack, 0, sizeof(struct seqStack));
    return stack;
}

int len_seqStack(SeqStack stk)
{
    checkNull(stk, "stk is NULL");
    struct seqStack* stack = stk;
    return stack->m_size;   
}

void* top_seqStack(SeqStack stk)
{
    checkNull(stk, "stk is NULL");
    struct seqStack* stack = stk;
    if (stack->m_size > 0)
        return stack->addr[stack->m_size-1];
    return NULL;
}

void pop_seqStack(SeqStack stk)
{
    checkNull(stk, "stk is NULL");
    struct seqStack* stack = stk;
    stack->addr[stack->m_size - 1] = NULL;
    stack->m_size--;
}

void push_seqStack(SeqStack stk, void* data)
{
    checkNull(stk, "stk is NULL");
    checkNull(data, "data is NULL");

    struct seqStack* stack = stk;
    if(stack->m_size < SIZE - 1)
    {
        stack->addr[stack->m_size] = data;
        stack->m_size++;
    }
    else
    {
        perror("push error, is full");
    }
}

void free_seqStack(SeqStack stk)
{
    checkNull(stk, "stk is NULL");
    free(stk);
}
