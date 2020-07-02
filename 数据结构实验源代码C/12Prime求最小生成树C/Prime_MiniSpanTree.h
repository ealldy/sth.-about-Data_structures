#include <stdio.h> 
#include "MGraph.h" 

#define INF 32767		//INF��ʾ��
void Prim(MatGraph g, int v)
{
	int lowcost[MAXV];
	int min;
	int closest[MAXV],i,j,k;
	for(i=0;i<g.n;i++)	//��lowcost[]��closest[]�ó�ֵ
	{
		lowcost[i]= g.edges[v][i];
		closest[i]= v;
	}
	for(i=1;i<g.n;i++)	  //�ҳ�(n-1)������
	{
		min=INF;
		for(j=0;j<g.n;j++) //��(V-U)���ҳ���U����Ķ���k
		{
			if(lowcost[j]!=0 && lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;			//k��¼�������ı��
			}
		}
		 
		//�����Ա����� 
//		printf(" ��(%d,%d)ȨΪ:%d\n",closest[k],k,min);	
		//*�������ַ���� 
		InfoType value1 = g.vexs[closest[k]].info;
		InfoType value2 = g.vexs[k].info;
		printf(" ��(%c,%c)ȨΪ:%d\n",value1,value2,min);
		//*/
		
		lowcost[k]=0;		//���k�Ѿ�����U
		for(j=0;j<g.n;j++)	//�޸�����lowcost��closest
		{
			if(g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k;
			}
		}
	}
}

