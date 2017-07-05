#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int ch;
    while ((ch = getopt(argc,argv,"h:")) != -1) {
        switch (ch){
            case 'h':
                fprintf(stdout,"Sample -h \n");
                break;
            case '?':
                fprintf(stderr,"error");
                break;
        }
    }
    printf("hello world\n");
    return 0;
}