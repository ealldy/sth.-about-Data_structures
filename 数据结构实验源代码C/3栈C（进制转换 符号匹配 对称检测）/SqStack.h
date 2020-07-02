#include <malloc.h>
#include <stdio.h> 


typedef char ElemType;

//----- 栈的顺序存储表示 -----
#define MaxSize 50
typedef struct 
{
	ElemType data[MaxSize]; 
    int top;		//栈顶指针
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
	if (s->top==MaxSize-1)  //栈满的情况，即栈上溢出
		return false;
    s->top++;		   //栈顶指针增1
    s->data[s->top]=e;	   //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *&s,ElemType &e)
{
    if (s->top==-1)	//栈为空的情况，即栈下溢出
		return false;
    e=s->data[s->top];	//取栈顶指针元素的元素
    s->top--;		//栈顶指针减1
    return true;
}
bool GetTop(SqStack *s,ElemType &e)
{
	if (s->top==-1)	//栈为空的情况，即栈下溢出    
    	return false;
    e=s->data[s->top];	//取栈顶指针元素的元素
    return true;
}
int StackLength(SqStack *s)
{
	return s->top+1;
}

void DispStack(SqStack *S)
{
//	printf("\n栈长为：%d",StackLength(S)); 
//	printf("\n当前栈为：");
	
	for(int i=0;i<StackLength(S);i++)
	{
		printf("%c ",S->data[i]);  
	}

}
