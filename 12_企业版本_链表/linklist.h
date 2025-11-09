#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct LinkNode
{
    struct LinkNode* next;
};

struct Person
{
    struct LinkNode node;
    char name[64];
    int age;
};

struct LLink
{
    struct LinkNode pHeader;
    int m_Size;
};

typedef void* LinkList;

// 初始化链表
LinkList init_LinkList();

// 插入链表节点
void insert_LinkList(LinkList list, void* data, int pos);

// 作为foreach_LinkList函数的回调函数
void printPerson(void* data);

// 遍历链表
void foreach_LinkList(LinkList list, void(*Print)(void*));

// 根据位置 删除链表节点
void removeNodeByPos(LinkList list, int pos);

// 根据值 删除链表节点 回调函数
int ComparePerson(void* pCurrent, void* data);
// 根据值 删除链表节点
void removeNodeByVal(LinkList list, void* data, int(*Compare)(void*, void*));


// 清空链表节点
void clear_LinkList(LinkList list);

// 销毁链表
void destroy_LinkList(LinkList list);
