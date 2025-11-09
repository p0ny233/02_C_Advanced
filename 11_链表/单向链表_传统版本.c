#include "单向链表_传统版本.h"

// 作为回调函数, 输出Person
void printPerson(void* data)
{
    if(data == NULL)
    {
        perror("error, data is null");
        return;
    }

    struct Person* p = data;
    printf("name： %s, age：%d\n", p->name, p->age);

}

// 初始化链表
LinkList init_linkList()
{
    // 创建链表
    struct LList* list = malloc(sizeof(struct LList));
    if (list == NULL)
        return NULL;
    memset(list, 0, sizeof(struct LList));

    return list;
}

// 根据位置 插入链表节点
void insertNodeList(LinkList list, void* data, int pos)
{
    if(list == NULL || data == NULL)
    {
        perror("list is null or data is null");
        return;
    }
    
    // 将list转换为 真实的链表结构体
    struct LList* llist = list;


    // 若提供的位置无效，全部进行尾插
    if(pos < 0 || pos > llist->m_Size)
    {
        pos = llist->m_Size;
    }

    // 创建辅助指针，移动到 指定位置的前驱节点
    struct LinkNode* pCurrent = &llist->pHeader;

    for(int i = 0; i < pos; i++)
        pCurrent = pCurrent->next;  // 循环完成后，pCurrent 最终指向目标位置的前驱节点
    
    // 创建新的节点
    struct LinkNode* newNode = malloc(sizeof(struct LinkNode));
    if (newNode == NULL)
        return;
    newNode->data = data;
    newNode->next = NULL;

    // 建立节点之间关系
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;
    
    // 更新链表的长度
    llist->m_Size++;
}

// 遍历链表
void for_eachLinkList(LinkList list, void(*PrintCallBack)(void*))
{
    if(list == NULL)
    {
        perror("error foreach, list is null");
        return;
    }
    struct LList* mylist = list;
    
    struct LinkNode* pCurrent = mylist->pHeader.next;

    for(int i = 0; i < mylist->m_Size; i++)
    {
        PrintCallBack(pCurrent->data);
        pCurrent = pCurrent->next;
    }
}

// 根据位置 删除链表节点
void removeNodeByPos(LinkList list, int pos)
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }

    // 还原真实的链表结构
    struct LList* llist = list;

    // 检测提供的位置是否合法
    if(pos < 0 || pos >= llist->m_Size)
    {
        perror("invalid position");
        return;
    }
    
    // 创建两个辅助指针记录 节点的位置
    struct LinkNode* pPrev = &llist->pHeader;
    struct LinkNode* pCurrent = llist->pHeader.next;
    for(int i = 0; i < pos; i++)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->next;

    }

    // 删除pCurrent指向的节点之前，先更新 Prev的下一个
    pPrev->next = pCurrent->next;
    
    // 删除pCurrent指向的节点
    free(pCurrent);

    // 更新链表大小
    llist->m_Size--;
}

// 根据值 删除链表节点的回调函数定义
int ComparePerson(void* s1, void* s2)
{
    if(s1 == NULL || s2 == NULL)
    {
        perror("s1 or s2 is null");
        return 0;
    }
    struct Person* p1 = s1;
    struct Person* p2 = s2;
    //int ret = strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
    //if (ret)
    //    printf("ret: %d, %s\n", ret, p2->name);
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
    // 运算符优先级：https://learn.microsoft.com/zh-cn/cpp/c-language/precedence-and-order-of-evaluation?view=msvc-170
}

// 根据值   删除链表节点
void removeNodeByVal(LinkList list, void* tdata, int(*Compare)(void*, void*))
{

    if(list == NULL || tdata == NULL)
    {
        perror("list is null or tdata is null");
        return;
    }
    // 还原真实的链表结构
    struct LList* llist = list;

    // 创建两个辅助指针，记录当前节点以及上一个节点
    struct LinkNode* pPrev = llist->pHeader.next;
    struct LinkNode* pCurrent = pPrev;
    
    // 遍历链表，找用户要删的数据
    for(int i = 0; i < llist->m_Size; i++)
    {

        if(Compare(tdata, pCurrent->data))
        {  // 找到要删除的数据，开始删除
            pPrev->next = pCurrent->next;
            // 释放内存
            free(pCurrent);
            pCurrent = NULL;
    
            // 更新链表长度
            llist->m_Size--;
            // 已经删除元素，退出循环
            break;
        }

        // 辅助指针向后移动
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
}

// 返回链表长度
int sizeof_linkList(LinkList list)
{
    if(list == NULL)
    {
        perror("list is null");
        return -1;
    }
  
    struct LList* llist = list;
    return llist->m_Size;
}


// 清空链表
void clear_linkList(LinkList list)
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }
    
    // 将 list转换为 真实的链表结构
    struct LList* llist = list;
    
    // 遍历每一个节点，并释放节点内存，保留头节点
    struct LinkNode* pPrev = &llist->pHeader;
    struct LinkNode* pCurrent = llist->pHeader.next;
    while(true)
    {
        if (pCurrent == NULL || llist->m_Size <= 0)
            break;
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
        if(pPrev)
        {
            free(pPrev);
            llist->m_Size--;
        }
    }
    
    


}

// 销毁链表
void destroy_linkList(LinkList list)
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }

    // 先将节点清空
    clear_linkList(list);

    // 再释放头节点内存
    free(list);
}

