#include <malloc.h>
#include <stdio.h> 
#define N 20 //N要大于n  

typedef struct
{     
	char data;		//节点值
    int weight ;    //权值域
	int parent,lchild,rchild ;
}HTNode; //Huffman树的结点类型

typedef struct
{  
	char cd[N];  //存放当前节点的哈夫曼码
	int start;   //存放哈夫曼码在cd中的起始位置
}HCode;	//哈夫曼编码结点类型 

void CreateHT(HTNode ht[],int n)
{ 
	int i,j,k,lnode,rnode; 
	float min1,min2;
    for(i=0;i<2*n-1;i++)	  //所有节点的相关域置初值-1
    	ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    for(i=n;i<2*n-1;i++)		//构造哈夫曼树
    {  
		min1=min2=32767; 
		lnode=rnode=-1;
		for(k=0;k<=i-1;k++)
	  		if(ht[k].parent==-1)	//未构造二叉树的节点中查找
			{
			  	if(ht[k].weight<min1)
	     		{
					min2=min1; 
					rnode=lnode;
		  			min1=ht[k].weight;
					lnode=k;  
				}
	     		else if(ht[k].weight<min2)
	     		{  
					min2=ht[k].weight; 
					rnode=k;  
				}   
        	} //if
	  		ht[lnode].parent=i;
			ht[rnode].parent=i;
        	ht[i].weight=ht[lnode].weight+ht[rnode].weight;
	  		ht[i].lchild=lnode;
			ht[i].rchild=rnode;
   }
} 


void CreateHCode(HTNode ht[],HCode hcd[],int n)		//编码 
{
	int i,f,c; 
	HCode hc;
    for(i=0;i<n;i++)		//根据哈夫曼树求哈夫曼编码
    {  
		hc.start=n; 
		c=i;  
		f=ht[i].parent;
		while(f!=-1)   //循环直到无双亲节点即到达树根节点
		{  
			if(ht[f].lchild==c)	//当前节点是左孩子节点
	      		hc.cd[hc.start--]='0';
	   		else	  		//当前节点是双亲节点的右孩子节点
	      		hc.cd[hc.start--]='1';
	   		c=f;
			f=ht[f].parent; //再对双亲节点进行同样的操作
 	 	}
	 	hc.start++;		//start指向哈夫曼编码最开始字符
		hcd[i]=hc;
   }
} 

//译码 
bool EnHCode(char Code[],HTNode ht[],char DeCode[],int n)//Code要译的码，DeCode保存译码后的字符串
{
	int i=0; //取str的循环变量 
	int m=2*n-2; 
	int CodeNum=0;	//保存当前已译好编码的数量 
	
	while(Code[i] != '\0')
	{
		if(Code[i] == '0')	//进入左分支 
		{
			m=ht[m].lchild;			
		}
		else if(Code[i] == '1')//进入右分支 
		{ 
			m=ht[m].rchild;
		} 	
		if(ht[m].lchild == -1 && ht[m].rchild == -1) //到达某叶子节点 
		{
			DeCode[CodeNum] = ht[m].data; 
			m=2*n-2; //重新从根结点开始
			CodeNum++;
		}
		i++; //取下一个字符 
	}
	if(m != 2*n-2)
		return false;
	DeCode[CodeNum] = '\0';
	return true;
} 

