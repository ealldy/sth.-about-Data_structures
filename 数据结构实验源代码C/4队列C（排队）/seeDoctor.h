

void SeeDoctor()
{
	LiQueue *Q;
	InitQueue(Q);
	
	int select,flag=1;
	int num;  //num为病历号 
	while(flag == 1)
	{
		printf("\n\n==========================================");
		printf("\n1：排队  2：就诊  3：查看排队   4：下班    请选择：");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				printf("--->>请输入病历号：");
				scanf("%d",&num);
				enQueue(Q,num);
				printf("排队的病人依次是：");
				DispQueue(Q);
				break;
			case 2:
				if(QueueEmpty(Q))
				printf("--->>没有排队的病人！\n"); 
				else
				{
					deQueue(Q,num);
					printf("当前就诊的是：%d\n",num);
					printf("排队的病人依次是：");
					DispQueue(Q);
				}
				break;
			case 3:
				if(QueueEmpty(Q))
				{
					printf("--->>没有排队的病人！\n"); 
				}
				else
				{
					printf("--->>排队的病人按以下顺序就诊：\n"); 				
					DispQueue(Q);
				}
				break;
			case 4:
				if(!QueueEmpty(Q))
				printf("--->>请排队的病人明天就医！\n");
				flag = 0;
				DestroyQueue(Q);
				break;
		}
	}
}
