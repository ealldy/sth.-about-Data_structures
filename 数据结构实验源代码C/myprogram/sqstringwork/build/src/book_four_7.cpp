#include<iostream>
#include<string>
#include"book_four_7.h"
#include"sqstring.h"
using namespace std;

void book_four_7()	
{
	char a[256]={0};
	int i,j,k,len;
	SqString s1,s2,s3,s4;

	cout<<"������s1��";gets(a);
	while (a[0]=='\0') {cout<<"������s1��";gets(a);}
	StrAssign(s1,a);

	cout<<"������s2��";gets(a);
	while (a[0]=='\0') {cout<<"������s2��";gets(a);}
	StrAssign(s2,a);

	len=0;
	memset(a,0,256);

	for (i=0;i<=s1.length-1;i++)
	{
		for (j=0;j<=s2.length-1;j++)
		{
			if (s1.data[i]==s2.data[j])	
			{
				a[len]=s1.data[i];//�ҹ�ͬ����
				len++;
			}
		}
	}
	a[len]='\0';
	StrAssign(s3,a);//����˳��
	s3=DeldupStr(s3);//ȥ��˳�����ظ����ַ�
	if (s3.length==0) cout<<"s3������"<<endl;
	else
	{
		cout<<"s3=";
		DispStr(s3);//���˳��
		cout<<"s3.length="<<s3.length<<endl;
	}
}