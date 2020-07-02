#include <malloc.h>
#include <stdio.h> 
#include "SqString.h"

SqString EnCrypt(SqString p,SqString A,SqString B) //���ܣ�p����Ҫ���ܵĴ���A�ǳ�ʼ����B��ӳ�䴮 
{
	int i=0,j;
	SqString q;		//���ܺ�Ĵ� 
	while(i<p.length)
	{
		for(j=0;p.data[i]!=A.data[j];j++);	//��A����p.data[i],����λ��j 
		if(j>=A.length)	//A����δ�ҵ�p.data[i]
			q.data[i] = p.data[i];
		else			//A�����ҵ�p.data[i] 
			q.data[i] = B.data[j];
		i++;
	}
	q.length = p.length;
	return q;
} 

SqString UnEnCrypt(SqString q,SqString A,SqString B) //���ܣ�q���Ѿ����ܵĴ���A�ǳ�ʼ����B��ӳ�䴮
{
	int i=0,j;
	SqString p;		//���ܺ�Ĵ� 
	while(i<q.length)
	{
		for(j=0;q.data[i]!=B.data[j];j++);	//��B����p.data[i],����λ��j 
		if(j>=B.length)	//B����δ�ҵ�q.data[i]
			p.data[i] = q.data[i];
		else			//B�����ҵ�q.data[i] 
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
	printf("����ԭ�Ĵ���");
	gets(str);
	StrAssign(p,str);
	
	printf("���ܽ������£�\n");
	printf("  ԭ�Ĵ���"); 
	DispStr(p);
	q=EnCrypt(p,A,B);
	printf("  ���ܴ���"); 
	DispStr(q);
	p=UnEnCrypt(q,A,B);
	printf("  ���ܴ���"); 
	DispStr(p);
	
	return 0;
}
