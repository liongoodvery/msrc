#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define FILE_NAME __FILE__
#define BUF_SIZE 64


int main() {
    FILE *fp = fopen(FILE_NAME, "r");

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    int len;

    while ((len = fread(buf, sizeof(char), BUF_SIZE - 1, fp)) > 0) {
        fwrite(buf, sizeof(char), len, stdout);
    }
    printf("\nHello World\n");
    return 0;
}