#include<iostream>
using namespace std;
int a[100][100];
void rotate(int m,int n)
{
	//up,down,left,right分别是上下左右四个边界的位置 
	int up=0,down=0,right=0,left=0;
	//i=j=0表示初始时的a[0][0]，r表示已经输出的元素个数
	int i=0,j=0,r=0;  
	while(1)
	{
		//一个循环内应依次向右，向下，向左，向上遍历所有元素 
		for(j=left;j<n-right;j++)    //向右遍历 
		{printf("%d ",a[i][j]);r++;}//每次输出的同时记录下输出的个数，为r 
		j--;                         //上面的j溢出，故这里要-1，下面同理 
		
		for(i=up+1;i<m-down;i++)	 //向下遍历 
		{printf("%d ",a[i][j]);r++;}
		i--;
		
		for(j--;j>=left;j--)           //j--是防止其输出了两个相同的元素，向z左遍历 
		{printf("%d ",a[i][j]);r++;}
		j++;
		
		for(i--;i>up;i--)          //向上遍历 
		{printf("%d ",a[i][j]);r++;};
		i++;
		
		up++;down++;right++;left++;//当顺时针走完一圈后，所有边界的位置都 +1
		if(r==m*n)break;           //当输出完所有元素后，跳出循环，函数结束 
	}
}
int main()
{
	int m,n; 
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
	rotate(m,n);
	return 0;
}
