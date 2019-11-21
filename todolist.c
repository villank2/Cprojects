#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct GenType{
    int date;
};

struct qNode{
    struct GenType data;
    struct qNode *next;
};


struct qNode *first = NULL; //points to where we dequeue
struct qNode *last = NULL; // points to where we enqueue

void enq(struct GenType item);
void deq();
void main(){

    struct GenType task;
    task.date = 1;
    struct GenType event;
    event.date = 2;
    enq(task);
    enq(event);
    enq(event);
    enq(task);
    deq();
    deq();
    deq();
    deq();
    deq();
}

void enq(struct GenType x){
    struct qNode *tmp = (struct qNode *)malloc(sizeof(struct qNode));
    tmp -> data = x;
    tmp -> next = NULL;
    if(first==NULL && last==NULL){
        first = last = tmp;
    }else{
        last->next = tmp;
        last = last -> next;
    }
}

void deq(){
    
    if(first==NULL){
        printf("empty\n");
        return;
    }else if(first == last){
        struct GenType tmp = first ->data;
        printf("%d\n",tmp.date);
        first = last = NULL;
    }else{
        struct GenType tmp = first ->data;
        printf("%d\n",tmp.date);
        struct qNode *temp = first;
        first = first -> next;
        free(temp);
    }
}