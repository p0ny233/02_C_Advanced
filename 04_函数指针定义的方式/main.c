#include <stdio.h>

void func01(int a, char character)
{
    printf("%s\na = %d, character = %c", __func__, a, character);

}

// 定义 函数的类型
void test01()
{
    // 1. 先定义 函数的类型，再通过类型定义函数指针变量
    typedef void (FUNC_TYPE)(int, char);  // 返回值类型 void，形参列表 (int, char)
    FUNC_TYPE *pFunc = func01;
    pFunc(11, 'a');
}

// 定义 函数指针的类型
void test02()
{
    // 1. 先定义 函数指针的类型，再通过类型定义函数指针变量
    typedef void (*FUNC_TYPE)(int, char);  // 返回值类型 void，形参列表 (int, char)
    FUNC_TYPE pFunc = func01;
    pFunc(12, 'b');
}

// 根据 编译器报错提示，得到函数的指针类型
void test03()
{
    //int *p = func01;  // 1>D:\cpp_code\bxg\02_C语言高级\04_函数指针定义的方式\main.c(30,10): warning C4047: “初始化”:“int *”与“void (__cdecl *)(int,char)”的间接级别不同
    void(__cdecl*p)(int, char) = func01;
    p(13, 'c');


}

/*****************************************************************************/
/******************* 如下 函数指针数组的定义  ********************************/
/*****************************************************************************/
void func2()
{
    printf("%s的调用\n", __func__);
}

void func3()
{
    printf("%s的调用\n", __func__);
}

void func4()
{
    printf("%s的调用\n", __func__);
}

void test04()
{
    // 函数指针数组定义的方式
    void (*funcs_array[3])();  // funcs_array 是一维数组，有3个元素，元素类型都是 void (*)()
    funcs_array[0] = func2;
    funcs_array[1] = func3;
    funcs_array[2] = func4;

    for(int i = 0; i < sizeof(funcs_array) / sizeof(funcs_array[0]); i++)
        funcs_array[i]();
   
}


int main(void)
{
    test01();

    putchar('\n');
    putchar('\n');
    test02();

    putchar('\n');
    putchar('\n');
    test03();

    putchar('\n');
    putchar('\n');
    test04();
   
    return 0;
}
/*
func01
a = 11, character = a

func01
a = 12, character = b

func01
a = 13, character = c

func2的调用
func3的调用
func4的调用

D:\cpp_code\bxg\02_C语言高级\x64\Debug\04_函数指针定义的方式.exe (进程 13856)已退出，代码为 0。
*/