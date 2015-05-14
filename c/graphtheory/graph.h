#include<limits.h>
#include"LinkedList.h"
#include"Queue.h"

typedef struct GRAPH GRAPH;
typedef struct VERTEX VERTEX;
GRAPH *CREATE_GRAPH(int SIZE);
void ADD_UNDIRECTED_EDGE(GRAPH *G,int v1,int v2);
void ADD_DIRECTED_EDGE(GRAPH *G,int v1,int v2);
void PRINT_TREE(GRAPH *G);
void PRINT_UNDIRECTED_GRAPH(GRAPH *G);
void printintArray(int *a,int l,int h);
void printcharArray(char *a,int l,int h);
void DFS(GRAPH *G);
void DFS_VISIT(GRAPH *G,VERTEX *u,int *time);
void PRINT_VERTEX(VERTEX *V);

void printcharArray(char *a,int l,int h){
	for(;l<=h;l++)
		printf("%c ",a[l]);
	printf("\n");
}

void printintArray(int *a,int l,int h){
	for(;l<=h;l++)
		printf("%d ",a[l]);
	printf("\n");
}

struct GRAPH{
	int N;
	VERTEX **V;
};

struct VERTEX{
	char color;
	int key,d,p,f,w;
	LINKED_LIST *adj;
};

VERTEX *CREATE_VERTEX(int i){
	VERTEX *V;
	V=(VERTEX *)malloc(sizeof(VERTEX));
	V->key=i;
	return V;
}
GRAPH *CREATE_GRAPH(int SIZE){
	GRAPH *G;
	G=(GRAPH *)malloc(sizeof(GRAPH));
	G->N=SIZE;
	G->V=(VERTEX **)malloc((G->N)*sizeof(VERTEX *));
	for(int i=0;i<G->N;i++){
		G->V[i]=CREATE_VERTEX(i);
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

//will produce graphviz ouput of a tree
//basically doing BFS
void PRINT_TREE(GRAPH *G){
	int *visited;
	visited=(int *)calloc((G->N),sizeof(int));
	QUEUE *Q;
	Q=(QUEUE *)malloc(sizeof(QUEUE));
	Q->head=NULL;
	int root=0;
	QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(root));
	//assuming a tree with 0th VERTEX as root
	visited[root]=1;
	printf("diGraph{\n");
	while(!IS_QUEUE_EMPTY(Q)){
		int s;
		s=QUEUE_DEQUEUE(Q)->data;
		printf("%d [shape=circle,style=filled,color=lightgrey]\n",s+1);
		LINKED_LIST_NODE *N;
		N=G->V[s]->adj->head;
		while(N!=NULL){
			if(!visited[N->key]){
				printf("%d [shape=circle,style=filled,color=lightgrey]\n",N->key+1);
				printf("%d -> %d\n",s+1,N->key+1);
				visited[N->key]=1;
				QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(N->key));
			}
			N=N->next;
		}
		free(N);
	}
	printf("}\n");
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

//strictly identicle to CLRS 3th edition BFS
void BFS(GRAPH *G){
	for(int i=1;i<G->N;i++){
		G->V[i]->color='w';
		G->V[i]->d=INT_MAX;
		G->V[i]->p=-1;
	}
	int start=0;
	G->V[start]->color='g';
	G->V[start]->d=0;
	G->V[start]->p=-1;
	QUEUE *Q;
	Q=CREATE_QUEUE();
	QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(start));
	while(!IS_QUEUE_EMPTY(Q)){
		int u=QUEUE_DEQUEUE(Q)->data;
		LINKED_LIST_NODE *N;
		N=G->V[u]->adj->head;
		while(N!=NULL){
			if(G->V[N->key]->color=='w'){
				G->V[N->key]->color='g';
				G->V[N->key]->d=G->V[u]->d+1;
				G->V[N->key]->p=u;
				QUEUE_ENQUEUE(Q,NEW_QUEUE_NODE(N->key));
			}
			N=N->next;	
		}
		G->V[u]->color='b';
	}
}

void DFS(GRAPH *G){
	for(int i=0;i<G->N;i++){
		G->V[i]->color='w';
		G->V[i]->p=-1;
	}
	int time=0;
	for(int i=0;i<G->N;i++){
		if(G->V[i]->color=='w'){
			DFS_VISIT(G,G->V[i],&time);
		}
	}
	for(int i=0;i<G->N;i++)
		PRINT_VERTEX(G->V[i]);
}

void PRINT_VERTEX(VERTEX *V){
	printf("key: %3d color: %c d: %3d f: %3d p: %3d\n",V->key+1,V->color,V->d,V->f,V->p+1);
}

void DFS_VISIT(GRAPH *G,VERTEX *u,int *time){
	u->d=++(*time);
	u->color='g';
	LINKED_LIST_NODE *N;
	N=u->adj->head;
	while(N!=NULL){
		if(G->V[N->key]->color=='w'){
			G->V[N->key]->p=u->key;
			DFS_VISIT(G,G->V[N->key],time);
		}
		N=N->next;
	}
	u->color='b';
	u->f=++(*time);
}
