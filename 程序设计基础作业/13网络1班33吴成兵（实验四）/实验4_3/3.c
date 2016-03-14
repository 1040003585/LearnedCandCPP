#include<stdio.h>
int main()
{
	int score;char c;
	printf("百分制成绩转为等级\n\n");
	printf("请输入整型成绩score=\n");
	scanf("%d",&score); 
    while(score<0||score>100)
	{
		printf("请再输入成绩");
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
	printf("成绩等级：%c\n",c);
	return 0;
}