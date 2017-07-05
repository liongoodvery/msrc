#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <apue.h>

#define DEF_SIZE 4096
#define BUF_SIZE 1024
extern char *optarg;

int main(int argc, char *argv[]) {
    int ch;
    key_t key = 0;

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    int p = 0;
    while ((ch = getopt(argc, argv, "k:s:gh")) != -1) {
        switch (ch) {
            case 'h':
                fprintf(stdout, "shm -k:s:gh \n");
                exit(EXIT_SUCCESS);
                break;
            case 's':
                strncpy(buf, optarg, BUF_SIZE - 1);
                p = 1;
                break;

            case 'g':
                p = 2;
                break;

            case 'k':
                key = atoi(optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
        }


    }
    if (p == 0) {
        err_quit("s or g must have one\n");

    }
    void *sp = shmat(key, 0, 0);
    printf("key=%ld\n", sp);
    if (errno) {
        strerror(errno);
        err_sys("shmat error");
    }

    if (p == 1) {
        strncpy(sp, buf, strlen(buf) + 1);
    } else if (p == 2) {
        strncpy(buf, sp, BUF_SIZE - 1);
        fprintf(stdout, "value:\n");
        fprintf(stdout, "%s", buf);
        fprintf(stdout, "\n");
    }
    shmdt(sp);

    if (errno) {
        strerror(errno);
        err_quit("shmdt error");
    }
    return 0;
}