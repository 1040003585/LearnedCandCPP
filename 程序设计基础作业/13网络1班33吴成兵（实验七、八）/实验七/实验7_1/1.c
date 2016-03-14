#include<stdio.h>
#include<math.h>
int main()
{
	int a;int sushu(int x);
	printf("�б�������\n\n������һ�����1������\n");
	scanf("%d",&a);
	while(a<2)                   //����ݴ���
	{
		printf("���������������һ�����1������:\n");
    	scanf("%d",&a);
	}
	
	for(a=2;a<100 ;a++){
	if(a==2||a==3)             //��ʼ�ж��Ƿ�Ϊ����
		printf("%d is a sushu.\n",a);
	else
		sushu(a);}
	return 0;
}

extern

int sushu(int x)             //����������
{
	int i;
	for(i=2;i<=1+sqrt(x);i++)
		if(x%i!=0)
			return printf("%d is a sushu.\n",x);
		else
		return printf("%d isn't a sushu.\n",x);

}//for后可以不用大括号
//有问题平方数