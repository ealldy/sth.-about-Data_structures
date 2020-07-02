#include<iostream>
using namespace std;
#include"btree.h"
#include"BTOrder_rec.h"



int main(void)
{
	int i,k;
	bool key;
	char *c="A(B(D(,G)),C(E,F))";
	BTNode *st;
	CreateBTree(st,c);
	cout<<"二叉树：";
	DispBTree(st);
	cout<<endl;
	cout<<"二叉树的结点数:"<<sum(0,st);
	cout<<endl<<endl;
	cout<<"其叶子结点:";
	PreOrder_rec(1,st);
	cout<<endl;
	cout<<"其叶子结点数:";
	cout<<sum(1,st);
	cout<<endl<<endl;
	for (i=1;i<=10;i++) cout<<"-";cout<<"递归遍历";for (i=1;i<=10;i++) cout<<"-";cout<<endl;
	cout<<"先序遍历：";
	PreOrder_rec(0,st);
	cout<<endl;
	cout<<"中序遍历：";
	InOrder_rec(0,st);
	cout<<endl;
	cout<<"后序遍历：";
	PostOrder_rec(0,st);
	cout<<endl;
	for (i=1;i<=10;i++) cout<<"-";cout<<"递归遍历";for (i=1;i<=10;i++) cout<<"-";cout<<endl<<endl;
	key=true;
	while (key)
	{
		cout<<"1,求二叉树中第k层的结点个数"<<endl<<"0,退出"<<endl;
		cout<<"请输入序号：";
		cin>>i;
		switch(i)
		{
			case 1:
				{	
					cout<<"请输入k：";
					cin>>k;
					cout<<"第k层结点个数="<<Lnodenum(st,0,k)<<endl;
				}
		}
		cout<<endl;
		if (0==i) key=false;
	}
	return 0;
}