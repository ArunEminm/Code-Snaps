#include"binarysearchtree.h"

int main(void){
	BST_TREE *T;
	T=CREATE_BST_TREE();
	BST_INSERT(T,NEW_BST_NODE(78));
	BST_INSERT(T,NEW_BST_NODE(732));
	BST_INSERT(T,NEW_BST_NODE(223));
	BST_INSERT(T,NEW_BST_NODE(337));
	BST_INSERT(T,NEW_BST_NODE(88));
	BST_INSERT(T,NEW_BST_NODE(100));
	BST_PrintInorderTraversal(T);
	BST_PrintPostorderTraversal(T);
	BST_PrintPreorderTraversal(T);
	printf("BST_MINIMUM: %d\n",BST_MINIMUM(T->root)->key);
	printf("BST_MAXIMUM: %d\n",BST_MAXIMUM(T->root)->key);
	return 0;
}
