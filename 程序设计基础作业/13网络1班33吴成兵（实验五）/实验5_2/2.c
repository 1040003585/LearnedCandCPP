#include<stdio.h>
int main()
{
	int a,b,one,two,three;
	printf("��ˮ�ɻ���\n\n");
	printf("ˮ�ɻ���:\n");
	printf("****************************\n");
	//ѭ��������λ��
	for(a=100;a<1000;a++)
	{
		//ȡ����������
		three=a/100;
		two=(a-100*three)/10;
		one=a%(100*three+10*two);
		b=three*three*three+two*two*two+one*one*one;
		//�ж��ǲ���ˮ�ɻ���
		if(a==b)
			printf("* %d *",a);
	}
	printf("\n****************************\n\n");
	return 0;
}