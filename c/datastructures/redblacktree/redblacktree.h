#include<stdio.h>
#include<stdlib.h>

typedef struct RB_NODE RB_NODE;
typedef struct RB_TREE RB_TREE;

struct RB_NODE{
	int key;
	char color;
	RB_NODE *parent;
	RB_NODE *left;
	RB_NODE *right;
};

struct RB_TREE{
	RB_NODE *root;
	RB_NODE *nil;
};

//TRANSPLANT 
void RB_TRANSPLANT(RB_TREE *T,RB_NODE *u,RB_NODE *v);
//finds minimum
RB_NODE *RB_MAXIMUM(RB_TREE *T,RB_NODE *root);
RB_NODE *RB_GRANDPARENT(RB_NODE *x);
RB_NODE *RB_MINIMUM(RB_TREE *T,RB_NODE *root);
//is it a left child
int RB_ISRIGHTCHILD(RB_NODE *r);
//is it a right child
int RB_ISLEFTCHILD(RB_NODE *l);
//find the sibling
RB_NODE *RB_SIBLING(RB_NODE *x);
RB_NODE *RB_UNCLE(RB_NODE *n);
void RB_INSERT(RB_TREE *T,RB_NODE *x);
void RB_INSERT_FIXUP(RB_TREE *T,RB_NODE *z);
void RB_ROTATE_LEFT(RB_TREE *T,RB_NODE *x);
void RB_ROTATE_RIGHT(RB_TREE *T,RB_NODE *x);
void RB_DELETE(RB_TREE *T,RB_NODE *z);
void RB_DELETE_FIXUP(RB_TREE *T,RB_NODE *x);
RB_TREE *CREATE_RB_TREE();
RB_NODE *NEW_RB_NODE(RB_TREE *T,int k);
void RB_SHOWNODE(RB_NODE *y);

RB_TREE *CREATE_RB_TREE(){
	RB_TREE *T;
	T=(RB_TREE *)malloc(sizeof(RB_TREE));
	T->nil=NEW_RB_NODE(T,-1);
	T->nil->color='B';
	T->root=T->nil;
	return T;
}

void RB_DELETE(RB_TREE *T,RB_NODE *z){
	RB_NODE *y,*x;
	y=z;
	char y_original_color=y->color;
	if(z->left==T->nil){
		x=z->right;
		RB_TRANSPLANT(T,z,z->right);
	}
	else if(z->right==T->nil){
		x=z->left;
		RB_TRANSPLANT(T,z,z->left);
	}
	else{
		y=RB_MINIMUM(T,z->right);
		y_original_color=y->color;
		x=y->right;
		if(y->parent==z)
			x->parent=y;
		else{
			RB_TRANSPLANT(T,y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		RB_TRANSPLANT(T,z,y);
		y->left=z->left;
		y->left->parent=y;
		y->color=z->color;
	}
//	printf("RB_DELETE Done\n");	
	if(y_original_color=='B')
		RB_DELETE_FIXUP(T,x);
}

void RB_DELETE_FIXUP(RB_TREE *T,RB_NODE *x){
	RB_NODE *w;
	while(x!=T->root && x->color=='B'){
		if(RB_ISLEFTCHILD(x)){
			w=RB_SIBLING(x);
			if(w->color=='R'){
				w->color='B';
				x->parent->color='R';
				RB_ROTATE_LEFT(T,x->parent);
				w=x->parent->right;
			}
			if(w->left->color=='B' && w->right->color=='B'){
				w->color='R';
				x=x->parent;
			}
			else{
				if(w->right->color=='B'){
					w->left->color='B';
					w->color='R';
					RB_ROTATE_RIGHT(T,w);
					w=x->parent->right;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->right->color='B';
				RB_ROTATE_LEFT(T,x->parent);
				x=T->root;
			}
		}
		else{
			w=RB_SIBLING(x);
			if(w->color=='R'){
				w->color='B';
				x->parent->color='R';
				RB_ROTATE_RIGHT(T,x->parent);
				w=x->parent->left;
			}
			if(w->right->color=='B' && w->left->color=='B'){
				w->color='R';
				x=x->parent;
			}
			else{
				if(w->left->color=='B'){
					w->right->color='B';
					w->color='R';
					RB_ROTATE_LEFT(T,w);
					w=x->parent->left;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->left->color='B';
				RB_ROTATE_RIGHT(T,x->parent);
				x=T->root;
			}
		}

	}
	x->color='B';
//	printf("RB_DELETE_FIXUP Done\n");
}

void RB_ROTATE_RIGHT(RB_TREE *T,RB_NODE *x){
	RB_NODE *y;
	y=x->left;
	x->left=y->right;
	if(y->right!=T->nil)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==T->nil)
		T->root=y;
	else{
		if(RB_ISRIGHTCHILD(x))
			x->parent->right=y;
		else
			x->parent->left=y;
	}
	y->right=x;
	x->parent=y;
//	printf("RB_ROTATE_RIGHT Done\n");
}

void RB_ROTATE_LEFT(RB_TREE *T,RB_NODE *x){
	RB_NODE *y;
	y=x->right;
	x->right=y->left;
	if(y->left!=T->nil)
		y->left->parent=x;
	y->parent=x->parent;
	if(x->parent==T->nil)
		T->root=y;
	else{
		if(RB_ISLEFTCHILD(x))
			x->parent->left=y;
		else
			x->parent->right=y;
	}
	y->left=x;
	x->parent=y;
//	printf("RB_ROTATE_LEFT Done\n");
}

void RB_INSERT_FIXUP(RB_TREE *T,RB_NODE *z){
	RB_NODE *y;
	while(z->parent->color=='R'){
	//	printf("Inside While RB_INSERT_FIXUP for RB_NODE @ %p\n",z);
		if(RB_ISLEFTCHILD(z->parent)){
		//	printf("Inside if->");
			y=RB_UNCLE(z);
			if(y->color=='R'){
			//	printf("case 1\n");
				z->parent->color='B';
				y->color='B';
				RB_GRANDPARENT(z)->color='R';
				z=RB_GRANDPARENT(z);
			}
			else{
				if(RB_ISRIGHTCHILD(z)){
			//		printf("case 2\n");
					z=z->parent;
					RB_ROTATE_LEFT(T,z);
				}
			//	printf("case 3\n");
				z->parent->color='B';
				RB_GRANDPARENT(z)->color='R';
				RB_ROTATE_RIGHT(T,RB_GRANDPARENT(z));
			}
		}
		else{
		//	printf("Inside else->");
			y=RB_UNCLE(z);
			if(y->color=='R'){
			//	printf("case 1\n");
				z->parent->color='B';
				y->color='B';
				RB_GRANDPARENT(z)->color='R';
				z=RB_GRANDPARENT(z);
			}
			else{
				if(RB_ISLEFTCHILD(z)){
				//	printf("case 2\n");
					z=z->parent;
					RB_ROTATE_RIGHT(T,z);
				}
			//	printf("case 3\n");
				z->parent->color='B';
				RB_GRANDPARENT(z)->color='R';
				RB_ROTATE_LEFT(T,RB_GRANDPARENT(z));
			}
		}
	}
	T->root->color='B';
//	printf("RB_INSERT_FIXUP Done\n");
}

void RB_INSERT(RB_TREE *T,RB_NODE *z){
	RB_NODE *x,*y;
	y=T->nil;
	x=T->root;
	while(x!=T->nil){
	//	printf("Inside WHILE RB_INSERT\n");
		//RB_SHOWNODE(T->nil);
		//RB_SHOWNODE(y);
		y=x;
		if(z->key < x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==T->nil){
		T->root=z;
	}
	else if(z->key < y->key){
		y->left=z;
	}
	else{
		y->right=z;
	}
	z->left=T->nil;
	z->right=T->nil;
	z->color='R';
//	printf("RB_INSERT Done\n");
	RB_INSERT_FIXUP(T,z);
}

RB_NODE *RB_UNCLE(RB_NODE *n){
	return RB_SIBLING(n->parent);	
}

RB_NODE *RB_GRANDPARENT(RB_NODE *x){
	return x->parent->parent;
}

RB_NODE *RB_SIBLING(RB_NODE *x){
	if(RB_ISLEFTCHILD(x))
		return x->parent->right;
	else
		return x->parent->left;
}

int RB_ISLEFTCHILD(RB_NODE *l){
	if(l==l->parent->left)
		return 1;
	return 0;
}

int RB_ISRIGHTCHILD(RB_NODE *r){
	if(r==r->parent->right)
		return 1;
	return 0;
}


RB_NODE *RB_MINIMUM(RB_TREE *T,RB_NODE *root){
	while(root->left!=T->nil)
		root=root->left;
	return root;
}

RB_NODE *RB_MAXIMUM(RB_TREE *T,RB_NODE *root){
	while(root->right!=T->nil)
		root=root->right;
	return root;
}

void RB_TRANSPLANT(RB_TREE *T,RB_NODE *u,RB_NODE *v){
	if(u->parent==T->nil)
		T->root=v;
	else if(RB_ISLEFTCHILD(u))
		u->parent->left=v;
	else
		u->parent->right=v;
	v->parent=u->parent;
//	printf("TRANSPLANT Done\n");
}

void RB_INORDER_TRAVERSAL(RB_TREE *T,RB_NODE *root){
	if(root!=T->nil){
		RB_INORDER_TRAVERSAL(T,root->left);
		RB_SHOWNODE(root);
		RB_INORDER_TRAVERSAL(T,root->right);
	}
}

void RB_PrintInorderTraversal(RB_TREE *T){
	printf("RB_INORDER_TRAVERSAL:\n");
	RB_INORDER_TRAVERSAL(T,T->root);
}

RB_NODE *NEW_RB_NODE(RB_TREE *T,int k){
	RB_NODE *x;
	x=(RB_NODE *)malloc(sizeof(RB_NODE));
//	printf("Created RB_NODE @ %p\n",x);
	x->key=k;
//	RB_SHOWNODE(x);
	return x;
}

void RB_SHOWNODE(RB_NODE *y){
	printf("key: %d color: %c @ %p\n",y->key,y->color,y);	
}


