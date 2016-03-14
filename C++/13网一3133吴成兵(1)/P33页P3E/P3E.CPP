#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double num =123.45678;
	
	cout<<num<<endl;
	cout<<setprecision(7)<<num<<endl;
	cout<<fixed<<setprecision(2)<<num<<endl;
	return 0;
}