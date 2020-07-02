#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/***************************创建线性表********************************/
void CreateList(SqList *&L,int a[],int n)//由a中的n个元素建立顺序表
{
	int i=0,k=0;//k表示L中的元素个数，初始值为0
	L=(SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
	while(i<n)//i扫描数组a中的元素
	{
		L->data[k]=a[i];//将元素a[i]存放到L中
		k++;
		i++;
	}
	L->length=k;//设置L的长度k
}



/***************************初始化线性表*******************************/
void InitList(SqList *L)
{
	L=(SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
	L->length=0;//置空线性表的长度为0
}//复杂度为（1）




/****************************销毁线性表********************************/
void DestroyList(SqList *L)
{
	free(L);
}//复杂度为（1）




/************************判断线性表是否为空表**************************/
bool ListEmpty(SqList *L)
{
	return(L->length==0);
}//复杂度为（1）




/***************************求线性表的长度*****************************/
int ListLength(SqList *L)
{
	return(L->length);
}//复杂度为（1）




/*****************************输出线性表*******************************/
void DispList(SqList *L)
{
	for(int i=0;i<L->length;i++)//扫描顺序表输出各元素值
		printf("%d",L->data[i]);
	printf("\n");
}//复杂度为（n）




/*************************获取某个元素值********************************/
bool GetElem(SqList *L,int i,int e)
{
	if(i<1||i>L->length)
		return false;//参数i错误时返回false
	e=L->data[i-1];//取元素值
	return true;//成功找到元素时返回true
}//复杂度为（1）




/*************************按元素值查找**********************************/
int LocateElem(SqList *L,int e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;//查找元素e
	if(i>=L->length)//未找到时返回0
		return 0;
	else 
		return i+1;//找到后返回逻辑序号
}//复杂度为（n）




/*************************插入数据元素**********************************/
bool ListInsert(SqList *L,int i,int e)
{
	int j;
	if(i<1||i>L->length+1)
		return false;//参数i错误时返回false
	i--;//将顺序表逻辑序号转化为物理序号
	for(j=L->length;j>i;j--)//将data[i]及后面的元素后移一个位置
		L->data[j]=L->data[j-1];
	L->data[i]=e;//插入元素e
	L->length++;//顺序表长度增1
	return true;//成功插入返回true
}//复杂度为（n）




/**************************删除数据元素*********************************/
bool ListDelete(SqList *L,int i,int e)
{
	int j;
	if(i<1 || i>L->length)//参数i错误时返回false
		return false;
	i--;//将顺序表逻辑序号转化为物理序号
	e=L->data[i];
	for(j=i;j<L->length-1;j++)//将data[i]之后的元素前移一个位置
		L->data[j]=L->data[j+1];
	L->length--;//顺序表的长度减1
	return true;//成功删除返回true
}//复杂度为（n）