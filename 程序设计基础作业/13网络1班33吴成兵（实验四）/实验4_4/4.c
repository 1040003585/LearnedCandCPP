#include"stdio.h"
int main()
{
	int a,b,c,d,f;
	printf("���������ĸ�����С��˳��\n\n");
	printf("������a=\n");   scanf("%d",&a);
	printf("������b=\n");	scanf("%d",&b);
	printf("������c=\n");	scanf("%d",&c);
    printf("������d=\n");	scanf("%d",&d);

	if(a>b){f=a;a=b;b=f;}
	if(a>c){f=a;a=c;c=f;}
	if(a>d){f=a;a=d;d=f;}
	if(b>c){f=b;b=c;c=f;}
	if(b>d){f=b;b=d;d=f;}
	if(c>d){f=c;c=d;d=f;}
 
	printf("�ĸ�����С��˳��Ϊ��%d,%d,%d,%d\n",a,b,c,d);
	return 0;

}