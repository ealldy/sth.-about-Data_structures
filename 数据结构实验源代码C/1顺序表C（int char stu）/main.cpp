#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main(int argc, char** argv) {

	SqList *L;
	ElemType e;
	
	//*int���� 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	CreateList(L,a,10);
	DispList(L);
	//*/	
	
	/*stu���� 
	int ItemNum;
	InitList(L);
	printf("�������ʼ���Ա������Ԫ�صĸ�����");
	scanf("%d",&ItemNum);			
	for(int ti=1;ti<=ItemNum;ti++)
	{
		printf("�������%d������Ԫ�أ�",ti);		
		InputData(e);       //stu���� 
		ListInsert(L,ti,e);
	}
	printf("\n����������ǣ�\n");
	DispList(L);
	//*/ 

	int choice;
	int position;
	
while(choice != 4)
{
	printf("\n\n==============\n"); 
	printf("1.��������\n");
	printf("2.ɾ������\n");
	printf("3.�鿴����\n");
	printf("4.�˳�\n");  
	printf("==============��ѡ��"); 
	scanf("%d",&choice);
	
	switch (choice)
	{
		case 1:
			printf("\n\n=====������Ҫ�����λ�ã�");
			scanf("%d",&position);
			printf("=====������Ҫ���������Ԫ�أ�");
//			InputData(e);		//stu����		
			scanf("%d",&e);		//int���� 
//			scanf(" %c",&e);		//char���� 
			
			ListInsert(L,position,e);	
			printf("�����������ǣ�\n");		
			DispList(L);
			break;		
		case 2: 
			printf("\n\n=====������Ҫɾ����λ�ã�");
			scanf("%d",&position);
			ListDelete(L,position,e); 
			printf("=====ɾ���������ǣ�");			
//			OutputData(e);		//stu���� 
//			printf("%d",e);		//int����
//			printf("%c",e);		//char����
			
			printf("\nɾ����������ǣ�\n");
			DispList(L);
			break;
		case 3:
			printf("\n\n=====��ǰ���Ա�Ϊ��\n");
			DispList(L);
			break; 
		case 4:
			break;
		default:
			printf("����������������룡");	
	}	
}	
	return 0;
}
