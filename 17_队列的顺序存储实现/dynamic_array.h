#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void foreach_int(void*);


struct dynamicArray
{
    // 维护 数组起始地址
    void** pAddr;
    // 数组容量
    int m_Capacity;
    // 数组中的元素个数
    int m_Size;
};


// 两个int比较
int ComareInt(void* data1, void* data2);

// 初始化数组
struct dynamicArray * init_dynamicArray(int);

// 遍历数组
void foreach_dynamicArray(struct dynamicArray*, void(*)(void*));

// 插入数组
int insert_dynamicArray(struct dynamicArray* arr, void* data, int pos);

// 删除数组元素
void removeEleByPos_dynamicArray(struct dynamicArray*, int );

// 根据值删除数组元素
void removeEleByVal_dynamicArray(struct dynamicArray* arr, void* tdata, int(*Compare)(void*, void*));

// 销毁数组
void destory_dynamicArray(struct dynamicArray*);
