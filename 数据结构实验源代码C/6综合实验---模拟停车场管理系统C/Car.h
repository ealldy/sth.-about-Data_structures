#include <stdio.h>



typedef struct
{
	int ParkNum;	//ͣ��ͣ������λ�� 
	int CarNum;		//���ƺ��� 
	int ATime;		//��վʱ�� 
}car;



void InputData(car &e)
{
	bool flag=true;	//flag=false����ʾ�����ͣ��λ���Ϸ� 
	do
	{
		flag=true;
		printf("\n������ͣ��λ�ã�");			
		scanf("%d",&e.ParkNum); 
		if(e.ParkNum == 0)
		{
			flag=true;
		}
		else if(e.ParkNum<110 || e.ParkNum>117) 
		//���ͣ��λ������ĺϷ��� 
		{
			printf("���복λ�Ƿ������������룡");
			flag = false;
		}
			
	}while(flag == false);


	printf("�����복�ƺ��룺");
	scanf("%d",&e.CarNum);
	
	printf("�����뵽��ʱ�䣺");
	scanf("%d",&e.ATime);	
}

void OutputData(car e)
{		
	printf("ͣ��λ�ã�%d,",e.ParkNum);
	printf("���ƺ��룺%d,",e.CarNum);
	printf("����ʱ�䣺%d",e.ATime);
	printf("\n");
}
