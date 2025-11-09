#include <stdio.h>
#include <stdbool.h>

void printElem(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void printElems(char* arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%s ", arr[i]);
}

// 降序
void test02()
{
    char *strs[] = {"aaaa", "cccc", "bbbb", "ffff"};
    for(int i = 0; i < sizeof(strs) / sizeof(strs[0] - 1); i++)
    {
        bool change = false;
        int index = i;
        for(int j = i; j < sizeof(strs) / sizeof(strs[0]) - 1; j++)
        {
            if(*strs[index] < *strs[j + 1])
            {
                index = j + 1;
                change = true;

            }
        }

        if(change)
        {
            strs[i] = (uintptr_t)strs[i] ^ (uintptr_t)strs[index];
            strs[index] = (uintptr_t)strs[i] ^ (uintptr_t)strs[index];
            strs[i] = (uintptr_t)strs[i] ^ (uintptr_t)strs[index];
        }

    }

    printElems(strs, sizeof(strs) / sizeof(strs[0]));


}

// 对一组数据升序
void test01()
{
    int arr[] = {66, 5, 9, 7, 6 ,0, 11, 33, 10, 2, 0, 1, 2, 3, 4};
    for(int i = 0; i < sizeof(arr) / sizeof(arr[0] - 1); i++)
    {
        int index = i;
        bool change = false;
        for(int j = i; j < (sizeof(arr) / sizeof(arr[0]) - 1); j++)
        {
            if(arr[index] > arr[j + 1])
            {
                index = j + 1;
                change = true;
            }
            
        }
        if(change)
        {
            arr[i] = arr[i] ^ arr[index];
            arr[index] = arr[i] ^ arr[index];
            arr[i] = arr[i] ^ arr[index];
        }
    }
    
    printElem(arr, sizeof(arr) / sizeof(arr[0]));
}

int main(void)
{
    test01();
    printf("\n");
    test02();
    return 0;
}
/*
0 0 1 2 2 3 4 5 6 7 9 10 11 33 66
ffff cccc bbbb aaaa
*/