#include <stdio.h>
#include <string.h>

int getNumber(char *data);

int main() {
    char a[32];
    char b[32];
    while (scanf("%s %s", a, b) != EOF) {
        int ia = getNumber(a);
        int ib = getNumber(b);
        printf("%d\n", ia + ib);
    }
    return 0;
}

int getNumber(char *data) {
    char *d = data;
    int sign = 1;
    if (*d == '-') {
        sign = -1;
        d = data + 1;
    }

    int ret = 0;
    int len = strlen(d);
    int base = 1;
    for (int i = len - 1; i >= 0; i--) {
        if (*(d + i) == ',') continue;
        ret += (*(d + i) - '0') * base;
        base *= 10;
    }
    return sign*ret;
}