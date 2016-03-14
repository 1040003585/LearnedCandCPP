#include<iostream>
#include<string>
using namespace std;
int main()
{
	string n1,n2;
	int a,i,j,k1,k2,n;
	while(cin>>n1>>n2)
	{
	    
	    k2=0;
	     for(a=0;a<n1.size();a++)
	    {
	    	  
	          n=0;
	          k1=0;
	    for(i=a;i<n1.size();i++)
	    {
		     for(j=n;j<n2.size();j++)
		     {
			     if(n1[i]==n2[j]){k1++;n=j;break;}
			 }
	    
		}
		if(k1>k2)k2=k1;
	
		}
		cout<<k2<<endl;
	
	}

return 0;
}



