#include "seqQueue.h"

// 测试队列
struct Person
{
    char name[64];
    int age;
};

int main(void)
{
    // 初始化队列
    SeqQueue queue = init_SeqQueue();
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
    push_SeqQueue(queue, pp1);
    push_SeqQueue(queue, pp2);
    push_SeqQueue(queue, pp3);
    push_SeqQueue(queue, pp4);
    push_SeqQueue(queue, pp5);

    // 输出队列大小
    printf("队列大小: %d\n", size_SeqQueue(queue));

    // 通过循环查看队列
    while(!isEmpty(queue))
    {
        // 取头部元素
        struct Person* pPerson1 = (struct Person*)front_SeqQueue(queue);
        printf("头部元素: name: %s, age %d\n", pPerson1->name, pPerson1->age);

        // 取尾部元素
        struct Person* pPerson2 = (struct Person*)back_SeqQueue(queue);
        printf("尾部元素: name: %s, age %d\n", pPerson2->name, pPerson2->age);

        // 出队 pop 的同时，会free掉内存
        pop_SeqQueue(queue);
    }
    // 输出队列大小
    printf("队列大小: %d\n", size_SeqQueue(queue));
    destory(queue);
    return 0;
}