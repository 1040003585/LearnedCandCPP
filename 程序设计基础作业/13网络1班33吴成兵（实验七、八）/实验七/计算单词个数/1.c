#include<stdio.h>
int main()
{
	int i=0,geshu=1;
	char str[100000];
	printf("������һ��Ӣ����ӣ���ͷ��β���ܼӿո񣬵��ʼ������һ���ո������\n");
	gets(str);
	for(;str[i]!='\0';i++)
	{
		if(str[i]==32&&str[i-1]==' ')
		{printf("�����̫��ȷ�����벻���������ո�\n��رմ��ڣ������롣\n");break;}
		else if(str[i]==32) geshu++;
	}
	printf("\n�˴�Ӣ�������%d�����ʡ�\n",geshu);
	return 0;
}