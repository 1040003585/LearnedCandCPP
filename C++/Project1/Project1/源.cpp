#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;
int main(){
int a,b,c,d,h,j,k,n,m=0;
double s;
while(scanf("%d %d %d",&a,&b,&c)==3&&a&&a&&c){
  cout<<fixed<<setprecision(c)<<(long double)a/b<<endl;
}  
printf("%f\n",(double)clock()/CLOCKS_PER_SEC);
return 0;
}