#include <malloc.h>
#include <stdio.h> 

#define MaxSize 50 
typedef char ElemType;
typedef struct node
{  
	ElemType  data ;
    struct node  *lchild , *rchild ;
    bool rightSubTreeVisited;	//非递归后序遍历时用 
}BTNode;


//方法一：括号法表示二叉树 
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


//方法二：先序序列建立二叉链表
bool CreateBiTree(BTNode *&T)   
{
	char ch;
	scanf("%c",&ch);
	if(ch == ' ') T=NULL;
	else
	{
		if(!(T=(BTNode *)malloc(sizeof(BTNode)))) return false;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return true;
} 
//先序，递归显示
void DispBinTree(BTNode *T)
{
	if(T==NULL) printf(" ");
	else
	{
		printf("%c",T->data);
		DispBinTree(T->lchild);
		DispBinTree(T->rchild);
	}
} 



int LeafNodes(BTNode *b)
{
	int num1,num2;
    if (b==NULL)
    	return 0;
    else if (b->lchild==NULL && b->rchild==NULL)
        return 1;
    else
    {	
		num1=LeafNodes(b->lchild);
		num2=LeafNodes(b->rchild);
		return (num1+num2);
    }
}

