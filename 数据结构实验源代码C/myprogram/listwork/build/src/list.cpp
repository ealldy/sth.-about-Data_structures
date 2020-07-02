#include<stdio.h>
#include<stdlib.h>
#include"list.h"

/***************************�������Ա�********************************/
void CreateList(SqList *&L,int a[],int n)//��a�е�n��Ԫ�ؽ���˳���
{
	int i=0,k=0;//k��ʾL�е�Ԫ�ظ�������ʼֵΪ0
	L=(SqList *)malloc(sizeof(SqList));//���������Ա�Ŀռ�
	while(i<n)//iɨ������a�е�Ԫ��
	{
		L->data[k]=a[i];//��Ԫ��a[i]��ŵ�L��
		k++;
		i++;
	}
	L->length=k;//����L�ĳ���k
}



/***************************��ʼ�����Ա�*******************************/
void InitList(SqList *L)
{
	L=(SqList *)malloc(sizeof(SqList));//���������Ա�Ŀռ�
	L->length=0;//�ÿ����Ա�ĳ���Ϊ0
}//���Ӷ�Ϊ��1��




/****************************�������Ա�********************************/
void DestroyList(SqList *L)
{
	free(L);
}//���Ӷ�Ϊ��1��




/************************�ж����Ա��Ƿ�Ϊ�ձ�**************************/
bool ListEmpty(SqList *L)
{
	return(L->length==0);
}//���Ӷ�Ϊ��1��




/***************************�����Ա�ĳ���*****************************/
int ListLength(SqList *L)
{
	return(L->length);
}//���Ӷ�Ϊ��1��




/*****************************������Ա�*******************************/
void DispList(SqList *L)
{
	for(int i=0;i<L->length;i++)//ɨ��˳��������Ԫ��ֵ
		printf("%d",L->data[i]);
	printf("\n");
}//���Ӷ�Ϊ��n��




/*************************��ȡĳ��Ԫ��ֵ********************************/
bool GetElem(SqList *L,int i,int e)
{
	if(i<1||i>L->length)
		return false;//����i����ʱ����false
	e=L->data[i-1];//ȡԪ��ֵ
	return true;//�ɹ��ҵ�Ԫ��ʱ����true
}//���Ӷ�Ϊ��1��




/*************************��Ԫ��ֵ����**********************************/
int LocateElem(SqList *L,int e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
		i++;//����Ԫ��e
	if(i>=L->length)//δ�ҵ�ʱ����0
		return 0;
	else 
		return i+1;//�ҵ��󷵻��߼����
}//���Ӷ�Ϊ��n��




/*************************��������Ԫ��**********************************/
bool ListInsert(SqList *L,int i,int e)
{
	int j;
	if(i<1||i>L->length+1)
		return false;//����i����ʱ����false
	i--;//��˳����߼����ת��Ϊ�������
	for(j=L->length;j>i;j--)//��data[i]�������Ԫ�غ���һ��λ��
		L->data[j]=L->data[j-1];
	L->data[i]=e;//����Ԫ��e
	L->length++;//˳�������1
	return true;//�ɹ����뷵��true
}//���Ӷ�Ϊ��n��




/**************************ɾ������Ԫ��*********************************/
bool ListDelete(SqList *L,int i,int e)
{
	int j;
	if(i<1 || i>L->length)//����i����ʱ����false
		return false;
	i--;//��˳����߼����ת��Ϊ�������
	e=L->data[i];
	for(j=i;j<L->length-1;j++)//��data[i]֮���Ԫ��ǰ��һ��λ��
		L->data[j]=L->data[j+1];
	L->length--;//˳���ĳ��ȼ�1
	return true;//�ɹ�ɾ������true
}//���Ӷ�Ϊ��n��