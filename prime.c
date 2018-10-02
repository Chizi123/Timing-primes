/*
 * Prime number generator using linked lists to keep track of found primes to reduce number of calculations
 * Made by Joel Grunbaum
*/

int prime(void);

#ifndef header
int main(void){
	prime();
}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <conio.h>
#include <pthread.h>
//Swap pthread for conio if running on windows instead of linux

//Linked list
typedef struct node{
	unsigned long long num;
	struct node *next;
} list_t;

//Only way I could make it exit on command
int t = 0;

//Comment out for compiling on windows instead of linux
void *check(void *g){
	t = getchar();
	pthread_exit(NULL);
}

int prime(void){
	printf("start\n");
	FILE *ls;

	list_t * head = malloc(sizeof(list_t));
	list_t * current = head;

	unsigned long long lastknown = 3;

	//Checks for existence of file and if exists loads into memory
	if(access("PrimeList.txt", F_OK)!=-1){
		ls = fopen("PrimeList.txt","a+");
		unsigned long long a;
		current->next = malloc(sizeof(list_t));
		do{
			fscanf(ls, "%llu", &a);
			current->num = a;
			lastknown = current->num;
			current->next = malloc(sizeof(list_t));
			current = current->next;
		}while(fgetc(ls)!=-1);
		//Checks for empty file
		if(head->num != 2)
			goto elist;
	}
	//If no file, creates new one and starts list
	else{
		elist:
		ls = fopen("PrimeList.txt","w");
		head->num = 2;
		head->next = malloc(sizeof(list_t));
		head->next->num = 3;
		fprintf(ls, "2\n3");
		lastknown=3;
	}

	int isprime;
	//Inform loading has finished
	printf("begin loop\nPRESS ENTER TO END PROGRAM");

	//Comment out for compiling on windows instead of linux
	//Creates second thread to listen for user input
	pthread_t thread[2];
	pthread_create(&thread[1], NULL, check, (void *) lastknown);

	//Main loop of program, loops through odd numbers and checks of they are factors of numbers in the list
	//Swap "t == 0" for "!kbhit()" when compiling on windows instead of linux
	for(unsigned long long n = (lastknown+2); t==0; n+=2){
		current = head;
		isprime=1;
		while(current != NULL){
			unsigned long long a = current->num;
			if(a*a>n)
				break;
			if(a!=0){
				if(n%a==0){
					isprime = 0;
					break;
				}
			}
			current = current->next;
		}
		//Adds new primes to list
		if(isprime == 1){
			current = head;
			while(current->next!=NULL){
				current= current->next;
			}
			current->next = malloc(sizeof(list_t));
			current = current->next;
			current->num = n;
		}

	}
	printf("end loop\n");

	//Moves list to the last known in the file and then to the one after
	current = head;
	while(current->num != lastknown){
		current = current->next;
	}
	current = current->next;

	//Writes new primes to the list
	while(current!=NULL){
		if(current->num != 0)
			fprintf(ls, "\n%llu", current->num);
		current = current->next;
	}

	//Frees the list and closes the file
	while(head!=NULL){
		current = head;
		head = head->next;
		free(current);
	}

	fclose(ls);

	printf("k thx bai\n");
}