#include<stdio.h>
int main()
{
	int score;char c;
	printf("�ٷ��Ƴɼ�תΪ�ȼ�\n\n");
	printf("���������ͳɼ�score=\n");
	scanf("%d",&score); 
    while(score<0||score>100)
	{
		printf("��������ɼ�");
		scanf("%d",&score);
	}
	switch((int)(score/10))
	{
	case 9:
	case 10:c='A';break;
	case 8:c='B';break;
	case 7:c='C';break;
	case 6:c='D';break;
	default :c='E';
	}
	printf("�ɼ��ȼ���%c\n",c);
	return 0;
}