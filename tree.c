#include<stdio.h>
void main()
{
	int L,i,j,n,begin,end,count;
	int trees[10001];
	scanf("%d%d",&L,&n);
	for(i=0;i<=L;i++){
		trees[i]=1;
	}
	for(i=0;i<n;i++){
		scanf("%d%d",&begin,&end);
		for(j=begin;j<=end;j++){
			trees[j]=0;
		}
	}
	for(count=0,i=0;i<=L;i++){
		if(trees[i])
			count++;
	}
	printf("%d\n",count);
}
