#include <stdio.h>



typedef struct
{
	int ParkNum;	//停在停车场的位置 
	int CarNum;		//车牌号码 
	int ATime;		//进站时间 
}car;



void InputData(car &e)
{
	bool flag=true;	//flag=false，表示输入的停车位不合法 
	do
	{
		flag=true;
		printf("\n请输入停车位置：");			
		scanf("%d",&e.ParkNum); 
		if(e.ParkNum == 0)
		{
			flag=true;
		}
		else if(e.ParkNum<110 || e.ParkNum>117) 
		//检测停车位置输入的合法性 
		{
			printf("输入车位非法，请重新输入！");
			flag = false;
		}
			
	}while(flag == false);


	printf("请输入车牌号码：");
	scanf("%d",&e.CarNum);
	
	printf("请输入到达时间：");
	scanf("%d",&e.ATime);	
}

void OutputData(car e)
{		
	printf("停车位置：%d,",e.ParkNum);
	printf("车牌号码：%d,",e.CarNum);
	printf("到达时间：%d",e.ATime);
	printf("\n");
}
