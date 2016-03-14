#include <iostream.h>
#include <iomanip.h>
struct sport		//结构声明（声明结构时不分配内存空间）
{
	char num[4];	//数据成员1（结构中包含的数据变量称为数据成员）
	double grade;	//数据成员2
};					//不能缺少分号

void main()
{
sport a[12]={{"001",13.6},{"002",14.8},{"010",12.0},
			{"011",12.7},{"023",15.6},{"025",13.4},
			{"031",14.9},{"036",12.6},{"037",13.4},
			{"102",12.5},{"325",15.3},{"438",12.7}}; //结构数组的定义和初始化
	sport temp;
	int i,j;
	int row=12,col=3;
	
	for(i=1;i<row;i++)  //"冒泡"排序
		for(j=0;j<row-i;j++)
		{
			if (a[j].grade>a[j+1].grade)
			{
				temp=a[j];			//结构数组变量可以互相赋值
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	
	cout<<setw(6)<<"名次"<<setw(6)<<"编号"<<setw(6)<<"成绩"<<endl;
	for(i=0;i<row;i++)
	cout<<setw(6)<<(i+1)<<setw(6)<<a[i].num<<setw(6)<<a[i].grade<<endl;
	
}
