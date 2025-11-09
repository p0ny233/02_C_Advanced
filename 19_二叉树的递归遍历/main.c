#include <stdio.h>

struct BinaryNode
{
    // 数据域
    char ch;
    // 指针域
    struct BinaryNode * lChild;
    struct BinaryNode * rChild;    
};

// 先序：先根、再左、再右
void recursion_preorder(struct BinaryNode* root)
{
    if (root == NULL)
        return;
    
    printf("%c ", root->ch);
    
    recursion_preorder(root->lChild);

    recursion_preorder(root->rChild);

}

// 中序：先左、再根、再右
void recursion_inorder(struct BinaryNode* root)
{
    if (root == NULL)
        return ;
    recursion_inorder(root->lChild);
    printf("%c ", root->ch);
    recursion_inorder(root->rChild);
    


 }

// 后序：先左、再右、再根
void recursion_postorder(struct BinaryNode* root)
{
    if(root == NULL)
        return;
    recursion_postorder(root->lChild);
    recursion_postorder(root->rChild);
    printf("%c ", root->ch);

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
    struct BinaryNode nodeH = { .ch = 'H', .lChild = NULL, .rChild = NULL};
    
    // 建立关系
    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;

    nodeB.rChild = &nodeC;

    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;

    nodeF.rChild = &nodeG;
    nodeG.lChild = &nodeH;

    // 递归遍历
    struct BinaryNode* root = &nodeA;
    printf("先序遍历: ");
    recursion_preorder(root);  // 先序：A B C D E F G H
    putchar('\n');
    printf("中序遍历: ");
    recursion_inorder(root);  // 中序：B D C E A F H G
    putchar('\n');

    printf("后序遍历: ");
    recursion_postorder(root);  // 后序：D E C B H G F A

    return 0;
}
/*
    先序遍历: A B C D E F G H
    中序遍历: B D C E A F H G
    后序遍历: D E C B H G F A
*/
