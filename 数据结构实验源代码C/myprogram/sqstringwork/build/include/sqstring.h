#ifndef SQSTRING_H
#define SQSTRING_H

typedef struct
{
	char data[256];
	int length;
}SqString;

void StrAssign(SqString &s,char cstr[]);//����˳��
void StrCopy(SqString &s,SqString t);//��˳��t���Ƹ�˳��s
bool StrSqual(SqString s,SqString t);//�ж���˳���Ƿ���ͬ
SqString SubStr(SqString s,int i,int j);//��˳��s�е�i���ַ���ʼ����j���ַ���ɵ��Ӵ�
void DispStr(SqString s);//���˳���ַ�
SqString DeldupStr(SqString s);//ȥ��˳�����ظ����ַ�

#endif
