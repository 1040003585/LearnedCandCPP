#include<stdio.h>
int main()
{
    float x,y;
	printf("求函数\ny=x,(x<1)\ny=2x-1,(1<=x<10)\ny=3x-11,(x>=10)\n\n");
	printf("请输入x,x=\n");
	scanf("%f",&x);
	if(x<1)
		y=x;
	else
		if(x>=1&&x<10)
			y=2*x-1;
		else
			y=3*x-11;
	printf("所求的函数值y=%f\n",y);
	return 0;
}
