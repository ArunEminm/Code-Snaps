#include "orderstatistictreewithbinarysearchtree.h"

int main(void){
	OST_BST_TREE *T;
	T=CREATE_OST_BST_TREE();
	OST_BST_INSERT(T,NEW_OST_BST_NODE(23));
	OST_BST_INSERT(T,NEW_OST_BST_NODE(23));
	OST_BST_INSERT(T,NEW_OST_BST_NODE(23));
	OST_BST_INSERT(T,NEW_OST_BST_NODE(23));
	OST_BST_NODE *x;
	x=NEW_OST_BST_NODE(21);
	OST_BST_INSERT(T,x);
	printf("OST_BST_RANK of node @ %p: %d\n",x,OST_BST_RANK(T,x));
	x=NEW_OST_BST_NODE(22);
	OST_BST_INSERT(T,x);
	printf("OST_BST_RANK of node @ %p: %d\n",x,OST_BST_RANK(T,x));
	OST_BST_PrintInorderTraversal(T);
	return 0;
}
