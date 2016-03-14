#include<stdio.h>
	int wei=0,length=0,i=0;
	char str[10000];
int main()
{ 
	void maxlen(char x);       //声明
	void shuchu(int x,int y);  //声明
	printf("求最长单词函数\n\n");
	printf("请输入一行单词：\n");
	gets(str);
	maxlen(str);
	shuchu(length,wei);
	return 0;
}

void maxlen(char x)           //求最长单词
{
	for(;str[i]!='\0';i++)
	{   
		if(str[i]==32)
		{
		    if(i-wei>length)
			{
				length=i-wei;wei=i;//取出空格间相距最大length,和第几个wei
			}
		}
	}

}

void shuchu(int x,int y)      //输出函数
{
	printf("最长单词：\n");
	for(i=wei;i<=wei+length;i++)//从位数输出最长length个
		printf("%c",str[i]);
	printf("\n");
}