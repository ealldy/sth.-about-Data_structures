#include <malloc.h>
#include <stdio.h> 

#define MaxSize 7	//停车场只有7个停车位 
//typedef int ElemType;
typedef car ElemType;


typedef struct 
{	
	ElemType data[MaxSize];
   	int length;
}SqList;    //顺序表类型


void CreateList(SqList *&L,ElemType a[],int n)  //建立顺序表
{  
	int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0;i<n;i++)
		L->data[i]=a[i];
    L->length=n;
}
void InitList(SqList *&L)   //引用型指针
{  
	L=(SqList *)malloc(sizeof(SqList));	
       //分配存放线性表的空间
    L->length=0;
}

void DestroyList(SqList *&L)
{
    free(L);
}
bool ListFull(SqList *L)
{
	return(L->length==MaxSize);
}

bool ListEmpty(SqList *L)
{
	return(L->length==0);
}
int ListLength(SqList *L)
{
	return(L->length);
}
void DispList(SqList *L)
{
	int i;
	if (ListEmpty(L)) 
		return;
	for (i=0;i<L->length;i++)
//		printf("%4d",L->data[i]);	//int类型 
		OutputData(L->data[i]);      //car类型 
	printf("\n");
} 
bool GetElem(SqList *L,int i,ElemType &e)
{
	if (i<1 || i>L->length)  
		return false;
	e=L->data[i-1];
	return true;
}
/*
int LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while (i<L->length && L->data[i] != e) 
		i++;
	if (i>=L->length) 
		return 0;
	else  
		return i+1;
}
*/
bool ListInsert(SqList *&L,int i,ElemType e)
{  
	int j;
    if (i<1||i>L->length+1)
		return false;	//参数错误时返回false
	i--;			//将顺序表逻辑序号转化为物理序号	
    for (j=L->length;j>i;j--)	//将data[i..n]元素后移一个位置
		L->data[j]=L->data[j-1];

    L->data[i]=e;			//插入元素e
    L->length++;			//顺序表长度增1
    return true;			//成功插入返回true
}
bool ListDelete(SqList *&L,int i,ElemType &e)
{  
	int j;
	if(i<1||i>L->length)  //参数错误时返回false
		return false;
    i--;		//将顺序表逻辑序号转化为物理序号
	e=L->data[i];
    for (j=i;j<L->length-1;j++)  //将data[i..n-1]元素前移
		L->data[j]=L->data[j+1];
	L->length--;			  //顺序表长度减1
    return true;			  //成功删除返回true
}



//返回第i个数据元素 
bool ElemValue(SqList *L,int i,ElemType &e)
{
	if((i < 1) || (i > L->length))  
		return false;           // 删除位置不合法
	
	e=L->data[i-1];
	return true; 
} 
//初始化线性表
void InitData_Sq(SqList *&L,int n)    
{
	ElemType e;	
	for(int ti=1;ti<=n;ti++){
		printf("------请输入第%d个数据元素：",ti);		
		InputData(e);       //car类型 
//		scanf("%d",&e);		//int类型 
//		scanf(" %c",&e);		//char类型
		ListInsert(L,ti,e);		
	}
}
