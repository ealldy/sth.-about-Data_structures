#include <stdio.h>
#include <stdlib.h>		/*ʹ��malloc( ) ��Ҫ*/
#include <math.h> 
#include <stdbool.h>    //Dev����������ϲ���ʹ��bool 

struct data /*����ṹ��*/
{
    int day,month,year;
};
typedef struct  /*����ṹ��*/
{    
	char name[20];
    long num;
    struct data birthday; 
	/*Ƕ�׵Ľṹ�����ͳ�Ա*/
}stu;


bool prime(int n)     //�ж�������n�Ƿ�Ϊ���� 
{
	int i;
	for(i=2;i<=(int)sqrt(n);i++)
		if(n%i == 0)
			return false;
		return true;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*ʵ������1 
	stu *student;    //����ṹ������ָ��
	student=(stu*)malloc(sizeof(stu)); //Ϊָ��������䰲ȫ�ĵ�ַ

	printf("Input name:");
	scanf("%s",student->name);
	
	printf("Input number:");
	scanf("%ld",&student->num);
	
	printf("Input year-month-day:");
	scanf("%d-%d-%d",&student->birthday.year,&student->birthday.month,&student->birthday.day);
	
	printf("\nOutput name,number,year,month,day:");
	printf("%s,%ld,",student->name,student->num);
	printf("%d/%d/%d\n",student->birthday.year,student->birthday.month,student->birthday.day);
*/ 



    //*ʵ������2	
	int n,i,j=0;     //j�����ۼ��������� 
	printf("������n��");
	scanf("%d",&n);
	
	printf("С�ڵ���%d��������\n",n);
	for(i=2;i<=n;i++)
	{
		if(prime(i))
		{
			printf("%4d",i);
			j++;
			if(j%10==0)
			printf("\n");
		}
	}
//	*/

	return 0;
}
