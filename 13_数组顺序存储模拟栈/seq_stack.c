#include "seq_stack.h"


// 初始化栈
void* init_SeqStack()
{
    struct SStack * stack = malloc(sizeof(struct SStack));
    if(stack == NULL)
    {
        perror("init error");
        return NULL;
    }
    memset(stack->data, 0, MAX);
    stack->m_Size = 0;

    return stack;
}

// 入栈
void push_SeqStack(SeqStack stack, void* data)
{
    if(stack == NULL)
    {
        perror("stack is NULL");
        return;
    }
    if(data == NULL)
    {
        perror("data is NULL");
        return;
    }

    struct SStack* mystack = stack;

    // 判断 栈是否能够 压入
    if(mystack->m_Size >= MAX)
    {
        perror("stack is full");
        return;
    }
    
    // 压入数据，首地址为栈底，进行尾插
    mystack->data[mystack->m_Size] = data;

    // 更新栈大小
    mystack->m_Size++;
}

// 出栈
void pop_SeqStack(SeqStack stack)
{
    if(stack == NULL)
    {
        perror("stack is NULL");
        return;
    }
    
    struct SStack* mystack = stack;
    // 判断栈内是否为空
    if(mystack->m_Size <= 0)
    {
        perror("stack is empty");
        return;
    }

    // 抹掉尾元素，为什么 中括号内部是这个？可以假设个数为 1的时候，有一个元素，m_Size为1，要抹掉这个元素，应该 -1
    mystack->data[mystack->m_Size - 1] = NULL;

    // 更新栈大小
    mystack->m_Size--;
}

// 返回栈顶元素
void* top_SeqStack(SeqStack stack)
{
    if(stack == NULL)
    {
        perror("stack is null");
        return NULL;
    }

    struct SStack* mystack = stack;
    if(mystack->m_Size <= 0)
    {
        perror("stack is empty");
        return NULL;
    }

    return mystack->data[mystack->m_Size-1];
}

// 返回栈大小
int size_SeqStack(SeqStack stack)
{
    if(stack == NULL)
    {
        perror("stack is null");
        return -1;
    }

    struct SStack* mystack = stack;
    return mystack->m_Size;
}

// 判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{
    if(stack == NULL)
    {
        perror("stack is null");
        return 0;  // 无效的stack，也是为空
    }
    struct SStack* mystack = stack;
    return mystack->m_Size == 0;
}

// 销毁栈
void destory_SeqStack(SeqStack stack)
{
    if(stack == NULL)
    {
        perror("stack is null");
        return;
    }
    free(stack);
}
