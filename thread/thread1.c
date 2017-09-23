#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

extern char *optarg;

void *t_start(void *);

int main(int argc, char *argv[]) {

    pthread_t pt;
    pthread_t pt2;

    int a = 1;
    int b = 2;
    pthread_create(&pt, NULL, t_start, &a);
    pthread_create(&pt2, NULL, t_start, &b);

    fprintf(stdout, "join start\n");
    pthread_join(pt, NULL);
    pthread_join(pt2, NULL);
    fprintf(stdout, "join end");
    return 0;
}

void *t_start(void *args) {
    int ind = *(int *) args;
    fprintf(stdout, "thread start%d\n", ind);
    sleep(1);
    fprintf(stdout, "thread%d end\n", ind);
    return NULL;
}