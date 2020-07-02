#include<iostream>
#include"btree.h"
#include"BTOrder_rec.h"
using namespace std;

int Lnodenum(BTNode *b,int h,int k)
{
	if (b==NULL)
		return 0;
	else
	{
		if (h==k) return 1;
		else 
		{
			return Lnodenum(b->lchild,h+1,k)+Lnodenum(b->rchild,h+1,k);
		}
	}
}
int sum(int a,BTNode *b)
{
	if (0==a)
		if ((b!=NULL) && ((b->lchild!=NULL) || (b->rchild!=NULL))) 
			return (sum(a,b->lchild)+sum(a,b->rchild)+1);
		else 
			if (b!=NULL) return 1;
			else return 0;
	else
		if (b!=NULL) 
		{	
			
			if ((b->lchild==NULL) && (b->rchild==NULL)) return 1;
			else {return sum(a,b->lchild)+sum(a,b->rchild);}
		} 
		else return 0;
}

void PreOrder_rec(int a,BTNode *b)
{
	if (b!=NULL)
	{
		if (a)
		{if (b->lchild==NULL && b->rchild==NULL) 
		cout<<b->data;}
		else cout<<b->data;
		PreOrder_rec(a,b->lchild);
		PreOrder_rec(a,b->rchild);
	}
}

void InOrder_rec(int a,BTNode *b)
{
	if (b!=NULL)
	{
		InOrder_rec(a,b->lchild);
		if (a)
		{if (b->lchild==NULL && b->rchild==NULL) 
		cout<<b->data;}
		else cout<<b->data;
		InOrder_rec(a,b->rchild);
	}
}

void PostOrder_rec(int a,BTNode *b)
{
	if (b!=NULL)
	{
		PostOrder_rec(a,b->lchild);
		PostOrder_rec(a,b->rchild);
		if (a)
		{if (b->lchild==NULL && b->rchild==NULL) 
		cout<<b->data;}
		else cout<<b->data;
	}
}