#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h" 

int main(int argc, char** argv) {
		
	LinkList *LA;
	LinkList *LB;
	ElemType e;
	
	//*int类型 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	CreateListR(LA,a,10);
	printf("集合A：");
	DispList(LA);
	//*/
	
	//*int类型 
	int b[10]={3,4,7,11,56,23,21,102,9,5};
	CreateListR(LB,b,10);
	printf("集合B：");
	DispList(LB);
	//*/
	
	//求线性表的长度
    int LA_len = ListLength(LA); 
    int LB_len = ListLength(LB); 

	for (int i=1; i<=LB_len; i++)
	{
		//取LB中第i个数据元素赋给e    
		GetElem(LB,i,e); 
	
		// LA中不存在和 e相同的数据元素，
		//则插入之
		if (LocateElem(LA,e) == 0) 
			ListInsert(LA, ++LA_len, e);
	}
	printf("集合A＝A∪B：");
	DispList(LA);
	
	return 0;
}
