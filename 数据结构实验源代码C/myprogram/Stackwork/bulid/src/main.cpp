#include<iostream>
#include"stack.h"
#include"match.h"
using namespace std;

int main(void)
{   while (1) 
	{ 
	char exp[256];
	int n;
	char o='1';

	cout<<"�������ַ�������";
	cin>>n;
	cout<<"�������ַ���";
	cin>>exp;
	//gets(exp);
	cout<<endl<<endl;
	if (Match(exp,n,o))
	{
		cout<<"�ɹ�ƥ�䣡����ķ����ǣ�"<<exp<<endl;
	}
	else 
	{
		if ((o=='(') || (o=='['))
		{
			cout<<"����������ƥ�䣡"<<endl;
		}
		if (o==']')
		{
			cout<<"'['���Ų�ƥ��"<<endl;
		}
		if (o==')')
		{
			cout<<"'('���Ų�ƥ��"<<endl;
		}
	}
	cout<<endl<<"-------------------------------------------"<<endl;
	}
	return 0;
}