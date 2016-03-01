#include "stdio.h"
#include "stdlib.h"
#include "AVLTree.h"

int PreOrder(TreeNode* pRoot) {
    if (NULL == pRoot)
    {
        return 0;
    }
    printf(" %d", pRoot->iKey);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
    return 0;
}

int MidOrder(TreeNode* pRoot) {
    if (NULL == pRoot)
    {
        return 0;
    }
    MidOrder(pRoot->pLeft);
    printf(" %d", pRoot->iKey);
    MidOrder(pRoot->pRight);
    return 0;
}

int main() {
    TreeNode* pRoot = (TreeNode*) malloc(sizeof(TreeNode));
    pRoot->iKey = 1;
    pRoot->iHeight = 1;
    pRoot->iWeight = 1;
    pRoot->pLeft = pRoot->pRight = NULL;
    pRoot = InsertNode(pRoot, 2);
    pRoot = InsertNode(pRoot, 3);
    pRoot = InsertNode(pRoot, 4);
    pRoot = InsertNode(pRoot, 5);
    pRoot = InsertNode(pRoot, 6);
    pRoot = InsertNode(pRoot, 7);
    pRoot = InsertNode(pRoot, 8);
    pRoot = InsertNode(pRoot, 9);
    pRoot = InsertNode(pRoot, 10);
    pRoot = InsertNode(pRoot, 11);
    pRoot = InsertNode(pRoot, 12);
    pRoot = InsertNode(pRoot, 13);
    pRoot = InsertNode(pRoot, 14);
    pRoot = InsertNode(pRoot, 15);
    pRoot = InsertNode(pRoot, 16);
    printf("Root: %d\n", pRoot->iKey);
    printf("middle order: ");
    MidOrder(pRoot);
    printf("\n");

    pRoot = DeleteNode(pRoot, 2);
    printf("Root: %d\n", pRoot->iKey);
    printf("middle order: ");
    MidOrder(pRoot);
    printf("\n");
    return 0;
}