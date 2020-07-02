#include<iostream>
#include"sqstring.h"
using namespace std;

void StrAssign(SqString &s,char cstr[])
{
	int i;
	for (i=0;cstr[i]!='\0';i++)
	{
		s.data[i]=cstr[i];
	}
	s.length=i;
}//生成顺序串

void StrCopy(SqString &s,SqString t)
{
	int i;
	for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
	s.length=t.length;
}//将顺序串t复制给顺序串s

bool StrSqual(SqString s,SqString t)
{
	int i;
	if (s.length!=t.length)
		return false;
	else
		for (i=0;i<s.length;i++)
			if (s.data[i]!=t.data[i])
			{
				return false;
			}
}//判断两顺序串是否相同

SqString SubStr(SqString s,int i,int j)
{
	int k;
	SqString str;
	str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;
	for (k=i-1;k<i+j-1;k++)
		str.data[k+1-i]=s.data[k];
	str.length=j;
	return str;
}//求顺序串s中第i个字符开始连续j个字符组成的子串

void DispStr(SqString s)
{
	int i;
	if (s.length>0)
	{
		for (i=0;i<s.length;i++)
			printf("%c",s.data[i]);
		cout<<endl;
	}
}//输出顺序串字符

SqString DeldupStr(SqString s)
{
	int i,j,len;
	int a[256];
	SqString str;
	len=0;
	for (i=0;i<=s.length-1;i++) a[i]=1;
	for (i=0;i<=s.length-1;i++)
	{
		if (a[i]) 
		{
			a[i]=0;
			str.data[len]=s.data[i];
			len++;
		}
		for (j=i+1;j<=s.length-1;j++)
		{
			if ((s.data[i]==s.data[j]) & (a[j])) a[j]=0; 
		}
	}
	str.length=len;
	return str;
}//去除顺序串中重复的字符