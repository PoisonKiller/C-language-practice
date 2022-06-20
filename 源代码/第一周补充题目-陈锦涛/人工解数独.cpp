/*
测试数据
800000000
003600000
070090200
050007000
000045700
000100030
001000068
008500010
090000400
*/
/*
思路：本体采用深度优先搜索，从棋盘的第一个位置开始搜索
首先调用pos函数存储每个空位上可能填的数
再从第一个空位开始，深度搜索所有的结果
当成功搜完最后一个元素时，回溯
这样就能完成解法
*/
#include<iostream>
using namespace std;
char sudoku[9][9];//定义数独棋盘，0表示此处为空，需要填数
char a[9][9];     //a棋盘为最终的正确答案棋盘
int ans[9][9][9]; //ans数组存放着9*9棋盘上每个位置上可以填的数
int res[9][9];    //res数组表示9*9棋盘上每个位置上可以填的数字的个数
int row,col,num;  //与后面goin函数有关

//check_row函数是用来查询与空位在相同行上某个数字(不含0)的个数
int check_row(int row,char ch)
{
    int f1=0;
    for(int i=0;i<9;i++){
        if(a[row][i]==ch)f1++;
    }
    return f1;
}

//check_col函数是用来查询与空位在相同列上某个数字(不含0)的个数
int check_col(int col,char ch)
{
    int f2=0;
    for(int i=0;i<9;i++){
        if(a[i][col]==ch)f2++;
    }
    return f2;
}

//check_nine函数是用来查询空位所在九宫格上某个数(不含0)的个数
int check_nine(int i,int j,char ch)
{
    int f3=0;
    for(int x=(i/3)*3;x<(i/3)*3+3;x++)
    for(int y=(j/3)*3;y<(j/3)*3+3;y++)
        if(a[x][y]==ch)f3++;
    return f3;
}

//pos函数是用来搜索某个空位上可能填的数字,并存储下来
void pos(int i,int j,bool flag)
{
    if(flag)printf("第%d行第%d个空的可能答案有",i+1,j+1);
    int r=0;
    for(char x='1';x<='9';x++)
    {
        int f1=check_row(i,x);
        int f2=check_col(j,x);
        int f3=check_nine(i,j,x);
        if(f1>1 || f2>1 || f3>1){cout << "此题无解" <<endl;return;}
        if(!f1 && !f2 && !f3){if(flag)cout << x << ' ';ans[i][j][r++]=x-'0';res[i][j]++;}
    }
    if(flag)cout << endl;
}

bool flag; //定义回溯的标志，初始为false
void dfs(int i,int j)
{
    if(flag)return; //若标志成立，则一直返回
    //若当前位置不是空位，则搜索下一位
    if(a[i][j]!='0'){
        if(j<8)dfs(i,j+1);
        else if(i<8)dfs(i+1,0);
        else if(i==8){flag=true;return;}//
        //若当前位置不是空位，且是最后一位，则标志成立，返回
    }
    //若当前位置是空位，开始搜索
    else{
        //每个空位上的可能填的数的数量为res[i][j]
        for(int x=0;x<res[i][j];x++)
        {
            char ch='0'+ans[i][j][x];
            int f1=check_row(i,ch);//查询相同行上的x的数量
            int f2=check_col(j,ch);//查询相同列上的x的数量
            int f3=check_nine(i,j,ch);//查询所在九宫格上的x的数量
            if(f1>1 || f2>1 || f3>1)return;//若有一处d的数量大于1，返回
            //若当前位置可填x，继续搜索
            if(!f1 && !f2 && !f3){
                a[i][j]=ch;       //填进去
                if(j<8)dfs(i,j+1);//搜索下一位
                else if(i<8)dfs(i+1,0);
                else if(i==8){flag=true;return;}//若正好是最后以为，标志成立，返回
                if(flag)break;//若标志成立，直接break跳出循环并返回
                a[i][j]='0';//若未搜索成功,
            }
        }
    }
    return;
}

//goin函数是用来输入答案的
void goin()
{
    printf("请按照行数+列数+数字的格式输入");
    cin >> row >> col >> num;
}

//goout函数用来，当输入答案正确时，输出现在的sudoku棋盘
void goout(char* p)
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout << *(p+9*i+j) <<' ';
        cout << endl;
    }
}

int main(void)
{
    int t1=0,t2=0;        //t1记录空位的数量,t2记录已经填入的空位的数量
    for(int i=0;i<9;i++)cin >> sudoku[i];//输入棋盘
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    {
        a[i][j]=sudoku[i][j]; //将原来的棋盘复制成a,即确定a的初始状态
        if(sudoku[i][j]=='0')t1++;
    }

    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
    if(a[i][j]=='0')pos(i,j,true); //第一遍的时候，输出每个位置上可以填入的数

    dfs(0,0);//深搜答案
    
    printf("正确解法为\n");//输出最终解法
    goout(a[0]);

    while(1){
        //当t2=t1时，表示已经完成，解题成功
        if(t2==t1){
            printf("解题成功，最终答案为\n");
                goout(sudoku[0]);
        }

        goin();//输入解法

        if('0'+num==a[row-1][col-1]){
            printf("正确\n");
            t2++;
            sudoku[row-1][col-1]='0'+num; //填入答案
            goout(sudoku[0]);
        }

        else {
            printf("错误\n");
            goout(sudoku[0]);
        }
    }

}