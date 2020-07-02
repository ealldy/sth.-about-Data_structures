#include <malloc.h>
#include <stdio.h> 

typedef car QElemType;

//----- 队列的链式存储-----
typedef struct QNode 
{ // 结点类型
     QElemType data;
     struct QNode *next;
}QNode;

typedef struct 
{ // 链队列类型
      QNode* front;  // 队头指针
      QNode* rear;   // 队尾指针
}LinkQueue;

void InitQueue(LinkQueue *&Q) // 构造一个空队列Q
{
   Q = (LinkQueue*)malloc(sizeof(LinkQueue));
   Q->front =  Q->rear = NULL;
}
void EnQueue (LinkQueue *&Q, QElemType e)
{      // 插入元素e为Q的新的队尾元素
		QNode* p; 
        p = (QNode*) malloc (sizeof (QNode));
        p->data = e;   
        p->next = NULL;
        if(Q->rear == NULL)
        {
        	Q->front=Q->rear=p;
        }
        else
        {
        	Q->rear->next = p;
        	Q->rear = p;
        }
}
bool DeQueue (LinkQueue *&Q, QElemType &e)
{      // 若队列不空，则删除Q的队头元素，
        QNode* t;
		if(Q->rear == NULL)
			return false;
		t=Q->front;
		if(Q->front == Q->rear)
			Q->front = Q->rear = NULL;
		else
			Q->front = Q->front->next;
		
		e=t->data;
		free(t);
		return true;
}
void DestroyQueue(LinkQueue *&Q)
{
	QNode *p = Q->front,*r;
	if(p != NULL)
	{
		r=p->next;
		while(r!=NULL)
		{
			free(p);
			p=r;r=p->next;
		}
	}
	free(p);
	free(Q);
}

bool QueueEmpty(LinkQueue *&Q)
{
	return(Q->rear == NULL);
} 

int QueueLength(LinkQueue *Q)
{
	QNode *p=Q->front;
	int num=0;
	while( p!= NULL)	//队列不为空 
	{
		num++;
		p=p->next;
    }
    return num;
}

void DispQueue_L(LinkQueue *Q)    
{
	//从队头到队尾，逐个显示出来 
	QNode *p=Q->front;
	while(p != NULL)
	{
		OutputData(p->data);
		p = p->next;
	}
}

