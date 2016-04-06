/*************************************************************************
    > File Name: main.c
    > Author: Wei Dai
    > Mail: daiwei_wow@126.com 
    > Created Time: 2016年04月06日 星期三 21时26分57秒
 ************************************************************************/

#include<stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tryRob(struct TreeNode* root, int* p) {
	if (root == NULL) {
		return 0;
	}

	int child = tryRob(root->left, &root->val) + tryRob(root->right, &root->val);
	*p += child;

	return child > root->val ? child : root->val;
}

int rob(struct TreeNode* root) {
	int a = 0;
	int b = tryRob(root, &a);
	return a > b ? a : b;
}
