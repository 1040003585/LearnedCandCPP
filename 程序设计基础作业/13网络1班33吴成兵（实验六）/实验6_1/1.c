#include<stdio.h>
int main()
{
	int t,j,i,a[10];
	printf("������10��������");//����10����
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);

    for(j=0;j<9;j++)//ѡ������
		for(i=j;i<9;i++)
            if(a[j]>a[i+1])
			{t=a[j];a[j]=a[i+1];a[i+1]=t;}

	printf("10��������˳���ǣ�");//����˳��
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}