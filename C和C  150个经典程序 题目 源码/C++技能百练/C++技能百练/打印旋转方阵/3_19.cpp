#include <iostream.h>
#include<iomanip.h>
#define N 6
void main()
{
	int a[N+1][N+1];
	int row,column,i,j,k,t,p;
	row=0;column=1;k=N;t=1;p=1;

	do
	{
		for(i=1;i<=k;i++)  //给一列数赋值
		{
			row+=t;
			a[row][column]=p;
			p++;
		}
		k--;   //列数减一
		for(i=1;i<=k;i++)  //给一行数赋值
		{
			column+=t;
			a[row][column]=p;
			p++;
		}
		t=-t;   //改变赋值方向
	}while(p<=N*N);  //赋值共计N*N个数时终止

	for(i=1;i<=N;i++)   //逐行输出
	{
		for(j=1;j<=N;j++)
			cout<<setw(5)<<a[i][j];
		cout<<endl;
	}
}
