#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <apue.h>
#include "mymsg.h"

int main(int argc, char *argv[]) {
    int msgid;
    Msg msg;
    msgid = 0;
    int ch;

    while ((ch = getopt(argc, argv, "t:m:i:")) != -1) {
        switch (ch) {
            case 't':
                msg.type = atol(optarg);
                break;
            case 'm':
                strncpy(msg.msg, optarg, MAX_LEN - 1);
                break;
            case 'i':
                msgid = atol(optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
        }
    }


    if(msgsnd(msgid, &msg, strlen(msg.msg) + 1, 0)==-1){
        err_sys("msgsnd error : %s\n", strerror(errno));
    }

    return 0;
}