#include<iostream>
using namespace std;
int main()
{
	int   i,sum1=0;
	float j,sum2=0,average;

	for(i=1;i<=5;i++)
		sum1+=i;
	for(j=1;j<2.1;j+=0.1)//为什么j<=2不行？
		sum2+=j;
	average=sum2/11;

	cout<<"\nthe sum of the integers 1 to 5 is :                                "
		<<sum1<<endl;
	cout<<"the average of the floating-point numbers 1.0,1.1,1.2 ...2.0 is :  "
		<<average<<endl<<'\n';

	return 0;
}