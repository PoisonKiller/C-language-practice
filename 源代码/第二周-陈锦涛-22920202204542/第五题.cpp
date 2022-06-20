#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char str[10000];
	gets(str);
	char *a;
	a=str; //定义a为字符串的首地址 
	int i=0,cnt=0; //i使用记录已经扫描到了字符串的哪个位置，cnt表示数字的个数 
	while(i++<strlen(str)){
		char c=*(a++);     //每次将指针偏移一位 
		if(c>='0' && c<='9')cnt++;
	}
	
	cout << cnt << endl;
	return 0;
 }
