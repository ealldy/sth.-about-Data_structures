#include <malloc.h>
#include <stdio.h> 
#define N 20 //NҪ����n  

typedef struct
{     
	char data;		//�ڵ�ֵ
    int weight ;    //Ȩֵ��
	int parent,lchild,rchild ;
}HTNode; //Huffman���Ľ������

typedef struct
{  
	char cd[N];  //��ŵ�ǰ�ڵ�Ĺ�������
	int start;   //��Ź���������cd�е���ʼλ��
}HCode;	//���������������� 

void CreateHT(HTNode ht[],int n)
{ 
	int i,j,k,lnode,rnode; 
	float min1,min2;
    for(i=0;i<2*n-1;i++)	  //���нڵ��������ó�ֵ-1
    	ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    for(i=n;i<2*n-1;i++)		//�����������
    {  
		min1=min2=32767; 
		lnode=rnode=-1;
		for(k=0;k<=i-1;k++)
	  		if(ht[k].parent==-1)	//δ����������Ľڵ��в���
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


void CreateHCode(HTNode ht[],HCode hcd[],int n)		//���� 
{
	int i,f,c; 
	HCode hc;
    for(i=0;i<n;i++)		//���ݹ������������������
    {  
		hc.start=n; 
		c=i;  
		f=ht[i].parent;
		while(f!=-1)   //ѭ��ֱ����˫�׽ڵ㼴���������ڵ�
		{  
			if(ht[f].lchild==c)	//��ǰ�ڵ������ӽڵ�
	      		hc.cd[hc.start--]='0';
	   		else	  		//��ǰ�ڵ���˫�׽ڵ���Һ��ӽڵ�
	      		hc.cd[hc.start--]='1';
	   		c=f;
			f=ht[f].parent; //�ٶ�˫�׽ڵ����ͬ���Ĳ���
 	 	}
	 	hc.start++;		//startָ������������ʼ�ַ�
		hcd[i]=hc;
   }
} 

//���� 
bool EnHCode(char Code[],HTNode ht[],char DeCode[],int n)//CodeҪ����룬DeCode�����������ַ���
{
	int i=0; //ȡstr��ѭ������ 
	int m=2*n-2; 
	int CodeNum=0;	//���浱ǰ����ñ�������� 
	
	while(Code[i] != '\0')
	{
		if(Code[i] == '0')	//�������֧ 
		{
			m=ht[m].lchild;			
		}
		else if(Code[i] == '1')//�����ҷ�֧ 
		{ 
			m=ht[m].rchild;
		} 	
		if(ht[m].lchild == -1 && ht[m].rchild == -1) //����ĳҶ�ӽڵ� 
		{
			DeCode[CodeNum] = ht[m].data; 
			m=2*n-2; //���´Ӹ���㿪ʼ
			CodeNum++;
		}
		i++; //ȡ��һ���ַ� 
	}
	if(m != 2*n-2)
		return false;
	DeCode[CodeNum] = '\0';
	return true;
} 

