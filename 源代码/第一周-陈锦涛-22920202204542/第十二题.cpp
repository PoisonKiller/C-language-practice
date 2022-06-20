#include<iostream> 
using namespace std;

int a[100][100];
int m,n;
//x表示向右，y表示向下 
//使用和第十题类似的深搜法，但是要增加了判断条件 
int dfs(int x,int y)
{
	//判断是否到达终点，若已到达，返回1 
	if(x==m && y==n)return 1; 
	
	//当此时的位置不处于边界线上，则有两种走法.
	//判断这两种走法分别是否遇到障碍物 ,则可分4种情况 
	if(x<m && y<n ){
		if(a[x+1][y]==1 && a[x][y+1]==1)return 0;
		if(a[x+1][y]==1 && a[x][y+1]==0)return dfs(x,y+1);
		if(a[x+1][y]==0 && a[x][y+1]==1)return dfs(x+1,y);
		if(a[x+1][y]==0 && a[x][y+1]==0)return dfs(x+1,y)+dfs(x,y+1);
	}
	
	//当此时的位置到达了右边界或下边界时
	//只有一直向下或者一直向右一种走法 
	//再判断能否继续向下或者继续向右即可 
	if(x<m && y==n){
		if(a[x+1][y]==1)return 0;
		if(a[x+1][y]==0)return dfs(x+1,y);
	}
	
	if(x==m && y<n){
		if(a[x][y+1]==1)return 0;
		if(a[x][y+1]==0)return dfs(x,y+1);
	}
}
int main()
{
	cin >> m >> n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)cin >> a[i][j];
	cout << dfs(1,1) << endl ;	
}
