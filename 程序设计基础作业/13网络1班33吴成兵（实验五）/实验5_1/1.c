#include<stdio.h>
int main()
{
	char c;
	int i=0,j=0,k=0,h=0;
	printf("ͳ����ĸ���ո����ֺ������ַ�����\n\n");
	printf("������һ���������س�����\n");
	//ѭ��
	scanf("%c",&c);
	while(c!='\n')
	{if('A'<=c&&c<='Z'||'a'<=c&&c<='z')
		i++;
	else if(c==' ')
    	j++;
	else if(48<=c&&c<='9')
		k++;
	else h++;
	scanf("%c",&c);
	}
	//���
	printf("��ĸ�ĸ����ǣ�%d\n",i);
	printf("�ո�ĸ����ǣ�%d\n",j);
	printf("���ֵĸ����ǣ�%d\n",k);
	printf("�����ַ��ĸ����ǣ�%d\n",h);
	return 0;
}