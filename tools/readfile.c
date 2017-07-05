#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define BUF_SIZE 4096
extern char *optarg;

int read_dir(char *dir);

void path(char *dir, char *name, char **ret);

int main(int argc, char *argv[]) {
    int ch;
    while ((ch = getopt(argc, argv, "ha:")) != -1) {
        switch (ch) {
            case 'h':
                fprintf(stdout, "Sample -h \n");
                break;
            case 'a':
                fprintf(stdout, "-a %s\n", optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
        }
    }

    read_dir("/home/lion/msrc/");
    return 0;
}


int read_dir(char *dir) {
    printf("read %s\n", dir);
    DIR *dp = opendir(dir);

    if (dp == NULL) {
        if (errno == ENOTDIR) {
            fprintf(stdout, "file:%s\n", dir);
            return 0;
        } else {
            strerror(errno);
            fprintf(stderr, "read error:%s\n", dir);
            exit(EXIT_FAILURE);
        }
    }
    struct stat mstat;
    struct dirent *ent;
    struct stat;
    while ((ent = readdir(dp)) != NULL) {
        char *abs;
        path(dir, ent->d_name, &abs);
        stat(abs, &mstat);
        if (S_ISDIR(mstat.st_mode)) {
            printf("dir %s\n", abs);
            if (strcmp(".", ent->d_name) && strcmp("..", ent->d_name)) {
                read_dir(abs);
            }
        } else {
            printf("file:%s\n", abs);
        }

        free(abs);
    }
    closedir(dp);
    return 0;
}

void path(char *dir, char *name, char **ret) {
    *ret = (char *) malloc(BUF_SIZE);
    memset(*ret, 0, BUF_SIZE);
    snprintf(*ret, BUF_SIZE, "%s/%s", dir, name);
}
