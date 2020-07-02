#include <stdio.h> 

#define INF 32767	//INF表示∞
#define MAXV  5  // 顶点个数
typedef char InfoType;
typedef struct 
{	int no; //顶点编号
	InfoType info;  //顶点其他信息，如顶点的字符
}VertexType; //顶点类型

typedef struct 
{	VertexType vexs[MAXV];//存放顶点信息
	int edges[MAXV][MAXV]; //邻接矩阵	
    int n,e; //顶点数，弧数
}MatGraph; //图的邻接矩阵类型


//图的初始化 
void InitMatrix(MatGraph &G, int A[MAXV][MAXV], InfoType *v, int n, int e) 
{	 G.n = n;
	 G.e = e;
	 for(int i=0;i<n;i++)
	 {
	 	G.vexs[i].no = i;
	 	G.vexs[i].info = v[i];
	 	for(int j=0;j<n;j++)
	 		G.edges[i][j] = A[i][j];
	 }	 	
} 

//显示邻接矩阵 
void DispMGraph(MatGraph G)  
{
	int i,j;
	for(i=0;i<G.n;i++)
	{
		for(j=0;j<G.n;j++)
		{
			if(G.edges[i][j]==INF)
			{
				printf("  ∞");
			}
			else
				printf("%4d",G.edges[i][j]);
		} 
		printf("\n");
	}
}
