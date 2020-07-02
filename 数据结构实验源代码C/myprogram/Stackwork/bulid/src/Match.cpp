#include<iostream>
#include"stack.h"
#include"match.h"
using namespace std;

bool Match(char exp[],int n,char &o)
{
	int i=0; char e;
	bool match=true;
	LinkStNode *st;
	InitStack(st);
	while (i<n && match)
	{
		if ((exp[i]=='(') || (exp[i]=='[')) Push(st,exp[i]);
		else if ((exp[i]==')') || (exp[i]==']'))
		{
			if(GetTop(st,e)==true)
			{
				if ((exp[i]==')') && (e!='('))
					match=false;
				else if ((exp[i]==']') && (e!='['))
				{
					match=false;
				}
				Pop(st,e);
			}
			else 
			{
				match=false;
			}
		} 
		i++;
	}
	if (!StackEmpty(st)) match=false;
	o=exp[i-1];
	DestroyStack(st);
	return match;
}
