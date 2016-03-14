#include<stdio.h>
void main()
{
	int i,f1,f2,f3,a,b,n;
	while (1){
		f1=1;f2=2;
		scanf("%d%d%d",&a,&b,&n);
		if(a==0 && b==0 && n==0)
			break;
		for(i=3;i<=n;i++){
			f3=(a*f2+b*f1)%7;
			f1=f2;f2=f3;
		}
		printf("%d\n",f3);
	}
}
