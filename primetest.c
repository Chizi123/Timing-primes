/*
 * Prime number generator using linked lists to keep track of found primes to reduce number of calculations
 * Made by Joel Grunbaum
*/
#include <stdio.h>
#include <stdlib.h>

//Linked list
typedef struct node{
	unsigned long long num;
	struct node *next;
} list_t;

void free_list(list_t *lst);

int prime(int reps){
	int isprime;
	list_t *head, *current;
	//Main loop of program, loops through odd numbers and checks of they are factors of numbers in the list
	for(unsigned long long n = 3; n<reps; n+=2){
		head=malloc(sizeof(list_t));
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
		free_list(head);
	}
	return 1;
}

void free_list(list_t *lst){
	while(lst!=NULL){
		list_t *temp=lst;
		lst=lst->next;
		free(temp);
	}
}