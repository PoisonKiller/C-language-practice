#include<iostream>
using namespace std;
int main()
{
	int a[3][4]={1,3,5,7,9,11,13,15,17,19,21,23};
	int *p=a[0];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout << *p << ' ';
			p++;    //使该地址偏移一个位置至下一个元素的地址 
		}
		cout << endl;
	}
			
	return 0;
 }
