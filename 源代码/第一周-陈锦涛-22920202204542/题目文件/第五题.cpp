#include<iostream>
using namespace std;

const int N=7;

int main()
{
	int a[N]={1,2,3,4,11,12,13};
	int b[N];
	int * p=a;              //定义首地址 
	for(int i=N-1;i>=0;i--)
	{
		b[i]=*(p+i) ;       //记录逆序数组 
		cout << b[i] << ' ';//采用首地址偏移i个位置使其正好以逆序输出 
	}
	cout << endl;
	return 0;
}

