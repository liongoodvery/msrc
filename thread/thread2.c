#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

extern char *optarg;

void *t_start(void *);

void t_clean(void *arg);

int main(int argc, char *argv[]) {
    void *ret;
    pthread_t pt;
    int a = 1;
    pthread_create(&pt, NULL, t_start, &a);
    pthread_join(pt, &ret);
    exit(0);
}

void *t_start(void *args) {
    pthread_cleanup_push(t_clean, args) ;
            int ind = *(int *) args;
            fprintf(stdout, "thread%d start\n", ind);
            sleep(1);
            fprintf(stdout, "thread%d end\n", ind);
            pthread_exit((void *) 2);
    pthread_cleanup_pop(0);
    pthread_exit((void *) 2);
}

void t_clean(void *arg) {
    fprintf(stdout, "cleanup %d", *(int *) (arg));
}