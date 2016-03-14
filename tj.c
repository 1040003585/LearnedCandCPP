#include<stdio.h>
void main()
{
	int n,i,f[31];
	while (1){
		scanf("%d",&n);
		if(n==0)
			break;
		f[1]=1;
		f[2]=2;
		for(i=3;i<=n;i++){
			f[i]=f[i-1]+f[i-2];	
		}
		printf("%d\n",f[n]);
	}
	return;
}
