#include<stdio.h>
int main()
{

//����
	int i,LETTER=0,letter=0,number=0,space=0,other=0;
	char str[100];
	printf("������һ�в�����100���ַ���Ӣ����ӣ�\n");
	gets(str);

//ѭ������
	for(i=0;str[i]!='\0';i++)
	{   if(str[i]>='0'&&str[i]<='9')number++;
		else if(str[i]>='a'&&str[i]<='z')letter++;
		else if(str[i]>='A'&&str[i]<='Z')LETTER++;
		else if(' '==str[i])space++;
		else other++;
	}

//���
	printf("����Ӣ�������%d����д��ĸ\n����Ӣ�������%d��Сд��ĸ\n����Ӣ�������%d������\n����Ӣ�������%d���ո�\n����Ӣ�������%d�������ַ�\n"
		,LETTER,letter,number,space,other);

	return 0;
}