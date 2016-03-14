#include<iostream>
using namespace std;
int main()
{
	int a=12,b=0,c=3,d;

	a++;//12
	cout<<" \n  a is now:       "<<a<<endl;

	b--;//-1
	cout<<"  b is now:       "<<b<<endl;

	d=++c;//4
	cout<<"  d is now:       "<<d<<endl;

	d=c--;//4 c=3
	cout<<"  d is now:       "<<d<<endl;

	d=a++ - 2;//
	cout<<"  d is now:       "<<d<<endl;

	d=a++ + b++ - c--;//14-1-3
	cout<<"  d is now:       "<<d<<endl<<'\n'; 

	return 0;	
}