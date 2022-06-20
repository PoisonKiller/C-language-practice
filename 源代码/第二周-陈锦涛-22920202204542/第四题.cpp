#include<iostream>
#include<cstring>
using namespace std;
//指针法 
int main()
{
	char str[10000];
	gets(str);		//读入字符串，故用gets函数读入 
	char *a=str+strlen(str);//定义a为字符串的最后一个元素的地址的下一个地址 
	int i=0;
	while(i++<strlen(str)){
		cout << *(--a);//每次将指针往前面偏移一位并输出 
	}
	return 0;
}
