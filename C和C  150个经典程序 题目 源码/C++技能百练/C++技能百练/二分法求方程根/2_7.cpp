#include <iostream.h>
#include <math.h>
#include <iomanip.h>
void main()
{
	float x0,x1,x2,fx0,fx1,fx2;
	do
	{
		cout<<"请输入根区间的起始值：";
		cin>>x1;
		cout<<endl;
        cout<<"请输入根区间的终止值：";
		cin>>x2;
		cout<<endl;
		fx1=x1*((2*x1-4)*x1+3)-6;
        fx2=x2*((2*x2-4)*x2+3)-6;
	}while (fx1*fx2>0);
	do
	{
		x0=(x1+x2)/2;
		fx0=x0*((2*x0-4)*x0+3)-6;
		if (fx0*fx1<0)
		{
			x2=x0;
			fx2=fx0;
		}
		else
		{
			x1=x0;
			fx1=fx0;
		}
	}while (fabs(fx0)>=1e-5);
	cout<<"方程的根=";
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<x0<<endl;
}
