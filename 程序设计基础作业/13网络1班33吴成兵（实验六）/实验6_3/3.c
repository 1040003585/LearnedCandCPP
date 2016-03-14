#include<stdio.h>
int main()
{

//定义
	int i,LETTER=0,letter=0,number=0,space=0,other=0;
	char str[100];
	printf("请输入一行不超过100个字符的英语句子：\n");
	gets(str);

//循环搜索
	for(i=0;str[i]!='\0';i++)
	{   if(str[i]>='0'&&str[i]<='9')number++;
		else if(str[i]>='a'&&str[i]<='z')letter++;
		else if(str[i]>='A'&&str[i]<='Z')LETTER++;
		else if(' '==str[i])space++;
		else other++;
	}

//输出
	printf("这行英语句子有%d个大写字母\n这行英语句子有%d个小写字母\n这行英语句子有%d个数字\n这行英语句子有%d个空格\n这行英语句子有%d个其他字符\n"
		,LETTER,letter,number,space,other);

	return 0;
}