#include<stdio.h>
int main()
{
	int i=0,geshu=1;
	char str[100000];
	printf("请输入一串英语句子，开头结尾不能加空格，单词间务必以一个空格隔开：\n");
	gets(str);
	for(;str[i]!='\0';i++)
	{
		if(str[i]==32&&str[i-1]==' ')
		{printf("结果不太正确，输入不能有连续空格。\n请关闭窗口，再输入。\n");break;}
		else if(str[i]==32) geshu++;
	}
	printf("\n此串英语句子有%d个单词。\n",geshu);
	return 0;
}