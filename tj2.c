#include <stdio.h>
void main()
{
	int i,n,f1,f2,f3,flag;
	while(1){
		scanf("%d",&n);
		f1=1;f2=2;flag=0;
		switch (n){
			case 0:	flag=1;
				break;
			case 1:	printf("%d\n",f1);
				continue;
			case 2:	printf("%d\n",f2);
			       	continue;
			default:
				 for(i=3;i<=n;i++){
				 	f3=f1+f2;
					f1=f2;
					f2=f3;
				 }
				 printf("%d\n",f3);
		}
		if(flag==1) break;
	}
}
