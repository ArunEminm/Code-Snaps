#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
typedef struct binarytree binarytree;

struct node{
	int data;
	node *left,*right;
};

struct binarytree{
	node *root;
	int size;
};

void inordertraversal(node *n){
	if(n!=NULL){
		inordertraversal(n->left);
		printf("%d ",n->data);
		inordertraversal(n->right);
	}
}

void swapnodes(binarytree *tree,int k){
	
}

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
	int length;
};

QUEUE *CREATE_QUEUE(){
	QUEUE *Q;
	Q=(QUEUE *)malloc(sizeof(QUEUE));
	Q->head=NULL;
	Q->length=0;
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
	Q->length+=1;
}


QUEUE_NODE *QUEUE_DEQUEUE(QUEUE *Q){
	QUEUE_NODE *temp;
	temp=Q->head;
	if(temp!=NULL){
		Q->head=Q->head->next;
		Q->length-=1;
		printf("QUEUE_DEQUEUED %d @ %p\n",temp->data,temp);
		return temp;
	}
	printf("QUEUE Empty\n");
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
	printf("Created node %d @ %p\n",temp->data,temp);
	return temp;
}

int **nodesatheight(binarytree *tree){
	int **arr;
		
}

int main(void){
	int n,l,r;
	binarytree *tree;
	tree=(binarytree *)malloc(sizeof(binarytree));
	scanf("%d",&n);
	tree->size=n;
	node **arrofnodes;
	arrofnodes=(node **)malloc(n*sizeof(node *));
	for(int i=0;i<n;i++){
		arrofnodes[i]=(node *)malloc(sizeof(node));
		arrofnodes[i]->data=i+1;
		arrofnodes[i]->left=NULL;
		arrofnodes[i]->right=NULL;
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&l,&r);
		if(l!=-1)
			arrofnodes[i]->left=arrofnodes[l-1];
		if(r!=-1)
			arrofnodes[i]->right=arrofnodes[r-1];
	}
	tree->root=arrofnodes[0];
	inordertraversal(tree->root);
	printf("\n");
	int t,k;
	scanf("%d",&t);
	while(t-->0){
		scanf("%d",&k);
		swapnodes(tree,k);
	}
	return 1;
}
