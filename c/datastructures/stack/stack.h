//By Arun Kumar
//Btech IIT Delhi

#include<stdio.h>
#include<stdlib.h>


typedef struct STACK STACK;
typedef struct STACK_NODE STACK_NODE;

STACK_NODE *NEW_STACK_NODE(int k);
void STACK_PUSH(STACK *S,STACK_NODE *N);
STACK_NODE *STACK_POP(STACK *S);
int IS_STACK_EMPTY(STACK *S);
void PRINT_STACK(STACK *S);
STACK *CREATE_STACK();

struct STACK{
	STACK_NODE *top;	
};

struct STACK_NODE
{
	int data;
	STACK_NODE *next;
};

STACK *CREATE_STACK(){
	STACK *S;
	S=(STACK *)malloc(sizeof(STACK));
	S->top=NULL;
	return S;
}

STACK_NODE *NEW_STACK_NODE(int k)
{
	STACK_NODE *temp;
	temp=(STACK_NODE *)malloc(sizeof(STACK_NODE));
	temp->data=k;
	printf("Created STACK_NODE %d @ %p\n",k,temp);
	return temp;
}

void STACK_PUSH(STACK *S,STACK_NODE *N)
{
	N->next=S->top;
	S->top=N;
}

STACK_NODE *STACK_POP(STACK *S)
{
	if(!IS_STACK_EMPTY(S))
	{
		STACK_NODE *temp;
		temp=S->top;
		printf("Popped STACK_NODE %d @ %p\n",temp->data,temp);
		S->top=S->top->next;
		return temp;
	}
	printf("Empty STACK\n");
	return NULL;
}

int IS_STACK_EMPTY(STACK *S)
{
	if(S->top==NULL)
		return 1;
	return 0;
}

void PRINT_STACK(STACK *S)
{
	STACK_NODE *temp;
	temp=S->top;
	while(temp!=NULL)
	{
		printf("%d @ %p\n",temp->data,temp);
		temp=temp->next;
	}
}
