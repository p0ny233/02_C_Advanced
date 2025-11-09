/*
    设计回调函数
*/
#include <stdio.h>

struct Person
{
    char name[64];
    int age;
};

void printAllelements(void *arr, int size, int len, void (*myPrint)(void*))
{
    // 遍历时，记录每个元素地址
    for(int i = 0; i < len; i++)
    {
        char* p = (char*)arr + size * i;
        //printf("%d\n", *(int*)p);  // 仅仅打印 int类型的值，其它类型不适合，因此需要回调函数
        myPrint(p);
    }
}

void printInt(void *data)
{
    printf("%d, ", *(int*)data);
}

void printFloat(void *data)
{
    printf("%f, ", *(float*)data);
}

void printDouble(void *data)
{
    printf("%lf, ", *(double*)data);
}

void printUser(void* data)
{
    struct Person* p = data;
    printf("name; %s, age: %d\n", p->name, p->age);
}


// 整型数组
void test01()
{
    int arr[] = {3, 6, 3, 7, 8, 9, 6};
    printAllelements(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printInt);
}

// float数组
void test02()
{
    float arr[] = {1.1, 1.2, 1.3, 1.7, 2.8, 3.9, 1.6};
    printAllelements(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printFloat);
}

// double数组
void test03()
{
    double arr[] = {3.3, 6.3, 3.2, 7.6, 8.1, 9.9, 6.1};
    printAllelements(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printDouble);
}

// Person 类型数组
void test04()
{
    struct Person arr[] = {
                {"xiaomi", 10},
                {"huawei", 20},
        };
    printAllelements(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), printUser);
}

int myComparePerson(void* data1, void* data2)
{
    struct Person* pdata1 = data1;
    struct Person* pdata2 = data2;
    
    if (!strcmp(pdata1->name, pdata2->name) && (pdata1->age == pdata2->age))
        return 1;

    return 0;
}

// 查找元素
int findArrEle(void *arr, int eleSize ,int len,void* dstEle, int(*myCompare)(void*, void*))
{
    char *p = arr;
    for(int i = 0; i < len; i++)
    {
        void* ele = p + eleSize * i;
        if (myCompare(ele, dstEle))
            return 1;
    }


    return 0;
}

void test05()
{
    struct Person arr[] = {
            {"xiaomi", 10},
            {"huawei", 20},
            {"oppo", 30},
            {"vivo", 40},
            {"honor",50},
            {"google", 60},

    };
    //struct Person p = {"oppo", 30};
    struct Person p = { "google", 60};
    int ret = findArrEle(arr, sizeof(struct Person), sizeof(arr)/sizeof(struct Person), &p, myComparePerson);
    if(ret)
        printf("Found!!!\n");
    else
        printf("Not Found!!!\n");

}


int main(void)
{
    test01();
    putchar('\n');
    test02();
    putchar('\n');
    test03();
    putchar('\n');
    test04();
    putchar('\n');
    test05();


    return 0;
}
/*

3, 6, 3, 7, 8, 9, 6,
1.100000, 1.200000, 1.300000, 1.700000, 2.800000, 3.900000, 1.600000,
3.300000, 6.300000, 3.200000, 7.600000, 8.100000, 9.900000, 6.100000,
name; xiaomi, age: 10
name; huawei, age: 20

Found!!!

*/