//
// Created by daiwei07 on 2017/4/13.
//

#include "stdio.h"

int maxSum(int *pInput, int len) {
    int start, end = 0;
    int i , max , sum;
    sum = max = pInput[0];
    for(i = 1 ; i < len ; ++i)
    {
        if(sum < 0) {
            sum = pInput[i];
            start = i;
        } else {
            sum += pInput[i];
        }

        if(sum > max) {
            max = sum;
            end = i;
        }
    }
    if(max < 0) {
        max = 0;
        start = end = 0;
    }

    printf("start: %d end: %d\n", start, end);

    return max;
}


int main() {
    int input[] = {1, -2, 3, 10, -4, 7, 2, -5};

    int max = maxSum(input, 8);

    printf("max: %d\n", max);
    return 0;
}