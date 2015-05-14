#include<stdio.h>
#include<stdlib.h>

typedef struct node node;
typedef struct Tree Tree;

//returns pointer to a node
node *NEWNODE(int k);
//INSERT key into the tree
void INSERT(Tree *T,node *z);
//checks if the root is NULL
int isEmpty(node *root);
//DELETE a node from the tree
void DELETE_NODE(Tree *T,node *z);
//inorder traversal
void INORDER_TRAVERSAL(Tree *T,node *root);
//TRANSPLANT 
void TRANSPLANT(Tree *T,node *u,node *v);
//finds min key in the tree
node *MINIMUM(node *root);
//finds node with a particular key
node *SEARCH(node *root,int k);
//DELETE the node with a particular key
void DELETE(Tree *T,int k);
//return size of node
int SIZE(node *a);
//update size of node
void UPDATE_SIZE(Tree *T,node *a);
//return rank of a node
int Rank(Tree *T,node *x);

struct node{
	int key;
	node *left;
	node *right;
	node *parent;
	int size;
};

struct Tree{
	node *root;
	node *nil;
};

node *NEWNODE(int k){
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->key=k;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	temp->size=1;
	return temp;
}

int isEmpty(node *root){
	if(root==NULL){
		return 1;
	}
	return 0;
}

void INSERT(Tree *T,node *z){
	node *x,*y;
	y=NULL;
	x=T->root;
	while(!isEmpty(x)){
		y=x;
		if(z->key < x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(isEmpty(y)){
		T->root=z;
		//printf("Inserted @ %p\n",z);
	}
	else if(z->key < y->key){
		y->left=z;
		//printf("Inserted @ %p\n",z);
	}
	else{
		y->right=z;
		//printf("Inserted @ %p\n",z);
	}
	UPDATE_SIZE(T,z);
}

node *MINIMUM(node *root){
	while(!isEmpty(root->left))
		root=root->left;
	return root;
}

node *SEARCH(node *root,int k){
	if(isEmpty(root) || k==root->key){
		//printf("Found @ %p\n",root);
		return root;
	}
	else if(k < root->key)
		return SEARCH(root->left,k);
	else
		return SEARCH(root->right,k);
}

void DELETE(Tree *T,int k){
	node *y;
	y=SEARCH(T->root,k);
	if(!isEmpty(y))
		DELETE_NODE(T,y);
}

void DELETE_NODE(Tree *T,node *z){
	node *y;
	if(isEmpty(z->left))
		TRANSPLANT(T,z,z->right);
	else if(isEmpty(z->right))
		TRANSPLANT(T,z,z->left);
	else{
		y=MINIMUM(z->right);
		if(y->parent!=z){
			TRANSPLANT(T,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		TRANSPLANT(T,z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	//printf("Deleted node @ %p\n",z);
}

void TRANSPLANT(Tree *T,node *u,node *v){
	if(isEmpty(u->parent))
		T->root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else
		u->parent->right=v;
	if(!isEmpty(v))
		v->parent=u->parent;
}

void INORDER_TRAVERSAL(Tree *T,node *root){
	if(!isEmpty(root)){
		INORDER_TRAVERSAL(T,root->left);
		printf("Key: %5d Size: %5d Rank: %5d\n",root->key,root->size,Rank(T,root));
		INORDER_TRAVERSAL(T,root->right);
	}
}

void PrintInorderTraversal(Tree *T){
	printf("INORDER_TRAVERSAL:\n");
	INORDER_TRAVERSAL(T,T->root);
	printf("\n");
}

void UPDATE_SIZE(Tree *T,node *a){
	while(a!=T->root){
		a->parent->size+=1;
		a=a->parent;
	}
}

int Rank(Tree *T,node *x){
	node *y;
	int count=0;
	y=x;
	count=SIZE(y->left)+1;
	while(y!=T->root){
		if(y==y->parent->right)
			count+=(SIZE(y->parent->left)+1);
		y=y->parent;
	}
	return count;
}

int SIZE(node *a){
	if(a==NULL)
		return 0;
	else
		return a->size;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t-->0){
		int n,val;
		scanf("%d",&n);
		Tree *T;
		long count=0l;
		T=(Tree *)malloc(sizeof(Tree));
		T->root=NULL;T->nil=NULL;
		for(int i=0;i<n;i++){
			scanf("%d",&val);
			node *new;
			new=NEWNODE(val);
			INSERT(T,new);
			count+=i+1-Rank(T,new);
		}
		printf("%ld\n",count);
	}
	return 0;
}

