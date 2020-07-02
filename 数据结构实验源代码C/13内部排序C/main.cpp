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
	printf("初始关键字：");
	DispSort(R,N);
	
	/****************直接插入排序*************** 
	InsertSort(R,N);
	printf("------------\n"); 
	printf("直接插入排序后结果：");
	DispSort(R,N);
	//*/ 
	
	/****************折半插入排序*************** 
	InsertSort1(R,N);
	printf("------------\n"); 
	printf("折半插入排序后结果：");
	DispSort(R,N);
	//*/ 
	
	/****************希尔排序*************** 
	ShellSort(R,N); 
	printf("------------\n"); 
	printf("希尔排序后结果：");
	DispSort(R,N);
	//*/

	/****************冒泡排序***************	
	BubbleSort(R,N);
	printf("------------\n"); 
	printf("冒泡排序后结果：");
	DispSort(R,N);
	//*/
	
	/**************改进冒泡排序*************	
	BubbleSort1(R,N);
	printf("------------\n"); 
	printf("改进冒泡排序后结果：");
	DispSort(R,N);
	//*/
	
	/****************快速排序*************** 
	QuickSort(R,0,N-1);
	printf("------------\n"); 
	printf("快速排序后结果：");
	DispSort(R,N);
	//*/
	
	//****************简单选择排序***************
	SelectSort(R,N);
	printf("------------\n"); 
	printf("简单选择排序后结果：");
	DispSort(R,N);
	//*/
	
	return 0;
}
 
