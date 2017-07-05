#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>

void write_log(char *s);


int main() {
    char *abc = "abc";
    write_log(abc);
    return 0;
}

void write_log(char *s) {
    time_t tDate;
    struct tm *tTm;

    time(&tDate);
    tTm = localtime(&tDate);
    int year = tTm->tm_year + 1900;
    int mon = tTm->tm_mon + 1;
    int day = tTm->tm_mday;
    char buf[BUFSIZ];
    memset(buf,0,BUFSIZ);

    printf(buf);
    sprintf(buf, "%04d-%02d-%02d", year, mon, day);

    printf(buf);

}