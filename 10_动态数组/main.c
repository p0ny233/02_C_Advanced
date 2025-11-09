#include <stdio.h>
#include "dynamic_array.h"

struct dynamicArray* test_init_insert_ele()
{
    struct dynamicArray* arr = init_dynamicArray(5);

    int* a = malloc(sizeof(int));

    int* b = malloc(sizeof(int));

    int* c = malloc(sizeof(int));
    int* d = malloc(sizeof(int));
    int* e = malloc(sizeof(int));

    int* f = malloc(sizeof(int));

    int* g = malloc(sizeof(int));

    int* h = malloc(sizeof(int));

    int* i = malloc(sizeof(int));

    *a = 1;
    *b = 2;
    *c = 3;
    *d = 4;
    *e = 5;
    *f = 6;
    *g = 7;
    *h = 8;
    *i = 9;

    insert_dynamicArray(arr, a, 0);
    insert_dynamicArray(arr, b, 1);
    insert_dynamicArray(arr, c, 2);
    insert_dynamicArray(arr, d, 3);
    insert_dynamicArray(arr, e, 4);
    insert_dynamicArray(arr, f, 5);
    insert_dynamicArray(arr, g, 6);
    insert_dynamicArray(arr, h, 7);
    insert_dynamicArray(arr, i, 8);
    return arr;
}

void removeEleByPos(struct dynamicArray* arr)
{
    printf("根据位置 删除元素前元素个数：%d\n", arr->m_Size);
    foreach_dynamicArray(arr, foreach_int);
    removeEleByPos_dynamicArray(arr, 1);
    putchar('\n');
    printf("\n根据位置 删除元素后元素个数：%d\n", arr->m_Size);
    foreach_dynamicArray(arr, foreach_int);
}

void removeEleByVal(struct dynamicArray* arr)
{
    printf("\n\n根据值 删除元素前元素个数：%d\n", arr->m_Size);
    foreach_dynamicArray(arr, foreach_int);

    removeEleByVal_dynamicArray(arr, 7, ComareInt);
    printf("\n根据值 删除元素后元素个数：%d\n", arr->m_Size);
    foreach_dynamicArray(arr, foreach_int);
}

int main(void)
{

    // 1. 初始化/插入元素/遍历元素/删除元素
    struct dynamicArray* arr = test_init_insert_ele();

    removeEleByPos(arr);
    removeEleByVal(arr);

    destory_dynamicArray(arr);

    return 0;
}

/*

根据位置 删除元素前元素个数：9
1, 2, 3, 4, 5, 6, 7, 8, 9,

根据位置 删除元素后元素个数：8
1, 3, 4, 5, 6, 7, 8, 9,

根据值 删除元素前元素个数：8
1, 3, 4, 5, 6, 7, 8, 9,
根据值 删除元素后元素个数：7
1, 3, 4, 5, 6, 8, 9,
D:\cpp_code\bxg\02_C语言高级\x64\Debug\10_动态数组.exe (进程 12152)已退出，代码为 0。

*/