#include <malloc.h>
#include <stdio.h> 
#include "SqString.h"

SqString EnCrypt(SqString p,SqString A,SqString B) //加密，p是需要加密的串，A是初始串，B是映射串 
{
	int i=0,j;
	SqString q;		//加密后的串 
	while(i<p.length)
	{
		for(j=0;p.data[i]!=A.data[j];j++);	//在A中找p.data[i],返回位置j 
		if(j>=A.length)	//A串中未找到p.data[i]
			q.data[i] = p.data[i];
		else			//A串中找到p.data[i] 
			q.data[i] = B.data[j];
		i++;
	}
	q.length = p.length;
	return q;
} 

SqString UnEnCrypt(SqString q,SqString A,SqString B) //解密，q是已经加密的串，A是初始串，B是映射串
{
	int i=0,j;
	SqString p;		//解密后的串 
	while(i<q.length)
	{
		for(j=0;q.data[i]!=B.data[j];j++);	//在B中找p.data[i],返回位置j 
		if(j>=B.length)	//B串中未找到q.data[i]
			p.data[i] = q.data[i];
		else			//B串中找到q.data[i] 
			p.data[i] = A.data[j];
		i++;
	}
	p.length = q.length;
	return p;
} 


int main(int argc, char** argv) {
	
	char strA[] = "abcdefghijklmnopqrstuvwxyz";
	char strB[] = "ngzqtcobmuhelkpdawxfyivrsj";
	
	SqString A;
	SqString B;
	StrAssign(A,strA);
	StrAssign(B,strB);
	
	SqString p,q;
	char str[100];
	printf("输入原文串：");
	gets(str);
	StrAssign(p,str);
	
	printf("加密解密如下：\n");
	printf("  原文串："); 
	DispStr(p);
	q=EnCrypt(p,A,B);
	printf("  加密串："); 
	DispStr(q);
	p=UnEnCrypt(q,A,B);
	printf("  解密串："); 
	DispStr(p);
	
	return 0;
}
