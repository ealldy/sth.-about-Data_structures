#include<iostream>
#include<string>
#include"public_substring.h"
#include"sqstring.h"
using namespace std;

void public_substring()
{
	char a[256];
	string b[256];
	int i,j,k,n,n1,n2;
	bool f,ff;
	SqString str,s1,s2,s3,s4;

	cout<<"ÇëÊäÈës1£º";gets(a);
	while (a[0]=='\0') {cout<<"ÇëÊäÈës1£º";gets(a);}
	StrAssign(s1,a);

	cout<<"ÇëÊäÈës2£º";gets(a);
	while (a[0]=='\0') {cout<<"ÇëÊäÈës2£º";gets(a);}
	StrAssign(s2,a);

	if (s1.length<s2.length)
	{
		StrCopy(str,s1);
		StrCopy(s1,s2);
		StrCopy(s2,str);
	}

	for (i=1;i<=s2.length;i++)
	{
		for (j=s2.length+1-i;j>=1;j--)
		{
			s3=SubStr(s2,i,j);
			n=0;
			for (k=1;k<=s1.length+1-j;k++)
			{
				s4=SubStr(s1,k,j);
				ff=true;
				for (n1=1;n1<=n;n1++)
				{
					f=false;
					for (n2=0;n2<=j-1;n2++)
					{
						if (b[n1][n2]!=s4.data[n2]) 
						{
							f=true;
							break;
						}
					}
					if (f==false) ff=false; 
				}
				if ((ff) && (StrSqual(s4,s3)))
				{
					cout<<"s3=";
					DispStr(s3);
					cout<<"length="<<s3.length<<endl;
					n++;
					b[n]=s3.data;		
				}
			}
		}
	}

}