#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <apue.h>

#define DEF_SIZE 4096

extern char *optarg;

int main(int argc, char *argv[]) {
    int ch;
    key_t key = 0;
    size_t size = 0;
    while ((ch = getopt(argc, argv, "k:s:h")) != -1) {
        switch (ch) {
            case 'h':
                fprintf(stdout, "getshm -k key -s size \n");
                exit(EXIT_SUCCESS);
                break;
            case 's':
                size = atoi(optarg);
                break;
            case 'k':
                key = atoi(optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
        }
    }

    size = (size == 0 ? DEF_SIZE : size);

    fprintf(stdout, "create shm of key=%d size=%ld\n", key, size);
    int flag = IPC_CREAT | 0660;
    int shmid;
    if ((shmid=shmget(key, size, flag)) == -1) {
        strerror(errno);
        err_sys("shmget failed\n");
    }
    printf("shmid=%d\n", shmid);

    return 0;
}