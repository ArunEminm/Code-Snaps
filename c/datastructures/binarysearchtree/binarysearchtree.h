//Binary search tree are binary with BST_NODE->left->key < BST_NODE->key <BST_NODE->right->key
//By Arun Kumar
//Btech IIT Delhi


#include<stdio.h>
#include<stdlib.h>

typedef struct BST_NODE BST_NODE;
typedef struct BST_TREE BST_TREE;
//returns pointer to a BST_NODE
BST_NODE *NEW_BST_NODE(int k);
//BST_INSERT key into the tree
void BST_INSERT(BST_TREE *T,BST_NODE *z);
//checks if the root is NULL
int IS_BST_EMPTY(BST_NODE *root);
//BST_DELETE a BST_NODE from the tree
void BST_DELETE_NODE(BST_TREE *T,BST_NODE *z);
//inorder traversal
void BST_INORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root);
//BST_TRANSPLANT 
void BST_TRANSPLANT(BST_TREE *T,BST_NODE *u,BST_NODE *v);
//finds min key in the tree
BST_NODE *BST_MINIMUM(BST_NODE *root);
//finds maximum in tree
BST_NODE *BST_MAXIMUM(BST_NODE *root);
//finds BST_SUCCESSOR
BST_NODE *BST_SUCCESSOR(BST_NODE *x);
//finds BST_NODE with a particular key
BST_NODE *BST_SEARCH(BST_NODE *root,int k);
//BST_DELETE the BST_NODE with a particular key but if duplicates key are there you should use BST_DELETE_NODE
void BST_POSTORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root);
void BST_PREORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root);
BST_TREE *CREATE_BST_TREE(void);

struct BST_NODE{
	int key;
	BST_NODE *left;
	BST_NODE *right;
	BST_NODE *parent;
};

struct BST_TREE{
	BST_NODE *root;
	BST_NODE *nil;
};

BST_TREE *CREATE_BST_TREE(void){
	BST_TREE *T;
	T=(BST_TREE *)malloc(sizeof(BST_TREE));
	T->root=NULL;
	return T;
}

BST_NODE *NEW_BST_NODE(int k){
	BST_NODE *temp;
	temp=(BST_NODE *)malloc(sizeof(BST_NODE));
	temp->key=k;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	return temp;
}

int IS_BST_EMPTY(BST_NODE *root){
	if(root==NULL){
		return 1;
	}
	return 0;
}

void BST_INSERT(BST_TREE *T,BST_NODE *z){
	BST_NODE *x,*y;
	y=NULL;
	x=T->root;
	while(!IS_BST_EMPTY(x)){
		y=x;
		if(z->key < x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(IS_BST_EMPTY(y)){
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

BST_NODE *BST_SUCCESSOR(BST_NODE *x){
	BST_NODE *y;
	if(x->right!=NULL)
		return BST_MINIMUM(x->right);
	y=x->parent;
	while(y!=NULL || x==y->right){
		x=y;
		y=y->parent;
	}
	return y;
}

BST_NODE *BST_MINIMUM(BST_NODE *root){
	while(!IS_BST_EMPTY(root->left))
		root=root->left;
	return root;
}

BST_NODE *BST_MAXIMUM(BST_NODE *root){
	while(!IS_BST_EMPTY(root->right))
		root=root->right;
	return root;
}


BST_NODE *BST_SEARCH(BST_NODE *root,int k){
	if(IS_BST_EMPTY(root) || k==root->key){
		//printf("Found @ %p\n",root);
		return root;
	}
	else if(k < root->key)
		return BST_SEARCH(root->left,k);
	else
		return BST_SEARCH(root->right,k);
}

void BST_DELETE_NODE(BST_TREE *T,BST_NODE *z){
	BST_NODE *y;
	if(IS_BST_EMPTY(z->left))
		BST_TRANSPLANT(T,z,z->right);
	else if(IS_BST_EMPTY(z->right))
		BST_TRANSPLANT(T,z,z->left);
	else{
		y=BST_MINIMUM(z->right);
		if(y->parent!=z){
			BST_TRANSPLANT(T,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		BST_TRANSPLANT(T,z,y);
		y->left=z->left;
		y->left->parent=y;
	}
	//printf("Deleted BST_NODE @ %p\n",z);
}

void BST_TRANSPLANT(BST_TREE *T,BST_NODE *u,BST_NODE *v){
	if(IS_BST_EMPTY(u->parent))
		T->root=v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else
		u->parent->right=v;
	if(!IS_BST_EMPTY(v))
		v->parent=u->parent;
}

void BST_INORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root){
	if(!IS_BST_EMPTY(root)){
		BST_INORDER_TRAVERSAL(T,root->left);
		printf("%d ",root->key);
		BST_INORDER_TRAVERSAL(T,root->right);
	}
}

void BST_POSTORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root){
	if(!IS_BST_EMPTY(root)){
		BST_POSTORDER_TRAVERSAL(T,root->left);
		BST_POSTORDER_TRAVERSAL(T,root->right);
		printf("%d ",root->key);
	}
}

void BST_PREORDER_TRAVERSAL(BST_TREE *T,BST_NODE *root){
	if(!IS_BST_EMPTY(root)){
		printf("%d ",root->key);
		BST_PREORDER_TRAVERSAL(T,root->left);
		BST_PREORDER_TRAVERSAL(T,root->right);
	}
}

void BST_PrintPreorderTraversal(BST_TREE *T){
	printf("BST_PREORDER_TRAVERSAL:\n");
	BST_PREORDER_TRAVERSAL(T,T->root);
	printf("\n");
}

void BST_PrintInorderTraversal(BST_TREE *T){
	printf("BST_INORDER_TRAVERSAL:\n");
	BST_INORDER_TRAVERSAL(T,T->root);
	printf("\n");
}

void BST_PrintPostorderTraversal(BST_TREE *T){
	printf("BST_POSTORDER_TRAVERSAL:\n");
	BST_POSTORDER_TRAVERSAL(T,T->root);
	printf("\n");
}
