#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

#define DIR_PATH ("/home/lion/msrc")

int main(int argc, char *argv[]) {
    DIR *dp = opendir(DIR_PATH);
    struct dirent *pent;
    while ((pent = readdir(dp)) != NULL) {
        fprintf(stdout, "%c:%s\n", (char) pent->d_type, pent->d_name);
    }
    closedir(dp);
    return 0;
}