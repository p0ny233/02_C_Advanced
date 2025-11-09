#include <stdio.h>
#include <stdlib.h>

struct LinkNode
{
    int num;
    struct LinkNode* next;
};

// 静态链表
void test01()
{
    // 1. 创建节点
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};
    struct LinkNode node5 = {50, NULL};

    // 2. 建立节点之间的关系
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    // 3. 遍历节点
    struct LinkNode *pCurr = &node1;
    while(pCurr != NULL)
    {
        printf("%d\n", pCurr->num);
        pCurr = pCurr->next;
    }
}


// 动态链表
void test02()
{
    // 1. 创建节点
    struct LinkNode * node1 = malloc(sizeof(struct LinkNode));
    struct LinkNode * node2 = malloc(sizeof(struct LinkNode));
    struct LinkNode * node3 = malloc(sizeof(struct LinkNode));
    struct LinkNode * node4 = malloc(sizeof(struct LinkNode));
    struct LinkNode * node5 = malloc(sizeof(struct LinkNode));

    // 2. 给节点赋值
    node1->num = 10;
    node2->num = 20;
    node3->num = 30;
    node4->num = 40;
    node5->num = 50;

    // 3. 建立节点关系
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    // 4. 遍历节点
    struct LinkNode * pCurr = node1;
    while(pCurr != NULL)
    {
        printf("%d\n", pCurr->num);
        pCurr = pCurr->next;
    }

    
    // 5. 释放内存
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
}


int main(void)
{

    test01();
    printf("\n");
    test02();
    return 0;
}