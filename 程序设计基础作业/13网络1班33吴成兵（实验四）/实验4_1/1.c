#include<stdio.h>
int main()
{
    float x,y;
	printf("����\ny=x,(x<1)\ny=2x-1,(1<=x<10)\ny=3x-11,(x>=10)\n\n");
	printf("������x,x=\n");
	scanf("%f",&x);
	if(x<1)
		y=x;
	else
		if(x>=1&&x<10)
			y=2*x-1;
		else
			y=3*x-11;
	printf("����ĺ���ֵy=%f\n",y);
	return 0;
}
