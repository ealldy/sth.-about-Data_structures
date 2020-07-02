using namespace std;

typedef struct
{
	char name[8];
	int age;
//	int gender;	//1表示男，0表示女 
}stu;

void InputData(stu &e)
{
	printf("\n请输入姓名name：");
	scanf("%s",&e.name);
		
	printf("请输入数据age：");
	scanf("%d",&e.age);	
	
//	printf("请输入性别(1表示男，0表示女)：");
//	scanf("%d",&e.gender);
}

void OutputData(stu e)
{		
	printf("%8s",e.name);
		
	printf("%4d\n",e.age);
	
/*
	if(e.gender == 1)
	{
		printf("\t男\n");
	} 
	else if(e.gender == 0)
	{
		printf("\t女\n"); 
	}
	*/
	
}
