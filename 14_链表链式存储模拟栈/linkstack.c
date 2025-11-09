#include "linkstack.h"

int isNULL(void* p, char* message)
{
    if(p == NULL)
    {
        perror(message);
        return 1;
    }
    return 0;
}

// 1. 初始化栈
LinkStack init_LinkStack()
{
    LinkStack stack = malloc(sizeof(struct LStack));
    if (isNULL(stack, "init malloc"))
        return NULL;
    memset(stack, 0, sizeof(struct LStack));

    return stack;

}

// 2. 入栈
void push_LinkStack(LinkStack sk, void* data)
{
    if(isNULL(sk, "LinkStack is null"))
        return NULL;

    if(isNULL(data, "data is null"))
        return NULL;

    struct LStack* stack = sk;
    struct LinkNode* pPrev = stack->pHeader.next;
    struct Person* p = data;
    if(pPrev != NULL)
    {
        p->node.next = pPrev;
    }
    stack->pHeader.next = data;


    stack->m_Size++;
}

// 3. 计算栈的大小
int sizeof_LinkStack(LinkStack sk)
{

    if(isNULL(sk, "stack is null"))
        return -1;

    struct LStack* stack = sk;
    return stack->m_Size;
}

// 4. 出栈
void pop_LinkStack(LinkStack sk)
{
    if(isNULL(sk, "stack is null"))
        return;
    
    struct LStack* stack = sk;
    struct Person* pPrev = stack->pHeader.next;
    stack->pHeader.next = pPrev->node.next;
    stack->m_Size--;

}

// 5. 返回栈顶元素
void* top_LinkStack(LinkStack sk)
{
    if(isNULL(sk, "sk is null"))
        return NULL;

    struct LStack* stack = sk;
    return stack->pHeader.next;
    
}

// 6. 判断栈是否为空
int isEmpty_LinkStack(LinkStack sk)
{
    if(isNULL(sk, "sk is null"))
        return NULL;

    struct LStack* stack = sk;
    return stack->m_Size == 0;
}

// 7. 销毁栈
void destroy_LinkStack(LinkStack sk)
{
    if(isNULL(sk, "sk is null"))
        return NULL;

    free(sk);
}
