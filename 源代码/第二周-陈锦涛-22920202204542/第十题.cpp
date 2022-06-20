#include<iostream>
#include<cstdlib>
using namespace std;
const int N=1e5+10;
int str[N];
int n;

void swap(int* a,int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    cin >> n;
    int* a=str;
    for(int i=0;i<n;i++)*(a++)=rand();//复制随机数
    a=a-n;//让a重新成为首地址
    for(int i=0;i<n;i++)cout << *(a++) << " ";//输出原来的数据单元的位置
    cout << endl;
    a=a-n;
    for(int i = 0 ; i < n-1 ; i++)//冒泡排序
        for(int j = 0 ; j < n-1-i ; j++)
        if(*(a+j) > *(a+j+1))swap(*(a+j) , *(a+j+1)); 
    
    for(int i=0;i<n;i++)cout << *(a++) << " ";//输出查看现在的位置
    return 0;
}