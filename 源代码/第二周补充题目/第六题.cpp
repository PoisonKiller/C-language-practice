#include<iostream>
using namespace std;
struct num{
    int a : 3;
    int b : 5;
    int c : 6;
    int d : 9;
}re;
int main()
{
    re.a = 7;
    cout << re.a << endl;
    return 0;
}