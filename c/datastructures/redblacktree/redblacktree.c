#include"redblacktree.h"

int main(void){
	RB_TREE *T;
	T=CREATE_RB_TREE();
	int n;
	n=50;
	RB_NODE **RB_NODE_arr;
	RB_NODE_arr=(RB_NODE **)malloc(n*sizeof(RB_NODE *));
	for(int i=0;i<n;i++){
		RB_NODE_arr[i]=NEW_RB_NODE(T,rand()%300+100);
		RB_INSERT(T,RB_NODE_arr[i]);
	}
	for(int i=0;i<n/2;i++){
		RB_DELETE(T,RB_NODE_arr[i]);
	}
	RB_PrintInorderTraversal(T);
	return 0;
}
