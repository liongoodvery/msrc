#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

extern char *optarg;

void printArray(int*p ,int num){
	for (int i = 0; i < num; ++i)
	{
		printf("%d\t",*(p+i) );
	}
}

void s(int** a){
	printf("%d\n",sizeof(*a) );
}
int main(int argc, char *argv[]) {

	int a[10]={0};
	printf("%d\n",sizeof(a) );
	printf("%d\n",sizeof(&a) );

	s(a);
	s(&a);
    return 0;
}