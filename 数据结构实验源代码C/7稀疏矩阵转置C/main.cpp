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
	printf("��ʼ����Ϊ��\n");
	DispMatrix(MM);
	printf("�������Ԫ��˳���Ϊ��\n");	
	DispMat(MM);
	
	printf("\n\n"); 


	
	TSMatrix T;
	TranTat(MM,T); 
	printf("ת�ú����Ϊ��\n");
	DispMatrix(T);
	printf("\nת�ú����Ԫ��˳���Ϊ��\n");	
	DispMat(T);

	return 0;
}
