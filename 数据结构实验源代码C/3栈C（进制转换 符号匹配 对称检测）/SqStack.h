#include <malloc.h>
#include <stdio.h> 


typedef char ElemType;

//----- ջ��˳��洢��ʾ -----
#define MaxSize 50
typedef struct 
{
	ElemType data[MaxSize]; 
    int top;		//ջ��ָ��
}SqStack;

void InitStack(SqStack *&s)
{  
	s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
} 
void DestroyStack(SqStack *&s)
{
	free(s);
}
bool StackEmpty(SqStack *s)
{
	return(s->top==-1);
}
bool Push(SqStack *&s,ElemType e)
{
	if (s->top==MaxSize-1)  //ջ�����������ջ�����
		return false;
    s->top++;		   //ջ��ָ����1
    s->data[s->top]=e;	   //Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
    if (s->top==-1)	//ջΪ�յ��������ջ�����
		return false;
    e=s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;		//ջ��ָ���1
    return true;
}
bool GetTop(SqStack *s,ElemType &e)
{
	if (s->top==-1)	//ջΪ�յ��������ջ�����    
    	return false;
    e=s->data[s->top];	//ȡջ��ָ��Ԫ�ص�Ԫ��
    return true;
}
int StackLength(SqStack *s)
{
	return s->top+1;
}

void DispStack(SqStack *S)
{
//	printf("\nջ��Ϊ��%d",StackLength(S)); 
//	printf("\n��ǰջΪ��");
	
	for(int i=0;i<StackLength(S);i++)
	{
		printf("%c ",S->data[i]);  
	}

}
