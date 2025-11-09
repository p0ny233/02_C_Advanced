#include "单向链表_传统版本.h"

int main(void)
{
    LinkList list = init_linkList();

    struct Person p1 = {"关羽", 18};
    struct Person p2 = {"赵子龙", 11};
    struct Person p3 = {"钟馗", 12};
    struct Person p4 = {"金柯", 16};
    struct Person p5 = {"天才", 17};
    struct Person p6 = {"刘邦", 19};
    struct Person p7 = {"亚瑟", 22};

    insertNodeList(list, &p1, 11);
    insertNodeList(list, &p2, 1);
    insertNodeList(list, &p3, -1);
    insertNodeList(list, &p4, 1);
    insertNodeList(list, &p5, -1);
    insertNodeList(list, &p6, 99);
    insertNodeList(list, &p7, 1);
    

    for_eachLinkList(list, printPerson);//  关羽  亚瑟 金柯 赵子龙 钟馗 天才 刘邦
    printf("链表长度: %d\n", sizeof_linkList(list));


    // 按位置 来删除元素 
    printf("-----------------------------------------\n");
    removeNodeByPos(list, 1);
    printf("根据位置来删除元素：删除位置1\n");
    for_eachLinkList(list, printPerson);//  关羽 金柯 赵子龙 钟馗 天才 刘邦
    printf("链表长度: %d\n", sizeof_linkList(list));

    // 根据 值 删除元素， 删除 天才
    printf("-----------------------------------------\n");
    printf("按值 来删除元素：删除 天才\n");
    struct Person pp = { "天才", 17};
    removeNodeByVal(list, &pp, ComparePerson);
    for_eachLinkList(list, printPerson);//  关羽 金柯 赵子龙 钟馗 刘邦
    printf("链表长度: %d\n", sizeof_linkList(list));

    // 清空节点
    printf("-----------------------------------------\n");
    clear_linkList(list);
    for_eachLinkList(list, printPerson);
    printf("链表长度: %d\n", sizeof_linkList(list));

    // 销毁链表
    printf("-----------------------------------------\n");
    insertNodeList(list, &p3, -1);
    insertNodeList(list, &p4, 1);
    insertNodeList(list, &p5, -1);
    for_eachLinkList(list, printPerson);
    printf("链表长度: %d\n", sizeof_linkList(list));
    
    destroy_linkList(list);
    list = NULL;
    for_eachLinkList(list, printPerson);

    // list内存已经释放，但是 sizeof_linkList还能获取，只不过获取的是非法值，怎么判断这块内存是不可用，从而安全访问
    printf("链表长度: %d\n", sizeof_linkList(list));  // 目前只能注释

    return 0;
}

/*

name： 关羽, age：18
name： 亚瑟, age：22
name： 金柯, age：16
name： 赵子龙, age：11
name： 钟馗, age：12
name： 天才, age：17
name： 刘邦, age：19
链表长度: 7
-----------------------------------------
根据位置来删除元素：删除位置1
name： 关羽, age：18
name： 金柯, age：16
name： 赵子龙, age：11
name： 钟馗, age：12
name： 天才, age：17
name： 刘邦, age：19
链表长度: 6
-----------------------------------------
按值 来删除元素：删除 天才
name： 关羽, age：18
name： 金柯, age：16
name： 赵子龙, age：11
name： 钟馗, age：12
name： 刘邦, age：19
链表长度: 5
-----------------------------------------
链表长度: 0
-----------------------------------------
name： 钟馗, age：12
name： 金柯, age：16
name： 天才, age：17
链表长度: 3
error foreach, list is null: No error
list is null: No error
链表长度: -1

D:\cpp_code\bxg\02_C语言高级\x64\Debug\11_链表.exe (进程 13644)已退出，代码为 0。

*/