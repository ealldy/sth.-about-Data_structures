#include <malloc.h>
#include <stdio.h> 
#include "SqString.h"

int main(int argc, char** argv) {
	
	char str1[] = "HelloWorle";  
	char str2[] = "HelloWorlddddddd";  
	
	SqString T,S;	
	StrAssign(T,str1);
	printf("��TΪ:");
	DispStr(T);
	
	printf("\n��T����Ϊ��%d\n",StrLength(T)); 

	SqString T1; 
	StrCopy(T1,T);
	printf("\n��T1����T��T1Ϊ:");
	DispStr(T1);
	
	StrAssign(S,str2);
	printf("\n��SΪ:");
	DispStr(S);
	
	int i = Strcmp(T,S);
	if(i>0)
		printf("\nT��S��\n");
	else if(i==0)
		printf("\nT��S���\n");
	else
		printf("\nT��SС\n");


	SqString TT;
	TT=Concat(T,S);
	printf("\n����T��S������ΪTT��\n");
	DispStr(TT);
	
	SqString Sub;
	Sub=SubStr(S,3,4);
	printf("\n��S��3��λ�ÿ�ʼ��4���ַ�Ϊ:");
	DispStr(Sub);

	return 0;
}
