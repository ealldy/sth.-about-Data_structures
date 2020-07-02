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
	printf("�������ַ�������"); 
	scanf("%d",&ItemNum);
	
	printf("�������ַ���");
	for(int i=0;i<=ItemNum;i++)     //��ΪҪ����س������ȼ�1 
	{	
		scanf("%c",&inputch);
		if(inputch != 0x0a)    //0x0a�ǻس��� 
		{
			Push(T,inputch);    //����������ַ�	
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
					printf("'('���Ų�ƥ��"); 
            	    return FALSE;  
				}
				break;
			case ']':
				Pop(S,e); 
         		if(e != '[')
        		{  
					printf("'['���Ų�ƥ��"); 
          	      	return FALSE;  
				}
				break;
		} 
	}    	
    if(!StackEmpty(S)) 
	{    
		printf("\n\n����������ƥ�䣡") ;
      	return FALSE;
	}
	else
	{
		printf("\n\n�ɹ�ƥ�䣡"); 
		DispStack(T);
		return TRUE; 
	}			
}
