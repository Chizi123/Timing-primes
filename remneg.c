#include <stdio.h>
#include <stdlib.h>

int main(void){
	FILE *og, *new;
	og=fopen("times.csv","r");
	new=fopen("nneg_times.csv","w");
	char line[1024];
	long d;
	fgets(line,1024,og);
	fputs(line,new);
	while(fgets(line,1024,og)){
		int i,j=0;
		for(i=0;i<1024&&line[i]!='\n';i++){
			if(line[i]==',') j++;
			if(j==3) {
				i++;
				break;
			}
		}
		d=atoi(line+i);
		if(d>0) {
			fputs(line,new);
		}
	}
	fflush(new);
	fclose(og);
	fclose(new);
}