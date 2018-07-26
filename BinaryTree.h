//
// Created by 芦yafei  on 18/7/17.
//

#ifndef SORT_BINARYTREE_H
#define SORT_BINARYTREE_H


// 二叉链表
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
};


//求节点数
int GetNodeNum(BinaryTreeNode* pRoot)
{
    // 递归出口
    if (NULL == pRoot) {
        return 0;
    }

    return 1 + GetNodeNum(pRoot->pLeft) + GetNodeNum(pRoot->pRight);
}


//求深度
int GetDepth(BinaryTreeNode* pRoot)
{
    // 递归出口
    if (NULL == pRoot) {
        return 0;
    }

    int depthLeft = GetDepth(pRoot->pLeft);
    int depthRight = GetDepth(pRoot->pRight);

    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);
}


//前序遍历
void PreOrderTraverse(BinaryTreeNode* pRoot)
{
    // 递归出口
    if (NULL == pRoot) {
        return 0;
    }


    Visit(pRoot); // 访问根节点
    PreOrderTraverse(pRoot->pLeft); // 前序遍历左子树
    PreOrderTraverse(pRoot->pRight); // 前序遍历右子树
}


//反转
void invertTree(BinaryTreeNode* pRoot)
{
    // 递归出口
    if (NULL == pRoot) {
        return 0;
    }

    BinaryTreeNode* t = pRoot->pRight;
    pRoot->pRight = pRoot->pLeft;
    pRoot->pLeft = t;

    invertTree(pRoot->pLeft);
    invertTree(pRoot->pRight);
}


#endif //SORT_BINARYTREE_H
