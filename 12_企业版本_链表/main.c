#include "linklist.h"

/*
    1. 测试 init_LinkList
    2. 测试 insert_LinkList
    3. 测试 foreach_LinkList
*/
void test01(void)
{
    LinkList list = init_LinkList();

    struct Person p1 = { .node.next = NULL,.name = "天才1", .age = 18 };
    struct Person p2 = { .node.next = NULL,.name = "天才2", .age = 11 };
    struct Person p3 = { .node.next = NULL,.name = "天才3", .age = 10 };

    insert_LinkList(list, &p1, 1);
    insert_LinkList(list, &p2, 0);
    insert_LinkList(list, &p3, -1);
    // 天才2 天才1 天才3
    foreach_LinkList(list, printPerson);
}

/*
    1. 测试 init_LinkList
    2. 测试 insert_LinkList
    3. 测试 foreach_LinkList
    4. 测试 removeNodeByPos 根据位置删除节点
    5. 测试 removeNodeByVal 根据值删除节点
*/
void test02(void)
{
    LinkList list = init_LinkList();

    struct Person p1 = { .node.next = NULL,.name = "牛魔王", .age = 18 };
    struct Person p2 = { .node.next = NULL,.name = "武则天", .age = 11 };
    struct Person p3 = { .node.next = NULL,.name = "刘备", .age = 14 };
    struct Person p4 = { .node.next = NULL,.name = "霸王", .age = 13 };
    struct Person p5 = { .node.next = NULL,.name = "诸葛", .age = 10 };
    struct Person p6 = { .node.next = NULL,.name = "猴子", .age = 19 };

    insert_LinkList(list, &p1, 1);
    insert_LinkList(list, &p2, 0);
    insert_LinkList(list, &p3, 0);
    insert_LinkList(list, &p4, 1);
    insert_LinkList(list, &p5, 2);
    insert_LinkList(list, &p6, 99);

    // 刘备 霸王 诸葛 武则天 牛魔王 猴子
    foreach_LinkList(list, printPerson);

    printf("*********** 删除【位置0】后结果 ***********\n");
    removeNodeByPos(list, 0);
    foreach_LinkList(list, printPerson);// 霸王 诸葛 武则天 牛魔王 猴子
    
    printf("*********** 删除【位置-1】后结果 ***********\n");
    removeNodeByPos(list, -1);
    foreach_LinkList(list, printPerson);// 霸王 诸葛 武则天 牛魔王 猴子

    printf("*********** 删除【位置为末尾元素】后结果 ***********\n");
    removeNodeByPos(list, 4);
    foreach_LinkList(list, printPerson);// 霸王 诸葛 武则天 牛魔王

    printf("*********** 删除【值为 武则天的元素】后结果 ***********\n");
    removeNodeByVal(list, &p2, ComparePerson);
    foreach_LinkList(list, printPerson);// 霸王 诸葛 牛魔王
    
    printf("*********** 清除节点 ***********\n");
    clear_LinkList(list);
    foreach_LinkList(list, printPerson);// 

    printf("*********** 销毁链表 ***********\n");
    destroy_LinkList(list);
}

int main(void)
{

    test01();
    printf("\n\n");
    test02();

    return 0;
}

/*

name: 天才2, age: 11
name: 天才1, age: 18
name: 天才3, age: 10


name: 刘备, age: 14
name: 霸王, age: 13
name: 诸葛, age: 10
name: 武则天, age: 11
name: 牛魔王, age: 18
name: 猴子, age: 19
*********** 删除【位置0】后结果 ***********
name: 霸王, age: 13
name: 诸葛, age: 10
name: 武则天, age: 11
name: 牛魔王, age: 18
name: 猴子, age: 19
*********** 删除【位置-1】后结果 ***********
remove error, pos is invalid: No error
name: 霸王, age: 13
name: 诸葛, age: 10
name: 武则天, age: 11
name: 牛魔王, age: 18
name: 猴子, age: 19
*********** 删除【位置为末尾元素】后结果 ***********
name: 霸王, age: 13
name: 诸葛, age: 10
name: 武则天, age: 11
name: 牛魔王, age: 18
*********** 删除【值为 武则天的元素】后结果 ***********
name: 霸王, age: 13
name: 诸葛, age: 10
name: 牛魔王, age: 18
*********** 清除节点 ***********
*********** 销毁链表 ***********

*/