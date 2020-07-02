#include <malloc.h>
#include <stdio.h> 
#include <iostream>
using namespace std;

typedef char ElemType;

//Visit函数，对每个节点进行的访问
//需设置函数返回值类型
typedef void Status; 
Status DispLargeThanC(ElemType e)//该函数输出树中大于C的字符 
{
	if(e>'C') 
	{
		printf("%2c",e);
	}
	else
	{
		printf("%2c",'*');
	}
}

Status DispLessThanD(ElemType e)//该函数输出树中小于D的字符 
{
	if(e<'D') 
	{
		printf("%2c",e);
	}
	else
	{
		printf("%2c",'*');
	}
}

#include "BiTree.h" 

int main(int argc, char** argv) {
	
	BTNode *T;
	char str[]="A(B(D(,G)),C(E,F))"; 
	
	CreateBTNode(T,str);
	printf("二叉树：");
	DispBTNode(T);
	
	printf("\n\n------------递归遍历-----------");
	printf("\n\n先序遍历为：");
	PreOrder(T);
	printf("\n中序遍历为：");
	InOrder(T);
	printf("\n后序遍历为：");
	PostOrder(T);
	
	printf("\n\n------------非递归遍历---------");
	printf("\n\n先序遍历为：");
	NonRecurPreOrder(T);
	printf("\n中序遍历为：");
	NonRecurInOrder(T);
	printf("\n后序遍历为：");
	NonRecurPostOrder(T);
	
	
	cout<<endl<<endl<<endl<<"---------------------------"<<endl;
	
	
	cout<<"以下输出树中大于C的字符";
	cout<<endl<<"先序："; 
	PreOrderTraverse(T,DispLargeThanC);
	cout<<endl<<"中序："; 
	InOrderTraverse(T,DispLargeThanC);
	cout<<endl<<"后序："; 
	PostOrderTraverse(T,DispLargeThanC);
	
	cout<<endl<<endl<<endl<<"---------------------------"<<endl;
	cout<<"以下输出树中小于D的字符";
	cout<<endl<<"先序："; 
	PreOrderTraverse(T,DispLessThanD);
	cout<<endl<<"中序："; 
	InOrderTraverse(T,DispLessThanD);
	cout<<endl<<"后序："; 
	PostOrderTraverse(T,DispLessThanD);
	
	
	return 0;
}

