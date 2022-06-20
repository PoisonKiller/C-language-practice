#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

vector<char> b;    //b数组是用来存放a中的元音字母

//check函数使用来判断字符是不是元音字母的
bool check(char ch)
{
    if(ch=='a' || ch=='A' || ch=='e' || ch=='E'|| ch=='i' || ch=='I' || ch=='o' || ch=='O' ||ch=='u' || ch=='U')
    return true; 
    return false;
}
int main()
{
    string a;
    cin >> a;
    for(int i=0;i<a.size();i++)
    if(check(a[i]))b.push_back(a[i]);  //若a[i]时元音字母，则将其存进b中
    for(int i=0;i<b.size();i++)cout << b[i];
    return 0;
}