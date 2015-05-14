//Binary search tree are binary with OST_BST_NODE->left->key < OST_BST_NODE->key <OST_BST_NODE->right->key
//By Arun Kumar
//Btech IIT Delhi


#include<stdio.h>
#include<stdlib.h>

typedef struct OST_BST_NODE OST_BST_NODE;
typedef struct OST_BST_TREE OST_BST_TREE;
//returns pointer to a OST_BST_NODE
OST_BST_NODE *NEW_OST_BST_NODE(int k);
//OST_BST_INSERT key into the tree
void OST_BST_INSERT(OST_BST_TREE *T,OST_BST_NODE *z);
//checks if the root is NULL
int IS_OST_BST_EMPTY(OST_BST_NODE *root);
//OST_BST_DELETE a OST_BST_NODE from the tree
void OST_BST_DELETE_NODE(OST_BST_TREE *T,OST_BST_NODE *z);
//inorder traversal
void OST_BST_INORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root);
//OST_BST_TRANSPLANT 
void OST_BST_TRANSPLANT(OST_BST_TREE *T,OST_BST_NODE *u,OST_BST_NODE *v);
//finds min key in the tree
OST_BST_NODE *OST_BST_MINIMUM(OST_BST_NODE *root);
//finds maximum in tree
OST_BST_NODE *OST_BST_MAXIMUM(OST_BST_NODE *root);
//finds OST_BST_SUCCESSOR
OST_BST_NODE *OST_BST_SUCCESSOR(OST_BST_NODE *x);
//finds OST_BST_NODE with a particular key
OST_BST_NODE *OST_BST_SEARCH(OST_BST_NODE *root,int k);
int OST_BST_RANK(OST_BST_TREE *T,OST_BST_NODE *x);
int OST_BST_SIZE(OST_BST_NODE *a);
void OST_BST_POSTORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root);
void OST_BST_PREORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root);
OST_BST_TREE *CREATE_OST_BST_TREE();

struct OST_BST_NODE{
	int key;
	int size;
	OST_BST_NODE *left;
	OST_BST_NODE *right;
	OST_BST_NODE *parent;
};

struct OST_BST_TREE{
	OST_BST_NODE *root;
	OST_BST_NODE *nil;
};

OST_BST_TREE *CREATE_OST_BST_TREE(){
	OST_BST_TREE *T;
	T=(OST_BST_TREE *)malloc(sizeof(OST_BST_TREE));
	T->root=NULL;
	return T;
}

OST_BST_NODE *NEW_OST_BST_NODE(int k){
	OST_BST_NODE *temp;
	temp=(OST_BST_NODE *)malloc(sizeof(OST_BST_NODE));
	temp->key=k;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	return temp;
}

int IS_OST_BST_EMPTY(OST_BST_NODE *root){
	if(root==NULL){
		return 1;
	}
	return 0;
}

void OST_BST_INSERT(OST_BST_TREE *T,OST_BST_NODE *z){
	OST_BST_NODE *x,*y;
	y=NULL;
	x=T->root;
	while(!IS_OST_BST_EMPTY(x)){
		y=x;
		y->size+=1;
		if(z->key < x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(IS_OST_BST_EMPTY(y)){
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
}

OST_BST_NODE *OST_BST_SUCCESSOR(OST_BST_NODE *x){
	OST_BST_NODE *y;
	if(x->right!=NULL)
		return OST_BST_MINIMUM(x->right);
	y=x->parent;
	while(y!=NULL || x==y->right){
		x=y;
		y=y->parent;
	}
	return y;
}

OST_BST_NODE *OST_BST_MINIMUM(OST_BST_NODE *root){
	while(!IS_OST_BST_EMPTY(root->left))
		root=root->left;
	return root;
}

OST_BST_NODE *OST_BST_MAXIMUM(OST_BST_NODE *root){
	while(!IS_OST_BST_EMPTY(root->right))
		root=root->right;
	return root;
}


OST_BST_NODE *OST_BST_SEARCH(OST_BST_NODE *root,int k){
	if(IS_OST_BST_EMPTY(root) || k==root->key){
		//printf("Found @ %p\n",root);
		return root;
	}
	else if(k < root->key)
		return OST_BST_SEARCH(root->left,k);
	else
		return OST_BST_SEARCH(root->right,k);
}

void OST_BST_DELETE_NODE(OST_BST_TREE *T,OST_BST_NODE *z){
	OST_BST_NODE *y;
	if(IS_OST_BST_EMPTY(z->left))
		OST_BST_TRANSPLANT(T,z,z->right);
	else if(IS_OST_BST_EMPTY(z->right))
		OST_BST_TRANSPLANT(T,z,z->left);
	else{
		y=OST_BST_MINIMUM(z->right);
		if(y->parent!=z){
			OST_BST_TRANSPLANT(T,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		OST_BST_TRANSPLANT(T,z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	//printf("Deleted OST_BST_NODE @ %p\n",z);
}

void OST_BST_TRANSPLANT(OST_BST_TREE *T,OST_BST_NODE *u,OST_BST_NODE *v){
	if(IS_OST_BST_EMPTY(u->parent))
		T->root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else
		u->parent->right=v;
	if(!IS_OST_BST_EMPTY(v))
		v->parent=u->parent;
}

void OST_BST_INORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root){
	if(!IS_OST_BST_EMPTY(root)){
		OST_BST_INORDER_TRAVERSAL(T,root->left);
		printf("key: %d size: %d @ %p\n",root->key,root->size,root);
		OST_BST_INORDER_TRAVERSAL(T,root->right);
	}
}

void OST_BST_POSTORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root){
	if(!IS_OST_BST_EMPTY(root)){
		OST_BST_POSTORDER_TRAVERSAL(T,root->left);
		OST_BST_POSTORDER_TRAVERSAL(T,root->right);
		printf("key: %d size: %d @ %p\n",root->key,root->size,root);
	}
}

void OST_BST_PREORDER_TRAVERSAL(OST_BST_TREE *T,OST_BST_NODE *root){
	if(!IS_OST_BST_EMPTY(root)){
		printf("key: %d size: %d @ %p\n",root->key,root->size,root);
		OST_BST_PREORDER_TRAVERSAL(T,root->left);
		OST_BST_PREORDER_TRAVERSAL(T,root->right);
	}
}

void OST_BST_PrintPreorderTraversal(OST_BST_TREE *T){
	printf("OST_BST_PREORDER_TRAVERSAL:\n");
	OST_BST_PREORDER_TRAVERSAL(T,T->root);
}

void OST_BST_PrintInorderTraversal(OST_BST_TREE *T){
	printf("OST_BST_INORDER_TRAVERSAL:\n");
	OST_BST_INORDER_TRAVERSAL(T,T->root);
}

void OST_BST_PrintPostorderTraversal(OST_BST_TREE *T){
	printf("OST_BST_POSTORDER_TRAVERSAL:\n");
	OST_BST_POSTORDER_TRAVERSAL(T,T->root);
}

int OST_BST_RANK(OST_BST_TREE *T,OST_BST_NODE *x){
	OST_BST_NODE *y;
	int count=0;
	y=x;
	count=OST_BST_SIZE(y->left)+1;
	while(y!=T->root){
		if(y==y->parent->right)
			count+=(OST_BST_SIZE(y->parent->left)+1);
		y=y->parent;
	}
	return count;
}

int OST_BST_SIZE(OST_BST_NODE *a){
	if(a==NULL)
		return 0;
	else
		return a->size;
}


