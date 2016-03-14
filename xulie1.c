#include<stdio.h>
void main()
{
	int i, j, a, b, f[50], k, m;
	long n, c;
	while (1) {
		f[1]=1;f[2]=1;m=0;
		scanf("%d%d%ld",&a,&b,&n);
		if(a==0 && b==0 && n==0) {
			break;
		}
		for(i=3;i<43;i++){
			f[i]=(a*f[i-1]+b*f[i-2])%7;
			for(j = 2; j < i; j++)
		       		if(f[j-1] == f[i-1] && f[j] == f[i]){
					m=j-1;
					k=i-j;
					break;
				}
		if(m!=0) break;
		}
		if(n<m)
			printf("%d\n",f[n]);
		else
			c=(n-(m-1))%k+m-1;
			printf("%d\n",f[c]);
	}
}
