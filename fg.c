#include<stdio.h>
void main()
{
	int i,n,f2,f1;
	while (1){
		scanf("%d",&n);
		if(n==0)
			break;
		f1=2;
		for(i=1;i<=n;i++){
			f2=f1+2*(i-1);
			f1=f2;
		}
		printf("%d\n",f2);
	}
}
