#include <malloc.h>
#include <stdio.h> 
#include "SparseMatrix.h"



int main(int argc, char** argv) {
	
	ElemType a[8][8]={{0,0,-3,0,0,0,0,0},
					  {0,0,0,0,0,0,37,0},
					  {0,0,0,0,0,0,0,0},
					  {0,0,0,24,0,0,0,0},
					  {0,0,0,0,0,0,0,0},
					  {0,15,0,0,0,0,0,0},
					  {0,0,0,0,0,0,88,0},
					  {0,0,0,0,0,0,0,0},
					  };
	TSMatrix MM;
	CreatMat(MM,a);
	printf("初始矩阵为：\n");
	DispMatrix(MM);
	printf("矩阵的三元组顺序表为：\n");	
	DispMat(MM);
	
	printf("\n\n"); 


	
	TSMatrix T;
	TranTat(MM,T); 
	printf("转置后矩阵为：\n");
	DispMatrix(T);
	printf("\n转置后的三元组顺序表为：\n");	
	DispMat(T);

	return 0;
}
