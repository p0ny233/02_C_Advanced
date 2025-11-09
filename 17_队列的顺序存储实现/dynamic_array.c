#include "dynamic_array.h"

// 循环int类型数组
void foreach_int(void* addr)
{
    printf("%d, ", *(int*)addr);
}

// 初始化数组
struct dynamicArray* init_dynamicArray(int capacity)
{
    struct dynamicArray* addr = malloc(sizeof(struct dynamicArray));
    if(addr == NULL)
    {
        perror("init_dynamicArray malloc");
        return NULL;
    }
    
    addr->pAddr= malloc(sizeof(void*) * capacity);
    if(addr->pAddr == NULL)
    {
        perror("pAddr malloc");
        return;
    }
    memset(addr->pAddr, NULL, sizeof(void*) * capacity);
    addr->m_Capacity = capacity;
    addr->m_Size = 0;
    return addr;
}


// 遍历数组, 由 形参 myPrint 来决定元素怎么样输出
void foreach_dynamicArray(struct dynamicArray* arr, void(*myPrint)(void*))
{
    void** ptr = arr->pAddr;
    for(int i = 0; i < arr->m_Size; i++)
        myPrint(ptr[i]);
}

// 插入数组
int insert_dynamicArray(struct dynamicArray* arr, void* data, int pos)
{
    // 空指针、pos值无效
    if(arr == NULL || pos < 0)
    {
        perror("insert faild !!!");
        return 0;
    }

    // 尾插
    if (pos >= arr->m_Size)
        pos = arr->m_Size;

    // 2. 容量不够，扩充
    if(arr->m_Size >= arr->m_Capacity)
    {
        // 1. 开辟新的空间
        int newCapacity = arr->m_Capacity * 2;
        void* newAddr = malloc(sizeof(void*) * newCapacity);
        if(newAddr == NULL)
        {
            perror("expand malloc");
            return 0;
        }
        // 2. 原内存拷贝
        memcpy(newAddr, arr->pAddr, arr->m_Size * sizeof(arr->pAddr[0]));

        // 3. 释放原内存
        free(arr->pAddr);
        
        // 4. 更新指向到新开辟的空间
        arr->pAddr = newAddr;
        arr->m_Capacity = newCapacity;
        
    }
        
    // 插入元素逻辑， 从最后一个开始，将元素一个一个往后挪
    for(int i = arr->m_Size - 1; i >= pos; i--)
    {
        arr->pAddr[i+1] = arr->pAddr[i];
    }

    // 插入新元素到指定位置
    arr->pAddr[pos] = data;
    arr->m_Size++;

    return 1;
    
}

// 根据位置删除数组元素
void removeEleByPos_dynamicArray(struct dynamicArray* arr, int pos)
{
    if(arr == NULL || arr->pAddr == NULL)
    {
        perror("Null Pointer");
        return;
    }
    if(pos < 0 || pos > arr->m_Size - 1)
    {
        perror("error delete elements");
        return;
    }

    // 覆盖 pos指定位置上的元素
    if(arr->pAddr[pos])
        free(arr->pAddr[pos]);  // exception, 数组中的指针元素可能是栈上的地址
    for(int i = 0; pos + i + 1 < arr->m_Size; i++)
    {
        arr->pAddr[pos+i] = arr->pAddr[pos + i + 1];
    }
    arr->m_Size--;
}

// 两个int比较
int ComareInt(void* data1, void* data2)
{
    int v1 = data1;
    int *v2 = data2;
    
    return v1 - *v2;
}

// 根据值删除数组元素
void removeEleByVal_dynamicArray(struct dynamicArray* arr, void* tdata, int(*Compare)(void*, void*))
{
    if(arr == NULL || arr->pAddr == NULL)
    {
        perror("arr is null");
        return;
    }

    if(arr->m_Size <= 0)
    {
        perror("size is 0");
        return;
    }

    bool found = false;
    int i = 0;
    for(; i < arr->m_Size; i++)
    {
        if(Compare(tdata, arr->pAddr[i]) == 0)
        {
            found = true;
            break;
        }
    }

    if(found)
        removeEleByPos_dynamicArray(arr, i);
}

// 销毁数组
void destory_dynamicArray(struct dynamicArray*arr)
{
    if(arr == NULL || arr->pAddr == NULL)
    {
        perror("addr is null");
        return;
    }

    for(int i = 0; i < arr->m_Size; i++)
    {
        removeEleByPos_dynamicArray(arr, i);
    }

    free(arr->pAddr);
    free(arr);
    
}
