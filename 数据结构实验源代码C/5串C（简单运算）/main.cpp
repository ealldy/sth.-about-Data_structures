#include <malloc.h>
#include <stdio.h> 
#include "SqString.h"

int main(int argc, char** argv) {
	
	char str1[] = "HelloWorle";  
	char str2[] = "HelloWorlddddddd";  
	
	SqString T,S;	
	StrAssign(T,str1);
	printf("串T为:");
	DispStr(T);
	
	printf("\n串T长度为：%d\n",StrLength(T)); 

	SqString T1; 
	StrCopy(T1,T);
	printf("\n串T1复制T，T1为:");
	DispStr(T1);
	
	StrAssign(S,str2);
	printf("\n串S为:");
	DispStr(S);
	
	int i = Strcmp(T,S);
	if(i>0)
		printf("\nT比S大\n");
	else if(i==0)
		printf("\nT和S相等\n");
	else
		printf("\nT比S小\n");


	SqString TT;
	TT=Concat(T,S);
	printf("\n联接T和S两个串为TT：\n");
	DispStr(TT);
	
	SqString Sub;
	Sub=SubStr(S,3,4);
	printf("\n串S第3个位置开始的4个字符为:");
	DispStr(Sub);

	return 0;
}
