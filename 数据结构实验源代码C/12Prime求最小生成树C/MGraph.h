#include <stdio.h> 

#define INF 32767	//INF��ʾ��
#define MAXV  5  // �������
typedef char InfoType;
typedef struct 
{	int no; //������
	InfoType info;  //����������Ϣ���綥����ַ�
}VertexType; //��������

typedef struct 
{	VertexType vexs[MAXV];//��Ŷ�����Ϣ
	int edges[MAXV][MAXV]; //�ڽӾ���	
    int n,e; //������������
}MatGraph; //ͼ���ڽӾ�������


//ͼ�ĳ�ʼ�� 
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

//��ʾ�ڽӾ��� 
void DispMGraph(MatGraph G)  
{
	int i,j;
	for(i=0;i<G.n;i++)
	{
		for(j=0;j<G.n;j++)
		{
			if(G.edges[i][j]==INF)
			{
				printf("  ��");
			}
			else
				printf("%4d",G.edges[i][j]);
		} 
		printf("\n");
	}
}
