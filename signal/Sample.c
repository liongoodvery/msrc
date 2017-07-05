#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

extern char *optarg;

int main(int argc, char *argv[]) {
    int ch;
    while ((ch = getopt(argc, argv, "ha:")) != -1) {
        switch (ch) {
            case 'h':
                fprintf(stdout, "Sample -h \n");
                break;
            case 'a':
                fprintf(stdout, "-a %s\n",optarg);
                break;
            case '?':
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}