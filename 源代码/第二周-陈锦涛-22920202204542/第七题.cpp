#include<iostream>
#include<cstring> 
using namespace std;

int replace(char* a)
{
	int cnt=0;
	char c=*a;//定义头指针 
	while(c!='\0'){
		//当当前字符为t或T时，将其替换为e或E，注意换的必须是地址内的字符 
		if(c=='t' || c=='T'){*a-=15;cnt++;}
		c=*(++a);//指针偏移 
	}
	return cnt;
}

int main()
{
	char str[10000];
	gets(str);
	int cnt=replace(str);
	//输出替换后的字符串和替换次数，便于观察 
	puts(str);
	cout << cnt << endl;
	return 0;
}
