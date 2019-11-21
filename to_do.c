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

struct qNode *first = NULL;//where we dequeue
struct qNode *last = NULL; // pointer that constantly points to the newest node

void enq(struct GenType);
void deq();
void show(struct qNode*);
void main(){

	struct GenType task;
	task.date = 12;
	struct GenType event;
	event.date = 13;
	enq(task);
	enq(event);
	enq(event);
	struct GenType event1;
	enq(event1);
	deq();
	deq();

	
};

void enq(struct GenType item){
	struct qNode *n = (struct qNode*)malloc(sizeof(struct qNode));
	n -> value = item;
	n -> next = NULL;
	if(first==NULL && last==NULL){
		first = last = n;
	}else{
		last -> next = last;
		last = n; 
		 
	}
}

void deq(){
	

	if(first==NULL){
		printf("empty");
		return;
	}
	if(first==last){
		first=last=NULL;
	}else{
		struct qNode* tmp = first;
		first = first->next;
		show(tmp);
		
	}
	
	
	

}

void show(struct qNode *node){
	struct GenType tmpx = node -> value;
	printf("%d\n",tmpx.date);
	
}