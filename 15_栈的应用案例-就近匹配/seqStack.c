#include "seqStack.h"

int isNULL(void* stk, char *msg)
{
    if(stk == NULL)
    {
        perror(msg);
        exit(-1);
    }
}

void* init_SeqStack()
{
    SeqStack stack = malloc(sizeof(struct seqStack));
    isNULL(stack, "malloc error");
    memset(stack, 0, sizeof(struct seqStack));

    return stack;
}

int len_SeqStack(SeqStack stk)
{
    isNULL(stk, "stk is null");
    struct seqStack* stack = stk;
    return stack->m_size;
}


void push_SeqStack(SeqStack stk, void* data)
{
    isNULL(stk, "stk is null");
    isNULL(data, "data is null");

    // 直接 起始地址 + m_size ??
    struct seqStack* stack = stk;
    *(stack->addr + stack->m_size) = data;
    stack->m_size++;
}


void pop_SeqStack(SeqStack stk)
{
    isNULL(stk, "stk is null");

    struct seqStack* stack = stk;
    if (!len_SeqStack(stk))
        return NULL;
    stack->m_size--;
    *(stack->addr + stack->m_size) = NULL;

}
void* top_SeqStack(SeqStack stk)
{
    void* ret = NULL;
    isNULL(stk, "stk is null");
    struct seqStack* stack = stk;
    if (len_SeqStack(stk) == 0)
        return NULL;
    return *(stack->addr + stack->m_size - 1);
}

void destroy_SeqStack(SeqStack stk)
{
    isNULL(stk, "malloc error");
    free(stk);
}
