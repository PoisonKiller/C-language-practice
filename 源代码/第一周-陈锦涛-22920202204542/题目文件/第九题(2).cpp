#include<iostream>
using namespace std;

const int N=1e5+10;
int a[N];

void fac(int u,int *p)
{
	float k=1;
	for(int i=0;i<=u;i++) 
	 k*=*(p+i);                 //指针访问数组地址内容,循环完成阶乘 
	printf("result=%f",k);			//输出
}

int main()
{
	int m;
	printf("input m:");
	scanf("%d",&m);
	
	a[0]=1;                     //0!=1
	for(int i=1;i<=m;i++)a[i]=i;    //将每个数存进数组里 
	int *p;
	p=a;                        //定义首地址 
	fac(m,p);
	return 0;
}
