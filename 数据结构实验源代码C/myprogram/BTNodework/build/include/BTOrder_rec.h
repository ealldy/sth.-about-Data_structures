#ifndef BTORDER_REC_H
#define BTORDER_REC_H


int Lnodenum(BTNode *b,int h,int k);//求第k层的结点个数

//a的值为0时为输出二叉树的全遍历，其他值为输出所有叶子结点的遍历
int sum(int a,BTNode *b);//计算结点数
void PreOrder_rec(int a,BTNode *b);//先序遍历-递归
void InOrder_rec(int a,BTNode *b);//中序遍历-递归
void PostOrder_rec(int a,BTNode *b);//后序遍历-递归

#endif