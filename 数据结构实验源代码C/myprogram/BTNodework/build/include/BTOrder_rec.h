#ifndef BTORDER_REC_H
#define BTORDER_REC_H


int Lnodenum(BTNode *b,int h,int k);//���k��Ľ�����

//a��ֵΪ0ʱΪ�����������ȫ����������ֵΪ�������Ҷ�ӽ��ı���
int sum(int a,BTNode *b);//��������
void PreOrder_rec(int a,BTNode *b);//�������-�ݹ�
void InOrder_rec(int a,BTNode *b);//�������-�ݹ�
void PostOrder_rec(int a,BTNode *b);//�������-�ݹ�

#endif