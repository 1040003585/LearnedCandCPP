#include<stdio.h>
int main()
{
	int  i,k,n,m,num[50],*p;
	printf("input number  of person: ");
	scanf ("%d",&n);
	p=num;for(i=1;i<n;i++)
	*(p+i)=i+1;
	i=k=m=0;
	while(m<n-1){
		if(*(p+i)!=0)k++;
		if(k==3){
			*(p+i)=0;k=0;m++;}
			i++;if(i==n)i=0;}
		while(*p==0)p++;printf("the last one is no.%d\n",*p);
	return 0;
}