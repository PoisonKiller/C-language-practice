//读入一个数字，0表示程序结束
#include<iostream>
#include<cstring>
using namespace std;

int read()
{
    int x;
    printf("请输入一个数字代表星期几");
    scanf("%d",&x);
    return x;
}
int main()
{
    char*  day[]={ "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };//定义指针数组
    int x=read();
    //输入0表示程序结束
    while(x!=0){
        if(x>0 && x<=7)printf("%s\n",*(day+x-1));
        else printf("输入有误\n");
        x=read();
    }
    return 0;
}