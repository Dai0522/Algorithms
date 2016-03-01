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

TreeNode* DeleteNode(TreeNode* pNode, int iVal) {
    if (pNode == NULL) return NULL;

    if (iVal == pNode->iKey)
    {
        if (pNode->pLeft && pNode->pRight)
        {
            int iHeight = TreeHeight(pNode->pLeft) - TreeHeight(pNode->pRight);
            if (iHeight >= 0)
            {
                /* 左子树高度大于等于右子树 */
                pNode->pLeft = DeleteNode(pNode->pLeft, pNode->pLeft->iKey);
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
                /* 右子树高度大于左子树 */
                pNode->pRight = DeleteNode(pNode->pRight, pNode->pRight->iKey);
                if (TreeHeight(pNode->pLeft) - TreeHeight(pNode->pRight) > 1) {
                    if (iVal < pNode->pLeft->iKey) {
                        /* LL */
                        pNode = SingleLeftRotate(pNode);
                    } else {
                        /* LR */
                        pNode = LeftRightRotate(pNode);
                    }
                }
            }
        } else {
            /* 1个或0个子节点时 */
            TreeNode* pCur = pNode;
            pNode = pNode->pLeft ? pNode->pLeft : pNode->pRight;
            free(pCur);
        }
    } else if (iVal < pNode->iKey)
    {
        /* 左子树中删除 */
        pNode->pLeft = DeleteNode(pNode->pLeft, iVal);
        if (TreeHeight(pNode->pRight) - TreeHeight(pNode->pLeft) > 1) {
            if (TreeHeight(pNode->pRight->pLeft) <= TreeHeight(pNode->pRight->pRight)) {
                /* 右子树的左子树高小于等于右子树的右子树，一次右旋就可以恢复平衡 */
                pNode = SingleRightRotate(pNode);
            } else {
                /* 右子树的左子树高大于右子树的右子树，需要一次左旋使右子树的右子树较高，再做一次右旋 */
                pNode = RightLeftRotate(pNode);
            }
        }
    } else if (iVal > pNode->iKey)
    {
        /* 右子树中删除 */
        pNode->pRight = DeleteNode(pNode->pRight, iVal);
        if (TreeHeight(pNode->pLeft) - TreeHeight(pNode->pRight) > 1) {
            if (TreeHeight(pNode->pLeft->pLeft) >= TreeHeight(pNode->pLeft->pRight)) {
                /* 左子树的左子树高大于等于左子树的右子树，一次左旋就可以恢复平衡 */
                pNode = SingleLeftRotate(pNode);
            } else {
                /* 左子树的左子树高小于左子树的右子树，需要一次右旋使左子树的左子树较高，再做一次左旋 */
                pNode = LeftRightRotate(pNode);
            }
        }
    }

    // pNode为叶子节点时不计算树高
    if (pNode == NULL) return NULL;
    // 重新计算树高度
    pNode->iHeight = MaxHeight(TreeHeight(pNode->pLeft), TreeHeight(pNode->pRight)) + 1;
    return pNode;
}

TreeNode* FindNode(TreeNode* pNode, int iVal) {
    return pNode;
}