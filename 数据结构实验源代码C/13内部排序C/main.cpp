#include <malloc.h>
#include <stdio.h> 
#define N 8
#include "Sorting.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	
//	KeyType a[N]={49,38,65,97,76,13,49,27,55,4};
	KeyType a[N]={49,38,65,97,76,13,27,49};
//	KeyType a[N]={1,2,3,4,5,6,7,8};
	
	RecType R[N];
	CreateSort(R,a,N);
	printf("��ʼ�ؼ��֣�");
	DispSort(R,N);
	
	/****************ֱ�Ӳ�������*************** 
	InsertSort(R,N);
	printf("------------\n"); 
	printf("ֱ�Ӳ������������");
	DispSort(R,N);
	//*/ 
	
	/****************�۰��������*************** 
	InsertSort1(R,N);
	printf("------------\n"); 
	printf("�۰�������������");
	DispSort(R,N);
	//*/ 
	
	/****************ϣ������*************** 
	ShellSort(R,N); 
	printf("------------\n"); 
	printf("ϣ�����������");
	DispSort(R,N);
	//*/

	/****************ð������***************	
	BubbleSort(R,N);
	printf("------------\n"); 
	printf("ð�����������");
	DispSort(R,N);
	//*/
	
	/**************�Ľ�ð������*************	
	BubbleSort1(R,N);
	printf("------------\n"); 
	printf("�Ľ�ð�����������");
	DispSort(R,N);
	//*/
	
	/****************��������*************** 
	QuickSort(R,0,N-1);
	printf("------------\n"); 
	printf("�������������");
	DispSort(R,N);
	//*/
	
	//****************��ѡ������***************
	SelectSort(R,N);
	printf("------------\n"); 
	printf("��ѡ�����������");
	DispSort(R,N);
	//*/
	
	return 0;
}
 
