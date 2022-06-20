#include<iostream>
using namespace std;
int main()
{
	int a[ ][4]={0,1,2,3,1,4,5,6,2,5,7,8,3,6,8,9};
	
	bool found=true;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(j!=i && a[i][j]!=a[j][i]) {
				found=false;
				break;
			}
		}
	if(!found)cout << "no" << endl;
	else cout << "yes" << endl;
	return 0;
}
