void conversion () 
{
	SqStack *S;
	int N,e;	
	InitStack(S); 
	printf("������ʮ������N��");
    scanf ("%d",&N);
    while(N) 
    {
          Push(S, N%2);
          N = N/2;
    }
//    DispStack(S);
    printf("��Ӧ�Ķ������ǣ�");
    while (!StackEmpty(S))
    {
          Pop(S,e);
          printf ("%d", e );
    }
} 
