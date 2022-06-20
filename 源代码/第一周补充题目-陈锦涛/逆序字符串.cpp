#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//创建vector数组来存放字符串a逆序后的字符串
vector<char> b;
void nixu(string a)
{
    for(int i=a.size()-1;i>=0;i++)
    b.push_back(a[i]);//逆序存放a中的字符
}

int main()
{
    string a;
    cin >> a;
    nixu(a);
    for(int i=0;i<a.size();i++)cout << b[i] ;//按序输出
    return 0;
}