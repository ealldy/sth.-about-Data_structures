#include <malloc.h>
#include <stdio.h> 
#include "huffmanTree.h" 

int main(int argc, char** argv) {
	
	//*ʾ��1 
	int w[]={8,3,4,6,5,5};	
	char c[]={'a','b','c','d','e','f'}; 
	int nums=6;
	//*/
	
	/*ʾ��2 
	int w[]={7,19,2,6,32,3,21,10};	
	char c[]={'a','b','c','d','e','f','g','h'}; 
	int nums=8;
	//*/
	
	HTNode HT[2*nums-1];  //��������������� 
	for(int i=0;i<nums;i++)  //����ʼdata��weight��HT���� 
	{
		HT[i].weight=w[i];
		HT[i].data=c[i];
	}
	CreateHT(HT,nums); //������������ 
	
	printf("huffman�����ڵ��ֵΪ��\n");	
	for(int j=0;j<2*nums-1;j++)
	{
		printf("%4d",HT[j].weight);
	}

	 
	HCode HC[nums]; //���Huffman�������� 
	CreateHCode(HT,HC,nums); 
	
	printf("\n\n");	
	for(int k=0;k<nums;k++)
	{
		printf("�ַ�%c�ı����ǣ�",HT[k].data);
		for(int t=HC[k].start; t<=nums; t++)
			printf("%c",HC[k].cd[t]);
		printf("\n");
	}


//����----ʾ��1 
//	char code[]={'0','1','1','0','1','1','1','0','1','1','1','1','1','0','\0'};   //ccafe
	char code[]="10010001101111000";  //abdefad
//	char code[]="1111"; //������ź�
//	char code[]="10011110111";  //acef

	printf("\n\n�������ź�Ϊ��");
	for(int k=0;code[k]!='\0';k++)
	{
		printf("%c",code[k]);
	}

	char DeCode[20]; //�����������ַ���
	if(EnHCode(code,HT,DeCode,nums))
	{
		printf("\n\n�ɹ����룡");
		printf("\n�����");
		int i=0;
		while(DeCode[i] != '\0')
		{
			printf("%c",DeCode[i]);
			i++;
		}
	} 
	else
	{
		printf("\n\n�������");
	} 
	
	return 0;
}
