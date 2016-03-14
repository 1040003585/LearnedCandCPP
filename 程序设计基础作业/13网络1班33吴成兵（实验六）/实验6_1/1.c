#include<stdio.h>
int main()
{
	int t,j,i,a[10];
	printf("请输入10个整数：");//输入10整数
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);

    for(j=0;j<9;j++)//选择法排序
		for(i=j;i<9;i++)
            if(a[j]>a[i+1])
			{t=a[j];a[j]=a[i+1];a[i+1]=t;}

	printf("10个整数的顺序是：");//输入顺序
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}