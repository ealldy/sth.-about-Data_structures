#include <malloc.h>
#include <stdio.h> 

#define MaxSize 7	//ͣ����ֻ��7��ͣ��λ 
//typedef int ElemType;
typedef car ElemType;


typedef struct 
{	
	ElemType data[MaxSize];
   	int length;
}SqList;    //˳�������


void CreateList(SqList *&L,ElemType a[],int n)  //����˳���
{  
	int i;
    L=(SqList *)malloc(sizeof(SqList));
    for (i=0;i<n;i++)
		L->data[i]=a[i];
    L->length=n;
}
void InitList(SqList *&L)   //������ָ��
{  
	L=(SqList *)malloc(sizeof(SqList));	
       //���������Ա�Ŀռ�
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
//		printf("%4d",L->data[i]);	//int���� 
		OutputData(L->data[i]);      //car���� 
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
		return false;	//��������ʱ����false
	i--;			//��˳����߼����ת��Ϊ�������	
    for (j=L->length;j>i;j--)	//��data[i..n]Ԫ�غ���һ��λ��
		L->data[j]=L->data[j-1];

    L->data[i]=e;			//����Ԫ��e
    L->length++;			//˳�������1
    return true;			//�ɹ����뷵��true
}
bool ListDelete(SqList *&L,int i,ElemType &e)
{  
	int j;
	if(i<1||i>L->length)  //��������ʱ����false
		return false;
    i--;		//��˳����߼����ת��Ϊ�������
	e=L->data[i];
    for (j=i;j<L->length-1;j++)  //��data[i..n-1]Ԫ��ǰ��
		L->data[j]=L->data[j+1];
	L->length--;			  //˳����ȼ�1
    return true;			  //�ɹ�ɾ������true
}



//���ص�i������Ԫ�� 
bool ElemValue(SqList *L,int i,ElemType &e)
{
	if((i < 1) || (i > L->length))  
		return false;           // ɾ��λ�ò��Ϸ�
	
	e=L->data[i-1];
	return true; 
} 
//��ʼ�����Ա�
void InitData_Sq(SqList *&L,int n)    
{
	ElemType e;	
	for(int ti=1;ti<=n;ti++){
		printf("------�������%d������Ԫ�أ�",ti);		
		InputData(e);       //car���� 
//		scanf("%d",&e);		//int���� 
//		scanf(" %c",&e);		//char����
		ListInsert(L,ti,e);		
	}
}
