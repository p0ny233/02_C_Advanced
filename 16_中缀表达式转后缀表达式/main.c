#include "seqStack.h"

/*
* 判断符号优先级
    c1: 表达式字符串的符号
    c2: 栈顶的符号

    return 1: 直接压栈
    return 0: 将栈顶符号弹出，之后入栈
*/
int priority_sym(char c1, char c2)
{
    if (c2 == NULL)
        return 1;
    switch(c1)
    {
        case '(':
            return 1;

        case '+':
        case '-':
            switch(c2)  // c2 为 栈顶符号
            {
                case '+':
                case '-':
                case '*': // 乘
                case '/': // 除
                    return 0;
            }
        case '*': // 乘
        case '/': // 除
            switch(c2)  // c2 为 栈顶符号
            {
                case '+':
                case '-':  // 栈顶符号优先级低，符号进栈
                    return 1;
                case '*': // 乘
                case '/': // 除
                    // TODO 遇到同级符号，将栈顶符号弹出并输出
                    return 0;
            }
    }
}


// 中缀表达式 (infix expression) 转 后缀表达式 (postfix expression)
void test_infix2postfix_expression(char* string, char* postbuffer)
{
    SeqStack stack = init_seqStack();

    char *ptr = string;
    char* buffer_ptr = postbuffer;  // 存储 结果
    char c2 = NULL;
    memset(postbuffer, 0 , 1024);
    while(*ptr)
    {
        if(*ptr >= '0' && *ptr <= '9') // 对于数字，直接输出，这里直接将字符 放入 postbuffer
        {
            *buffer_ptr = *ptr;
            buffer_ptr++;
        }
        else if(*ptr == ')')
        {
            while(len_seqStack(stack))
            {
                c2 = *(char*)top_seqStack(stack);
                pop_seqStack(stack);
                if(c2 == '(')
                    break;

                *buffer_ptr = c2;
                buffer_ptr++;
            }
        }
        else  // 对于符号
        {
            c2 = NULL;
            if (len_seqStack(stack))
                c2 = *(char*)top_seqStack(stack);
            if(priority_sym(*ptr, c2) == 0)
            {
                if(len_seqStack(stack))
                {
                    c2 = *(char*)top_seqStack(stack);
                    pop_seqStack(stack);
                }

                *buffer_ptr = c2;
                buffer_ptr++;
            }
            push_seqStack(stack, ptr);
        }
        ptr++;
    }

    while(len_seqStack(stack))
    {
        c2 = *(char*)top_seqStack(stack);
        pop_seqStack(stack);
        *buffer_ptr = c2;
        buffer_ptr++;
    }

    printf("result: %s\n", postbuffer);
}

// 后缀表达式(postfix expression) 转 计算结果
void test_postfix2result_expression(char *string, int* pResult)
{
    char *ptr = string;
    SeqStack stack = init_seqStack();

    while(*ptr)
    {
        int left = 0;
        int right = 0;
        int result = 0;
        char c = *ptr;
        if(c >= '0' && c <= '9')  // 对于数字
            push_seqStack(stack, c - '0');
        else  // 遇到符号
        {
            // 先弹出右操作数 后弹出左操作数
            right = (int)top_seqStack(stack);
            pop_seqStack(stack);
            left = (int)top_seqStack(stack);
            pop_seqStack(stack);

            switch(c)
            {
                case '+':
                    result = right + left;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
            }
            push_seqStack(stack, (void*)result);
        }
        ptr++;
    }
    // 遍历结束
    *pResult = (int)top_seqStack(stack);
}

int main(void)
{
    char postbuffer[SIZE];

    /****************  中缀表达式 转 后缀表达式  ************************/
    char string1[]  = "8+(3-1)*5";
    test_infix2postfix_expression(string1, postbuffer);

    /****************  后缀表达式 转 计算结果  ************************/
    int result = 0;
    test_postfix2result_expression(postbuffer, &result);
    printf("result: %d\n", result);



    return 0;
}

/*

result: 831-5*+
result: 18

*/

