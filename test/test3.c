#include <stdio.h>
#include <time.h>
#include <memory.h>
extern char *__progname;
int main(){
	struct timespec ts;
	memset(&ts,0 ,sizeof(struct timespec));
	clock_gettime(CLOCK_REALTIME, &ts);
   	printf("%ld----->%ld\n", ts.tv_sec, ts.tv_nsec);
   	printf("__progname=%s",__progname);
   	return 0;
}

