#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h" 

int main(int argc, char** argv) {
		
	LinkList *LA;
	LinkList *LB;
	ElemType e;
	
	//*int���� 
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	CreateListR(LA,a,10);
	printf("����A��");
	DispList(LA);
	//*/
	
	//*int���� 
	int b[10]={3,4,7,11,56,23,21,102,9,5};
	CreateListR(LB,b,10);
	printf("����B��");
	DispList(LB);
	//*/
	
	//�����Ա�ĳ���
    int LA_len = ListLength(LA); 
    int LB_len = ListLength(LB); 

	for (int i=1; i<=LB_len; i++)
	{
		//ȡLB�е�i������Ԫ�ظ���e    
		GetElem(LB,i,e); 
	
		// LA�в����ں� e��ͬ������Ԫ�أ�
		//�����֮
		if (LocateElem(LA,e) == 0) 
			ListInsert(LA, ++LA_len, e);
	}
	printf("����A��A��B��");
	DispList(LA);
	
	return 0;
}
