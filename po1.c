#include<stdio.h>
int main()
{
	int a=12,*p,**ptr;
	ptr=&p;
	p=&a;
	printf("%d %d %d\n",a,*p,**ptr);
	**ptr=34;
	printf("%d %d %d\n",a,*p,**ptr);
}
