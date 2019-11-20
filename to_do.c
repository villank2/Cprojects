#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct GenType{
	int date;
	int start_time;
	int duration;
	int people;
	char location[50];
	char type[6];
};

struct qNode{
	struct GenType value;
	struct qNode *next;
};

struct qNode *first = NULL;
struct qNode *last = NULL;

void put(struct GenType);
void show();
void get();
void main(){

	struct GenType task;
	task.date = 12;
	struct GenType event;
	event.date = 13;
	put(task);
	show();
	put(event);
	show();

};

void put(struct GenType item){
	struct qNode *n = malloc(sizeof(struct qNode));
	n -> value = item;
	n -> next = NULL;
	if(first==NULL){
		first = n;
		first -> next = last;
	}else{
		struct qNode *tmp = last;
		last = n;
		last -> next = tmp;
	}
}

void show(){
	struct GenType x;
	if(last==NULL){
		x = first->value;

	}else{
		x = last->value;	
	}
	
	printf("%d\n", x.date);
}

void get(){
	if
}