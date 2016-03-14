#include<iostream>
using namespace std;
int main()
{
	int var1=0,var2=10;
	cout<<"\nvar1 starts at        "<<var1<<endl
		<<"var2 starts at        "<<var2<<endl; 

	var2=var1+18;
	cout<<"var2 is now           "<<var2<<endl;

    var1=var2*3;  
	cout<<"var1 is now           "<<var1<<endl;
	
	var1=var2/3;    
	cout<<"var1 is now           "<<var1<<endl;

    var2=var1-1;
	cout<<"var2 is now           "<<var2<<endl;
    
	var1=var2%3;
	cout<<"var1 is now           "<<var1<<endl;

	var1=var1+1;  
	cout<<"var1 is finally       "<<var1<<endl;

    var2=var2*5;
	cout<<"and var2 is finally   "<<var2<<endl<<endl;
	return 0;
}