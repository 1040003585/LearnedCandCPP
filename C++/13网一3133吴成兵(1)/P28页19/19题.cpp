#include<iostream>
using namespace std;
int main()
{
	double purchase_price,selling_price,profit,percentage_profit;

	purchase_price=50;
	selling_price=60;

	profit=selling_price-purchase_price;
	percentage_profit=profit/purchase_price;

	cout<<"\n profit is :                "<<profit<<endl;
	cout<<" percentage_profit is :     "<<percentage_profit<<endl<<endl;
	return 0;
}