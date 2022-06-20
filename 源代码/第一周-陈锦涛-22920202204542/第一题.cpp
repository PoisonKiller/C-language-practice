#include<iostream>
using namespace std;

void mp_sort(int a[])//冒泡排序函数
{
	for(int i=0;i<4;i++)//进行4次冒泡 
		for(int j=0;j<4-i;j++) //冒泡过程 
			{
				if(a[j]<a[j+1])swap(a[j],a[j+1]); 
			}
	
	for(int i=0;i<5;i++)cout << a[i] << " ";
	cout << endl;
}
int main()
{
	int a[8]={1,2,3,4,5};
	int b[8]={3,5,4,1,2};
	mp_sort(a);
	mp_sort(b);
	return 0;
}
