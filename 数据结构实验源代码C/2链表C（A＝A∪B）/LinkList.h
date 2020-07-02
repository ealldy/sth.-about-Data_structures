#include <malloc.h>
#include <stdio.h> 

typedef int ElemType;

typedef struct LNode 
{
    ElemType data;         // 数据域
    struct LNode *next;    // 指针域
}LinkList;  


bool ListInsert(LinkList *&L,int i,ElemType e)
{ 
	int j=0;
    LinkList *p=L,*s;          //p指向头节点,j置为0
    while (j<i-1 && p!=NULL)	//查找第i-1个节点
    {	
		j++;
		p=p->next;
   	}
 	if (p==NULL)	//未找到第i-1个节点,返回false
		return false;
    else	//找到第i-1个节点*p,插入新节点并返回true
    {	
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=e;		//创建新节点*s,其data域置为e
		s->next=p->next;	//将*s插入到*p之后
		p->next=s;
		return true;
   }
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{ 
	int j=0;
    LinkList *p=L,*q;		//p指向头节点,j置为0
    while (j<i-1 && p!=NULL)	//查找第i-1个节点
    {	
		j++;
		p=p->next;
    }
 	if (p==NULL)	//未找到第i-1个节点,返回false
		return false;
   	else		//找到第i-1个节点*p
  	{	
	  	q=p->next;		//q指向第i个节点
		if (q==NULL)	//若不存在第i个节点,返回false
	   		return false;
		e=q->data;
		p->next=q->next;	//从单链表中删除*q节点
		free(q);		//释放*q节点
		return true;	//返回true表示成功删除第i个节点
    }
}
void CreateListF(LinkList *&L,ElemType a[],int n)//头插法建表
{  
	LinkList *s;
   	int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;		
		//创建头节点,其next域置为NULL
    for (i=0;i<n;i++)	//循环建立数据节点
    {	
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];	//创建数据节点*s
		s->next=L->next;	//将*s插在原开始节点之前,头节点之后
		L->next=s;
   }
}
void CreateListR(LinkList *&L,ElemType a[],int n) //尾插法建表 
{  
   LinkList *s,*r;
   int i;

   L=(LinkList *)malloc(sizeof(LinkList));  //创建头节点
   r=L;			//r始终指向尾节点,开始时指向头节点
   
   for (i=0;i<n;i++)	//循环建立数据节点
   {	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=a[i];	//创建数据节点*s
	r->next=s;		//将*s插入*r之后
	r=s;
   }
   r->next=NULL;		//尾节点next域置为NULL
}
void DispList(LinkList *L)
{  
   LinkList *p=L->next;	//p指向开始节点

   while (p!=NULL)	//p不为NULL,输出*p节点的data域
   {	
		printf("%d ",p->data); //int类型 
		p=p->next;		//p移向下一个节点
   }

   printf("\n");
}
void InitList(LinkList *&L)
{  
	L=(LinkList *)malloc(sizeof(LinkList));//创建头节点
    L->next=NULL;
}

bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;	
		//p指向头节点,j置为0(即头节点的序号为0)
	while (j<i && p!=NULL)	//找第i个节点
   	{	
	   	j++;
		p=p->next;
   	}
   	if (p==NULL)	//不存在第i个数据节点,返回false
		return false;
   	else		//存在第i个数据节点,返回true
   	{  
		e=p->data;
		return true;
    }
}

int LocateElem(LinkList *L,ElemType e)
{
	int i=1;
   	LinkList *p=L->next;	//p指向开始节点,i置为1  

   	while (p!=NULL && p->data!=e) 
   	{  
   		p=p->next;  //查找data值为e的节点,其序号为i
		i++;
   	}
   	if (p==NULL)	//不存在元素值为e的节点,返回0
		return(0);
  	else		//存在元素值为e的节点,返回其逻辑序号i
		return(i);
}

int ListLength(LinkList *L)
{
	int n=0;
	LinkList *p=L;	//p指向头节点,n置为0(即头节点的序号为0)
   	while (p->next!=NULL)
   	{	
		n++;
		p=p->next;
   	}
   	return(n);	//循环结束,p指向尾节点,其序号n为节点个数
}

