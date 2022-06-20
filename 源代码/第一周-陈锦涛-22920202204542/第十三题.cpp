#include<iostream>
using namespace std;

int f[20][20];    //此数组是用来数组a中的元素是否进行了旋转 
void rotate(int* matrix, int matrixRowSize, int matrixColSize)
{
	int x=matrixRowSize,y=x-1;   
	for(int i=0;i<x;i++)
	for(int j=0;j<=y;j++)
	{
		//进行3此反转即可完成四个对应元素之间的旋转 
		//matrix+x*i+j 对应元素a[i][j]的地址 
		if(!f[i][j]){
			swap(*(matrix+i*x+j),*(matrix+x*j+y-i));
			swap(*(matrix+x*(y-i)+y-j),*(matrix+x*(y-j)+i));
			swap(*(matrix+x*i+j),*(matrix+x*(y-i)+y-j));
			f[i][j]=f[y-j][i]=f[y-i][y-j]=f[j][y-i]=1; //标记这个四个元素，表示已经完成旋转
		}
	}
}

int main()
{
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	rotate(a[0],3,3);
	int *p;
	for(p=a[0];p<a[0]+9;p++)
	{
		if((p-a[0])%3==0)printf("\n");
		printf("%4d",*p);
	}
	return 0;
}
