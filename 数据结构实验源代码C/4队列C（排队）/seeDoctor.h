

void SeeDoctor()
{
	LiQueue *Q;
	InitQueue(Q);
	
	int select,flag=1;
	int num;  //numΪ������ 
	while(flag == 1)
	{
		printf("\n\n==========================================");
		printf("\n1���Ŷ�  2������  3���鿴�Ŷ�   4���°�    ��ѡ��");
		scanf("%d",&select);
		switch(select)
		{
			case 1:
				printf("--->>�����벡���ţ�");
				scanf("%d",&num);
				enQueue(Q,num);
				printf("�ŶӵĲ��������ǣ�");
				DispQueue(Q);
				break;
			case 2:
				if(QueueEmpty(Q))
				printf("--->>û���ŶӵĲ��ˣ�\n"); 
				else
				{
					deQueue(Q,num);
					printf("��ǰ������ǣ�%d\n",num);
					printf("�ŶӵĲ��������ǣ�");
					DispQueue(Q);
				}
				break;
			case 3:
				if(QueueEmpty(Q))
				{
					printf("--->>û���ŶӵĲ��ˣ�\n"); 
				}
				else
				{
					printf("--->>�ŶӵĲ��˰�����˳����\n"); 				
					DispQueue(Q);
				}
				break;
			case 4:
				if(!QueueEmpty(Q))
				printf("--->>���ŶӵĲ��������ҽ��\n");
				flag = 0;
				DestroyQueue(Q);
				break;
		}
	}
}
