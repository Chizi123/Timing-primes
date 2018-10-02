/*
 * Checking function for a prime number generator
 * By Joel Grunbaum
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	unsigned long long num;
	struct node *next;
} llist;

int main(void){
	FILE *ls;
	ls = fopen("PrimeList.txt","r");

	if(ls == NULL)
		exit(1);

	unsigned long long num, last;
	llist *head = malloc(sizeof(llist));
	llist *current = head;
	unsigned long long listlen1, listlen2, listlen;

	current->num = fscanf(ls, "%llu", &current->num);

	//Load file into memory
	do{
		current->next = malloc(sizeof(llist));
		current = current->next;
		fscanf(ls, "%llu", &current->num);
		if(last<current->num)
			last = current->num;
		listlen1++;
	}while(fgetc(ls)!=-1);

	//IDK why but it alternates between listlen1 and listlen2 for which is accurate
	current = head;
	while(current!=NULL){
		current = current->next;
		listlen2++;
	}

	listlen1--;

	if(listlen2<listlen1)
		listlen = listlen2;
	else
		listlen = listlen1;

	current = head;
	printf("starting to check\n");
	int count1 = 0, count2 = 0;

	printf("checking for non-primes in list\n");
	do{
		num = current->num;

		for(unsigned long long i = 2; i*i<=num; i++){
			if(num%i == 0){
				printf("%llu isn't prime!\n", num);
				count2++;
				break;
			}

		}
		current = current->next;
	}while(current != NULL);

	printf("checking for missing primes\n");
	for(unsigned long long i = 2; i<=last; i++){
		int k=0;
		for(unsigned long long j = 2; j*j<=i; j++){
			if(i%j==0){
				k++;
			}
		}
		if(k==0){
			current = head;
				while(current != NULL){
					if(current->num!=i){
						k++;
					}
					current = current->next;
				}
			
			if(k < listlen){
				printf("%d\n", k);
				printf("%llu is a prime not in the list\n", i);
				count1++;	
			}
		}
	}
	
	printf("finished check, there were %d non primes in the list and %d primes out of the list\n", count2, count1);

	while(head!=NULL){
		current = head;
		head = head->next;
		free(current);
	}
	fclose(ls);
}