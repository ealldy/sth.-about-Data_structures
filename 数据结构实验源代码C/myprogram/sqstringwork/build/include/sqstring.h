#ifndef SQSTRING_H
#define SQSTRING_H

typedef struct
{
	char data[256];
	int length;
}SqString;

void StrAssign(SqString &s,char cstr[]);//生成顺序串
void StrCopy(SqString &s,SqString t);//将顺序串t复制给顺序串s
bool StrSqual(SqString s,SqString t);//判断两顺序串是否相同
SqString SubStr(SqString s,int i,int j);//求顺序串s中第i个字符开始连续j个字符组成的子串
void DispStr(SqString s);//输出顺序串字符
SqString DeldupStr(SqString s);//去除顺序串中重复的字符

#endif
