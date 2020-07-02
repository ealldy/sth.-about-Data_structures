#ifndef BTREE_H
#define BTREE_H

#define MaxSize 10
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node *lchild;
	struct node *rchild;
}BTNode;

void CreateBTree(BTNode *&b,char *str);//创建二叉树
void DestroyBTree(BTNode *&b);//销毁二叉树
BTNode *FindNode(BTNode *b,ElemType x);//查找结点
BTNode *LchildNode(BTNode *p);
BTNode *RchildNode(BTNode *p);//找左或右孩子结点
int BTHeight(BTNode *b);//求高度
void DispBTree(BTNode *b);//输出二叉树

#endif