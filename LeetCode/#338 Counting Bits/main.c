/*************************************************************************
    > File Name: main.c
    > Author: Wei Dai
    > Mail: daiwei_wow@126.com 
    > Created Time: 2016年04月06日 星期三 21时18分25秒
 ************************************************************************/

#include<stdio.h>

int* countBits(int num, int* returnSize) {
	*returnSize = num + 1;
	int* pHead = (int*)malloc(*returnSize * sizeof(int));
	pHead[0] = 0;
	for (int i = 1; i <= num; i++) {
		pHead[i] = pHead[i / 2] + i % 2;
	}
	return pHead;
}
