#include<iostream> 
using namespace std;

int m,n;
int dfs(int a,int b)     //a表示向右,b表示向下
{
	if(a==m || b==n)return 1; 
	//当向右或者向下走到边界时，就只有向下或向右一直走 这一种走法 
	else if(a<m && b<m)return dfs(a+1,b)+dfs(a,b+1); 
	//当向右或者向下都没有到边界时，有向右和向下两种走法 
}

int main()
{
	cin >> m >> n;
	int k=dfs(1,1);    //初始位置是(1,1)
	printf("共有%d条路径",k);
	return 0;
}
