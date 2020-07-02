void conversion () 
{
	SqStack *S;
	int N,e;	
	InitStack(S); 
	printf("请输入十进制数N：");
    scanf ("%d",&N);
    while(N) 
    {
          Push(S, N%2);
          N = N/2;
    }
//    DispStack(S);
    printf("对应的二进制是：");
    while (!StackEmpty(S))
    {
          Pop(S,e);
          printf ("%d", e );
    }
} 
