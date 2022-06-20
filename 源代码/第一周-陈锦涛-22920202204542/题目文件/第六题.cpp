#include<iostream>
using namespace std;

const int N=7;

int main()
{
	int a[N]={1,2,3,4,11,12,13};
	int b[N];
	for(int i=0;i<N;i++){
		int *p=&a[i];         // 定义第i个元素的地址 
		b[i]=*((p+N-1-i*2));  
		//将第i个元素的地址偏移至第N-1-2i的地址,使其正好逆序，并存储 
		cout << b[i] << ' ';
	}
	
	return 0;	
 }
