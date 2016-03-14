#include<stdio.h>
int dsum(int n){
	int sum,temp;
	sum=0;
	while (n>0){
		temp=n%10;
		sum += temp*temp;
		n/=10;
	}
	return sum;
}

void main()
{
	int m,i,a[650],flag,b,k;
	while (1){
		scanf("%d",&m);
		if(m==0){
			break;
		}
		flag=1;a[0]=m;k=0;
		while (flag){
			m=dsum(m);
			a[++k]=m;
			for(i=0;i<k-1;i++)
				if(a[i]==m){
					flag=0;
					break;
				}
		}
			for(i=0;i<=k;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
	}
}
