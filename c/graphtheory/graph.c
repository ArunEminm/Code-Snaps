#include"graph.h"

int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	GRAPH *G;
	G=CREATE_GRAPH(n);
	while(m-->0){
		int v1,v2;
		scanf("%d %d",&v1,&v2);
		ADD_UNDIRECTED_EDGE(G,v1-1,v2-1);
	}
	PRINT_TREE(G);
	PRINT_UNDIRECTED_GRAPH(G);
	BFS(G);
	DFS(G);
	return 0;
}
