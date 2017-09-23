#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
int main(){
	pid_t pid;
	int pipefd[2];
	pipe(pipefd);
	pid = fork();
	if (pid == -1) {

	} else if (pid == 0) {
        //children
		int writefd = pipefd[1];
		close(pipefd[0]);
		write(writefd, "hello", sizeof("hello"));
	} else {
        //parent
		int readfd = pipefd[0];
		close(pipefd[1]);
		char buf[BUF_SIZE];
		memset(buf, 0, BUF_SIZE);
		read(readfd, buf, BUF_SIZE);
		printf("%s", buf);
	}
}