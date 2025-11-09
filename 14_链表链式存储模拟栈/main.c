#include "linkstack.h"

int main(void)
{

    // 初始化stack
    LinkStack stack = init_LinkStack();

    // 创建数据
    struct Person p1 = {.node=NULL, .name="哪吒", .age = 1};
    struct Person p2 = {.node=NULL, .name="天才", .age = 2};
    struct Person p3 = {.node=NULL, .name="王强", .age = 3};
    struct Person p4 = {.node=NULL, .name="刘备", .age = 4};
    struct Person p5 = {.node=NULL, .name="猴子", .age = 5};
    struct Person p6 = {.node=NULL, .name="诸葛亮", .age = 6};

    // 压入数据
    push_LinkStack(stack, &p1);
    push_LinkStack(stack, &p2);
    push_LinkStack(stack, &p3);
    push_LinkStack(stack, &p4);
    push_LinkStack(stack, &p5);
    push_LinkStack(stack, &p6);

    while(!isEmpty_LinkStack(stack))
    {
        struct Person* person = top_LinkStack(stack);
        printf("name: %s, age: %d\n", person->name, person->age);
        pop_LinkStack(stack);
    }
    

    destroy_LinkStack(stack);
    return 0;
}

/*

name: 诸葛亮, age: 6
name: 猴子, age: 5
name: 刘备, age: 4
name: 王强, age: 3
name: 天才, age: 2
name: 哪吒, age: 1


*/