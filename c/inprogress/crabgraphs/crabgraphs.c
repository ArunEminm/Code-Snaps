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

//By Arun Kumar
//Btech IIT Delhi

#include<stdio.h>
#include<stdlib.h>

typedef struct QUEUE_NODE QUEUE_NODE;
typedef struct QUEUE QUEUE;

void QUEUE_ENQUEUE(QUEUE *Q,QUEUE_NODE *N);
QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q);
void PRINT_QUEUE(QUEUE *Q);
int IS_QUEUE_EMPTY(QUEUE *Q);
QUEUE_NODE *NEW_QUEUE_NODE(int k);
QUEUE *CREATE_QUEUE();

struct QUEUE_NODE{
	int data;
	QUEUE_NODE *next;
};

struct QUEUE{
	QUEUE_NODE *head;
	QUEUE_NODE *tail;
};

QUEUE *CREATE_QUEUE(){
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
	N->next=NULL;
}


QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q){
	QUEUE_NODE *temp;
	temp=Q->head;
	if(temp!=NULL){
		Q->head=Q->head->next;
		//printf("QUEUE_DEQUEUED %d @ %p\n",temp->data,temp);
		return temp;
	}
//	printf("QUEUE Empty\n");
	return temp;
}


void PRINT_QUEUE(QUEUE *Q){
	QUEUE_NODE *temp;
	temp=Q->head;
	while(temp!=NULL){
		printf("%d @ %p\n",temp->data,temp);
		temp=temp->next;
	}
	free(temp);
}

int IS_QUEUE_EMPTY(QUEUE *Q){
	if(Q->head==NULL)
		return 1;
	return 0;
}

QUEUE_NODE *NEW_QUEUE_NODE(int k){
	QUEUE_NODE *temp;
	temp=(QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
	temp->data=k;
	//printf("Created node %d @ %p\n",temp->data,temp);
	return temp;
}

typedef struct GRAPH GRAPH;
typedef struct VERTEX VERTEX;
GRAPH *CREATE_GRAPH(int SIZE);
void ADD_UNDIRECTED_EDGE(GRAPH *G,int v1,int v2);
void ADD_DIRECTED_EDGE(GRAPH *G,int v1,int v2);

struct GRAPH{
	int N;
	VERTEX **V;
};

struct VERTEX{
	LINKED_LIST *adj;
};

VERTEX *CREATE_VERTEX(){
	VERTEX *V;
	V=(VERTEX *)malloc(sizeof(VERTEX));
	return V;
}
GRAPH *CREATE_GRAPH(int SIZE){
	GRAPH *G;
	G=(GRAPH *)malloc(sizeof(GRAPH));
	G->N=SIZE;
	G->V=(VERTEX **)malloc((G->N)*sizeof(VERTEX *));
	for(int i=0;i<G->N;i++){
		G->V[i]=CREATE_VERTEX();
		G->V[i]->adj=CREATE_LINKED_LIST();
	}
	return G;
}

//v1,v2 are zero indexed vertex no.
void ADD_UNDIRECTED_EDGE(GRAPH *G,int v1,int v2){
		LINKED_LIST_ADD_LAST(G->V[v1]->adj,LINKED_LIST_NEWNODE(v2));
		LINKED_LIST_ADD_LAST(G->V[v2]->adj,LINKED_LIST_NEWNODE(v1));
}
//v1,v2 are zero indexed vertex no.
void ADD_DIRECTED_EDGE(GRAPH *G,int v1,int v2){
		LINKED_LIST_ADD_LAST(G->V[v1]->adj,LINKED_LIST_NEWNODE(v2));
}

void PRINT_UNDIRECTED_GRAPH(GRAPH *G){
	int **edges;
	edges=(int **)malloc((G->N)*sizeof(int *));
	for(int i=0;i<G->N;i++)
		edges[i]=(int *)calloc((G->N),sizeof(int));
	int start=0;
	printf("Graph{\n");
	for(int i=start;i<G->N;i++){
		printf("%d [shape=circle,style=filled,color=lightgrey]\n",i+1);
		LINKED_LIST_NODE *N;
		N=G->V[i]->adj->head;
		while(N!=NULL){
			if(!edges[i][N->key]){
				edges[i][N->key]=1;
				edges[N->key][i]=1;
				printf("%d [shape=circle,style=filled,color=lightgrey]\n",N->key+1);
				printf("%d -- %d\n",i+1,N->key+1);
			}
			N=N->next;
		}
	}
	printf("}\n");
	
}

void CrabGraph(GRAPH *G,int T){
	
}

int main(void){
	int C,N,T,M;
	scanf("%d",&C);
	while(C-->0){
		GRAPH *G;
		scanf("%d %d %d",&N,&T,&M);
		G=CREATE_GRAPH(N);
		while(M-->0){
			int v1,v2;
			scanf("%d %d",&v1,&v2);
			ADD_UNDIRECTED_EDGE(G,v1-1,v2-1);
		}
		for(int i=0;i<G->N;i++){
			printf("[ADJ]: %d\n",G->V[i]->adj->length);
			PRINT_LINKED_LIST(G->V[i]->adj);
		}
		CrabGraph(G,T);
		free(G);
	}
	return 1;
}
