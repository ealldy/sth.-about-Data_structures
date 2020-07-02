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

void CreateBTree(BTNode *&b,char *str);//����������
void DestroyBTree(BTNode *&b);//���ٶ�����
BTNode *FindNode(BTNode *b,ElemType x);//���ҽ��
BTNode *LchildNode(BTNode *p);
BTNode *RchildNode(BTNode *p);//������Һ��ӽ��
int BTHeight(BTNode *b);//��߶�
void DispBTree(BTNode *b);//���������

#endif