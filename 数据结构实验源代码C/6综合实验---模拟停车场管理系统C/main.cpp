#include <iostream>
using namespace std; 
#include "Car.h"
#include "SqList.h" 
#include "LinkQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void EmptyParkNum(SqList *L)		//���ص�ǰ�յ�ͣ��λ 
{
	int PNum=110;
	bool empty=true;
	printf("��ǰ�յ�ͣ��λΪ��");
	for(int i=1;i<=7;i++)
	{
		for(int j=0;j<L->length;j++)
		{
			if(PNum == L->data[j].ParkNum)
			{
				empty=false;
			}
		}
		if(empty == true)
		{
			printf("%5d",PNum);
		}	
		PNum++;
		empty=true;
	}
}


int main(int argc, char** argv) {
	
	//ͣ�������
	cout<<"ͣ�����ǿ�ͣ��7������������ͨ��"<<endl;
	cout<<"��λλ��Ϊ��110 111 112 113 114 115 116"<<endl;
	cout<<"����ʾ����δ���������ݵĺϷ��Խ����ж�"<<endl;
	cout<<"-----------------------------------------------"<<endl<<endl;
	
	SqList *L;	//��˳���ģ��ͣ���� 
	InitList(L);
	
	/*�ֶ�����ͣ�����ĳ�ʼ���� 
	cout<<"�����ʼʱ��ͣ������ͣ��6�������������ó�ʼ����"<<endl;
	InitData_Sq(L,6); 
	*/
	
	//*�������ó�ʼͣ�������� 
	cout<<"�����ʼʱ��ͣ������ͣ��6������"<<endl;
	car e;
	for(int ti=1;ti<=6;ti++){	
		 
		e.ParkNum = 110+ti;
		e.CarNum = ti;
		e.ATime = 1220;
		ListInsert(L,ti,e);		
	}
	//*/
	
	
	//����ʱ��һЩ�������� 
	int OutCarNum;	//��վ���������ƺ�
	bool find=false;
	int posNum;		//����ʱ����ų��������ĳ���λ��
	int lastTime;	//�����ĳ���ʱ��
	int ParkTime;	//������ͣ��ʱ�� 
	int InTime;		//�ŶӵȺ�����ʵ�����ʱ�� 
	
	//���������QIn�ͳ����� QOut 
	LinkQueue *QIn;
	InitQueue(QIn);
	LinkQueue *QOut;
	InitQueue(QOut);
	
	int choice=0;
	while(choice != 4)
	{	
		printf("\n\n��ǰͣ����ͣ�ŵĳ����ǣ�\n");
		DispList(L);	
		if(!QueueEmpty(QIn)) 
		{
			printf("------��ǰ�ŶӵȺ���վ�������ǣ�\n");
			DispQueue_L(QIn); 	
		}
		else
			cout<<endl<<"��ǰ���ŶӵȺ��վ������"<<endl;
			
		if(!QueueEmpty(QOut))
		{
			printf("\n------��ǰ�Ŷӵȴ���վ�������У�\n");
			DispQueue_L(QOut);
		} 
		else
			cout<<endl<<"��ǰ���ŶӵȺ��վ������"<<endl;
		printf("\n\n----------------------------");
		printf("\n1.��վ��2.��վ��3.���������Ʒѣ�4.�˳�ϵͳ��");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:	
			if(ListFull(L))		//ͣ����ͣ��������ȴ� 
			{
				printf("ͣ������ͣ������������ͨ���ڵȴ���");
				if(QueueLength(QIn) == 3)	//��ͨ����ͣ���� 
				{	
					printf("\n��ͨ������ͣ����������Ѱ������ͣ������");
					break; 
				} 
				printf("\n��������վ�����������Ϣ����ͣ��λ������Ϊ0��ʱ������Ϊ0��");	//������ͣ����������ڴ��ȴ���� 
				InputData(e);//��Ҫ���Ӷ��������ݺϷ��Ե��ж� 
				EnQueue(QIn,e);				
			}
			else		//ͣ����δ�� 
			{
				EmptyParkNum(L);	//��ʾ��ǰ�յĳ��� 
				printf("\n��������վ�����������Ϣ��");
				InputData(e);	//��ǰ��δ���п�ų�ͻ��� 
				ListInsert(L,L->length+1,e);	
			} 	
			break;
		case 2:
			if(QueueLength(QOut) == 3)	//��ͨ����ͣ���� 
			{
				printf("\n��ͨ������ͣ�����������Ժ��ٳ�վ��");
			}
			else
			{
				printf("������Ҫ��վ�ĳ��ƺ��룺");
				scanf("%d",&OutCarNum);
				for(int t=1;t<=L->length;t++)	 
				{
					ElemValue(L,t,e);		//ȡͣ���������������
					if(e.CarNum == OutCarNum)
					{
						find=true;
						ListDelete(L,t,e);	//�������� 
						posNum=e.ParkNum; 	//���������ĳ���λ�ã���ʱ��ţ����ʱҪ�� 
						EnQueue(QOut,e);
					} 
				} 		
				if(find == false)
				{
					printf("�����в����ڳ��ƺ���Ϊ%d������",OutCarNum);
				}
			} 
			if(find == true)	//������ʻ������ 
			{
				if(QueueLength(QIn)>0)	//�복��Ķ����������ڵȴ��������е�һ̨�������복�⣬���¼������ʱ�� 
				{
					DeQueue(QIn,e);
					e.ParkNum=posNum;
					printf("�Ŷӵ�����%d��Ҫ��⣬�����뵱ǰʱ�䣺",e.CarNum); 
					scanf("%d",&InTime);
					e.ATime=InTime;
					ListInsert(L,L->length+1,e);
				}
				find=false;	
			}
			break;
		case 3:	
			if(QueueLength(QOut)>0)	//������Ķ����������ڵȴ�
			{
				DeQueue(QOut,e);
				printf("����%d���ڼƷѣ�",e.CarNum);
				printf("�����뵱ǰʱ�䣺");
				scanf("%d",&lastTime) ;
				ParkTime = lastTime-e.ATime;
				printf("�뽻ͣ���ѣ�%d��",ParkTime*5) ;
				printf("\n����%d��ʻ��ͣ������\n",e.CarNum);
			}
			else 
			{
				printf("��ǰû��Ҫ�����������");
			}
			break;
		case 4:
			break;
		default:
			printf("����������������룡");
		}
	}
	return 0;
}
