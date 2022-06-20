#include<iostream>
using namespace std;
int main()
{
	int *p;
	int m=0;
	int num[5]={1,3,5,4,2};
	for(int i=0;i<5;i++) if(num[i]>m){
		m=num[i];      //擂台法找最大值 
		p=&num[i];		//记录最大值得地址 
	}
	swap(*p,num[4]);	//将最大值地址内的数和最后一个数进行交换 
	for(int i=0;i<5;i++)cout << num[i] << ' ';
	return 0;
}
