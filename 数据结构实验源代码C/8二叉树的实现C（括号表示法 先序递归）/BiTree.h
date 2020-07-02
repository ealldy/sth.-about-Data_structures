#include <malloc.h>
#include <stdio.h> 

#define MaxSize 50 
typedef char ElemType;
typedef struct node
{  
	ElemType  data ;
    struct node  *lchild , *rchild ;
    bool rightSubTreeVisited;	//�ǵݹ�������ʱ�� 
}BTNode;


//����һ�����ŷ���ʾ������ 
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


//���������������н�����������
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
//���򣬵ݹ���ʾ
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

