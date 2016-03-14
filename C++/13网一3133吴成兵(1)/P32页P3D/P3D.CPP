#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double num=123.456;
	cout<<setw(9)<<setfill('*')<<num<<endl;
	cout<<setw(9)<<setfill('0')<<num<<endl;
	cout<<setw(10)<<num<<endl<<endl;
	return 0 ;
}