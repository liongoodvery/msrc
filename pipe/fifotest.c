#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "fifo"
#define BUF_SIZE 1024

int main(){

    int fd = open(FIFO_NAME,O_WRONLY);
    if(fd==-1){
        fprintf(stderr,"open error");
    }

    printf("fd=%d\n",fd);
    char buf[BUF_SIZE]={'a','b','c'};
    int readnum;


    close(fd);
    // write(fd,buf,3);
	return 0;
}
