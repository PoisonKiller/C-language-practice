#include<iostream>
using namespace std;

float fac(int u)
{
	if(u==1||u==0)return 1;//回溯至u=1或0时，返回1;
	return u*fac(u-1);     //递归调用 
}

int main()
{
	int m;
	float k;
	printf("input m:");
	scanf("%d",&m);
	
	k=fac(m);
	
	printf("result=%f",k);
	return 0;
}
