#include "linklist.h"


// 初始化链表
LinkList init_LinkList()
{
    LinkList p = malloc(sizeof(struct LLink));
    if(p == NULL)
    {
        perror("init LinkList malloc: ");
        return NULL;
    }
    memset(p, 0, sizeof(struct LLink));
    return p;
}

// 插入链表节点
void insert_LinkList(LinkList list, void* data, int pos)
{
    if(list == NULL)
    {
        perror("list is null");
        return ;
    }

    if(data == NULL)
    {
        perror("data is null");
        return;
    }

    // 转换真实的链表结构
    struct LLink* llist = list;

    if(pos < 0 || pos >= llist->m_Size)
    {
        // 提供的pos不合法，都进行尾插
        pos = llist->m_Size;
    }


    // 指向第一个节点，实际只需要一个指针，找到插入的位置的前驱节点，即可完成插入节点的操作
    struct LinkNode* pCurrent = llist->pHeader.next;
    struct LinkNode* pPrev = &llist->pHeader;
    struct LinkNode* pdata = data;
    // 循环到最后一个节点
    for(int i = 0; i < pos; i++)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

    // 建立关系 (需要考虑当没有节点、有节点的情况)，节点与节点的内存都在栈区
    if(pPrev)
    {
        pdata->next = pPrev->next;
        pPrev->next = pdata;
        llist->m_Size++;
    }

}

void printPerson(void* data)
{
    if(data == NULL)
    {
        perror("data is null");
        return ;
    }
    // 转换真实的数据结构
    struct Person* p = data;
    
    printf("name: %s, age: %d\n", p->name, p->age);
}

// 遍历链表
void foreach_LinkList(LinkList list, void(*Print)(void*))
{
    if(list == NULL)
    {
        perror("list is null");
        return ;
    }

    // 转换真实的链表结构
    struct LLink* llist = list;
    struct LinkNode* pCurrent = llist->pHeader.next;

    for(int i = 0; i < llist->m_Size; i++)
    {
        // 不知道具体类型，则使用回调函数
        Print(pCurrent);
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
    struct LLink* llist = list;
    if(pos < 0 || pos >= llist->m_Size)
    {
        perror("remove error, pos is invalid");
        return;
    }
    
    // 创建两个辅助指针
    struct LinkNode* pPrev = &llist->pHeader;
    struct LinkNode* pCurrent = llist->pHeader.next;

    for(int i = 0; i < pos; i++)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    
    if(pPrev)
    {
        pPrev->next = pCurrent->next;
        llist->m_Size--;
    }
}

// 根据值 删除链表节点 的回调函数
int ComparePerson(void* pCurrent, void* data)
{
    if(pCurrent == NULL || data == NULL)
    {
        perror("is NULL");
        return 0;
    }
    struct Person* p1 = pCurrent;
    struct Person* p2 = data;
    
    return !strcmp(p1->name, p2->name) && p1->age == p2->age;

}

// 根据值 删除链表节点
void removeNodeByVal(LinkList list, void* data, int(*Compare)(void*, void*))
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }

    if(data == NULL)
    {
        perror("data is null");
        return;
    }

    struct LLink* llist = list;

    // 创建两个辅助指针
    struct LinkNode* pPrev = &llist->pHeader;
    struct LinkNode* pCurrent = llist->pHeader.next;
    for(int i = 0; i < llist->m_Size; i++)
    {
        if(Compare(pCurrent, data))
        {
            pPrev->next = pCurrent->next;
            llist->m_Size--;
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }


}


// 清空链表节点
void clear_LinkList(LinkList list)
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }
    struct LLink* llist = list;
    llist->pHeader.next = NULL;
    llist->m_Size = 0;


}

// 销毁链表
void destroy_LinkList(LinkList list)
{
    if(list == NULL)
    {
        perror("list is null");
        return;
    }
                            
    struct LLink* llist = list;
    llist->m_Size = 0;
    free(llist);
}

