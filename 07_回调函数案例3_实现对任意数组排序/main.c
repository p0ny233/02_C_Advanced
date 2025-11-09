#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

int compareInt(void* data1, void* data2)
{
    int* pdata1 = data1;
    int* pdata2 = data2;
    
    return *pdata1 > *pdata2;  // 升序
}

// 根据名字排序
int comparePersonByName(void* data1, void* data2)
{
    struct Person* pdata1 = data1;
    struct Person* pdata2 = data2;

    return pdata1->name[0] > pdata2->name[0];
}

// 根据年龄大小排序
int comparePersonByAge(void* data1, void* data2)
{
    struct Person* pdata1 = data1;
    struct Person* pdata2 = data2;

    return pdata1->age > pdata2->age;
}

// 选择排序
void selectSort(void* arr, int eleSize, int len, int(*myCompare)(void*, void*))
{
    char *buf = malloc(eleSize);
    char *ptr = arr;
    int min = 0;  // 记录 最小值的索引值
    for(int i = 0; i < len; i++)
    {
        min = i;
        for(int j = i + 1; j < len; j++)
        {
            if(myCompare(ptr + eleSize * min, ptr + eleSize * j))
                min = j;  // 小于之前的值，标记
        }

        // 可以判定需要进行交换
        if((min != i) && (buf != NULL))
        {
            memcpy(buf, ptr + eleSize * min, eleSize);  // 备份
            memcpy(ptr + eleSize * min, ptr + eleSize * i, eleSize);
            memcpy(ptr + eleSize * i, buf, eleSize);
        }
    }

    free(buf);
}

void printInt(void* data)
{
    int *p = data;
    printf("%d, ", *p);
}

void printPerson(void* data)
{
    struct Person* p = data;
    printf("name: %s, age: %d\n", p->name, p->age);
}

void printAllEles(void* arr, int eleSize ,int len, void(*func)(void*))
{
    char *p = arr;
    
    for(int i = 0; i < len; i++)
    {
        func(p + eleSize * i);
    }
}

// int整型数组
void test01()
{
    int arr[] = {3, 2, 5, 1, 6, 3, 2, 1};
    selectSort(arr, sizeof(arr[0]), sizeof(arr)/ sizeof(arr[0]), compareInt);

    printAllEles(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printInt);
}

// Person数组
void test02()
{
    struct Person arr[] = {
        {"zzz", 10},
        {"cccc", 20},
        {"vvvv", 60},
        {"aaaa", 60},
        {"dddd", 50},
        {"bbb", 90},
    };
    
    // 选择排序，根据名字排序
    selectSort(arr, sizeof(arr[0]), sizeof(arr)/ sizeof(arr[0]), comparePersonByName);
    
    // 选择排序，根据年龄排序
    //selectSort(arr, sizeof(arr[0]), sizeof(arr)/ sizeof(arr[0]), comparePersonByAge);

    printAllEles(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printPerson);
}

int main(void)
{
    test01();  // int 类型数组
    test02();    // Person类型数组
    printf("%s\n", __FUNCTION__);
    return 0;
}
/*

1, 1, 2, 2, 3, 3, 5, 6, name: aaaa, age: 60
name: bbb, age: 90
name: cccc, age: 20
name: dddd, age: 50
name: vvvv, age: 60
name: zzz, age: 10

*/