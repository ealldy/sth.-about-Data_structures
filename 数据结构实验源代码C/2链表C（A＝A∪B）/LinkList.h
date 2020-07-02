#include <malloc.h>
#include <stdio.h> 

typedef int ElemType;

typedef struct LNode 
{
    ElemType data;         // ������
    struct LNode *next;    // ָ����
}LinkList;  


bool ListInsert(LinkList *&L,int i,ElemType e)
{ 
	int j=0;
    LinkList *p=L,*s;          //pָ��ͷ�ڵ�,j��Ϊ0
    while (j<i-1 && p!=NULL)	//���ҵ�i-1���ڵ�
    {	
		j++;
		p=p->next;
   	}
 	if (p==NULL)	//δ�ҵ���i-1���ڵ�,����false
		return false;
    else	//�ҵ���i-1���ڵ�*p,�����½ڵ㲢����true
    {	
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=e;		//�����½ڵ�*s,��data����Ϊe
		s->next=p->next;	//��*s���뵽*p֮��
		p->next=s;
		return true;
   }
}
bool ListDelete(LinkList *&L,int i,ElemType &e)
{ 
	int j=0;
    LinkList *p=L,*q;		//pָ��ͷ�ڵ�,j��Ϊ0
    while (j<i-1 && p!=NULL)	//���ҵ�i-1���ڵ�
    {	
		j++;
		p=p->next;
    }
 	if (p==NULL)	//δ�ҵ���i-1���ڵ�,����false
		return false;
   	else		//�ҵ���i-1���ڵ�*p
  	{	
	  	q=p->next;		//qָ���i���ڵ�
		if (q==NULL)	//�������ڵ�i���ڵ�,����false
	   		return false;
		e=q->data;
		p->next=q->next;	//�ӵ�������ɾ��*q�ڵ�
		free(q);		//�ͷ�*q�ڵ�
		return true;	//����true��ʾ�ɹ�ɾ����i���ڵ�
    }
}
void CreateListF(LinkList *&L,ElemType a[],int n)//ͷ�巨����
{  
	LinkList *s;
   	int i;
    L=(LinkList *)malloc(sizeof(LinkList));
    L->next=NULL;		
		//����ͷ�ڵ�,��next����ΪNULL
    for (i=0;i<n;i++)	//ѭ���������ݽڵ�
    {	
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];	//�������ݽڵ�*s
		s->next=L->next;	//��*s����ԭ��ʼ�ڵ�֮ǰ,ͷ�ڵ�֮��
		L->next=s;
   }
}
void CreateListR(LinkList *&L,ElemType a[],int n) //β�巨���� 
{  
   LinkList *s,*r;
   int i;

   L=(LinkList *)malloc(sizeof(LinkList));  //����ͷ�ڵ�
   r=L;			//rʼ��ָ��β�ڵ�,��ʼʱָ��ͷ�ڵ�
   
   for (i=0;i<n;i++)	//ѭ���������ݽڵ�
   {	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=a[i];	//�������ݽڵ�*s
	r->next=s;		//��*s����*r֮��
	r=s;
   }
   r->next=NULL;		//β�ڵ�next����ΪNULL
}
void DispList(LinkList *L)
{  
   LinkList *p=L->next;	//pָ��ʼ�ڵ�

   while (p!=NULL)	//p��ΪNULL,���*p�ڵ��data��
   {	
		printf("%d ",p->data); //int���� 
		p=p->next;		//p������һ���ڵ�
   }

   printf("\n");
}
void InitList(LinkList *&L)
{  
	L=(LinkList *)malloc(sizeof(LinkList));//����ͷ�ڵ�
    L->next=NULL;
}

bool GetElem(LinkList *L,int i,ElemType &e)
{
	int j=0;
	LinkList *p=L;	
		//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j<i && p!=NULL)	//�ҵ�i���ڵ�
   	{	
	   	j++;
		p=p->next;
   	}
   	if (p==NULL)	//�����ڵ�i�����ݽڵ�,����false
		return false;
   	else		//���ڵ�i�����ݽڵ�,����true
   	{  
		e=p->data;
		return true;
    }
}

int LocateElem(LinkList *L,ElemType e)
{
	int i=1;
   	LinkList *p=L->next;	//pָ��ʼ�ڵ�,i��Ϊ1  

   	while (p!=NULL && p->data!=e) 
   	{  
   		p=p->next;  //����dataֵΪe�Ľڵ�,�����Ϊi
		i++;
   	}
   	if (p==NULL)	//������Ԫ��ֵΪe�Ľڵ�,����0
		return(0);
  	else		//����Ԫ��ֵΪe�Ľڵ�,�������߼����i
		return(i);
}

int ListLength(LinkList *L)
{
	int n=0;
	LinkList *p=L;	//pָ��ͷ�ڵ�,n��Ϊ0(��ͷ�ڵ�����Ϊ0)
   	while (p->next!=NULL)
   	{	
		n++;
		p=p->next;
   	}
   	return(n);	//ѭ������,pָ��β�ڵ�,�����nΪ�ڵ����
}

