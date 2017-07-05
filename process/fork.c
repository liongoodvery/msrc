#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();
    switch (pid) {
        case 0:
            printf("child pid=%d,ppid=%d\n", getpid(), getppid());
            pause();
            break;
        case -1:
            printf("fork error");
            exit(EXIT_FAILURE);
            break;

        default:
            printf("parent pid=%d,ppid=%d\n", getpid(), getppid());
            break;
    }
    printf("exit pid=%d\n",getpid());
    return 0;
}