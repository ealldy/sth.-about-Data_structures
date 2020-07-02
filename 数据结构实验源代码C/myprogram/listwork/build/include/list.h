#ifndef LIST_H
#define LIST_H

#define MaxSize 50
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];//������Ա��е�Ԫ��
	int length;//������Ա�ĳ���
}SqList;//˳�������


void CreateList(SqList *&L,int a[],int n);
void InitList(SqList *L);
void DestroyList(SqList *L);
bool ListEmpty(SqList *L);
int ListLength(SqList *L);
void DispList(SqList *L);
bool GetElem(SqList *L,int i,int e);
int LocateElem(SqList *L,int e);
bool ListInsert(SqList *L,int i,int e);
bool ListDelete(SqList *L,int i,int e);

#endif
