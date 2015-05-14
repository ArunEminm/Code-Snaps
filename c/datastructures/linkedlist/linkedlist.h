//By Arun Kumar
//Btech IIT Delhi


#include<stdio.h>
#include<stdlib.h>

typedef struct LINKED_LIST LINKED_LIST;
typedef struct LINKED_LIST_NODE LINKED_LIST_NODE;

int LINKED_LIST_LENGTH(LINKED_LIST *L);
void LINKED_LIST_ADD_LAST(LINKED_LIST *L, LINKED_LIST_NODE *N);
void LINKED_LIST_ADD_FIRST(LINKED_LIST *L, LINKED_LIST_NODE *N);
void PRINT_LINKED_LIST(LINKED_LIST *L);
LINKED_LIST_NODE *LINKED_LIST_NEWNODE(int k);

struct LINKED_LIST{
	LINKED_LIST_NODE *head;
	LINKED_LIST_NODE *tail;
	int length;
};

struct LINKED_LIST_NODE{
	int key;
	LINKED_LIST_NODE *next;
};

LINKED_LIST *CREATE_LINKED_LIST(){
	LINKED_LIST *L;
	L=(LINKED_LIST *)malloc(sizeof(LINKED_LIST));
	L->head=NULL;
	L->length=0;
	return L;
}

LINKED_LIST_NODE *LINKED_LIST_NEWNODE(int k){
	LINKED_LIST_NODE *temp;
	temp=(LINKED_LIST_NODE *)malloc(sizeof(LINKED_LIST_NODE));
	temp->key=k;
	return temp;
}

int LINKED_LIST_LENGTH(LINKED_LIST *L){
	return L->length;
}

void LINKED_LIST_ADD_LAST(LINKED_LIST *L,LINKED_LIST_NODE *N){
	if(L->head==NULL){
		L->head=N;
		L->tail=N;
	}
	else{
		L->tail->next=N;
		L->tail=N;
	}
	L->length+=1;
	L->tail->next=NULL;
}

void LINKED_LIST_ADD_FIRST(LINKED_LIST *L,LINKED_LIST_NODE *N){
	if(L->head==NULL){
		L->head=N;
		L->tail=N;
	}
	else{
		N->next=L->head;
		L->head=N;
	}
	L->length+=1;
}

void PRINT_LINKED_LIST(LINKED_LIST *L){
	LINKED_LIST_NODE *temp;
	temp=L->head;
	while(temp!=NULL){
		printf("%d ",temp->key);
		temp=temp->next;
	}
	printf("\n");
}
