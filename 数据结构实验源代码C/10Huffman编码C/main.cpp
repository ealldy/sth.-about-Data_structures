#include <malloc.h>
#include <stdio.h> 
#include "huffmanTree.h" 

int main(int argc, char** argv) {
	
	//*示例1 
	int w[]={8,3,4,6,5,5};	
	char c[]={'a','b','c','d','e','f'}; 
	int nums=6;
	//*/
	
	/*示例2 
	int w[]={7,19,2,6,32,3,21,10};	
	char c[]={'a','b','c','d','e','f','g','h'}; 
	int nums=8;
	//*/
	
	HTNode HT[2*nums-1];  //哈夫曼树结点数组 
	for(int i=0;i<nums;i++)  //赋初始data和weight至HT数组 
	{
		HT[i].weight=w[i];
		HT[i].data=c[i];
	}
	CreateHT(HT,nums); //创建哈夫曼树 
	
	printf("huffman树各节点的值为：\n");	
	for(int j=0;j<2*nums-1;j++)
	{
		printf("%4d",HT[j].weight);
	}

	 
	HCode HC[nums]; //存放Huffman编码数组 
	CreateHCode(HT,HC,nums); 
	
	printf("\n\n");	
	for(int k=0;k<nums;k++)
	{
		printf("字符%c的编码是：",HT[k].data);
		for(int t=HC[k].start; t<=nums; t++)
			printf("%c",HC[k].cd[t]);
		printf("\n");
	}


//译码----示例1 
//	char code[]={'0','1','1','0','1','1','1','0','1','1','1','1','1','0','\0'};   //ccafe
	char code[]="10010001101111000";  //abdefad
//	char code[]="1111"; //错误的信号
//	char code[]="10011110111";  //acef

	printf("\n\n待译码信号为：");
	for(int k=0;code[k]!='\0';k++)
	{
		printf("%c",code[k]);
	}

	char DeCode[20]; //保存译码后的字符串
	if(EnHCode(code,HT,DeCode,nums))
	{
		printf("\n\n成功译码！");
		printf("\n译码后：");
		int i=0;
		while(DeCode[i] != '\0')
		{
			printf("%c",DeCode[i]);
			i++;
		}
	} 
	else
	{
		printf("\n\n代码错误！");
	} 
	
	return 0;
}
