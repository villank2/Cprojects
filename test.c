#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct event
{
	char date[8];
};
struct node
{
	struct event *data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void put(struct event);
void show();

void main(){
	put("12/03/19");
	show();

	
}

void put(struct event item){
	struct node *nptr = malloc(sizeof(struct node));
	nptr -> data = item;
	nptr -> next = NULL;

	if(head == NULL){
		head = nptr;
		head->next = tail;
	}
}

void show(){
	printf("%s\n",head->data->date);
	printf("%p\n", head->next);
}