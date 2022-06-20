#include<iostream>
#include<cstring>
int main()
{
	char *a="I am a student";//a指针指向字符串 
	char *b;
	b=a;                     //将b指针指向a，即b指向的字符串也是a指向的 
	printf("%s\n",b);
	return 0;
}
