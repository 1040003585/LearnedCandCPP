
#include<algorithm>
#include<iostream>//
using namespace std;
int shu[100]={0,3,5,2,7,3,4,-99,0,8,3,2,3332,23,5,22,-3,4};
void merge1(int a[],int p,int q,int rr){
	int i,k,j,n1=q-p+1,n2=rr-q;
	int l[n1+1],r[n2+1];
	for( i=1;i<=n1;i++)
	    l[i]=a[p+i-1];
    for(int i=1;i<=n2;i++)
        r[i]=a[q+j];
    r[n2+1]=l[n1+1]=2100000000;
    i=j=1;
    for(k=p;k<=rr;k++){
    	if(l[i]<=r[j]){
    		a[k]=l[i];
    		i++;
    	}
    	else{
    		a[k]=r[j];
    		j++;
    	}
    }
}
void merge_sort(int a[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge1(a,p,q,r);
	}
}
int main(){
	merge_sort(shu,1,10);
	for(int i=0;i<20;i++)
	  cout<<shu[i]<<" ";	
	return 0;
}