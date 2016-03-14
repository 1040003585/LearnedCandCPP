#include<iostream>
#include<iomanip>
using namespace std;
inline void swap(float &a,float &b);
int main()
{
	float aa,bb;
	cout<<"Please input two number:"<<endl<<endl;
	while(cin>>aa>>bb)
	{
		if(aa>bb)
			swap(aa,bb);
		cout<<"The numbers in order are:"<<endl;
		cout<<aa<<setw(5)<<bb<<endl;
	}
	return 0;
}
void swap(float &a,float &b)
{
	int t;
	t=a;a=b;b=t;
}