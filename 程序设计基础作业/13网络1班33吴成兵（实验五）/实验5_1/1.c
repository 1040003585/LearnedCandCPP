#include<stdio.h>
int main()
{
	char c;
	int i=0,j=0,k=0,h=0;
	printf("统计字母、空格、数字和其他字符个数\n\n");
	printf("请输入一串东东，回车结束\n");
	//循环
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
	//结果
	printf("字母的个数是：%d\n",i);
	printf("空格的个数是：%d\n",j);
	printf("数字的个数是：%d\n",k);
	printf("其他字符的个数是：%d\n",h);
	return 0;
}