/*思路
    要计算这个问题，可以将A连乘b次，每次都对m求余，但这种方法特别慢，当b较大时无法使用。下面给出一种较快的算法(用A^b表示A的b次方)
　　若b=0，则A^b%m=I%m。其中I表示单位矩阵。
　　若b为偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
　　若b为奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。
*/
/*
2 2 2
1 1
0 1
3 2 3
1 2 3
1 2 3
1 2 3
*/
#include<iostream>
using namespace std;
int n,b,m;
//以为矩阵的乘法不具有互换性，即矩阵相乘是要有顺序的
//init函数用来初始化，也就是保持p矩阵是先乘的矩阵
//矩阵h是零矩阵，也就是所有元素为0
void init(int* p,int* h)
{
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
    *(p+10*i+j)=*(h+10*i+j);
    *(h+10*i+j)=0;
    }
}
//f函数是用来求矩阵相乘以后得到的新矩阵h
//函数中的h+row*10+col也就是h[row][col]的地址
void f(int* a,int* p,int* h)
{
        for(int row=0;row<n;row++)
        for(int col=0;col<n;col++)
        {
            for(int j=0;j<n;j++)
            *(h+row*10+col)+=(*(p+row*10+j))*(*(a+j*10+col));
        }
}
//qiuyu函数为求余函数，即对矩阵中的每一个数进行求余
void qiuyu(int* h,int m)
{
    for(int row=0;row<n;row++)
    for(int col=0;col<n;col++)
    *(h+10*row+col)%=m;
}

int main()
{
    scanf("%d%d%d",&n,&b,&m);
    //定义三个数组，a是矩阵，p是乘号前的矩阵，h是0矩阵
    //但在最后没有使用init函数，故最后的h矩阵就是要求的矩阵
    int a[10][10],p[10][10],h[10][10];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
        p[i][j]=a[i][j];     ////开始时将p矩阵复制成a矩阵
    }
    //若b=0，则A^b%m=I%m。其中I表示单位矩阵。
    if(b==0){
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)h[i][j]=1%m;
    }
    
    //若b=1，则A^b%m=A%m
    else if(b==1){
    	 init(h[0],p[0]);
		 qiuyu(h[0],m);
	}
	//若b=2，则A^b%m=A^2%m
	else if(b==2){
		f(a[0],a[0],h[0]);
		qiuyu(h[0],m);
	}
	//若b为大于2的偶数，则A^b%m=(A^(b/2)%m)^2%m，即先把A乘b/2次方对m求余，然后再平方后对m求余。
    else if(b%2==0){
        for(int s=1;s<=b/2-1;s++)
        {
            f(a[0],p[0],h[0]);
            init(p[0],h[0]); 
            //每次循环中都初始化一下，也就是将p矩阵始终视作乘号前的矩阵，h是0矩阵，下同
        }
        qiuyu(p[0],m);         //把A乘b/2次方对m求余
        f(p[0],p[0],h[0]);     //再平方
        qiuyu(h[0],m);
    }
    //若b为大于1的奇数，则A^b%m=(A^(b-1)%m)*a%m，即先求A乘b-1次方对m求余，然后再乘A后对m求余。
    else {
        for(int s=1;s<=b-2;s++){
            f(a[0],p[0],h[0]);
            init(p[0],h[0]);
        }
		qiuyu(p[0],m);
        f(a[0],p[0],h[0]);    //再乘A后对m求余
        qiuyu(h[0],m);
    } 
    
    //因为最后并没有调用init函数，所以h矩阵就是最后求余得到的矩阵
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    printf("%d ",h[i][j]);
    printf("\n");
    }

    return 0;
}