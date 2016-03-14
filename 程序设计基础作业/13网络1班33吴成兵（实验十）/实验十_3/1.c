#include<stdio.h>
int main ()
{
	void sort(char *p,int m);
	int i,n;
	char*p,num[20];
    printf("input:");
	scanf("%d",&n);
    printf("«Î ‰»Înumber£∫");
	for(i=0;i<n;i++)
	   scanf("%d",&num[i]);
	p=num;
	sort(p,n);
	printf("Now ,the xepuence is :\n");
	for(i=0;i<n;i++)
		printf("%d ",num[i]);
	printf("\n");
	return 0;
}

	void sort(char *p,int m)
	{
		int i;
		char temp ,*p1,*p2;
		for(i=0;i<m/2;i++)
		{p1=p+i;p2=p+(m-1-i);temp=*p1;*p1=*p2;*p2=temp;}

	}