#include "MGraph.h"
#define N 5
#include "AdjGraph.h"

int main(int argc, char** argv) {
		
	/*邻接矩阵 
	MGraph G;
	CreateGraph(G);
	printf("\n该图的邻接矩阵为：\n");
	DispMGraph(G);
	//*/ 
	
	
	//*邻接表方式 
	
	//定义顶点信息
	char vex[N]={'a','b','c','d','e'}; 
	//*定义邻接矩阵(带权有向图) 
	int A[N][N]={
	{0,6,2,INF,INF},
	{INF,0,INF,INF,3},
	{INF,3,0,1,INF},
	{INF,4,INF,0,5},
	{INF,INF,INF,INF,0}
	};
	//*/ 
	/*定义邻接矩阵(带权无向图) 
	int A[N][N]={
	{0,6,2,INF,INF},
	{6,0,3,4,3},
	{2,3,0,1,INF},
	{INF,4,1,0,5},
	{INF,3,INF,5,0}
	};
	//*/
	
	AdjGraph *G;
	CreateAdj(G,A,vex,5,7);
	DispAdj(G);
	printf("图顶点数和边数分别为：(%d,%d)",G->n,G->e);
	//*/
	
	//*深度优先遍历算法 
	printf("\n\n\n深度优先遍历：");
	DFS(G,1);	
	printf("\n\n\n");
	DFS1(G);
	//*/
	
	/*广度优先遍历算法
	printf("\n\n\n广度优先遍历：");
	BFS(G,1);	
	printf("\n\n\n");
	BFS1(G);
	//*/ 
	
	
	printf("\n\n\n");
	return 0;
}
