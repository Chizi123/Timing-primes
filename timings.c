#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "meme.h"

int main(void){
	FILE * f1=fopen("times.csv","w");
	int meme;
	printf("Enter the number of numbers to be tested: ");
	scanf("%d",&meme);
	fprintf(f1,"num_test,start,end,time\n");

	for(int i=1; i<meme; i++){
		clock_t start, end;
		start=clock();
		prime(i);
		end=clock();
		fprintf(f1,"%d,%li,%li,%li\n",i,start,end,end-start);
	}
	fclose(f1);
}