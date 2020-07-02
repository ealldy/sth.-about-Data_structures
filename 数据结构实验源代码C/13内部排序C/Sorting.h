#include <stdio.h> 
//#define  MAXSIZE  20

typedef int KeyType;
typedef char InfoType; 
typedef  struct  {
    KeyType key ;      /*关键字码*/
	InfoType data ;    /*其他域，本例暂存a*/
}RecType; //记录类型

void CreateSort(RecType R[],KeyType a[],int n)
{
	for(int i=0;i<n;i++)
	{
		R[i].key = a[i];
		R[i].data = 'a';	/*其他域，本例暂存a*/
	}
}

void DispSort(RecType R[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",R[i].key);
	}
	printf("\n");
} 

//****************直接插入排序*************** 
void InsertSort(RecType R[],int n) 
//对R[0..n-1]按递增有序进行直接插入排序
{	
	int i,j;	
	RecType temp;
	for(i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1;  //从右向左在有序区R[0..i-1]找R[i]的插入位置
		while(j>=0 && temp.key < R[j].key) 
		{
			R[j+1]=R[j];   //将关键字大于R[i].key的记录后移
			j--;
		}
		R[j+1]=temp;      //在j+1处插入R[i]
		
		//显示各趟排序过程 
		printf("第%d趟直接插入排序：",i); 
		DispSort(R,n);
	}
}
//****************折半插入排序*************** 
void InsertSort1(RecType R[],int n)
{
	int i,j,low,high,mid;
	RecType tmp;
	for(i=1;i<n;i++) 
	{
		tmp=R[i];		   //将R[i]保存到tmp中
		low=0;high=i-1;
		while(low<=high)	   //在R[low..high]中查找插入的位置
		{
			mid=(low+high)/2;		//取中间位置
			if(tmp.key<R[mid].key)
				high=mid-1;			//插入点在左半区
			else
				low=mid+1;			//插入点在右半区
		}
		for(j=i-1;j>=high+1;j--)	//记录后移
			R[j+1]=R[j];
		R[high+1]=tmp;			//插入
		
		//显示各趟排序过程 
		printf("第%d趟折半插入排序：",i); 
		DispSort(R,n);
   }
}
//****************希尔排序******************* 
void ShellSort(RecType R[],int n)	//希尔排序算法
{
	int d=1; 	//排序趟数
	
	int i,j,gap;
	RecType tmp;
	gap=n/2;			  //增量置初值
	while (gap>0)
	{
		for(i=gap;i<n;i++) //对相隔gap位置的元素组直接插入排序
		{
			tmp=R[i];
			j=i-gap;
			while(j>=0 && tmp.key<R[j].key)
			{
				R[j+gap]=R[j];
				j=j-gap;
			}
			R[j+gap]=tmp;
		}
		gap=gap/2;	//减小增量
		
		//显示各趟排序过程 
		printf("第%d趟希尔排序：",d); 
		DispSort(R,n);
		d++; 
	}
}
//****************冒泡排序******************* 
void BubbleSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for(i=0;i<n-1;i++) 
	{
		for(j=n-1;j>i;j--)  //比较找本趟最小关键字的记录
			if( R[j].key<R[j-1].key )   
			{
				temp=R[j];    //R[j]与R[j-1]进行交换
				R[j]=R[j-1];
				R[j-1]=temp;
			}
			
		//显示各趟排序过程 
		printf("第%d趟冒泡排序：",i+1); 
		DispSort(R,n);	
	}
} 
//**************改进后的冒泡排序*************
void BubbleSort1(RecType R[],int n)
{	
	int i,j;
	bool exchange;
	RecType temp;
	for(i=0;i<n-1;i++) 
	{
		exchange=false;
		for(j=n-1; j>i; j--)	//比较,找出最小关键字的记录
		if(R[j].key<R[j-1].key)   	
		{
			temp=R[j]; 
			R[j]=R[j-1];
			R[j-1]=temp;
			exchange=true;
		}
		if (exchange==false) return;  //中途结束算法
		
		//显示各趟排序过程 
		printf("第%d趟改进后的冒泡排序：",i+1); 
		DispSort(R,n);
	}
}
//****************快速排序*******************
void QuickSort(RecType R[],int s,int t) 
//对R[s]至R[t]的元素进行快速排序
{
	int i=s,j=t;
	RecType temp;
    if(s<t)         //区间内至少存在2个元素的情况
    {
		temp=R[s];		//用区间的第1个记录作为基准
		while (i!=j)	//从两端交替向中间扫描,直至i=j为止
		{
			while (j>i && R[j].key>=temp.key) j--;  
			R[i]=R[j];
			while (i<j && R[i].key<=temp.key) i++;
			R[j]=R[i];
		}
        R[i]=temp;
        
        //显示各趟排序过程
        printf("以%d为基准，划分[%d-%d]区间：",temp.key,s+1,t+1); 
        DispSort(R,N);
         
        QuickSort(R,s,i-1);    //对左区间递归排序
        QuickSort(R,i+1,t);    //对右区间递归排序
	} 
}

//****************简单选择排序*************** 
void SelectSort(RecType R[], int n)
{
	int i,j,k;
	RecType temp;
	for(i=0;i<n-1;i++)		//做第i趟排序
	{ 
		k=i;
		for(j=i+1; j<n; j++)  //在[i..n-1]中选key最小的R[k] 
			if(R[j].key < R[k].key)
				k=j;           //k记下的最小关键字所在的位置
		if(k!=i)			//交换R[i]和R[k] 
		{
			temp=R[i];
			R[i]=R[k];
			R[k]=temp;
		}
		
		//显示各趟排序过程 
		printf("第%d趟：选择[%d-%d]中最小的记录放到%d：",i+1,i+1,n,i+1); 
		DispSort(R,n);
	}
 }

