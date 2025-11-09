#include <stdio.h>

void insertSort(int arr[], int len)
{
    for(int i = 1, k = 0,j = i - 1; k < len - 1 ;k++, i++, j++)
    {
        if(arr[j] > arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            int m = j;
            while(m > 0 && arr[m - 1] > temp)
            {
                arr[m] = arr[m - 1];
                m--;
            }

            arr[m] = temp;
        }
    }
}

void foriEach(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
}

int main(void)
{

    int arr[] = { 8, 6, 7, 5, 3, 6, 4, 7, 3, 1, 2, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertSort(arr ,len);
    
    foriEach(arr, len);
    return 0;
}
/*

0, 1, 2, 3, 3, 4, 5, 6, 6, 7, 7, 8,

*/
