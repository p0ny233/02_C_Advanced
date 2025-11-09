#include "linkQueue.h"

struct Person
{   
    struct LinkNode* next;
    char name[64];
    int age;
};


int main(void)
{

    // 初始化队列
    LinkQueue linkQueue = init_LinkQueue();

    // 准备数据

    // 准备数据，底层封装的动态数组，释放元素的时候，用到free，因此不能传递栈上的地址
    struct Person p1 = { .name = "aaa", .age = 10 };
    struct Person* pp1 = malloc(sizeof(struct Person));
    memcpy(pp1, &p1, sizeof(struct Person));

    struct Person p2 = { .name = "bbb", .age = 20 };
    struct Person* pp2 = malloc(sizeof(struct Person));
    memcpy(pp2, &p2, sizeof(struct Person));

    struct Person p3 = { .name = "ccc", .age = 30 };
    struct Person* pp3 = malloc(sizeof(struct Person));
    memcpy(pp3, &p3, sizeof(struct Person));

    struct Person p4 = { .name = "ddd", .age = 40 };
    struct Person* pp4 = malloc(sizeof(struct Person));
    memcpy(pp4, &p4, sizeof(struct Person));

    struct Person p5 = { .name = "eee", .age = 50 };
    struct Person* pp5 = malloc(sizeof(struct Person));
    memcpy(pp5, &p5, sizeof(struct Person));

    // 入队
    push_LinkQueue(linkQueue, pp1);
    push_LinkQueue(linkQueue, pp2);
    push_LinkQueue(linkQueue, pp3);
    push_LinkQueue(linkQueue, pp4);
    push_LinkQueue(linkQueue, pp5);

    // 输出队列大小
    printf("队列大小: %d\n", size_LinkQueue(linkQueue));

    // 遍历
    while(size_LinkQueue(linkQueue))
    {
        // 返回队头元素
        struct Person* pPerson1 = front_LinkQueue(linkQueue);
        printf("队头元素 name: %s, age: %d\n", pPerson1->name, pPerson1->age);

        // 返回队尾元素
        struct Person* pPerson2 = back_LinkQueue(linkQueue);
        printf("队尾元素 name: %s, age: %d\n", pPerson2->name, pPerson2->age);

        pop_LinkQueue(linkQueue);
    }
    // 输出队列大小
    printf("队列大小: %d\n", size_LinkQueue(linkQueue));

    destory(linkQueue);

    return 0;
}
/*

队列大小: 5
队头元素 name: aaa, age: 10
队尾元素 name: eee, age: 50
队头元素 name: bbb, age: 20
队尾元素 name: eee, age: 50
队头元素 name: ccc, age: 30
队尾元素 name: eee, age: 50
队头元素 name: ddd, age: 40
队尾元素 name: eee, age: 50
队头元素 name: eee, age: 50
队尾元素 name: eee, age: 50
队列大小: 0

*/