#include <malloc.h>
#include <stdio.h> 
#include <iostream>
using namespace std;

typedef char ElemType;

//Visit��������ÿ���ڵ���еķ���
//�����ú�������ֵ����
typedef void Status; 
Status DispLargeThanC(ElemType e)//�ú���������д���C���ַ� 
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

Status DispLessThanD(ElemType e)//�ú����������С��D���ַ� 
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
	printf("��������");
	DispBTNode(T);
	
	printf("\n\n------------�ݹ����-----------");
	printf("\n\n�������Ϊ��");
	PreOrder(T);
	printf("\n�������Ϊ��");
	InOrder(T);
	printf("\n�������Ϊ��");
	PostOrder(T);
	
	printf("\n\n------------�ǵݹ����---------");
	printf("\n\n�������Ϊ��");
	NonRecurPreOrder(T);
	printf("\n�������Ϊ��");
	NonRecurInOrder(T);
	printf("\n�������Ϊ��");
	NonRecurPostOrder(T);
	
	
	cout<<endl<<endl<<endl<<"---------------------------"<<endl;
	
	
	cout<<"����������д���C���ַ�";
	cout<<endl<<"����"; 
	PreOrderTraverse(T,DispLargeThanC);
	cout<<endl<<"����"; 
	InOrderTraverse(T,DispLargeThanC);
	cout<<endl<<"����"; 
	PostOrderTraverse(T,DispLargeThanC);
	
	cout<<endl<<endl<<endl<<"---------------------------"<<endl;
	cout<<"�����������С��D���ַ�";
	cout<<endl<<"����"; 
	PreOrderTraverse(T,DispLessThanD);
	cout<<endl<<"����"; 
	InOrderTraverse(T,DispLessThanD);
	cout<<endl<<"����"; 
	PostOrderTraverse(T,DispLessThanD);
	
	
	return 0;
}

