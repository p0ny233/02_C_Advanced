/*
     1. 求叶子数量

     2. 求树的高度/深度

     3. 拷贝二叉树
        递归遍历新的树

     4. 释放二叉树
*/
#include <stdio.h>
#include <stdlib.h>

struct BinaryNode
{
    // 数据域
    char ch;
    // 指针域
    struct BinaryNode* lChild;
    struct BinaryNode* rChild;
};

// 使用先序递归遍历 计算叶子结点个数，判断每个结点是否同时没有左右孩子
void recursion_preorder(struct BinaryNode* root, int* pNum)
{
    if(root == NULL)
        return;

    if(root->lChild == NULL && root->rChild == NULL)
        (*pNum)++;  // 要括号

    recursion_preorder(root->lChild, pNum);
    recursion_preorder(root->rChild, pNum);
}

// 使用递归遍历 计算树的高度/深度
int recursion_inorder(struct BinaryNode* root)
{
    if (root == NULL)
        return 0;
    int left = recursion_inorder(root->lChild);
    int right = recursion_inorder(root->rChild);


    return (left > right ? left : right) + 1;
}

// 1. 求叶子数量
void test_01(struct BinaryNode* node)
{
    int num = 0;
    recursion_preorder(node, &num);

    printf("叶子数量: %d\n", num);

}

// 2. 求树的高度/深度
void test_02(struct BinaryNode* node)
{
    int depth = 0;
    depth = recursion_inorder(node);

    printf("树的深度: %d\n", depth);

}

// 3. 拷贝二叉树，递归遍历，进行拷贝
struct BinaryNode* copyTree(struct BinaryNode* root)
{
    if (root == NULL)
        return NULL;
    struct BinaryNode* pLeft = copyTree(root->lChild);
    struct BinaryNode* pRight = copyTree(root->rChild);

    struct BinaryNode* newNode = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
    newNode->ch = root->ch;
    newNode->lChild = pLeft;
    newNode->rChild = pRight;
    return newNode;
}

// 遍历二叉树并输出
void recursion_postorder(struct BinaryNode* root)
{
    if (root == NULL)
        return;
    recursion_postorder(root->lChild);

    recursion_postorder(root->rChild);
    printf("%c ", root->ch);

}

// 4. 释放结点，遍历二叉树，并释放结点
void freeBinaryNode(struct BinaryNode* root)
{
    if (root == NULL)
        return;
    freeBinaryNode(root->lChild);
    freeBinaryNode(root->rChild);
    printf("释放内存: %c\n", root->ch);
    free(root);
}

int main(void)
{
    // 创建结点数据
    struct BinaryNode nodeA = { .ch = 'A', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeB = { .ch = 'B', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeC = { .ch = 'C', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeD = { .ch = 'D', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeE = { .ch = 'E', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeF = { .ch = 'F', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeG = { .ch = 'G', .lChild = NULL, .rChild = NULL };
    struct BinaryNode nodeH = { .ch = 'H', .lChild = NULL, .rChild = NULL };

    // 建立关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;

    nodeB.rChild = &nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;
    nodeG.lChild = &nodeH;
    
    // 1. 求叶子数量
    test_01(&nodeA);

    // 2. 求树的高度/深度
    test_02(&nodeA);

    // 3. 拷贝二叉树
    struct BinaryNode* temp = copyTree(&nodeA);

    // 递归遍历新的树
    recursion_postorder(temp);
    putchar('\n');
    // 4. 释放二叉树
    freeBinaryNode(temp);
    return 0;
}

/*

叶子数量: 3
树的深度: 4
D E C B H G F A
释放内存: D
释放内存: E
释放内存: C
释放内存: B
释放内存: H
释放内存: G
释放内存: F
释放内存: A

*/