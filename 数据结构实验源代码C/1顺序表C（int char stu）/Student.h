using namespace std;

typedef struct
{
	char name[8];
	int age;
//	int gender;	//1��ʾ�У�0��ʾŮ 
}stu;

void InputData(stu &e)
{
	printf("\n����������name��");
	scanf("%s",&e.name);
		
	printf("����������age��");
	scanf("%d",&e.age);	
	
//	printf("�������Ա�(1��ʾ�У�0��ʾŮ)��");
//	scanf("%d",&e.gender);
}

void OutputData(stu e)
{		
	printf("%8s",e.name);
		
	printf("%4d\n",e.age);
	
/*
	if(e.gender == 1)
	{
		printf("\t��\n");
	} 
	else if(e.gender == 0)
	{
		printf("\tŮ\n"); 
	}
	*/
	
}
