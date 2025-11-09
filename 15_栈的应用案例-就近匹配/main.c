#include "seqStack.h"

// 测试栈是否正常使用
void test01()
{
    int a = 1;
    int b = 2;
    SeqStack stack = init_SeqStack();

    push_SeqStack(stack, &a);
    push_SeqStack(stack, &b);

    while(len_SeqStack(stack))
    {
        printf("%d ", *(int*)top_SeqStack(stack));
        pop_SeqStack(stack);
    }

    destroy_SeqStack(stack);
}


// 测试就近匹配，括号匹配
void test02()
{
    //char* str = "123456";
    char* str_1 ="5+5*(6)+(9/3*1)-1+3";   // 匹配成功
    char* str_2 ="5+5*(6)+9/3*1)-(1+3(";  // 匹配失败，右括号多了，栈内已没有元素
    char* str_3 = "5+5*(6)+9/3*1-(1+3(";  // 匹配失败，栈内还有元素

    char* ptr = str_1;
    //char* ptr = str_2;
    //char* ptr = str_3;

    SeqStack stack = init_SeqStack();
    //char c = *ptr++;  // 先 计算 * ，后自增
    //putchar(c);

    while(*ptr)
    {
        // 遇到左括号就 入栈
        if(*ptr == '(')
        {
            push_SeqStack(stack, ptr);
        }
        else if(*ptr == ')')  // 遇到 右括号就 出栈
        {
            if(!len_SeqStack(stack))
            {
                perror("匹配失败，右括号多了，栈内已没有元素\n");
                exit(-1);
            }
            
            pop_SeqStack(stack);
        }
        ptr++;
    }

    if(len_SeqStack(stack))
    {
        perror("匹配失败，栈内还有元素\n");
        exit(-1);
    }
    
    printf("匹配成功\n");
}

int main(void)
{
    //test01();
    test02();
    return 0;
}
