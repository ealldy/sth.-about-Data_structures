#ifndef LIST_H
#define LIST_H

#define MaxSize 50
typedef int ElemType;
typedef struct 
{
	ElemType data[MaxSize];//存放线性表中的元素
	int length;//存放线性表的长度
}SqList;//顺序表类型


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
