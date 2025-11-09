/*
    回调函数 案例
*/
#include <stdio.h>

struct user
{
    char id[64];
    char name[64];
};

void myPrint(void * data, void (*pfunc)(void*))
{
    pfunc(data);
}

void printInt(void *data)
{
    int *d = (int*)data;
    printf("%d\n", *d);
}

void printDouble(void* data)
{
    double *d = (double*)data;
    printf("%lf\n", *d);
}

void printFloat(void* data)
{
    float *f = (float*)data;
    printf("%f\n", *f);
}

void printUerInfo(void* data)
{
    struct user* pdata = (struct user*)data;
    printf("id: %s, name: %s\n", pdata->id, pdata->name);
}

int main(void)
{
    int a = 12;
    float f = 3.14;
    double d = 6.32;
    struct user u = {"13579", "xiaomi"};

    // 回调函数
    myPrint(&a, printInt);
    myPrint(&f, printFloat);
    myPrint(&d, printDouble);
    myPrint(&u, printUerInfo);

    return 0;
}
/*
    12
    3.140000
    6.320000
    id: 13579, name: xiaomi
*/
