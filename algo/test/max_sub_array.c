#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//
// Created by lion on 17-8-16.
//
#define max(a, b) ((a)>(b))?(a):(b)
#define SIZE 1000

int max_sub_array(int *A, int N);

int max_sub_array2(int *nums, int N);

int max_sub_array3(int *nums, int numsSize);

int main() {
    int *A = malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; ++i) {
        *(A + i) = (int) (cos(i) * SIZE);
    }

    int (*msa)(int *, int)=max_sub_array2;
    int ret = msa(A, SIZE);
    fprintf(stdout, "%d\n", ret);
    free(A);
}

int max_sub_array(int *A, int N) {
    int i, j, k, sum;
    int ret = 0x80000001;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            sum = 0;
            for (k = i; k < j; k++) {
                sum += *(A + k);
            }
            ret = max(ret, sum);
        }
    }
    return ret;
}

int max_sub_array2(int *nums, int N) {
    int i, j, sum;
    int ret = 0x80000001;

    for (i = 0; i < N; ++i) {
        sum = 0;
        for (int j = i; j < N; ++j) {
            sum += *(nums + j);
            ret = max(sum, ret);
        }
    }
    return ret;
}

int max_sub_array3(int *nums, int numsSize) {
    int i;
    int ret = 0x80000001;

    int sum = 0;

    for (i = 0; i < numsSize; ++i) {
        if (sum > 0) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }
        ret = (sum > ret ? sum : ret);
    }
    return ret;
}