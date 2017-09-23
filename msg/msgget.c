#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <apue.h>

int main(int argc, char *argv[]) {

    int msgid;
    if ((msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0755)) == -1) {
        err_sys("msgget error : %s\n", strerror(errno));
    }

    printf("key = %d\n", msgid);
    return 0;
}