#include <malloc.h>
#include <stdio.h> 

#define MaxSize 50 

typedef struct node
{  
	ElemType  data ;
    struct node  *lchild , *rchild ;
    bool rightSubTreeVisited;	//�ǵݹ�������ʱ�� 
}BTNode; //������������Ͷ��� 

void CreateBTNode(BTNode *&b,char *str)
{
	BTNode *St[MaxSize],*p=NULL;
    int top=-1,k,j=0;  
    char ch;
    b=NULL;				//�����Ķ�������ʼʱΪ��
    ch=str[j];
    while (ch!='\0')   //strδɨ����ʱѭ��
	{  
		switch(ch) 
        {
	    	case '(':
				top++;
				St[top]=p;
				k=1; 
				break;	   //Ϊ���ӽڵ�
	 		case ')':
			 	top--;
				break;
	 		case ',':
			 	k=2;
				break;     //Ϊ���ӽڵ��ҽڵ�
			default:
       			p=(BTNode *)malloc(sizeof(BTNode));
	 			p->data=ch;
	 			p->rightSubTreeVisited=false;//�ǵݹ�������ʱ�� 
				p->lchild=p->rchild=NULL;
	 			if (b==NULL)    	//pΪ�������ĸ��ڵ�
	     			b=p;
	 			else    		//�ѽ������������ڵ�
       			{
				   switch(k) 
          		   {
	    				case 1:
							St[top]->lchild=p;
							break;
						case 2:
							St[top]->rchild=p;
							break;
	    			}
       			}
     	}
     	j++;
		ch=str[j];
   }
}

void DispBTNode(BTNode *b) 
{
	if (b!=NULL)
    {  
		printf("%c",b->data);
	 	if (b->lchild!=NULL || b->rchild!=NULL)
	 	{  
		 	printf("(");
	    	DispBTNode(b->lchild);//�ݹ鴦��������
	    	if (b->rchild!=NULL) 
				printf(",");
	    	DispBTNode(b->rchild);//�ݹ鴦��������
	    		printf(")");
	 	}
   }
}

//=========================�ݹ�����㷨=========================
void PreOrder(BTNode *b)
{  
	if (b!=NULL)  
    {  
		printf("%c ",b->data); //���ʸ��ڵ�
	    PreOrder(b->lchild);
	    PreOrder(b->rchild);
    }
}
void InOrder(BTNode *b)
{  
	if (b!=NULL)  
    {  
		InOrder(b->lchild);
	 	printf("%c ",b->data); //���ʸ��ڵ�
	 	InOrder(b->rchild);
    }
 }
void PostOrder(BTNode *b) 
{  
	if (b!=NULL)  
    {  
		PostOrder(b->lchild);
	 	PostOrder(b->rchild);
	 	printf("%c ",b->data); //���ʸ��ڵ�
    }
}

//=========================�ǵݹ�����㷨=========================
typedef BTNode* SElemType;
#include "SqStack.h"
void NonRecurPreOrder(BTNode *b)
{
	SqStack *S;
	InitStack(S);	//��ʼ��Ϊ��ջ
	BTNode *p=b;
	
	while(p||!StackEmpty(S)) 
	{
		if(p)	//����һ���ڵ�
		{
			printf("%c ",p->data);//���ʸýڵ� 
			Push(S,p);//�ڵ��ջ 
			p=p->lchild; //���������� 
		} 
		else
		{
			Pop(S,p);
			p=p->rchild;
		}
	}	
} 

void NonRecurInOrder(BTNode *b)
{
	SqStack *S;
	InitStack(S);	//��ʼ��Ϊ��ջ
	BTNode *p=b;
	
	while(p||!StackEmpty(S))
	{
		if(p)
		{
			Push(S,p);
			p=p->lchild;
		}
		else
		{
			Pop(S,p);
			printf("%c ",p->data);//���ʸýڵ� 
			p=p->rchild;
		}
	} 
}

bool NonRecurPostOrder(BTNode *b)
{
	SqStack *S;
	InitStack(S);	//��ʼ��Ϊ��ջ
	BTNode *p=b;
	
	while(p||!StackEmpty(S)) 
	{
		while(p)	//�ҵ�����Ľڵ� 
		{
			Push(S,p);
			p=p->lchild;
		}
		Pop(S,p);
		while(p->rightSubTreeVisited == true)//�������ѱ���
		{
			printf("%c ",p->data);//���ʸýڵ�
			if(!StackEmpty(S))
				Pop(S,p);
			else
				return true;
		} 
		//������δ���ʣ����������� 
		p->rightSubTreeVisited=true; 
		Push(S,p);
		p=p->rchild;
	} 	
}



//======�ݹ�����㷨���Զ�������ÿ��������Visit������========================= 
void PreOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		Visit(b->data);     //���ʸ��ڵ�
	    PreOrderTraverse(b->lchild,Visit);
	    PreOrderTraverse(b->rchild,Visit);
    }
}//PreOrderTraverse����������ݹ� 

void InOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		InOrderTraverse(b->lchild,Visit);
	 	Visit(b->data);    //���ʸ��ڵ�
	 	InOrderTraverse(b->rchild,Visit);
    }
}//InOrderTraverse����������ݹ� 

void PostOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		PostOrderTraverse(b->lchild,Visit);
	 	PostOrderTraverse(b->rchild,Visit);
	 	Visit(b->data);    //���ʸ��ڵ�
    }
}//PostOrderTraverse����������ݹ� 





