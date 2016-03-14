#include<iostream>
using namespace std;
int main()
{
	int a=1,b=10,c=5;
	int d;

	d=b/c+1;
	cout<<"  d is now:         "<<d<<endl;

	d=b%3;
	cout<<"  d is now:         "<<d<<endl;

	d=b-3*c/5;
	cout<<"  d is now:         "<<d<<endl;

	d=b*10+c-a*5; 
	cout<<"  d is now:         "<<d<<endl;

	d=(a+b-1)/c;
	cout<<"  d is now:         "<<d<<endl;

	d=((-a%c)+b)*c;
	cout<<"  d is now:         "<<d<<endl;

	d=--a;
	cout<<"  d is now:         "<<d<<endl<<endl;
	return 0;	
}