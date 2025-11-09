#include "linklist.h"


// 1 测试 初始化功能
void test_init_LinkList()
{
    printf("%s\n", __func__);

    struct LinkNode* list = init_LinkList();

    destroy_LinkList(list);
}

// 2 测试 清空链表功能
void test_clear_LinkList()
{
    printf("%s\n", __func__);
    struct LinkNode* list = init_LinkList();
    clear_LinkList(list);
    printf("%s 之后的节点数量: %d\n", __func__, list->num);
    destroy_LinkList(list);

}

// 3. 测试 插入节点功能
void test_insert_LinkList()
{
    printf("%s\n", __func__);
    struct LinkNode* list = init_LinkList();
    insert_LinkList(list, 5, 99);       // 表中存在元素5则在元素5中前 插入新的值 99，
    insert_LinkList(list, 666, 10000);  // 表中不存在 元素666，则将新的值 999 插入到末尾
    destroy_LinkList(list);
    printf("\n");
}


// 4. 测试 遍历链表 功能 
void test_foreach_LinkList(struct LinkNode* pHeader)
{
    printf("%s\n", __func__);

    foreach_LinkList(pHeader);
    destroy_LinkList(pHeader);

}

// 5. 测试 销毁链表 功能
void test_destroy_LinkList(struct LinkNode* pHeader)
{
    printf("%s\n", __func__);

    destroy_LinkList(pHeader);
}

// 6. 测试 删除节点 功能
void test_delete_Node()
{
    printf("%s\n", __func__);
    struct LinkNode *list = init_LinkList();
    delete_Node(list, 99);
    foreach_LinkList(list);
    destroy_LinkList(list);
}

// 7. 测试 反转链表 功能
void test_rever_LinkList()
{
    printf("%s\n", __func__);
    struct LinkNode* list = init_LinkList();
    foreach_LinkList(list);
    rever_LinkList(list);
    printf("\n");
    foreach_LinkList(list);
}


int main(void)
{

    // 1
    //test_init_LinkList();
    //// 2
    //struct Node* list = init_LinkList();
    //test_foreach_LinkList(list);
    //// 3
    //test_clear_LinkList();
    //// 4
    //test_insert_LinkList();
    //// 5
    //list = init_LinkList();
    //test_destroy_LinkList(list);
        
    // 6
    //test_delete_Node();

    // 7. 反转链表
    test_rever_LinkList();
    return 0;
}

