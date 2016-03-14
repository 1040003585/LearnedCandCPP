#include <stdio.h>
void main()
{
	int a=12,b,*p,**ptr;
	p=&a;
	printf("a=%d &a=%d\n",a,&a);
	b=*p;
	printf("b=%d *p=%d\n",b,*p);
	ptr=&p;
	printf("p=%d *p=%d &p=%d\n",p,*p,&p);
	*ptr=&b;
	printf("b=%d &b=%d *ptr=%d\n",b,&b,*ptr);
	**ptr=34;
	printf("ptr=%d *ptr=%d **ptr=%d\n",ptr,*ptr,**ptr);
	ptr=a;
	printf("%d\n",ptr);
}
