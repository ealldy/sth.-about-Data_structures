#include <malloc.h>
#include <stdio.h> 

typedef car QElemType;

//----- ���е���ʽ�洢-----
typedef struct QNode 
{ // �������
     QElemType data;
     struct QNode *next;
}QNode;

typedef struct 
{ // ����������
      QNode* front;  // ��ͷָ��
      QNode* rear;   // ��βָ��
}LinkQueue;

void InitQueue(LinkQueue *&Q) // ����һ���ն���Q
{
   Q = (LinkQueue*)malloc(sizeof(LinkQueue));
   Q->front =  Q->rear = NULL;
}
void EnQueue (LinkQueue *&Q, QElemType e)
{      // ����Ԫ��eΪQ���µĶ�βԪ��
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
{      // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ�
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
	while( p!= NULL)	//���в�Ϊ�� 
	{
		num++;
		p=p->next;
    }
    return num;
}

void DispQueue_L(LinkQueue *Q)    
{
	//�Ӷ�ͷ����β�������ʾ���� 
	QNode *p=Q->front;
	while(p != NULL)
	{
		OutputData(p->data);
		p = p->next;
	}
}

