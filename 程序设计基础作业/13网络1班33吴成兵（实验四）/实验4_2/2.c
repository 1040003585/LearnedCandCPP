#include<stdio.h>
#include<math.h>
int main()
{   
	int x;
	printf("求小于1000的开根，再取整\n\n");
    printf("请输入x\n");
    scanf("%d",&x);
	while(x>1000)
	{
		printf("请再输入\n");
	    scanf("%d",&x);
	}
    x=sqrt(x);
	printf("所求值：%d\n",x);
	return 0;
}