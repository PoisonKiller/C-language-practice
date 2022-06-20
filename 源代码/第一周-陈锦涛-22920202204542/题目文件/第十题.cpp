#include<iostream>
#include<cstring>
using namespace std;

char *strcat(char str1[],char str2[]) 
{
	char *h;
	h=str1+strlen(str1);       //定义h为str1的最后一个元素的下一个地址 
	int i=0,j=strlen(str2);                   
	while(j--)
	*(h++) = str2[i++];       
	//h+strlen(str1)-1是str1最后一个字符的地址
	//将该地址的后面的地址的元素定义为str2的各元素就可连接起来 
	return str1;  
}

int main()
{
	char str1[30]="I learn ",*str2 ="C language.";
	char *s;
	s=strcat(str1,str2);
	printf("%s\n",s);
	return 0;
}
