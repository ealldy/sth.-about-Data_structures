#include <iostream>
using namespace std; 
#include "Car.h"
#include "SqList.h" 
#include "LinkQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void EmptyParkNum(SqList *L)		//返回当前空的停车位 
{
	int PNum=110;
	bool empty=true;
	printf("当前空的停车位为：");
	for(int i=1;i<=7;i++)
	{
		for(int j=0;j<L->length;j++)
		{
			if(PNum == L->data[j].ParkNum)
			{
				empty=false;
			}
		}
		if(empty == true)
		{
			printf("%5d",PNum);
		}	
		PNum++;
		empty=true;
	}
}


int main(int argc, char** argv) {
	
	//停车场简介
	cout<<"停车场是可停放7辆汽车的狭长通道"<<endl;
	cout<<"车位位置为：110 111 112 113 114 115 116"<<endl;
	cout<<"该演示程序未对输入数据的合法性进行判断"<<endl;
	cout<<"-----------------------------------------------"<<endl<<endl;
	
	SqList *L;	//用顺序表模拟停车场 
	InitList(L);
	
	/*手动设置停车场的初始参数 
	cout<<"假设初始时，停车场里停了6辆汽车，请设置初始数据"<<endl;
	InitData_Sq(L,6); 
	*/
	
	//*程序设置初始停车场数据 
	cout<<"假设初始时，停车场里停了6辆汽车"<<endl;
	car e;
	for(int ti=1;ti<=6;ti++){	
		 
		e.ParkNum = 110+ti;
		e.CarNum = ti;
		e.ATime = 1220;
		ListInsert(L,ti,e);		
	}
	//*/
	
	
	//出库时的一些变量定义 
	int OutCarNum;	//出站的汽车车牌号
	bool find=false;
	int posNum;		//出库时，存放出库汽车的车库位置
	int lastTime;	//汽车的出库时间
	int ParkTime;	//汽车的停放时间 
	int InTime;		//排队等候车辆的实际入库时间 
	
	//设置入队列QIn和出队列 QOut 
	LinkQueue *QIn;
	InitQueue(QIn);
	LinkQueue *QOut;
	InitQueue(QOut);
	
	int choice=0;
	while(choice != 4)
	{	
		printf("\n\n当前停车场停放的车辆是：\n");
		DispList(L);	
		if(!QueueEmpty(QIn)) 
		{
			printf("------当前排队等候入站的汽车是：\n");
			DispQueue_L(QIn); 	
		}
		else
			cout<<endl<<"当前无排队等候进站的汽车"<<endl;
			
		if(!QueueEmpty(QOut))
		{
			printf("\n------当前排队等待出站的汽车有：\n");
			DispQueue_L(QOut);
		} 
		else
			cout<<endl<<"当前无排队等候出站的汽车"<<endl;
		printf("\n\n----------------------------");
		printf("\n1.入站；2.出站；3.出库汽车计费；4.退出系统：");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:	
			if(ListFull(L))		//停车场停满车，请等待 
			{
				printf("停车场已停满车辆，请在通道内等待！");
				if(QueueLength(QIn) == 3)	//入通道已停满车 
				{	
					printf("\n入通道内已停满车辆，请寻找其他停车场！");
					break; 
				} 
				printf("\n请输入入站汽车的相关信息：（停车位置设置为0，时间设置为0）");	//车库已停满，请在入口处等待入库 
				InputData(e);//需要增加对输入数据合法性的判断 
				EnQueue(QIn,e);				
			}
			else		//停车场未满 
			{
				EmptyParkNum(L);	//显示当前空的车库 
				printf("\n请输入入站汽车的相关信息：");
				InputData(e);	//当前并未进行库号冲突检测 
				ListInsert(L,L->length+1,e);	
			} 	
			break;
		case 2:
			if(QueueLength(QOut) == 3)	//出通道已停满车 
			{
				printf("\n出通道内已停满车辆，请稍后再出站！");
			}
			else
			{
				printf("请输入要出站的车牌号码：");
				scanf("%d",&OutCarNum);
				for(int t=1;t<=L->length;t++)	 
				{
					ElemValue(L,t,e);		//取停车场里的汽车数据
					if(e.CarNum == OutCarNum)
					{
						find=true;
						ListDelete(L,t,e);	//汽车出库 
						posNum=e.ParkNum; 	//出库汽车的车库位置，暂时存放，入库时要用 
						EnQueue(QOut,e);
					} 
				} 		
				if(find == false)
				{
					printf("车库中不存在车牌号码为%d的汽车",OutCarNum);
				}
			} 
			if(find == true)	//有汽车驶出车库 
			{
				if(QueueLength(QIn)>0)	//入车库的队伍有汽车在等待，队伍中第一台汽车进入车库，重新计算入库时间 
				{
					DeQueue(QIn,e);
					e.ParkNum=posNum;
					printf("排队的汽车%d正要入库，请输入当前时间：",e.CarNum); 
					scanf("%d",&InTime);
					e.ATime=InTime;
					ListInsert(L,L->length+1,e);
				}
				find=false;	
			}
			break;
		case 3:	
			if(QueueLength(QOut)>0)	//出车库的队伍有汽车在等待
			{
				DeQueue(QOut,e);
				printf("汽车%d正在计费，",e.CarNum);
				printf("请输入当前时间：");
				scanf("%d",&lastTime) ;
				ParkTime = lastTime-e.ATime;
				printf("请交停车费：%d分",ParkTime*5) ;
				printf("\n汽车%d已驶出停车场。\n",e.CarNum);
			}
			else 
			{
				printf("当前没有要出库的汽车！");
			}
			break;
		case 4:
			break;
		default:
			printf("输入出错，请重新输入！");
		}
	}
	return 0;
}
