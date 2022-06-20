/*
由于本题中母串str较短，故可以采用暴力搜索的方法，搜索出所有字串在原串中出现的次数
并存贮下来，找到其中的最大值，然后将所有出现次数为最大值的子串输出
因为相同的子串出现的次数相同，故应该从字串的第一个元素对应的母串的下一个元素开始搜
这样就能避免输出相同的字串了
*/

#include<iostream>
#include<cstring>
using namespace std;

int L;             //定义字串长度为L
string str;

//p函数用来求某个子串在原串中出现的次数
int p(int init,char* a)
{
    int cnt=0;
    //因为字串在原串中一定会出现1次，故从子串的首元素的下一个元素开始搜索
    for(int i=init+1;i<=str.size()-L;i++)
    {
        int x=0,j=i;
        while(str[j++]==*(a+x) && x<L)x++;
        if(x==L)cnt++;
    }
    return cnt;
}

int main()
{
    cin >> L;
    cin >> str;
    char t[60];
    int res[60];
    int m=0;
    for(int i=0;i<=str.size()-L;i++)
    {
        int x=i;
        for(int j=0;j<L;j++)t[j]=str[x++];
            res[i]=p(i,t);     //用字串第一个元素对应的母串中的元素的位置来标记子串
                               //存储下来其在母串中出现的次数
            m=max(m,res[i]);  //擂台法找出出现的最大次数
    }

    for(int i=0;i<=str.size()-L;i++)
    {
        int x=i;
        for(int j=0;j<L;j++)t[j]=str[x++];
        //将所有出现出现次数等于最大次数的子串输出
        if(res[i]==m){
            for(int j=0;j<L;j++)
            cout << t[j] ;
            cout <<endl;
        }
    }
    return 0;
}