//
// Created by lion on 17-8-15.
//

#include <stdio.h>

int main() {
    int a[] = {3, 4, 1, 2, 5,10,8};
    int i, j;
    for (i = 1; i < sizeof(a)/sizeof(int); ++i) {
        int n = a[i];
        j = i - 1;

        while (j >= 0 && n < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = n;
    }
    for (int k = 0; k < sizeof(a)/ sizeof(int); ++k) {
        printf("%d\t", a[k]);
    }
    printf("\n");
}
