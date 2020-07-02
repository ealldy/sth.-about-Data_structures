#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

int main(int argc, char** argv) {

	SqList *L;
	ElemType e;
	
	//*int类型 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	CreateList(L,a,10);
	DispList(L);
	//*/	
	
	/*stu类型 
	int ItemNum;
	InitList(L);
	printf("请输入初始线性表的数据元素的个数：");
	scanf("%d",&ItemNum);			
	for(int ti=1;ti<=ItemNum;ti++)
	{
		printf("请输入第%d个数据元素：",ti);		
		InputData(e);       //stu类型 
		ListInsert(L,ti,e);
	}
	printf("\n输入的数据是：\n");
	DispList(L);
	//*/ 

	int choice;
	int position;
	
while(choice != 4)
{
	printf("\n\n==============\n"); 
	printf("1.插入数据\n");
	printf("2.删除数据\n");
	printf("3.查看数据\n");
	printf("4.退出\n");  
	printf("==============请选择："); 
	scanf("%d",&choice);
	
	switch (choice)
	{
		case 1:
			printf("\n\n=====请输入要插入的位置：");
			scanf("%d",&position);
			printf("=====请输入要插入的数据元素：");
//			InputData(e);		//stu类型		
			scanf("%d",&e);		//int类型 
//			scanf(" %c",&e);		//char类型 
			
			ListInsert(L,position,e);	
			printf("插入后的数据是：\n");		
			DispList(L);
			break;		
		case 2: 
			printf("\n\n=====请输入要删除的位置：");
			scanf("%d",&position);
			ListDelete(L,position,e); 
			printf("=====删除的数据是：");			
//			OutputData(e);		//stu类型 
//			printf("%d",e);		//int类型
//			printf("%c",e);		//char类型
			
			printf("\n删除后的数据是：\n");
			DispList(L);
			break;
		case 3:
			printf("\n\n=====当前线性表为：\n");
			DispList(L);
			break; 
		case 4:
			break;
		default:
			printf("输入出错，请重新输入！");	
	}	
}	
	return 0;
}
