#include <malloc.h>
#include <stdio.h> 

typedef int ElemType;
#define M 8
#define N 8

#define MaxSize 100
typedef struct {
     int r;
	 int c;   //�÷���Ԫ�����±�����±�
     ElemType  d;   //�÷���Ԫ��ֵ
 }TupNode;     // ��Ԫ������
typedef struct{
    TupNode data[MaxSize]; 
    int rows;
	int cols;
	int nums; // ����������������Ԫ����
}TSMatrix;    // ϡ���������

void CreatMat(TSMatrix &t,ElemType A[M][N])
{
	int i,j; 	
	t.rows=M; t.cols=N; t.nums=0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		if(A[i][j]!=0)		//ֻ�洢����Ԫ��
        {  
			t.data[t.nums].r=i;
            t.data[t.nums].c=j;
     	    t.data[t.nums].d=A[i][j];
            t.nums++;
        }
    }
}


void DispMatrix(TSMatrix TM)		//������� 
{
	int row=TM.rows;
	int col=TM.cols;
	int num=TM.nums;
	
	bool flag=true;
	int z=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			for(int z=0;z<num;z++)
			{
				if(TM.data[z].r == i && TM.data[z].c == j)
				{
					printf("%4d",TM.data[z].d);
					flag = false;
				}	
			}
			if(flag==true)
			{
				printf("%4d",0);	
			}
			else
			{
				flag = true;
			}
		}
		printf("\n");
	}
}

void DispMat(TSMatrix t)    //�����Ԫ��
{
	int i;
	if(t.nums<=0) return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("  ----------------------------\n");
    for(i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r, t.data[i].c, t.data[i].d);
}

void TranTat(TSMatrix t,TSMatrix &tb)	//ת�� 
{
	int p,q=0,v;				//qΪtb.data���±�
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0)			//�����ڷ���Ԫ��ʱִ��ת��
	{
		for (v=0;v<t.cols;v++)		
		//tb.data[q]�еļ�¼��c��Ĵ�������
	    for (p=0;p<t.nums;p++)	//pΪt.data���±�
	    	if (t.data[p].c==v)
	        {      
				tb.data[q].r=t.data[p].c;
				tb.data[q].c=t.data[p].r;
				tb.data[q].d=t.data[p].d;
				q++;
			}
	}
}



