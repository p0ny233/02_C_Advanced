#include "seq_stack.h"

/*
    1. 初始化栈 init_SeqStack();
    2. 入栈 push_SeqStack(SeqStack stack, void* data);
    3. 出栈 pop_SeqStack(SeqStack stack);
    4. 返回栈顶元素 top_SeqStack(SeqStack stack);
    5. 返回栈大小 size_SeqStack(SeqStack stack);
    6. 判断栈是否为空 isEmpty_SeqStack(SeqStack stack);
    7. 销毁栈 destory_SeqStack(SeqStack stack);
*/
void test01()
{
    SeqStack stack = init_SeqStack();

    // 创建数据
    struct Person p1 = { .name = "牛魔王", .age = 18 };
    struct Person p2 = { .name = "武则天", .age = 11 };
    struct Person p3 = { .name = "刘备", .age = 14 };
    struct Person p4 = { .name = "霸王", .age = 13 };
    struct Person p5 = { .name = "诸葛", .age = 10 };
    struct Person p6 = { .name = "猴子", .age = 19 };

    // 压入数据
    push_SeqStack(stack, &p1);
    push_SeqStack(stack, &p2);
    push_SeqStack(stack, &p3);
    push_SeqStack(stack, &p4);
    push_SeqStack(stack, &p5);
    push_SeqStack(stack, &p6);

    printf("size of stack: %d\n", size_SeqStack(stack));

    while(!isEmpty_SeqStack(stack))
    {
        // 读取栈顶元素。然后再 pop
        struct Person* pTop = top_SeqStack(stack);
        printf("name: %s, age: %d\n", pTop->name, pTop->age);
        // pop
        pop_SeqStack(stack);
    }
    printf("size of stack: %d\n", size_SeqStack(stack));

    destory_SeqStack(stack);
}

int main(void)
{
    test01();
    return 0;
}

/*

    size of stack: 6
    name: 猴子, age: 19
    name: 诸葛, age: 10
    name: 霸王, age: 13
    name: 刘备, age: 14
    name: 武则天, age: 11
    name: 牛魔王, age: 18
    size of stack: 0

*/