#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/time.h>
#include <pthread.h>
#include "apue.h"
#include "server.h"

#define BUF_SIZE 4096

void *handle_request(void *);


int main(int argc, char *argv[]) {
    struct sockaddr_in saddr;
    socklen_t socklen;
    int sfd;
    int port = 8090;
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    struct timeval timeout = {3, 0};

    int on = 1;
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
        printf("setsockopt failed %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    socklen = sizeof(struct sockaddr_in);

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sfd, (struct sockaddr *) &saddr, socklen)) {
        err_sys("bind port %d error: %s\n", port, strerror(errno));
    }

    if (listen(sfd, 0)) {
        err_sys("listen error: %s\n", port, strerror(errno));
    }

    for (;;) {
        fprintf(stderr, "\nbegin listen....\n");
        struct sockaddr_in *pcaddr = (struct sockaddr_in *) malloc(sizeof(struct sockaddr_in));

        int cfd = accept(sfd, (struct sockaddr *) pcaddr, &socklen);
        if (cfd == -1) {
            fprintf(stderr, "accept error\n");
            continue;
        }
        fprintf(stdout, "accept %s\n", inet_ntoa(pcaddr->sin_addr));

        setsockopt(cfd, SOL_SOCKET, SO_SNDTIMEO, (const char *) &timeout, sizeof(struct timeval));
        setsockopt(cfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &timeout, sizeof(struct timeval));
        ThreadArgs *threadArgs = malloc(sizeof(ThreadArgs));
        threadArgs->cfd = cfd;
        threadArgs->pcaddr = pcaddr;
        pthread_t pt;
        pthread_create(&pt, NULL, handle_request, threadArgs);
        pthread_detach(pt);
    }
    return 0;
}


void *handle_request(void *args) {
    ThreadArgs *pta = (ThreadArgs *) args;
    int cfd = pta->cfd;
    struct sockaddr_in *pcaddr = pta->pcaddr;
    char buf[BUF_SIZE];
    char end[4] = {13, 10, 13, 10};
    const char *hello = "HTTP/1.1 200 OK\x0D\x0A\x0D\x0Ahello world\x0D\x0A";
    ssize_t read_num;
    fprintf(stdout, "begin handle request form %s\n", inet_ntoa(pcaddr->sin_addr));
    while ((read_num = recv(cfd, buf, BUF_SIZE, 0)) > 0) {
        fprintf(stderr, "read %ld bytes\n", read_num);

        if (write(STDOUT_FILENO, buf, read_num) != read_num) {
            fprintf(stderr, "write error\n");
            break;
        }

        if (memcmp(end, buf + read_num - sizeof(end), sizeof(end)) == 0) {
            fprintf(stderr, "recv end\n");
            send(cfd, hello, strlen(hello), 0);
            break;
        }
    }

    if (read_num < 0) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
    } else if (read_num == 0) {
        fprintf(stderr, "sock closed\n");
    }
    close(cfd);

    free(pta->pcaddr);
    free(pta);
    return (void *) 0;
}

