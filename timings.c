#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "meme.h"

int main(void){
	FILE * f1=fopen("times.csv","w");
	int meme;
	printf("Enter the number of numbers to be tested: ");
	scanf("%d",&meme);
	fprintf(f1,"num_test,start,end,time\n");

	for(int i=1; i<meme; i++){
		LARGE_INTEGER start, end;
		QueryPerformanceCounter(&start);
		prime(i);
		QueryPerformanceCounter(&end);
		fprintf(f1,"%d,%li,%li,%li\n",i,start.QuadPart,end.QuadPart,end.QuadPart-start.QuadPart);
	}
	fclose(f1);
}