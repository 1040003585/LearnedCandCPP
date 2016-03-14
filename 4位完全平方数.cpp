#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
	for(int i=1;i<10;i++)
	  for(int j=0;j<10;j++)
	  {
	  	 n=1100*i+j*11;
//	  	int m=floor(sqrt(n)+0.5);
//	  	if(m*m==n)cout<<n;

	  	int m=sqrt(n);
        if(m*m==n)
		  cout<<n<<" "<<m<<endl;
	  }
	  cout<<endl;
	  for(n=0;n<10;n++)
	  	  cout<<n<<" "<<floor(sqrt(n))<<" "<<floor(sqrt(n)+0.5)<<endl;
	 for(n=0;n<10;n++)
	 cout<<'\a';
	return 0;
} 
