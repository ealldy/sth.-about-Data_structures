#include <malloc.h>
#include <stdio.h>
#define INF 32767	//INF��ʾ��
#define MAXV  20  // ��󶥵����
typedef char InfoType; 

//�߽ڵ�����
typedef struct ANode
{   
	//�ߵ��յ���
	int adjvex;
	//��һ���ߵ�ָ��
    struct ANode *nextarc;
    //�ߵ������Ϣ
    int weight;
}ArcNode;

//�ڽӱ�ͷ�ڵ�����
typedef struct VNode	
{    
	//������Ϣ
	InfoType info;
	//ָ���һ����
    ArcNode *firstarc;
}VNode;

//ͼ�ڽӱ�����
typedef struct
{   
	//�ڽӱ�
	VNode adjlist[ MAXV ];
	//nΪ��������eΪ����
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
				p->nextarc = G->adjlist[i].firstarc;//ͷ�巨
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

//----------------------------------��ȱ��� 
//(ǿ)��ͨͼ������ȱ����㷨 
int visited[MAXV]={0};
void DFS(AdjGraph *G,int v)
{
	ArcNode *p;
	visited[v]=1;
	printf("%d(%c)",v,G->adjlist[v].info); //���v����Ͷ�����Ϣ
	//������ȱ�����v���ڵ�δ�����ʵĽ�� 
	p=G->adjlist[v].firstarc;
	while(p!=NULL)
	{
		if(visited[p->adjvex] == 0)
			DFS(G,p->adjvex);
		p = p->nextarc;		
	} 
} 
//��(ǿ)��ͨͼ��������ȱ����㷨
void DFS1(AdjGraph *G)
{
	int i;
	for(i=0;i<G->n;i++)
		if(visited[i]==0) DFS(G,i);
} 
//----------------------------------��ȱ���
//(ǿ)��ͨͼ�Ĺ�����ȱ����㷨 
#include "LinkQueue.h"
void BFS(AdjGraph *G,int v)
{
	int w,i; 
	ArcNode *p;
	LiQueue *qu;
	InitQueue(qu);
	for(i=0;i<G->n;i++) visited[i]=0; 
	
	visited[v]=1;
	printf("%d(%c)",v,G->adjlist[v].info); //���v����Ͷ�����Ϣ
	enQueue(qu,v);
	while(!QueueEmpty(qu))//ֻҪ���в�Ϊ�� 
	{
		deQueue(qu,w);
		p=G->adjlist[w].firstarc;
		while(p!=NULL)
		{
			if(visited[p->adjvex] == 0)
			{
				printf("%d(%c)",p->adjvex,G->adjlist[p->adjvex].info); //���v����Ͷ�����Ϣ
				visited[p->adjvex]=1;
				enQueue(qu,p->adjvex);
			}
			p=p->nextarc;
		}
	}
}
//��(ǿ)��ͨͼ�Ĺ�����ȱ����㷨 
void BFS1(AdjGraph *G)
{
	int i;
	for(i=0;i<G->n;i++)
		if(visited[i]==0) BFS(G,i);
}




