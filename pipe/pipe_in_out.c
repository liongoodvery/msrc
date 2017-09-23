#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <apue.h>
#include <sys/wait.h>


int main()
{
    int fds[2];
    if(pipe(fds)==1){
        err_sys("pipe error");
    }

    switch(fork()){
        case -1:
            err_sys("fork error");
            break;

        case 0:
            if(close(fds[0]))
                err_sys("close error");
            dup2(fds[1],STDOUT_FILENO);
            if(close(fds[1]))
                err_sys("close error");
            execlp("ls","ls","-l",NULL);
            exit(0);
            break;

        default:
            break;
    }

    switch(fork()){
        case -1:
            err_sys("fork error");
            break;

        case 0:
            if(close(fds[1]))
                err_sys("close error");
            dup2(fds[0],STDIN_FILENO);
            if(close(fds[0]))
                err_sys("close error");
            execlp("wc","wc",NULL);
            break;

        default:
            break;
    }


    if(close(fds[0])){
        err_sys("close error");
    }
    if(close(fds[1])){
        err_sys("close error");
    }

    if(wait(NULL)==-1){
        err_sys("wait error");
    }
    if(wait(NULL)==-1){
        err_sys("wait error");
    }
    printf("hello Test\n");
    return 0;
}
