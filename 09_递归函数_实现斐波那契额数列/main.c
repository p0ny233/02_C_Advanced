#include <stdio.h>


// 根据 位置获取 斐波那契数列中的其中一个元素
int fibonacci(int pos)
{

    // 递归结束条件        
    if (pos == 1 || pos == 2)
        return 1;
    
    // 递归调用
    return fibonacci(pos-1) + fibonacci(pos-2);
}

int main(void)
{
    
    for(int i = 1; i < 10; i++)
    {
        int ret = fibonacci(i);
        printf("pos %d: %d\n", i, ret);
    }


    return 0;
}
/*

pos 1: 1
pos 2: 1
pos 3: 2
pos 4: 3
pos 5: 5
pos 6: 8
pos 7: 13
pos 8: 21
pos 9: 34

*/