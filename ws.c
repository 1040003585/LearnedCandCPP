#include<stdio.h>
#include<math.h>
int main()
{
	long i,m,n;
	double sum;
	scanf("%ld",&n);
	while(n>0){
		scanf("%ld",&m);
		sum=1.0;
		for(i=1;i<=m;i++){
			sum+=log10(i);
		}
		printf("%ld\n",(long)sum);
		n--;

	}
}
