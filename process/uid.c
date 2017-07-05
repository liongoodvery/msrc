#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
int main(int argc, char *argv[]) {
    char *login = getlogin();
    struct passwd *w= getpwnam(login);
    printf("%s\n", login);
    return 0;
}