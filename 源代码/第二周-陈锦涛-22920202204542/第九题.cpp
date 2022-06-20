#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char* a[]={"i","love","the","xmu's","c language"};
    //定义5个字符串并存进指针数组里面
    char* b[5];//保存排完序的字符串
    char c[5];
    int len[5];//存储每个字符串的长度
    for(int i=0;i<5;i++)len[i]=strlen(*(a+i));
    sort(len,len+5);//将长度排序
    //将字符串按长度排序并存进b中
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        if(strlen(*(a+j))==len[i]){*(b+i)=*(a+j);break;}
    }
    //取出排完序后的字符串的第三个字符组成一个新的字符串
    for(int i=0;i<5;i++)
    {
        if(len[i]<3)c[i]=' ';
        else c[i]=*(*(b+i)+2);
    }
    printf("%s\n",c);
    return 0;

}