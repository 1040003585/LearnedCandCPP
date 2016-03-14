#include<stdio.h>
int main()
{
	int b[4][3],a[3][4],i,j;
	printf("请输入3*4的a数组：\n");
	for(i=0;i<3;i++)
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			b[j][i]=a[i][j];
	printf("b数组:\n");
	for(i=0;i<4;i++)
		printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
	return 0;
}