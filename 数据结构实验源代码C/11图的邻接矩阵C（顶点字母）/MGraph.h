#include <stdio.h> 

typedef enum {DG,UDG,DN,UDN} GraphKind;    //有向图，无向图，带权有向图，带权无向图
#define INF 32767	//INF表示∞
#define MAXV  20  // 最大顶点个数
typedef char InfoType;
typedef struct 
{ 
	int no;	//顶点编号
	InfoType info;	//顶点其他信息，如顶点的字符 
}VertexType;	//顶点类型

typedef struct  //图的定义
{  
	VertexType vexs[MAXV];	//存放顶点信息
	int edges[MAXV][MAXV]; 	//邻接矩阵
    int vexnum,arcnum;  	//顶点数，弧数
    GraphKind kind;         //图的种类标志
}MGraph;		//图的邻接矩阵表示类型


void InitMatrix(MGraph &G)  //初始化矩阵，边向量每个值都为0 
{
	printf("\n请输入图的顶点数、弧(或边)数：");
	scanf("%d,%d",&G.vexnum,&G.arcnum); 
	for(int i=0;i<G.vexnum;i++) 
	{
		G.vexs[i].no = i+1;
		printf("请输入图的第%d个顶点信息：",i+1);
		scanf("\n%c",&G.vexs[i].info);   //构造顶点向量 
	}
	for(int i=0;i<G.vexnum;i++)    //初始化矩阵 
		for(int j=0;j<G.vexnum;j++)
		{
			G.edges[i][j] = 0;
		}
} 

int LocateVex(MGraph &G,InfoType v) //返回顶点v(字符)在数组vexs的位置 
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i].info == v)
			return i+1;
	}
}

void CreateGraph(MGraph &G)
{
	printf("请输入图的类型（0为有向图/1为无向图/2为带权有向图/3为带权无向图）：");
	scanf("%d",&G.kind);
	
	InitMatrix(G);  //初始化矩阵，arcs向量每个值都为0 	
	
	switch(G.kind)
	{
		case DG:    //构造有向图G 
			printf("\n有向图\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				printf("请输入第%d条边起点和终点：",k+1);
				scanf("\n%c,%c",&value1,&value2);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=1;
			}
			break;			
		case UDG:    //构造无向图G 
			printf("\n无向图\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				printf("请输入第%d条边依附的顶点：",k+1);
				scanf("\n%c,%c",&value1,&value2);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=1;
				G.edges[v2-1][v1-1]=1;
			}		
			break;	
		case DN:     //构造带权有向图G 
			printf("\n带权有向图\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				int w;
				printf("请输入第%d条边起点、终点和权值：",k+1);
				scanf("\n%c,%c,%d",&value1,&value2,&w);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=w;
			}
			for(int i=0;i<G.vexnum;i++)
			{
				for(int j=0;j<G.vexnum;j++)
				{
					if(G.edges[i][j]==0 && i!=j)
						G.edges[i][j]=INF;		
				}
			} 
			break;
		case UDN:    //构造带权无向图G 
			printf("\n带权无向图\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				int w;
				printf("请输入第%d条边依附的顶点和权值：",k+1);
				scanf("\n%c,%c,%d",&value1,&value2,&w);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=w;
				G.edges[v2-1][v1-1]=w; 
			}
			for(int i=0;i<G.vexnum;i++)
			{
				for(int j=0;j<G.vexnum;j++)
				{
					if(G.edges[i][j]==0 && i!=j)
						G.edges[i][j]=INF;		
				}
			} 
			break;
		default:
			printf("请重新输入");
	}
} 

void DispMGraph(MGraph G)  //显示邻接矩阵 
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if((G.kind==DN || G.kind==UDN)&&G.edges[i][j]==INF)
			{
				printf("  ∞");
			}
			else
				printf("%4d",G.edges[i][j]);
		} 
		printf("\n");
	}
}
