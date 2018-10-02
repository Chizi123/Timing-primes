#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <windows.h>
#include "meme.h"

int main(void){
	FILE * f1=fopen("times.csv","w");
	int start=1,end;
	// printf("Enter the number starting: ");
	// scanf("%d",&start);
	printf("Enter the number to end on: ");
	scanf("%d",&end);
	fprintf(f1,"num_test,start,end,time\n");

	for(int i=start; i<=end; i++){
		// long long start, end;
		struct timespec s, e;
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
		// s=GetTickCount();
		prime(i);
		// end=clock_gettime();
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
		// fprintf(f1,"%d,%d,%d,%d\n",i,start,end,end-start);
		fprintf(f1,"%d,%d,%d,%d\n",i,s.tv_nsec,e.tv_nsec,e.tv_nsec-s.tv_nsec);
		printf("%d,%d,%d,%d\n",i,s.tv_nsec,e.tv_nsec,(e.tv_nsec-s.tv_nsec));
		fflush(f1);
		fflush(stdout);
	}
	fclose(f1);
}