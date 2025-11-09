#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 节点结构体
struct LinkNode
{
    void* data;             // 数据域
    struct LinkNode* next;  // 指针域
};

// 链表的结构体
struct LList  // 包含头节点
{
    struct LinkNode pHeader;   // 链表的头节点
    int m_Size;                // 记录链表节点个数
};

typedef void* LinkList;  // 防止用户访问 链表的结构体成员，修改内部成员值


// 节数据域结构体
struct Person
{
    char name[64];
    int age;
};

// 根据值 删除链表节点的回调函数定义
int ComparePerson(void* s1, void* s2);

// 作为回调函数, 输出Person
void printPerson(void* data);

/********************************************************************/

// 初始化链表
LinkList init_linkList();

// 根据位置 插入链表节点
void insertNodeList(LinkList list, void* data, int pos);

// 遍历链表
void for_eachLinkList(LinkList list, void(*PrintCallBack)(void*));

// 根据位置 删除链表节点
void removeNodeByPos(LinkList list, int pos);

// 根据值   删除链表节点
void removeNodeByVal(LinkList list, void* tdata, int(*Compare)(void*, void*));

// 返回链表长度
int sizeof_linkList(LinkList list);

// 清空链表
void clear_linkList(LinkList list);

// 销毁链表
void destroy_linkList(LinkList list);

