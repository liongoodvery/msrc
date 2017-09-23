//
// Created by lion on 17-8-22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_NODE_COUNT(d) ((1<<(d))-1)

int main() {
    int D, I;
    int *p;
    while (scanf("%d%d", &D, &I)) {
        int count = TREE_NODE_COUNT(D);
        p = (int *) malloc(sizeof(int) * count);
        memset(p, 0, count);
        int k;
        for (int i = 0; i < I; ++i) {
            k = 1;
            while (k <= count) {
                p[k] = !p[k];
                k = p[k] ? 2 * k : 2 * k + 1;
            }

        }
        printf("%d\n", k / 2);
        free(p);
    }
    return 0;
}
