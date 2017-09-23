#include <stdio.h>
void t(int *p);
int main(){
    int is[2];
    t(is);
    printf("is[0]=%d,is[1]=%d\n",is[0],is[1]);
	return 0;
}
void t(int *p){
    p[0] =1;
    p[1] =2;
}
