#include<stdio.h>
int main()
{
	int a,b,one,two,three;
	printf("求水仙花数\n\n");
	printf("水仙花数:\n");
	printf("****************************\n");
	//循环所有三位数
	for(a=100;a<1000;a++)
	{
		//取出三个数字
		three=a/100;
		two=(a-100*three)/10;
		one=a%(100*three+10*two);
		b=three*three*three+two*two*two+one*one*one;
		//判断是不是水仙花数
		if(a==b)
			printf("* %d *",a);
	}
	printf("\n****************************\n\n");
	return 0;
}