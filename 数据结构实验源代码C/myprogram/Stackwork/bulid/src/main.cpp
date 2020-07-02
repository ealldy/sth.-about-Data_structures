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

	cout<<"ÇëÊäÈë×Ö·û¸öÊý£º";
	cin>>n;
	cout<<"ÇëÊäÈë×Ö·û£º";
	cin>>exp;
	//gets(exp);
	cout<<endl<<endl;
	if (Match(exp,n,o))
	{
		cout<<"³É¹¦Æ¥Åä£¡ÊäÈëµÄ·ûºÅÊÇ£º"<<exp<<endl;
	}
	else 
	{
		if ((o=='(') || (o=='['))
		{
			cout<<"À¨ºÅÊýÁ¿²»Æ¥Åä£¡"<<endl;
		}
		if (o==']')
		{
			cout<<"'['À¨ºÅ²»Æ¥Åä"<<endl;
		}
		if (o==')')
		{
			cout<<"'('À¨ºÅ²»Æ¥Åä"<<endl;
		}
	}
	cout<<endl<<"-------------------------------------------"<<endl;
	}
	return 0;
}