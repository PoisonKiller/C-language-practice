#include<iostream>
using namespace std;
int main()
{
	char a[ ] = "I love ";
	char b[ ] = "China";
	char *str=a+7;
	for(int i=0;i<5;i++)*(str++)=b[i]; //将b的每个元素传到a后面 
	printf("%s\n",a);
	return 0;
 }
