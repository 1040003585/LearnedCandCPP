#include<stdio.h>
void main()
{
	int i,n,f[5],flag;
	flag=1;
	n=1;
	while (flag=1){
		f[0]=5*n+1;
		flag=0;
		for(i=1;i<5;i++){
			if(f[i-1]%4!=0) {flag=1;break;}
			f[i] = 5*f[i-1]/4+1;
		}
		n++;
	}
	printf("%d\n",f[4]);
}
