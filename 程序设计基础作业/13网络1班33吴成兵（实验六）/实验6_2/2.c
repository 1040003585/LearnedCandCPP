#include<stdio.h>
int main()
{
//得到数
	int i,j,shu,a[10]={10,20,30,40,50,60,70,80,90,100};
	printf("请输入一个数：");
	scanf("%d",&shu);
    printf("顺序如下：\n");

//如果数在10和100之间
	for(i=0;i<9;i++)
	{
		if(shu>a[i]&&shu<=a[i+1])
		{for(j=0;j<=i;j++) printf("%d ",a[j]);
	  	 printf("%d ",shu);
		 for(j=i+1;j<10;j++)printf("%d ",a[j]);}
	}

//如果数小于10
	if(shu<a[0])
	{printf("%d ",shu);
	 for(i=0;i<10;i++)
	 printf("%d ",a[i]);}

//如果数大于100
	if(shu>a[9])
	{for(i=0;i<10;i++)
	 printf("%d ",a[i]);
	 printf("%d ",shu);}

	printf("\n");
	return 0;
}
