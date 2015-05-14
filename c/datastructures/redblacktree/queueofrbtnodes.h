//By Arun Kumar
//Btech IIT Delhi

#include<stdio.h>
#include<stdlib.h>
#include"redblacktree.h"

typedef struct QUEUE_NODE QUEUE_NODE;
typedef struct QUEUE QUEUE;

void QUEUE_ENQUEUE(QUEUE *Q,QUEUE_NODE *N);
QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q);
int IS_QUEUE_EMPTY(QUEUE *Q);
QUEUE *Q(void);

struct QUEUE_NODE{
	RB_NODE *data;
	QUEUE_NODE *next;
};

struct QUEUE{
	QUEUE_NODE *head;
	QUEUE_NODE *tail;
};

QUEUE *CREATE_QUEUE(void){
	QUEUE *Q;
	Q=(QUEUE *)malloc(sizeof(QUEUE));
	Q->head=NULL;
	return Q;
}

void QUEUE_ENQUEUE(QUEUE *Q,QUEUE_NODE *N){
	if(IS_QUEUE_EMPTY(Q)){
		Q->tail=N;
		Q->head=N;
	}
	else{
		Q->tail->next=N;
		Q->tail=N;
	}
	Q->tail->next=NULL;
}

QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q){
	QUEUE_NODE *temp;
	temp=Q->head;
	if(temp!=NULL){
		Q->head=Q->head->next;
		return temp;
	}
	return temp;
}

int IS_QUEUE_EMPTY(QUEUE *Q){
	if(Q->head==NULL)
		return 1;
	return 0;
}
