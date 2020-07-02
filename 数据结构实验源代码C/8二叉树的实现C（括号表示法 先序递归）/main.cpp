#include <malloc.h>
#include <stdio.h> 
#include "BiTree.h" 

int main(int argc, char** argv) {
	
	BTNode *T;
	char str[30]={'A','(','B','(','D','(',',','G',')',')',',','C','(','E',',','F',')',')'}; 
    char str1[30]={'A','(','B','(','D',',',')',',','C','(','E','(',',','G',')',',','F','(','H',',','I',')',')',')'};
	
	/*方法一 
	CreateBTNode(T,str);
	printf("二叉树：");
	DispBTNode(T);
	//*/
	
	
	//*方法二 
	CreateBiTree(T);
	printf("二叉树：");
	DispBinTree(T);
	//*/
	
	 
	printf("\n该二叉树的叶子结点个数为：%d\n\n",LeafNodes(T));
	/*
	CreateBTNode(T,str1);
	printf("二叉树：");
	DispBTNode(T);
	printf("\n该二叉树的叶子结点个数为：%d\n\n",LeafNodes(T));
	*/ 
	return 0;
}

