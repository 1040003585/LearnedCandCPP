#include<stdio.h>
#include<math.h>
int main()
{   
	int x;
	printf("��С��1000�Ŀ�������ȡ��\n\n");
    printf("������x\n");
    scanf("%d",&x);
	while(x>1000)
	{
		printf("��������\n");
	    scanf("%d",&x);
	}
    x=sqrt(x);
	printf("����ֵ��%d\n",x);
	return 0;
}