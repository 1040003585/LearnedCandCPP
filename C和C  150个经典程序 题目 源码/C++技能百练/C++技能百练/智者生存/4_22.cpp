#include <iostream.h>
void main()
{
	int i,k,m,s,sh,num[30],sea[15],ship[15];
	for (i=0;i<30;i++)
	num[i]=i+1;  //1至30给每人编号
	i=0;  //i为每次循环时计数变量
	k=0;  //k为按1，2...9报数时计数变量
	m=0;  //m为退出人数
	s=0;  //存被投入海者数组的下标
	sh=0;  //存在船上人编号数组的下标
	while (m<15)
	{
		if (num[i]!=0) k++;
		if (k==9)
		{
			sea[s]=num[i];
			s++;
			num[i]=0;
			k=0;
			m++;
		}
		i++;
		if (i==30) i=0;
	}
	for(i=0;i<30;i++)
		if (num[i]!=0)
		{
		ship[sh]=num[i];
		sh++;
		}

	cout<<"被投入海的序号为："<<endl;
	for(i=0;i<15;i++)
	{
	    cout<<sea[i]<<"  ";
	}
    cout<<endl<<"留在船上的序号为："<<endl;
    for(i=0;i<15;i++)
	{
	   	cout<<ship[i]<<"  ";
	}
	cout<<endl;
}
