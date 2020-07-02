typedef int Status;
#define TRUE 1 
#define FALSE 0

Status Match_Brackets()
{   

	SqStack *S,*T;
	InitStack(S);
	InitStack(T);
	
	char inputch,e;
	
	int ItemNum;
	printf("请输入字符个数："); 
	scanf("%d",&ItemNum);
	
	printf("请输入字符：");
	for(int i=0;i<=ItemNum;i++)     //因为要处理回车，长度加1 
	{	
		scanf("%c",&inputch);
		if(inputch != 0x0a)    //0x0a是回车符 
		{
			Push(T,inputch);    //保存输入的字符	
		}
				
		switch(inputch)
		{
			case '(':
				Push(S,inputch); 
				break;
			case '[':
				Push(S,inputch); 
				break;
			case ')':
				Pop(S,e); 
         		if(e != '(')
        		{  
					printf("'('括号不匹配"); 
            	    return FALSE;  
				}
				break;
			case ']':
				Pop(S,e); 
         		if(e != '[')
        		{  
					printf("'['括号不匹配"); 
          	      	return FALSE;  
				}
				break;
		} 
	}    	
    if(!StackEmpty(S)) 
	{    
		printf("\n\n括号数量不匹配！") ;
      	return FALSE;
	}
	else
	{
		printf("\n\n成功匹配！"); 
		DispStack(T);
		return TRUE; 
	}			
}
