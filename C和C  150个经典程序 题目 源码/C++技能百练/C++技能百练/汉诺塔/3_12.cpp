#include<iostream.h>
void move(char one,char anoth)
{
	cout<<one<<"移动到"<<anoth<<endl;
}

void hanoi(int n,char no1,char no2,char no3)
{
	//
	if (n==1) move(no1,no3);
	else 
	{
		hanoi(n-1,no1,no3,no2);
		move(no1,no3);
        hanoi(n-1,no2,no1,no3);
	}
}

void main()
{
	void hanoi(int n,char no1,char no2,char no3);
	int m;
	cout<<"请输入A柱上的金盘子总数：";
	cin>>m;
	cout<<"当有"<<m<<"个金盘子时，移动步骤依次为："<<endl;
	hanoi(m,'A','B','C');
}
