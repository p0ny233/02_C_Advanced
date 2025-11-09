#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdlib.h>
#include <stdio.h>

struct LinkNode
{
    int num;
    struct LinkNode *next;
};

// 初始化链表
struct LinkNode* init_LinkList();

// 遍历链表
void foreach_LinkList(struct LinkNode *pHeader);

// 销毁链表
void destroy_LinkList(struct LinkNode *pHeader);

// 插入节点
void insert_LinkList(struct LinkNode *pHeader, int oldVal, int newVal);

// 删除节点
void delete_Node(struct LinkNode *pHeader, int val);

// 反转链表
void rever_LinkList(struct LinkNode* list);

// 清空链表：只保留 pHeaer，其它节点释放内存
void clear_LinkList(struct LinkNode* pHeader);

