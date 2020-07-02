#include<iostream>
//#include<stdlib>
#include<windows.h>
using namespace std;

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nCmdShow)
{
	
	MessageBox(NULL,"Hello","World",MB_OK);
	//弹出一个消息框函数，第一个参数为副窗口一般写NULL，第二个参数是消息的内容，第三个参数是标题，第四个参数是按钮（常量）
	//system("pause 1111");
	return 0;
}