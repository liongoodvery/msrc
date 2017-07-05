#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "fifo"
#define BUF_SIZE 1024

int main(){
    remove(FIFO_NAME);
    if(mkfifo(FIFO_NAME,0666)==-1){
        fprintf(stderr,"mkfifo error");
        exit(-1);
    }else{
        int fd = open(FIFO_NAME,O_RDONLY);
        if(fd==-1){
            fprintf(stderr,"open error");
        }

        char buf[BUF_SIZE];
        int readnum;

        while((readnum = read(fd,buf,BUF_SIZE))>=0){
        	printf("readnum=%d\n",readnum);
            write(STDOUT_FILENO,buf,readnum);
        }
        printf("readnum=%d\n",readnum);

        close(0);
    }
	return 0;
}
