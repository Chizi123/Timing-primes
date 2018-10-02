#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <windows.h>
#include "primecalc.h"

int main(void){
	FILE * f1=fopen("times.csv","w");
	int end;
	printf("Enter the number to end on: ");
	scanf("%d",&end);
	fprintf(f1,"num_test,start,end,time\n");

	for(int i=1; i<=end; i++){
		struct timespec s, e;
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&s);
		prime(i);
		clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&e);
		fprintf(f1,"%d,%d,%d,%d\n",i,s.tv_nsec,e.tv_nsec,e.tv_nsec-s.tv_nsec);
		// printf("%d,%d,%d,%d\n",i,s.tv_nsec,e.tv_nsec,(e.tv_nsec-s.tv_nsec));
		fflush(f1);
		fflush(stdout);
	}
	fclose(f1);
}