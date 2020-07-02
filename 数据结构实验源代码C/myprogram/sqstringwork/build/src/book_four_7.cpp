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

	cout<<"请输入s1：";gets(a);
	while (a[0]=='\0') {cout<<"请输入s1：";gets(a);}
	StrAssign(s1,a);

	cout<<"请输入s2：";gets(a);
	while (a[0]=='\0') {cout<<"请输入s2：";gets(a);}
	StrAssign(s2,a);

	len=0;
	memset(a,0,256);

	for (i=0;i<=s1.length-1;i++)
	{
		for (j=0;j<=s2.length-1;j++)
		{
			if (s1.data[i]==s2.data[j])	
			{
				a[len]=s1.data[i];//找共同部分
				len++;
			}
		}
	}
	a[len]='\0';
	StrAssign(s3,a);//生成顺序串
	s3=DeldupStr(s3);//去除顺序串中重复的字符
	if (s3.length==0) cout<<"s3不存在"<<endl;
	else
	{
		cout<<"s3=";
		DispStr(s3);//输出顺序串
		cout<<"s3.length="<<s3.length<<endl;
	}
}