#include <iostream>
#include "Prime_MiniSpanTree.h"


int main(int argc, char** argv) {
	
	InfoType v[]={'A','B','C','D','E'};
	int A[5][5]={
		{	0,	8,INF,	4,INF},
		{	8,	0,	7,	5, 12},
		{ INF,	7,	0, 11,	6},
		{	4,	5, 11,	0,	3},
		{ INF, 12,	6,	3,	0}
	};
	
	MatGraph G;
	InitMatrix(G,A,v,5,8);
	printf("初始邻接矩阵为：\n"); 
	DispMGraph(G);
	
	printf("\n\n从编号0构造的最小生成树：\n");	
	Prim(G,0);
	
	printf("\n\n从编号1构造的最小生成树：\n");	
	Prim(G,1);
		
	
	return 0;
}
