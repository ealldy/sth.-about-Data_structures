#include <malloc.h>
#include <stdio.h> 

#define MaxSize 50 

typedef struct node
{  
	ElemType  data ;
    struct node  *lchild , *rchild ;
    bool rightSubTreeVisited;	//非递归后序遍历时用 
}BTNode; //二叉树结点类型定义 

void CreateBTNode(BTNode *&b,char *str)
{
	BTNode *St[MaxSize],*p=NULL;
    int top=-1,k,j=0;  
    char ch;
    b=NULL;				//建立的二叉树初始时为空
    ch=str[j];
    while (ch!='\0')   //str未扫描完时循环
	{  
		switch(ch) 
        {
	    	case '(':
				top++;
				St[top]=p;
				k=1; 
				break;	   //为左孩子节点
	 		case ')':
			 	top--;
				break;
	 		case ',':
			 	k=2;
				break;     //为孩子节点右节点
			default:
       			p=(BTNode *)malloc(sizeof(BTNode));
	 			p->data=ch;
	 			p->rightSubTreeVisited=false;//非递归后序遍历时用 
				p->lchild=p->rchild=NULL;
	 			if (b==NULL)    	//p为二叉树的根节点
	     			b=p;
	 			else    		//已建立二叉树根节点
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
	    	DispBTNode(b->lchild);//递归处理左子树
	    	if (b->rchild!=NULL) 
				printf(",");
	    	DispBTNode(b->rchild);//递归处理右子树
	    		printf(")");
	 	}
   }
}

//=========================递归遍历算法=========================
void PreOrder(BTNode *b)
{  
	if (b!=NULL)  
    {  
		printf("%c ",b->data); //访问根节点
	    PreOrder(b->lchild);
	    PreOrder(b->rchild);
    }
}
void InOrder(BTNode *b)
{  
	if (b!=NULL)  
    {  
		InOrder(b->lchild);
	 	printf("%c ",b->data); //访问根节点
	 	InOrder(b->rchild);
    }
 }
void PostOrder(BTNode *b) 
{  
	if (b!=NULL)  
    {  
		PostOrder(b->lchild);
	 	PostOrder(b->rchild);
	 	printf("%c ",b->data); //访问根节点
    }
}

//=========================非递归遍历算法=========================
typedef BTNode* SElemType;
#include "SqStack.h"
void NonRecurPreOrder(BTNode *b)
{
	SqStack *S;
	InitStack(S);	//初始化为空栈
	BTNode *p=b;
	
	while(p||!StackEmpty(S)) 
	{
		if(p)	//碰到一个节点
		{
			printf("%c ",p->data);//访问该节点 
			Push(S,p);//节点进栈 
			p=p->lchild; //进入左子树 
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
	InitStack(S);	//初始化为空栈
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
			printf("%c ",p->data);//访问该节点 
			p=p->rchild;
		}
	} 
}

bool NonRecurPostOrder(BTNode *b)
{
	SqStack *S;
	InitStack(S);	//初始化为空栈
	BTNode *p=b;
	
	while(p||!StackEmpty(S)) 
	{
		while(p)	//找到最左的节点 
		{
			Push(S,p);
			p=p->lchild;
		}
		Pop(S,p);
		while(p->rightSubTreeVisited == true)//右子树已遍历
		{
			printf("%c ",p->data);//访问该节点
			if(!StackEmpty(S))
				Pop(S,p);
			else
				return true;
		} 
		//右子树未访问，遍历右子树 
		p->rightSubTreeVisited=true; 
		Push(S,p);
		p=p->rchild;
	} 	
}



//======递归遍历算法（对二叉树中每个结点调用Visit函数）========================= 
void PreOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		Visit(b->data);     //访问根节点
	    PreOrderTraverse(b->lchild,Visit);
	    PreOrderTraverse(b->rchild,Visit);
    }
}//PreOrderTraverse先序遍历，递归 

void InOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		InOrderTraverse(b->lchild,Visit);
	 	Visit(b->data);    //访问根节点
	 	InOrderTraverse(b->rchild,Visit);
    }
}//InOrderTraverse中序遍历，递归 

void PostOrderTraverse(BTNode *b,Status(* Visit)(ElemType e))
{
	if (b!=NULL)  
    {  
		PostOrderTraverse(b->lchild,Visit);
	 	PostOrderTraverse(b->rchild,Visit);
	 	Visit(b->data);    //访问根节点
    }
}//PostOrderTraverse后序遍历，递归 





