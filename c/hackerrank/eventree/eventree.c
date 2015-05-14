#include<stdio.h>
#include<stdlib.h>

typedef struct LINKED_LIST LINKED_LIST;
typedef struct GRAPH GRAPH;
typedef struct VERTEX VERTEX;
typedef struct LINKED_LIST_NODE LINKED_LIST_NODE;
typedef struct QUEUE_NODE QUEUE_NODE;
typedef struct QUEUE QUEUE;

void QUEUE_ENQUEUE(QUEUE *Q,QUEUE_NODE *N);
QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q);
void PRINT_QUEUE(QUEUE *Q);
int IS_QUEUE_EMPTY(QUEUE *Q);
QUEUE_NODE *NEW_QUEUE_NODE(int k);
int LINKED_LIST_LENGTH(LINKED_LIST *L);
void LINKED_LIST_ADD_LAST(LINKED_LIST *L, LINKED_LIST_NODE *N);
void LINKED_LIST_ADD_FIRST(LINKED_LIST *L, LINKED_LIST_NODE *N);
void PRINT_LINKED_LIST(LINKED_LIST *L);
LINKED_LIST_NODE *LINKED_LIST_NEWNODE(int k);
void printArray(int *arr,int l,int h);
void EvenTree(GRAPH *G);

struct LINKED_LIST{
	LINKED_LIST_NODE *head;
	LINKED_LIST_NODE *tail;
	int length;
};

struct LINKED_LIST_NODE{
	int key;
	LINKED_LIST_NODE *next;
};

struct GRAPH{
	int N;
	VERTEX **V;
};

struct VERTEX{
	LINKED_LIST *adj;
};

struct QUEUE_NODE{
	int data;
	QUEUE_NODE *next;
};

struct QUEUE{
	QUEUE_NODE *head;
	QUEUE_NODE *tail;
};

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
	//printf("QUEUE Empty\n");
	return temp;
}


void PRINT_QUEUE(QUEUE *Q){
	QUEUE_NODE *temp;
	temp=Q->head;
	while(temp!=NULL){
	//	printf("%d @ %p\n",temp->data,temp);
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
		L->tail->next=NULL;
	}
	else{
		L->tail->next=N;
		L->tail=N;
		L->tail->next=NULL;
	}
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

void EvenTree(GRAPH *G){
	int *parent,*visited;
	int *childs;
	childs=(int *)calloc((G->N),sizeof(int));
	visited=(int *)calloc((G->N),sizeof(int));
	parent=(int *)malloc((G->N)*sizeof(int));
	for(int i=0;i<G->N;i++)
		parent[i]=-1;
	QUEUE *Q;
	Q=(QUEUE *)malloc(sizeof(QUEUE));
	Q->head=NULL;
	QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(0));
	visited[0]=1;
	//printf("diGraph{\n");
	while(!IS_QUEUE_EMPTY(Q)){
		int s;
		s=QUEUE_DEQUEUE(Q)->data;
	//	printf("%d [shape=circle,style=filled,color=lightgrey]\n",s+1);
		LINKED_LIST_NODE *N;
		N=G->V[s]->adj->head;
		while(N!=NULL){
			if(!visited[N->key]){
			//	printf("%d [shape=circle,style=filled,color=lightgrey]\n",N->key+1);
			//	printf("%d -> %d\n",s+1,N->key+1);
				parent[N->key]=s;
				childs[s]+=1;
				visited[N->key]=1;
				QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(N->key));
			}
			N=N->next;
		}
		free(N);
		childs[s]+=1;
	}
	for(int i=0;i<G->N-1;i++)
		visited[i]=0;
	int answer=0;
	for(int i=0;i<G->N;i++){
		if(childs[i]==1){
			int p=i,add;
			//stopping the loop 1 node before the path repetetion occurs
			while(p!=0 && !visited[parent[p]]){
				//printf("edge [color=green]\n");
				//printf("%d -> %d\n",p+1,parent[p]+1);
				visited[parent[p]]=1;
				add=childs[p]-1;
				childs[parent[p]]+=add;
				p=parent[p];
			}
			//this will be added in the repeteted path
			add=childs[p]-1;
			while(p!=0){
				//printf("edge [color=red]\n");
				//printf("%d -> %d\n",p+1,parent[p]+1);
				childs[parent[p]]+=add;
				p=parent[p];
			}
		}
	}
//	printf("}\n");
	for(int i=1;i<G->N;i++){
		if(childs[i]%2==0)
			answer+=1;
	}
	//printArray(childs,0,G->N-1);
	printf("%d\n",answer);
}

void printArray(int *arr,int l,int h){
	for(;l<=h;l++)
		printf("%3d__%3d\n",l+1,arr[l]);
}

int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	GRAPH *G;
	G=(GRAPH *)malloc(sizeof(GRAPH));
	G->N=n;
	G->V=(VERTEX **)malloc(n*sizeof(VERTEX *));
	for(int i=0;i<n;i++){
		G->V[i]=(VERTEX *)malloc(sizeof(VERTEX));
		G->V[i]->adj=(LINKED_LIST *)malloc(sizeof(LINKED_LIST));
		G->V[i]->adj->head=NULL;
	}
	while(m-->0){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		LINKED_LIST_ADD_LAST(G->V[v1-1]->adj,LINKED_LIST_NEWNODE(v2-1));
		LINKED_LIST_ADD_LAST(G->V[v2-1]->adj,LINKED_LIST_NEWNODE(v1-1));
	}
	EvenTree(G);
	return 0;
}
