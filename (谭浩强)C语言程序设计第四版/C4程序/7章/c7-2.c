#include <stdio.h>
int main()
{ int max(int x,int y);  
  int a,b,c;  
  printf("please enter two integer numbers:");
  scanf("%d,%d",&a,&b);
  c=max(a,b);
  printf("max is %d\n",c);
}

int max(int x,int y)               // ¶¨Òåmaxº¯Êı
{
    if(x>y)
		return (x);
	else
		return y;
}