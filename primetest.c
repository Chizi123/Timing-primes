/*
 * Prime number generator using linked lists to keep track of found primes to reduce number of calculations
 * Made by Joel Grunbaum
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//Swap pthread for conio if running on windows instead of linux

//Linked list
typedef struct node{
	unsigned long long num;
	struct node *next;
} list_t;

int prime(int runs){
	int isprime;
	list_t *head, *current;
	head=malloc(sizeof(list_t));
	//Main loop of program, loops through odd numbers and checks of they are factors of numbers in the list
	for(unsigned long long n = 3; n<runs; n+=2){
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
	return 1;
}