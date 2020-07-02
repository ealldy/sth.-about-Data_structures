#include <malloc.h>
#include <stdio.h> 

#define MaxSize  100
typedef  struct
{   
	char data[MaxSize] ;
	int length;
}SqString;   

void StrAssign(SqString &s,char cstr[])	//sΪ�����Ͳ���
{  
	int i;
    for (i=0;cstr[i]!='\0';i++)
		s.data[i]=cstr[i];
    s.length=i;
}
void StrCopy(SqString &s,SqString t)	//sΪ�����Ͳ���
{  
    int i;
    for (i=0;i<t.length;i++)
		s.data[i]=t.data[i];
    s.length=t.length;
}
/*
int StrCompare(SqString S,SqString T)
//��S>T���򷵻�ֵ>0����S=T���򷵻�ֵ=0����S<T���򷵻�ֵ<0�� 
{
	for(int i=0;i<S.length&&i<T.length;i++)
		if(S.ch[i] != T.ch[i]) 
			return S.ch[i]-T.ch[i];
	return S.length - T.length; 
}//StrCompare
*/
int Strcmp(SqString s,SqString t)
{  
	int i,comlen;
    if (s.length<t.length)comlen=s.length;//��s��t�Ĺ�ͬ����
    else comlen=t.length;

    for (i=0;i<comlen;i++)     //�ڹ�ͬ����������ַ��Ƚ�
	if (s.data[i]>t.data[i])
		return 1;
	else if (s.data[i]<t.data[i])
		return -1;

    if (s.length==t.length)	//s==t
		return 0;
    else if (s.length>t.length)//s>t
		return 1;
    else  return -1;		//s<t
}
int StrLength(SqString s)
{
	return s.length;
}
SqString Concat(SqString s,SqString t)
{  
	SqString str;
    int i;
    str.length=s.length+t.length;
    for (i=0;i<s.length;i++) 	//s.data[0..s.length-1]����str
		str.data[i]=s.data[i];
    for (i=0;i<t.length;i++)   //t.data[0..t.length-1]����str
		str.data[s.length+i]=t.data[i];
    return str;
}
SqString SubStr(SqString s,int i,int j)
{  
	SqString str;
    int k;
    str.length=0;
	if (i<=0 || i>s.length || j<0 || i+j-1>s.length)
		return str;		//��������ȷʱ���ؿմ�
	for (k=i-1;k<i+j-1;k++) //s.data[i..i+j]?str
		str.data[k-i+1]=s.data[k];
    str.length=j;
    return str;
} 

void DispStr(SqString s)
{ 
	int i;
    if (s.length>0)
    {  
		for(i=0;i<s.length;i++)
	   		printf("%c",s.data[i]);
		printf("\n");
    }
}
