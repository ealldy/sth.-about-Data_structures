#include <stdio.h> 
//#define  MAXSIZE  20

typedef int KeyType;
typedef char InfoType; 
typedef  struct  {
    KeyType key ;      /*�ؼ�����*/
	InfoType data ;    /*�����򣬱����ݴ�a*/
}RecType; //��¼����

void CreateSort(RecType R[],KeyType a[],int n)
{
	for(int i=0;i<n;i++)
	{
		R[i].key = a[i];
		R[i].data = 'a';	/*�����򣬱����ݴ�a*/
	}
}

void DispSort(RecType R[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",R[i].key);
	}
	printf("\n");
} 

//****************ֱ�Ӳ�������*************** 
void InsertSort(RecType R[],int n) 
//��R[0..n-1]�������������ֱ�Ӳ�������
{	
	int i,j;	
	RecType temp;
	for(i=1;i<n;i++) 
	{
		temp=R[i];
		j=i-1;  //����������������R[0..i-1]��R[i]�Ĳ���λ��
		while(j>=0 && temp.key < R[j].key) 
		{
			R[j+1]=R[j];   //���ؼ��ִ���R[i].key�ļ�¼����
			j--;
		}
		R[j+1]=temp;      //��j+1������R[i]
		
		//��ʾ����������� 
		printf("��%d��ֱ�Ӳ�������",i); 
		DispSort(R,n);
	}
}
//****************�۰��������*************** 
void InsertSort1(RecType R[],int n)
{
	int i,j,low,high,mid;
	RecType tmp;
	for(i=1;i<n;i++) 
	{
		tmp=R[i];		   //��R[i]���浽tmp��
		low=0;high=i-1;
		while(low<=high)	   //��R[low..high]�в��Ҳ����λ��
		{
			mid=(low+high)/2;		//ȡ�м�λ��
			if(tmp.key<R[mid].key)
				high=mid-1;			//������������
			else
				low=mid+1;			//��������Ұ���
		}
		for(j=i-1;j>=high+1;j--)	//��¼����
			R[j+1]=R[j];
		R[high+1]=tmp;			//����
		
		//��ʾ����������� 
		printf("��%d���۰��������",i); 
		DispSort(R,n);
   }
}
//****************ϣ������******************* 
void ShellSort(RecType R[],int n)	//ϣ�������㷨
{
	int d=1; 	//��������
	
	int i,j,gap;
	RecType tmp;
	gap=n/2;			  //�����ó�ֵ
	while (gap>0)
	{
		for(i=gap;i<n;i++) //�����gapλ�õ�Ԫ����ֱ�Ӳ�������
		{
			tmp=R[i];
			j=i-gap;
			while(j>=0 && tmp.key<R[j].key)
			{
				R[j+gap]=R[j];
				j=j-gap;
			}
			R[j+gap]=tmp;
		}
		gap=gap/2;	//��С����
		
		//��ʾ����������� 
		printf("��%d��ϣ������",d); 
		DispSort(R,n);
		d++; 
	}
}
//****************ð������******************* 
void BubbleSort(RecType R[],int n)
{
	int i,j;
	RecType temp;
	for(i=0;i<n-1;i++) 
	{
		for(j=n-1;j>i;j--)  //�Ƚ��ұ�����С�ؼ��ֵļ�¼
			if( R[j].key<R[j-1].key )   
			{
				temp=R[j];    //R[j]��R[j-1]���н���
				R[j]=R[j-1];
				R[j-1]=temp;
			}
			
		//��ʾ����������� 
		printf("��%d��ð������",i+1); 
		DispSort(R,n);	
	}
} 
//**************�Ľ����ð������*************
void BubbleSort1(RecType R[],int n)
{	
	int i,j;
	bool exchange;
	RecType temp;
	for(i=0;i<n-1;i++) 
	{
		exchange=false;
		for(j=n-1; j>i; j--)	//�Ƚ�,�ҳ���С�ؼ��ֵļ�¼
		if(R[j].key<R[j-1].key)   	
		{
			temp=R[j]; 
			R[j]=R[j-1];
			R[j-1]=temp;
			exchange=true;
		}
		if (exchange==false) return;  //��;�����㷨
		
		//��ʾ����������� 
		printf("��%d�˸Ľ����ð������",i+1); 
		DispSort(R,n);
	}
}
//****************��������*******************
void QuickSort(RecType R[],int s,int t) 
//��R[s]��R[t]��Ԫ�ؽ��п�������
{
	int i=s,j=t;
	RecType temp;
    if(s<t)         //���������ٴ���2��Ԫ�ص����
    {
		temp=R[s];		//������ĵ�1����¼��Ϊ��׼
		while (i!=j)	//�����˽������м�ɨ��,ֱ��i=jΪֹ
		{
			while (j>i && R[j].key>=temp.key) j--;  
			R[i]=R[j];
			while (i<j && R[i].key<=temp.key) i++;
			R[j]=R[i];
		}
        R[i]=temp;
        
        //��ʾ�����������
        printf("��%dΪ��׼������[%d-%d]���䣺",temp.key,s+1,t+1); 
        DispSort(R,N);
         
        QuickSort(R,s,i-1);    //��������ݹ�����
        QuickSort(R,i+1,t);    //��������ݹ�����
	} 
}

//****************��ѡ������*************** 
void SelectSort(RecType R[], int n)
{
	int i,j,k;
	RecType temp;
	for(i=0;i<n-1;i++)		//����i������
	{ 
		k=i;
		for(j=i+1; j<n; j++)  //��[i..n-1]��ѡkey��С��R[k] 
			if(R[j].key < R[k].key)
				k=j;           //k���µ���С�ؼ������ڵ�λ��
		if(k!=i)			//����R[i]��R[k] 
		{
			temp=R[i];
			R[i]=R[k];
			R[k]=temp;
		}
		
		//��ʾ����������� 
		printf("��%d�ˣ�ѡ��[%d-%d]����С�ļ�¼�ŵ�%d��",i+1,i+1,n,i+1); 
		DispSort(R,n);
	}
 }

