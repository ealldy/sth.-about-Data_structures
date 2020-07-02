#include <stdio.h> 
#include "MGraph.h" 

#define INF 32767		//INF表示∞
void Prim(MatGraph g, int v)
{
	int lowcost[MAXV];
	int min;
	int closest[MAXV],i,j,k;
	for(i=0;i<g.n;i++)	//给lowcost[]和closest[]置初值
	{
		lowcost[i]= g.edges[v][i];
		closest[i]= v;
	}
	for(i=1;i<g.n;i++)	  //找出(n-1)个顶点
	{
		min=INF;
		for(j=0;j<g.n;j++) //在(V-U)中找出离U最近的顶点k
		{
			if(lowcost[j]!=0 && lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;			//k记录最近顶点的编号
			}
		}
		 
		//顶点以编号输出 
//		printf(" 边(%d,%d)权为:%d\n",closest[k],k,min);	
		//*顶点以字符输出 
		InfoType value1 = g.vexs[closest[k]].info;
		InfoType value2 = g.vexs[k].info;
		printf(" 边(%c,%c)权为:%d\n",value1,value2,min);
		//*/
		
		lowcost[k]=0;		//标记k已经加入U
		for(j=0;j<g.n;j++)	//修改数组lowcost和closest
		{
			if(g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k;
			}
		}
	}
}

