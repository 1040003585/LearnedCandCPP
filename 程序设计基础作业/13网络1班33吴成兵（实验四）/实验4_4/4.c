#include"stdio.h"
int main()
{
	int a,b,c,d,f;
	printf("排列输入四个数的小大顺序\n\n");
	printf("请输入a=\n");   scanf("%d",&a);
	printf("请输入b=\n");	scanf("%d",&b);
	printf("请输入c=\n");	scanf("%d",&c);
    printf("请输入d=\n");	scanf("%d",&d);

	if(a>b){f=a;a=b;b=f;}
	if(a>c){f=a;a=c;c=f;}
	if(a>d){f=a;a=d;d=f;}
	if(b>c){f=b;b=c;c=f;}
	if(b>d){f=b;b=d;d=f;}
	if(c>d){f=c;c=d;d=f;}
 
	printf("四个数的小大顺序为：%d,%d,%d,%d\n",a,b,c,d);
	return 0;

}