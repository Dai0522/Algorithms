#ifndef _AVLTREE_H
#define _AVLTREE_H

typedef struct AVLTreeNode
{
    int iKey;
    int iHeight;
    int iWeight;
    struct AVLTreeNode* pLeft;
    struct AVLTreeNode* pRight;
} TreeNode;

TreeNode* InsertNode(TreeNode* pNode, int iVal);
TreeNode* DeleteNode(TreeNode* pNode, int iVal);

#endif