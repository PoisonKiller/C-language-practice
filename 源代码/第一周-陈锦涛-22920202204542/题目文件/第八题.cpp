#include<iostream>
using namespace std;
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int (*p)[4] = & a[0];                //行指针定义法
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		cout << *(*(p+i)+j) << ' ';     //p+i表示a[i]的地址,*(p+i)+j表示a[i][j]的地址 
		cout << endl;
	}
	return 0;
}
