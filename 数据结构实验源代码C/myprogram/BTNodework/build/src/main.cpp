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
	cout<<"��������";
	DispBTree(st);
	cout<<endl;
	cout<<"�������Ľ����:"<<sum(0,st);
	cout<<endl<<endl;
	cout<<"��Ҷ�ӽ��:";
	PreOrder_rec(1,st);
	cout<<endl;
	cout<<"��Ҷ�ӽ����:";
	cout<<sum(1,st);
	cout<<endl<<endl;
	for (i=1;i<=10;i++) cout<<"-";cout<<"�ݹ����";for (i=1;i<=10;i++) cout<<"-";cout<<endl;
	cout<<"���������";
	PreOrder_rec(0,st);
	cout<<endl;
	cout<<"���������";
	InOrder_rec(0,st);
	cout<<endl;
	cout<<"���������";
	PostOrder_rec(0,st);
	cout<<endl;
	for (i=1;i<=10;i++) cout<<"-";cout<<"�ݹ����";for (i=1;i<=10;i++) cout<<"-";cout<<endl<<endl;
	key=true;
	while (key)
	{
		cout<<"1,��������е�k��Ľ�����"<<endl<<"0,�˳�"<<endl;
		cout<<"��������ţ�";
		cin>>i;
		switch(i)
		{
			case 1:
				{	
					cout<<"������k��";
					cin>>k;
					cout<<"��k�������="<<Lnodenum(st,0,k)<<endl;
				}
		}
		cout<<endl;
		if (0==i) key=false;
	}
	return 0;
}