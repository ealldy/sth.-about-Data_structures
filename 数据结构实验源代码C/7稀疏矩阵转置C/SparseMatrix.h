#include <malloc.h>
#include <stdio.h> 

typedef int ElemType;
#define M 8
#define N 8

#define MaxSize 100
typedef struct {
     int r;
	 int c;   //该非零元的行下标和列下标
     ElemType  d;   //该非零元的值
 }TupNode;     // 三元组类型
typedef struct{
    TupNode data[MaxSize]; 
    int rows;
	int cols;
	int nums; // 行数、列数、非零元个数
}TSMatrix;    // 稀疏矩阵类型

void CreatMat(TSMatrix &t,ElemType A[M][N])
{
	int i,j; 	
	t.rows=M; t.cols=N; t.nums=0;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		if(A[i][j]!=0)		//只存储非零元素
        {  
			t.data[t.nums].r=i;
            t.data[t.nums].c=j;
     	    t.data[t.nums].d=A[i][j];
            t.nums++;
        }
    }
}


void DispMatrix(TSMatrix TM)		//输出矩阵 
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

void DispMat(TSMatrix t)    //输出三元组
{
	int i;
	if(t.nums<=0) return;
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("  ----------------------------\n");
    for(i=0;i<t.nums;i++)
		printf("\t%d\t%d\t%d\n",t.data[i].r, t.data[i].c, t.data[i].d);
}

void TranTat(TSMatrix t,TSMatrix &tb)	//转置 
{
	int p,q=0,v;				//q为tb.data的下标
	tb.rows=t.cols;tb.cols=t.rows;tb.nums=t.nums;
	if (t.nums!=0)			//当存在非零元素时执行转置
	{
		for (v=0;v<t.cols;v++)		
		//tb.data[q]中的记录以c域的次序排列
	    for (p=0;p<t.nums;p++)	//p为t.data的下标
	    	if (t.data[p].c==v)
	        {      
				tb.data[q].r=t.data[p].c;
				tb.data[q].c=t.data[p].r;
				tb.data[q].d=t.data[p].d;
				q++;
			}
	}
}



