#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    pid_t pid;
    pid = fork();
    int status;
    switch (pid) {
        case -1:
            printf("fork error");
            exit(EXIT_FAILURE);
            break;
        case 0:
            printf("child pid=%d,ppid=%d\n", getpid(), getppid());
            exit(0);
            break;
        default:
            printf("parent pid=%d,ppid=%d\n", getpid(), getppid());
            sleep(1);
            printf("wait...\n");
            wait(&status);
            sleep(100);
            printf("parent end\n");
            break;
    }
    printf("exit pid=%d\n",getpid());
    return 0;
}