#include<iostream>
#include<cstring>
using namespace std;

//check函数用来检查当前字符是不是字母 
bool check(char c)
{
	if((c > 'a' && c<'z') || ( c > 'A' && c <'Z'))return true;
	return false;
}

int main()
{
	char str[10000];
	gets(str);
	char* a=str;
	int i=0,cnt=0;
	while(i++<strlen(str)){
		char c=*(a++);
		//只有当前字符为字母且下一个字符是空格，才能算一个单词 
		if(check(c) && *a == ' ')cnt++; 
	}
	a--;
	//若最后一个字符是字母，则这个单词在上面的循环中未被记录
	//故单独判断一个，若是，则单词数+1； 
	if(check(*a))cout << cnt+1 << endl;
	else cout << cnt <<endl;
}
