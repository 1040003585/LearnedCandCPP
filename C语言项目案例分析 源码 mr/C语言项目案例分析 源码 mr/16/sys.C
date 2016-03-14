#include <conio.h> 
#include <stdlib.h>
#include <dos.h>
#include <stdio.h>
#include <bios.h>


/*////////////////////////*/
int mousetest();
void soundcontrol();
int backtable();
void menu();
void main()/*主函数*/
{ 
	int n;
	menu();
	scanf("%d",&n);/*输入选择功能的编号*/
	while(n)
	{ 
		switch(n)
		{ 
		case 1: mousetest();break;
		case 2: capstatus();break;
		case 3: soundcontrol();break;
		case 4: getSegInfo();break;
			
			
		default:break;
		}
		getch();
		menu();/*执行完功能再次显示菜单界面*/
		scanf("%d",&n);
	}
}

void menu()/*自定义函数实现菜单功能*/
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|---------------------MENUE-------------------|\n");
	printf("\t\t|\t 0. exit                              |\n");
	printf("\t\t|\t 1. Mouse test                        |\n");
	printf("\t\t|\t 2. Caps Lock key status              |\n");
	printf("\t\t|\t 3. sound control                     |\n");
	printf("\t\t|\t 4. register information              |\n");
	printf("\t\t|---------------------------------------------|\n\n");
	printf("\t\t\tchoose(0-4):");
}




int mousetest()
{
	union REGS regs; 						/*定义寄存器型共同体*/
	int mousedr; 							/*声明整型变量*/
	clrscr();								/*清屏*/
	printf("Initializing Mouse...\n\n");				/*输出字符串*/
	regs.x.ax=0; 							/*设置ax值为0*/
	int86(0x33,&regs,&regs);
	mousedr=regs.x.ax; 						/*记录ax值*/
	if(mousedr==0)							/*等于0时*/
	{ 
	printf("initialize mouse error!"); 			/*提示初始化鼠标错误*/
	exit(1); 							/*终止程序*/
	} 
	
	printf("Finished initializing!\n\n");			/*完成初始化*/

	printf("Showing Mouse...\n");			/*提示显示鼠标*/
	regs.x.ax=1;						/*设置ax值为1*/
	int86(0x33,&regs,&regs);				/*显示鼠标*/
	printf("you can use the mouse.....\n\n");		/*提示能用鼠标*/
	printf("Press any key to hide the mouse.\n");	/*提示按任意键隐藏鼠标*/
	getch();
	regs.x.ax=2; 						/*设置ax值为2*/
	int86(0x33,&regs,&regs);				/*隐藏鼠标*/
	printf("\nthe mouse is hided\n");			/*提示鼠标正在隐藏*/
	getch();
	return 1;

}
capstatus()
{
	int value=0;									/*声明整型变量*/
	printf("\n\The current status of  the Caps Lock key is:");	/*输出字符串*/
	value=peekb(0x0040,0x0017);						/*获取内存单元*/
	if (value & 64)									/*当获取的字节单元的值与64进行与运算的值非零*/
		printf("\n\nThe Caps Lock key is: on");				/*输出状态ON*/
	else											/*否则*/
		printf("\n\nThe Caps Lock key is: off");				/*输出状态OFF*/
}
getSegInfo() 
{ 
	struct SREGS	 seg_stacks;							/*声明SREGS结构变量*/
	segread(&seg_stacks);								/*获取寄存器信息*/
	printf("\nCS:%X\tDS:%X\tSS:%X\tES:%X",seg_stacks.cs,	/*输出寄存器信息*/
		seg_stacks.ds,seg_stacks.ss,seg_stacks.es);
}   

void soundcontrol()			/*控制PC扬声器*/
{
	unsigned fre=50;				/*声明无符合基本型变量*/
	int times;					/*声明整型变量*/
	for(times=0;times<1000;times++)	/*0至999循环*/
	{
		fre=(fre+times)%40000;		/*生成声音频率*/
		sound(fre);					/*发出声音*/
		delay(1000);				/*延时1秒*/
	}
	nosound(); 					/*停止发声*/
}

