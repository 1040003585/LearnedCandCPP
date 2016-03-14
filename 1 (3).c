#include<stdio.h>
 int a();
 
int main()
{
int j,i;
a(50);
i=1;
	for(;i<10;i++)
{	for(j=1;j<=9;j++)	
printf("%d+%d=%2d",i,j,i+ j);
printf(" \n ");}
a( 60);
	return 0;
}

int a(n)
{int a;
a=1;
	for(;a<n;a++)
		printf("*")	;
	printf("\n");
	}