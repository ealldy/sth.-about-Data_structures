#include <malloc.h>
#include <stdio.h> 
#include "BiTree.h" 

int main(int argc, char** argv) {
	
	BTNode *T;
	char str[30]={'A','(','B','(','D','(',',','G',')',')',',','C','(','E',',','F',')',')'}; 
    char str1[30]={'A','(','B','(','D',',',')',',','C','(','E','(',',','G',')',',','F','(','H',',','I',')',')',')'};
	
	/*����һ 
	CreateBTNode(T,str);
	printf("��������");
	DispBTNode(T);
	//*/
	
	
	//*������ 
	CreateBiTree(T);
	printf("��������");
	DispBinTree(T);
	//*/
	
	 
	printf("\n�ö�������Ҷ�ӽ�����Ϊ��%d\n\n",LeafNodes(T));
	/*
	CreateBTNode(T,str1);
	printf("��������");
	DispBTNode(T);
	printf("\n�ö�������Ҷ�ӽ�����Ϊ��%d\n\n",LeafNodes(T));
	*/ 
	return 0;
}

