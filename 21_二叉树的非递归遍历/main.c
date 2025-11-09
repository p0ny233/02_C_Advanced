/*
    每个结点都有一个初始化标志(假)
*/

#include "seq_stack.h"

struct BinaryNode
{
    // 数据域
    char ch;
    // 指针域
    struct BinaryNode* lChild;
    struct BinaryNode* rChild;
    // flag
    int flag;
};

void notRecursion(struct BinaryNode* root)
{

    if(root == NULL)
        return;
    // 创建栈
    SStack* stack = init_stack();
    push_Stack(stack, root);

    while(size_Stack(stack))
    {
        struct BinaryNode* node = top_Stack(stack);
        pop_Stack(stack);
        if(node->flag)
        {
            printf("%c ", node->ch);
            continue;
        }
        else
        {
            node->flag = 1;
            push_Stack(stack, node->rChild);
            push_Stack(stack, node->lChild);
            push_Stack(stack, node);
        }

    }
    // 销毁栈
    destroy_Stack(stack);
}


int main(void)
{
    struct BinaryNode nodeA = { .ch = 'A', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeB = { .ch = 'B', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeC = { .ch = 'C', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeD = { .ch = 'D', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeE = { .ch = 'E', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeF = { .ch = 'F', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeG = { .ch = 'G', .lChild = NULL, .rChild = NULL, .flag = 0 };
    struct BinaryNode nodeH = { .ch = 'H', .lChild = NULL, .rChild = NULL, .flag = 0 };

    // 根据图建立关系 形成二叉树
    nodeA.lChild=&nodeB;
    nodeA.rChild=&nodeF;

    nodeB.rChild=&nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;

    nodeG.lChild = &nodeH;

    // 非递归遍历
    notRecursion(&nodeA);


    return 0;
}