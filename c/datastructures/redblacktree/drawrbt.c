//By Arun Kumar
//Btech IIT Delhi

#include"queueofrbtnodes.h"

void Dump(RB_TREE *T){
	printf("digraph G {\n");
	QUEUE *Q;
	Q=CREATE_QUEUE();
	QUEUE_NODE *r;
	r=(QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
	r->data=T->root;
	QUEUE_ENQUEUE(Q,r);
	printf("\"%p\" [label=\"T.nil\\n%p\",shape=circle,style=filled,color=lightgrey]\n",T->root,T->root);
	printf("\"%p\" -> \"%p\"\n",T->nil,T->root);
	printf("\"%p\" [label=\"%d\\n%p\",shape=circle,style=filled,color=lightgrey]\n",T->root,T->root->key,T->root);
	while(!IS_QUEUE_EMPTY(Q)){
		RB_NODE *t=QUEUE_DEQUEUE(Q)->data;
		{
			if(t->left->color=='R')
				printf("\"%p\" [label=\"%d\\n%p\",shape=circle,style=filled,color=red]\n",t->left,t->left->key,t->left);
			else
				printf("\"%p\" [label=\"%d\\n%p\",shape=circle,style=filled,color=lightgrey]\n",t->left,t->left->key,t->left);
			printf("\"%p\" -> \"%p\"\n",t,t->left);
			
		if(t->left!=T->nil){
			QUEUE_NODE *l;
			l=(QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
			l->data=t->left;
			QUEUE_ENQUEUE(Q,l);
		}
		}
		{
			if(t->right->color=='R')
				printf("\"%p\" [label=\"%d\\n%p\",shape=circle,style=filled,color=red]\n",t->right,t->right->key,t->right);
			else
				printf("\"%p\" [label=\"%d\\n%p\",shape=circle,style=filled,color=lightgrey]\n",t->right,t->right->key,t->right);
			
		if(t->right!=T->nil){
			QUEUE_NODE *r;
			r=(QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
			r->data=t->right;
			printf("\"%p\" -> \"%p\"\n",t,t->right);
			QUEUE_ENQUEUE(Q,r);
		}
		}
	}
	printf("}");
}

int main(void){
	RB_TREE *T;
	T=CREATE_RB_TREE();
	int n;
	n=100;
	RB_NODE **RB_NODE_arr;
	RB_NODE_arr=(RB_NODE **)malloc(n*sizeof(RB_NODE *));
	for(int i=0;i<n;i++){
		RB_NODE_arr[i]=NEW_RB_NODE(T,rand()%n+n);
		RB_INSERT(T,RB_NODE_arr[i]);
	}
//	for(int i=1;i<923;i++)
//		RB_DELETE(T,RB_NODE_arr[i]);
	Dump(T);
	return 0;
}
