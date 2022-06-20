/*
char* TransSixteen(char *str)
{
    char sixteen[20];
    char a[]="0123456789ABCDEF";

    /*if(strlen(str)<=4){
        int t=1;
        int sum=0;
        for(int i = strlen(str)-1;i >= 0; i--)
        {
            sum += (str[i]-'0')*t;
            t *= 2;
        }
        return &a[sum];
    }
    int i;
    for(i = 0; i <= (strlen(str)-1)/4; i++)
    {
        int t=1;
        int sum=0;
        for(int j =  strlen(str)-1-4*i ;j >= 0 && j > strlen(str)-1-4*(i+1); j--)
        {
            sum += (str[j]-'0')*t;
            t *= 2;
        }
        sixteen[i] = a[sum];
    }
    char temp;
    for(int j=0;j<i/2;j++)
    {
        temp = sixteen[j];
        sixteen[j] = sixteen[i-1-j];
        sixteen[i-1-j] = temp;
    }
    return sixteen;
}
*/
//5、按二进制数输入一个数，转换为十、十六进制显示。
#include<iostream>
#include<cstring>
using namespace std;

int TransTen(char *str)
{
    int t = 1;
    int res = 0;
    for(int i = strlen(str)-1; i >= 0; i--)
    {
        res+=(str[i]-'0')*t;
        t*=2;
    }
    return res;
}


char a[]="0123456789ABCDEF";//索引表
void p(int u)
{
	if(u)p(u/16);//当u不等于0时，递归 
	else return;
	printf("%c",a[u%16]);
}

int main()
{
    char str[32];
    cin >> str;
    int t=TransTen(str);
    cout << t << endl;
    p(t);
    return 0;
}