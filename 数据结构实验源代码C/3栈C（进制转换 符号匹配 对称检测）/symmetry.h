bool symmetry(ElemType str[])
{  
	int i;  
	ElemType e;
    SqStack *st;
    InitStack(st);			//��ʼ��ջ
    for (i=0;str[i]!='\0';i++)	//��������Ԫ�ؽ�ջ
		Push(st,str[i]);		//Ԫ�ؽ�ջ

	printf("�����Ĵ��ǣ�"); 
	DispStack(st);
	
    for (i=0;str[i]!='\0';i++)
    {
		Pop(st,e);		  //��ջԪ��e
		if (str[i]!=e)	  //��e�뵱ǰ��Ԫ�ز�ͬ���ǶԳƴ�
		{  
			DestroyStack(st);//����ջ
	   		return false;
		}
   }
   DestroyStack(st);	  //����ջ
   return true;
}

