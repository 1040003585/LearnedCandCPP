#include<stdio.h>
int main()
{
//�õ���
	int i,j,shu,a[10]={10,20,30,40,50,60,70,80,90,100};
	printf("������һ������");
	scanf("%d",&shu);
    printf("˳�����£�\n");

//�������10��100֮��
	for(i=0;i<9;i++)
	{
		if(shu>a[i]&&shu<=a[i+1])
		{for(j=0;j<=i;j++) printf("%d ",a[j]);
	  	 printf("%d ",shu);
		 for(j=i+1;j<10;j++)printf("%d ",a[j]);}
	}

//�����С��10
	if(shu<a[0])
	{printf("%d ",shu);
	 for(i=0;i<10;i++)
	 printf("%d ",a[i]);}

//���������100
	if(shu>a[9])
	{for(i=0;i<10;i++)
	 printf("%d ",a[i]);
	 printf("%d ",shu);}

	printf("\n");
	return 0;
}
