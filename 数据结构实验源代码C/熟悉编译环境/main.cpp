#include <stdio.h>
#include <stdlib.h>		/*使用malloc( ) 需要*/
#include <math.h> 
#include <stdbool.h>    //Dev环境中需加上才能使用bool 

struct data /*定义结构体*/
{
    int day,month,year;
};
typedef struct  /*定义结构体*/
{    
	char name[20];
    long num;
    struct data birthday; 
	/*嵌套的结构体类型成员*/
}stu;


bool prime(int n)     //判断正整数n是否为素数 
{
	int i;
	for(i=2;i<=(int)sqrt(n);i++)
		if(n%i == 0)
			return false;
		return true;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	/*实验内容1 
	stu *student;    //定义结构体类型指针
	student=(stu*)malloc(sizeof(stu)); //为指针变量分配安全的地址

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



    //*实验内容2	
	int n,i,j=0;     //j用于累计素数个数 
	printf("请输入n：");
	scanf("%d",&n);
	
	printf("小于等于%d的素数：\n",n);
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
