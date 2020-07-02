#include <malloc.h>
#include <stdio.h>
#define INF 32767	//INF表示∞
#define MAXV  20  // 最大顶点个数
typedef char InfoType; 

//边节点类型
typedef struct ANode
{   
	//边的终点编号
	int adjvex;
	//下一条边的指针
    struct ANode *nextarc;
    //边的相关信息
    int weight;
}ArcNode;

//邻接表头节点类型
typedef struct VNode	
{    
	//顶点信息
	InfoType info;
	//指向第一条边
    ArcNode *firstarc;
}VNode;

//图邻接表类型
typedef struct
{   
	//邻接表
	VNode adjlist[ MAXV ];
	//n为顶点数、e为边数
    int n, e;
}AdjGraph;

void CreateAdj(AdjGraph *&G, int A[N][N], char V[N], int n, int e)
{
	int i,j;
	ArcNode *p;
	G=(AdjGraph *)malloc(sizeof(AdjGraph));
	for(i=0;i<n;i++)
	{
		G->adjlist[i].info = V[i];
		G->adjlist[i].firstarc = NULL;
	}
	for(i=0;i<n;i++)
		for(j=n-1;j>=0;j--)
			if(A[i][j] != 0 && A[i][j] != INF)
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc = G->adjlist[i].firstarc;//头插法
				G->adjlist[i].firstarc = p; 
			}
	G->n = n;
	G->e = e;
}

void DispAdj(AdjGraph *G)
{
	ArcNode *p;
	for(int i=0;i<G->n;i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%d(%c): ",i,G->adjlist[i].info);
		while(p!=NULL)
		{
			printf("%d[%d]->",p->adjvex,p->weight);
			p=p->nextarc;	
		}
		printf("^\n");
	}
}

//----------------------------------深度遍历 
//(强)连通图深度优先遍历算法 
int visited[MAXV]={0};
void DFS(AdjGraph *G,int v)
{
	ArcNode *p;
	visited[v]=1;
	printf("%d(%c)",v,G->adjlist[v].info); //输出v编码和顶点信息
	//深度优先遍历与v相邻的未被访问的结点 
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visited[p->adjvex] == 0)
			DFS(G,p->adjvex);
		p = p->nextarc;		
	} 
} 
//非(强)连通图的深度优先遍历算法
void DFS1(AdjGraph *G)
{
	int i;
	for(i=0;i<G->n;i++)
		if(visited[i]==0) DFS(G,i);
} 
//----------------------------------广度遍历
//(强)连通图的广度优先遍历算法 
#include "LinkQueue.h"
void BFS(AdjGraph *G,int v)
{
	int w,i; 
	ArcNode *p;
	LiQueue *qu;
	InitQueue(qu);
	for(i=0;i<G->n;i++) visited[i]=0; 
	
	visited[v]=1;
	printf("%d(%c)",v,G->adjlist[v].info); //输出v编码和顶点信息
	enQueue(qu,v);
	while(!QueueEmpty(qu))//只要队列不为空 
	{
		deQueue(qu,w);
		p=G->adjlist[w].firstarc;
		while(p!=NULL)
		{
			if(visited[p->adjvex] == 0)
			{
				printf("%d(%c)",p->adjvex,G->adjlist[p->adjvex].info); //输出v编码和顶点信息
				visited[p->adjvex]=1;
				enQueue(qu,p->adjvex);
			}
			p=p->nextarc;
		}
	}
}
//非(强)连通图的广度优先遍历算法 
void BFS1(AdjGraph *G)
{
	int i;
	for(i=0;i<G->n;i++)
		if(visited[i]==0) BFS(G,i);
}




