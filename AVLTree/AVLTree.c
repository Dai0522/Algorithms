#include "stdlib.h"
#include "AVLTree.h"

int TreeHeight(TreeNode* pRoot) {
    return NULL == pRoot ? 0 : pRoot->iHeight;
}

int MaxHeight(int iLeft, int iRight) {
    return iLeft > iRight ? iLeft : iRight;
}

TreeNode* SingleLeftRotate(TreeNode* pRoot) {
    // 翻转
    TreeNode* pNode = pRoot->pLeft;
    pRoot->pLeft = pNode->pRight;
    pNode->pRight = pRoot;
    // 重置高度
    pNode->iHeight = MaxHeight(TreeHeight(pNode->pLeft), TreeHeight(pNode->pRight)) + 1;
    pRoot->iHeight = MaxHeight(TreeHeight(pRoot->pLeft), TreeHeight(pRoot->pRight)) + 1;
    return pNode;
}

TreeNode* SingleRightRotate(TreeNode* pRoot) {
    // 翻转
    TreeNode* pNode = pRoot->pRight;
    pRoot->pRight = pNode->pLeft;
    pNode->pLeft = pRoot;
    // 重置高度
    pNode->iHeight = MaxHeight(TreeHeight(pNode->pLeft), TreeHeight(pNode->pRight)) + 1;
    pRoot->iHeight = MaxHeight(TreeHeight(pRoot->pLeft), TreeHeight(pRoot->pRight)) + 1;
    return pNode;
}

TreeNode* LeftRightRotate(TreeNode* pRoot) {
    pRoot->pLeft = SingleRightRotate(pRoot->pLeft);
    return SingleLeftRotate(pRoot);
}

TreeNode* RightLeftRotate(TreeNode* pRoot) {
    pRoot->pRight = SingleLeftRotate(pRoot->pRight);
    return SingleRightRotate(pRoot);
}

TreeNode* InsertNode(TreeNode* pNode, int iVal) {
    if (NULL == pNode) {
        pNode = (TreeNode*) malloc(sizeof(TreeNode));
        pNode->iKey = iVal;
        pNode->iHeight = 1;
        pNode->iWeight = 1;
        pNode->pLeft = pNode->pRight = NULL;
    } else if (iVal < pNode->iKey)
    {
        /* 在左子树中插入 */
        pNode->pLeft = InsertNode(pNode->pLeft, iVal);
        if (TreeHeight(pNode->pLeft) - TreeHeight(pNode->pRight) > 1) {
            if (iVal < pNode->pLeft->iKey) {
                /* LL */
                pNode = SingleLeftRotate(pNode);
            } else {
                /* LR */
                pNode = LeftRightRotate(pNode);
            }
        }
    } else if (iVal > pNode->iKey)
    {
        /* 在右子树中插入 */
        pNode->pRight = InsertNode(pNode->pRight, iVal);
        if (TreeHeight(pNode->pRight) - TreeHeight(pNode->pLeft) > 1) {
            if (iVal > pNode->pRight->iKey) {
                /* RR */
                pNode = SingleRightRotate(pNode);
            } else {
                /* RL */
                pNode = RightLeftRotate(pNode);
            }
        }
    } else {
        pNode->iWeight++;
    }

    // 重新计算树高度
    pNode->iHeight = MaxHeight(TreeHeight(pNode->pLeft), TreeHeight(pNode->pRight)) + 1;
    return pNode;
}

TreeNode* FindNode(TreeNode* pNode, int iVal) {
    if (NULL == pNode || pNode->iKey == iVal) {
        return pNode;
    } else if (iVal > pNode->iKey) {
        pNode = pNode->pRight;
    } else if (iVal < pNode->iKey) {
        pNode = pNode->pLeft;
    }
    return FindNode(pNode, iVal);
}