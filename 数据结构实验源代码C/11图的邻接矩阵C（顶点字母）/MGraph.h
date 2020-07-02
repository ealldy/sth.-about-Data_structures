#include <stdio.h> 

typedef enum {DG,UDG,DN,UDN} GraphKind;    //����ͼ������ͼ����Ȩ����ͼ����Ȩ����ͼ
#define INF 32767	//INF��ʾ��
#define MAXV  20  // ��󶥵����
typedef char InfoType;
typedef struct 
{ 
	int no;	//������
	InfoType info;	//����������Ϣ���綥����ַ� 
}VertexType;	//��������

typedef struct  //ͼ�Ķ���
{  
	VertexType vexs[MAXV];	//��Ŷ�����Ϣ
	int edges[MAXV][MAXV]; 	//�ڽӾ���
    int vexnum,arcnum;  	//������������
    GraphKind kind;         //ͼ�������־
}MGraph;		//ͼ���ڽӾ����ʾ����


void InitMatrix(MGraph &G)  //��ʼ�����󣬱�����ÿ��ֵ��Ϊ0 
{
	printf("\n������ͼ�Ķ���������(���)����");
	scanf("%d,%d",&G.vexnum,&G.arcnum); 
	for(int i=0;i<G.vexnum;i++) 
	{
		G.vexs[i].no = i+1;
		printf("������ͼ�ĵ�%d��������Ϣ��",i+1);
		scanf("\n%c",&G.vexs[i].info);   //���춥������ 
	}
	for(int i=0;i<G.vexnum;i++)    //��ʼ������ 
		for(int j=0;j<G.vexnum;j++)
		{
			G.edges[i][j] = 0;
		}
} 

int LocateVex(MGraph &G,InfoType v) //���ض���v(�ַ�)������vexs��λ�� 
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i].info == v)
			return i+1;
	}
}

void CreateGraph(MGraph &G)
{
	printf("������ͼ�����ͣ�0Ϊ����ͼ/1Ϊ����ͼ/2Ϊ��Ȩ����ͼ/3Ϊ��Ȩ����ͼ����");
	scanf("%d",&G.kind);
	
	InitMatrix(G);  //��ʼ������arcs����ÿ��ֵ��Ϊ0 	
	
	switch(G.kind)
	{
		case DG:    //��������ͼG 
			printf("\n����ͼ\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				printf("�������%d���������յ㣺",k+1);
				scanf("\n%c,%c",&value1,&value2);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=1;
			}
			break;			
		case UDG:    //��������ͼG 
			printf("\n����ͼ\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				printf("�������%d���������Ķ��㣺",k+1);
				scanf("\n%c,%c",&value1,&value2);
				int v1=LocateVex(G,value1);
				int v2=LocateVex(G,value2);
				G.edges[v1-1][v2-1]=1;
				G.edges[v2-1][v1-1]=1;
			}		
			break;	
		case DN:     //�����Ȩ����ͼG 
			printf("\n��Ȩ����ͼ\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				int w;
				printf("�������%d������㡢�յ��Ȩֵ��",k+1);
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
		case UDN:    //�����Ȩ����ͼG 
			printf("\n��Ȩ����ͼ\n");
			for(int k=0;k<G.arcnum;k++)
			{	
				InfoType value1,value2;
				int w;
				printf("�������%d���������Ķ����Ȩֵ��",k+1);
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
			printf("����������");
	}
} 

void DispMGraph(MGraph G)  //��ʾ�ڽӾ��� 
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if((G.kind==DN || G.kind==UDN)&&G.edges[i][j]==INF)
			{
				printf("  ��");
			}
			else
				printf("%4d",G.edges[i][j]);
		} 
		printf("\n");
	}
}
