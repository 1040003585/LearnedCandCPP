#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>

#define cputs printf

#define N 200
#define LEFT 0x4b00
#define RIGHT 0x4d00
#define DOWN 0x5000
#define UP 0x4800
#define ESC 0x011b

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

struct Food
{
	int x;/*食物的橫座標*/
	int y;/*食物的縱座標*/
	int yes;/*判斷是否要出現食物的變量,1需要出現食物*/
}food;/*食物的結構體*/
struct Snake
{
	int x[N];/*蛇的橫座標*/
	int y[N];/*蛇的縱座標*/
	int node;/*蛇的節數*/
	int direction;/*蛇移動方向*/
	int life;/*蛇的生命,0活著,1死亡*/
}snake;/*蛇的結構體*/

int i,key;
int score=0;/*得分*/
int gamespeed=500;/*遊戲速度自己調整*/

void Init(void);/*圖形驅動*/
void Close(void);/*圖形結束*/
void DrawK(void);/*開始畫面*/
void GameOver(void);/*結束遊戲*/
void GamePlay(void);/*玩遊戲具體過程*/
void PrScore(void);/*輸出成績*/
void DoError(void);
void DoOK(void);
void DoWin(void);
/*------------------------------------------------------*/
void gotoxy( int column, int line );
void textcolor(int fontcolor);
void delay(unsigned timeout);
void textmode(int mode);
void clrscr(void);
void randomize(void);
/*------------------------------------------------------*/

/*主函數*/
void main(void)
{
	Init();/*圖形驅動*/
	DrawK();/*開始畫面*/
	GamePlay();/*玩遊戲具體過程*/
	Close();/*圖形結束*/
}
/*圖形驅動*/
void Init(void)
{
	const char *User_Guide[]=
	{
		" ",
		"這是文字模式的貪吃蛇",
		" 操作模式如下:",
		" 按W--蛇轉頭向上",
		" 按S--蛇轉頭向下",
		" 按A--蛇轉頭向左",
		" 按D--蛇轉頭向右",
		" 按Q--結束遊戲",
		NULL,
	};

	clrscr();

	textcolor(BROWN);
	while(User_Guide[i]!=NULL)
	{
		if(0 == i)
			gotoxy(45,3);
		else gotoxy(45,3+i-1);

		cputs(User_Guide[i]);
		i++;
	}

}
/*開始畫面,左上角座標為(2,2),右下角座標為(43,23)的圍牆*/
void DrawK(void)
{
	textcolor(LIGHTBLUE);//設置顏色
        for(i=2;i<=43;i++)
	{
		gotoxy(i,2); putch('-'); //上邊
		gotoxy(i,23); putch('-'); //下邊
	}
        for(i=2;i<=23;i++)
	{
		gotoxy(2,i); putch('|'); //左邊
		gotoxy(43,i); putch('|'); //右邊
	}
}

//   (2,2)-----------------------------(2,43)
//	|				|
//	|				|
//	|				|
//	|				|
//	|				|
//	|				|
//  (2,23)----------------------------(43,23)

/*玩遊戲具體過程*/
void GamePlay(void)
{
	char ch;
	randomize();/*隨機數發生器*/
	food.yes=1;/*1表示需要出現新食物,0表示已經存在食物*/
	snake.life=0;/*活著*/
	snake.direction=1;/*方向向右*/
	snake.x[0]=5;snake.y[0]=12;/*蛇頭*/
	snake.x[1]=4;snake.y[1]=12;
	snake.node=2;/*節數*/
	PrScore();/*輸出得分*/
	while(1)/*可以重複玩遊戲,押ESC鍵結束*/
	{
		while(!kbhit())/*在沒有按鍵的情況下,蛇自己移動身體*/
		{
			if(food.yes==1)/*需要出現新食物*/
			{
				food.x=rand()%40+3;
				food.y=rand()%20+3;
				food.yes=0;/*畫面上有食物了*/
			}
			if(food.yes==0)/*畫面上有食物了就要顯示*/
			{
				textcolor(LIGHTGREEN);
				gotoxy(food.x,food.y);
				putch('*');
			}
			for(i=snake.node-1;i>0;i--)/*蛇的每個環節往前移動,也就貪吃蛇的關鍵算法*/
			{
				snake.x[i]=snake.x[i-1];
				snake.y[i]=snake.y[i-1];
			}
			/*1,2,3,4表示右,左,上,下四個方向,通過這個判斷來移動蛇頭*/
			switch(snake.direction)
			{
				case 1: snake.x[0]++;break;
				case 2: snake.x[0]--;break;
				case 3: snake.y[0]--;break;
				case 4: snake.y[0]++;break;
			}
			for(i=3;i<snake.node;i++)/*從蛇的第四節開始判斷是否撞到自己了,因為蛇頭為兩節,第三節不可能拐過來*/
			{
				if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
				{
					GameOver();/*顯示失敗,本次遊戲結束*/
					snake.life=1;/*蛇死*/
					break;
				}
			}
			if(snake.x[0]<3||snake.x[0]>42||snake.y[0]<3||snake.y[0]>22)/*蛇是否撞到牆壁*/
			{
				GameOver();/*顯示失敗,本次遊戲結束*/
				snake.life=1; /*蛇死*/
			}
			if(snake.life==1)/*以上兩種判斷以後,如果蛇死就跳出內循環,重新開始*/
				break;
			if(snake.x[0]==food.x&&snake.y[0]==food.y)/*吃到食物以後*/
			{
				//把畫面上的食物去掉
				gotoxy(food.x,food.y);
				putch(' ');
				/*新的一節先放在看不見的位置,下次循環就取前一節的位置*/
				snake.node++;/*蛇的身體長一節*/
				food.yes=1;/*畫面上需要出現新的食物*/
				DoWin();
				score+=10;
				PrScore();/*輸出新得分*/
			}
			textcolor(LIGHTRED); //畫出蛇
			for(i=0;i<snake.node;i++)
			{
				gotoxy(snake.x[i],snake.y[i]); putch('O');
			}
			if(1) //if(food.yes==1) //用空白去除蛇的最後一節
			{
				gotoxy(snake.x[snake.node-1],snake.y[snake.node-1]);
				putch(' ');
			}
			DoError();
			delay(gamespeed);
		}  /*endwhile(! kbhit)*/
		if(snake.life==1)/*如果蛇死就跳出循環*/
			break;
		ch=getch(); //接收按鍵
		if( ('q' == ch) || ('Q' == ch) ) key = ESC;
		else if( ('w' == ch) || ('W' == ch) ) key = UP;
		else if( ('s' == ch) || ('S' == ch) ) key = DOWN;
		else if( ('a' == ch) || ('A' == ch) ) key = LEFT;
		else if( ('d' == ch) || ('D' == ch) ) key = RIGHT;

		if((ESC==key)||(UP==key)||(DOWN==key)||(LEFT==key)||(RIGHT==key))
			DoOK();

		if(key==ESC)/*按ESC鍵退出*/
			break;
		/*判斷是否往相反的方向移動*/
		else if(key==UP&&snake.direction!=4)
			snake.direction=3;
		else if(key==RIGHT&&snake.direction!=2)
			snake.direction=1;
		else if(key==LEFT&&snake.direction!=1)
			snake.direction=2;
		else if(key==DOWN&&snake.direction!=3)
			snake.direction=4;
	}/*endwhile(1)*/
}
/*遊戲結束*/
void GameOver(void)
{
	clrscr();
	PrScore();
	textcolor(LIGHTBLUE);
	gotoxy(10,10);
	cputs("遊戲結束!");
	getch();
}
/*輸出成績*/
void PrScore(void)
{
	char str[13];
 	sprintf(str,"得分結果:%d",score);
	textcolor(YELLOW);
	gotoxy(10,1);
	cputs(str);
//	outtextxy(55,20,str);
}
/*圖形結束*/
void Close(void)
{
	getch();
}

void DoError(void)
{
	Beep(1200,50);
}

void DoOK(void)
{
	Beep(500,70);
	Beep(600,50);
	Beep(1000,100);
}

void DoWin(void)
{
	Beep(1500,100);
	Beep(0,50);
	Beep(800,100);
	Beep(0,50);
	Beep(1500,100);
	Beep(0,50);
	Beep(800,100);
	Beep(0,50);
}

/*-------------------------------------------------------------------*/
void gotoxy( int column, int line )
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void TextColor_1(int fontcolor,int backgroundcolor,HANDLE screen)
{
	int color_attribute;
	color_attribute = backgroundcolor;
	color_attribute = _rotl(color_attribute,4) | fontcolor;
	SetConsoleTextAttribute(screen,color_attribute);
}

void textcolor(int fontcolor)
{
	HANDLE screen;
	int backgroundcolor = BLACK;
	if(BLACK == fontcolor) backgroundcolor = WHITE;
	screen = GetStdHandle(STD_OUTPUT_HANDLE);
	TextColor_1(fontcolor, backgroundcolor, screen);
}

//timeout值等於多少毫秒
void delay(unsigned timeout)
{
	timeout += clock();
	while(clock() < timeout) continue;
}

void textmode(int mode)
{
	mode = 0;
}

void clrscr(void)
{
	system("cls");
}

void randomize(void)
{
	int i;
	time_t t;
	srand((unsigned) time(&t));
}
