#include <stdio.h>
#include <string.h>
void t(int *p);
int main(){
    char a[]="3+2";
    char* deli="+";
    char* result=strtok(a,"+");
    printf("result : %s\n",result);
    result = strtok(NULL,"+");
    printf("result : %s\n",result);
	return 0;
}
