#include <stdio.h>
double operation(double a1, double a2, int b)/*自定义函数，用于进行两个数之间的运算*/
{
    switch (b)
    {
	case 0:
		return (a1 + a2);/*返回两数相加的值*/
	case 1:
		return (a1 - a2);/*返回两数相减的值*/
	case 2:
		return (a1 *a2);/*返回两数相乘的值*/
	case 3:
		return (a1 / a2);/*返回两数相除的值*/
    }
}
void main()
{
	int i, n;
    while (1)
    {
        clrscr();
        gotoxy(15, 6); 										/*将光标定位*/
        printf("1.start game?(y/n)");
        gotoxy(15, 8);
        printf("2.Rule");
        gotoxy(15, 10);
        printf("3.exit\n");
        gotoxy(25, 15);
        printf("please choose:");
        scanf("%d", &i);
        switch (i)
        {
		case 1:
			clrscr();
			start();
			break;
		case 2:											/*输出游戏规则*/
			clrscr();
			printf("\t\tThe Rules Of The Game\n");
			printf(" step1: input 4 digits\n");
			printf(" step2: Reflections on 10 seconds\n");
			printf(" step3: use the + - * /and the 4 digits to make expression which the result is 24\n");
			
			sleep(10);
			break;
		case 3:											/*退出游戏*/
			exit(0);
		default:
			break;
        }
    }
	
}
start()
{
    int i, j, k, l, n, m, r,data[4],a[4]={0};
    double num[4] ={0}, res1, res2, res3;
    char sign[5] = "+-*/",ch;
	
    printf("input 4 numbers:");
    for (i = 0; i < 4; i++)
    {
        scanf("%lf", num + i);/*从键盘中输入要进行24点游戏的数字*/
        data[i] = num[i];
    }
    printf("Reflections on 10 seconds,input your answer:\n");
	sleep(10);/*程序暂停10秒钟*/
	printf("please input your result:\n");
	for(i=1;i<=3;i++)
	{
		
		scanf("%d",&a[2]);
		scanf("%c",&ch);
		scanf("%d",&a[3]);
		switch(ch)/*根据运算符进行运算*/
		{
		case '+':a[1]=a[2]+a[3];break;
		case '-':a[1]=a[2]-a[3];break;
		case '*':a[1]=a[2]*a[3];break;
		case '/':a[1]=a[2]/a[3];break;
		}
		printf("%d%c%d=%d\n",a[2],ch,a[3],a[1]);/*输出计算过程*/
	}
	if(a[1]==24)
		printf("you are right!\n");
	else
		printf("sorry,you are worry!\n");
	printf("press any key to see all the answers:\n");
	getch();
	printf("the result is:\n");/*输出所有结果*/
	for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
			if (j != i)
			{
				for (k = 0; k < 4; k++)
					if (k != i && k != j)
					{
						for (l = 0; l < 4; l++)
							if (l != i && l != j && l != k)
							{
								for (n = 0; n < 4; n++)
									for (m = 0; m < 4; m++)
										for (r = 0; r < 4; r++)
										{
											res1 = operation(num[i], num[j], n);
											res2 = operation(res1, num[k], m);
											res3 = operation(res2, num[l], r);
											if (res3 == 24.0)
												printf("[(%d%c%d)%c%d]%c%d=24\n", data[i],
												sign[n], data[j], sign[m], data[k], sign[r],
												data[l]);/*若结果为24则按正常顺序输出*/
											else if (res3 ==  - 24.0)
												printf("[%d%c(%d%c%d)]%c%d=24\n",data[k],
												sign[m],data[i], sign[n], data[j], sign[r],
												data[l]);/*调整输出顺序*/
											else if (res3 == 1.0 / 24.0)
												printf("%d%c[(%d%c%d)%c%d]=24\n", data[l],
												sign[r], data[i], sign[n],data[j], sign[m],
												data[k]);/*调整输出顺序*/
											else if (res3 ==  - 1.0 / 24.0)
												printf("%d%c[%d%c(%d%c%d)]=24\n", data[l],
												sign[r], data[k], sign[n], data[i], sign[m],
												data[j]);/*调整输出顺序*/
											else
											{
												res1 = operation(data[i], data[j], n);
												res2 = operation(data[k], data[l], r);
												res3 = operation(res1, res2, m);
												if (res3 == 24.0)/*判断结果是否为24*/
													printf("(%d%c%d)%c(%d%c%d)=24\n", data[i],
													sign[n], data[j], sign[m], data[k],
													sign[r], data[l]);
											}
										}
							}
					}
			}
			getch();
}