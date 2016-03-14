#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

#define CROSSRU '+'
#define CROSSLU '+'
#define CROSSLD '+'
#define CROSSRD '+'
#define CROSSL '+'
#define CROSSR '+'
#define CROSSU '+'
#define CROSSD '+'
#define CROSS '+'
/*
#define CROSSRU 0xbf //右上角點
#define CROSSLU 0xda //左上角點
#define CROSSLD 0xc0 //左下角點
#define CROSSRD 0xd9 //右下角點
#define CROSSL 0xc3  //左邊
#define CROSSR 0xb4  //右邊
#define CROSSU 0xc2  //上邊
#define CROSSD 0xc1  //下邊
#define CROSS 0xc5   //十字交叉點
*/

/*定義棋盤左上角點在屏幕上的位置*/
#define MAPXOFT 5
#define MAPYOFT 2

/*定義1號玩家的操作鍵鍵碼*/
#define PLAY1UP    0x1157/*上移--'W'*/
#define PLAY1DOWN  0x1f53/*下移--'S'*/
#define PLAY1LEFT  0x1e41/*左移--'A'*/
#define PLAY1RIGHT 0x2044/*右移--'D'*/
#define PLAY1DO    0x3920/*落子--空白鍵*/

/*定義2號玩家的操作鍵鍵碼*/
#define PLAY2UP    0x4800/*上移--方向鍵up*/
#define PLAY2DOWN  0x5000/*下移--方向鍵down*/
#define PLAY2LEFT  0x4b00/*左移--方向鍵left*/
#define PLAY2RIGHT 0x4d00/*右移--方向鍵right*/
#define PLAY2DO    0x1c0d/*落子--回車鍵Enter*/

/*若想在遊戲中途退出,可按Esc鍵*/
#define ESCAPE 0x011b

/*定義棋盤上交叉點的狀態,即該點有無棋子*/
/*若有棋子,還應能指出是哪個玩家的棋子*/
#define CHESSNULL 0 /*沒有棋子*/
#define CHESS1 'O'/*一號玩家的棋子*/
#define CHESS2 'X'/*二號玩家的棋子*/

/*定義按鍵類別*/
#define KEYEXIT 0/*退出鍵*/
#define KEYFALLCHESS 1/*落子鍵*/
#define KEYMOVECURSOR 2/*光標移動鍵*/
#define KEYINVALID 3/*無效鍵*/

/*定義符號常量:真,假---真為1,假為0*/
#define TRUE 1
#define FALSE 0

/*----------------------------------------*/
//需要自行定義各種顏色的數值,否則判斷程式抓不到值
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
#define C40 40
#define C80 80
/*----------------------------------------*/

/**********************************************************/
/* 定義數據結構 */

/*棋盤交叉點座標的數據結構*/
struct point
{
	int x,y;
};

/**********************************************************/
/*自定義函數原型說明*/
void Init(void);
int GetKey(void);
int CheckKey(int press);
int ChangeOrder(void);
int ChessGo(int Order,struct point Cursor);
void DoError(void);
void DoOK(void);
void DoWin(int Order);
void MoveCursor(int Order,int press);
void DrawCross(int x,int y);
void DrawMap(void);
int JudgeWin(int Order,struct point Cursor);
int JudgeWinLine(int Order,struct point Cursor,int direction);
void ShowOrderMsg(int Order);
void EndGame(void);
/*------------------------------------------------------*/
//補助TC2.0有,但VC6.0沒有的函數
void gotoxy( int column, int line );
void textcolor(int fontcolor);
void delay(unsigned timeout);
void textmode(int mode);
void clrscr(void);
/*------------------------------------------------------*/

/**********************************************************/

/**********************************************************/
/*定義全局變量*/
int gPlayOrder; /*指示當前行棋方*/
struct point gCursor; /*光標在棋盤上的位置*/
char gChessBoard[19][19]; /*用於紀錄棋盤上各點的狀態*/
/**********************************************************/

/**********************************************************/
/*主函數*/
void main()
{
	int press;
	int bOutWhile=FALSE; /*退出循環標誌*/
	printf("歡迎大家來使用五子棋程式!");
	delay(1000);
	Init();/*初始化圖像,數據*/

	while(1)
	{
		press=GetKey();/*獲取用戶的按鍵值*/
		switch(CheckKey(press))/*判斷按鍵類別*/
		{
			/*是退出鍵*/
			case KEYEXIT:
				clrscr();/*清屏*/
				bOutWhile = TRUE;
				break;

			/*是落子鍵*/
			case KEYFALLCHESS:
				if(ChessGo(gPlayOrder,gCursor)==FALSE)/*走棋*/
					DoError();/*落子錯誤*/
				else
				{
					DoOK();/*落子正確*/

					/*如果當前行棋方贏*/
					if(JudgeWin(gPlayOrder,gCursor)==TRUE)
					{
						DoWin(gPlayOrder);
						bOutWhile = TRUE;/*退出循環標誌置為真*/
					}
					/*否則*/
					else
						/*交換行棋方*/
						ChangeOrder();
					ShowOrderMsg(gPlayOrder);
				}
				break;

			/*是光標移動鍵*/
			case KEYMOVECURSOR:
				MoveCursor(gPlayOrder,press);
				break;

			/*是無效鍵*/
			case KEYINVALID:
				break;
		}

		if(bOutWhile==TRUE)
			break;
	}

	/*遊戲結束*/
	EndGame();
}
/**********************************************************/

/*介面初始化,數據初始化*/
void Init(void)
{
	int i,j;
	char *Msg[]=
	{
		" ",
		"玩家1 操作按鍵:",
		" 上移--W",
		" 下移--S",
		" 左移--A",
		" 右移--D",
		" 執行動作--Z",
		"",
		"玩家2 操作按鍵:",
		" 上移--I",
		" 下移--K",
		" 左移--J",
		" 右移--L",
		" 執行動作--M",
		"",
		"跳出程式不玩了:",
		" Q",
		NULL,
	};

	/*先手方為1號玩家*/
	gPlayOrder = CHESS1;

	/*棋盤數據初始化,使棋盤上所有的點清空記憶為空棋子*/
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			gChessBoard[i][j]=CHESSNULL;

	/*光標初始位置*/
	gCursor.x=gCursor.y=0;

	/*畫棋盤*/
	textmode(C40);
	DrawMap();

	/*顯示操作鍵說明*/
	i=0;
	textcolor(BROWN);
	while(Msg[i]!=NULL)
	{
		if(0 == i)
			gotoxy(25,3);
		else gotoxy(25,3+i-1);

		cputs(Msg[i]);
		i++;
	}

	/*顯示當前行棋方*/
	ShowOrderMsg(gPlayOrder);
	/*光標移至棋盤的左上角點處*/
	gotoxy(gCursor.x+MAPXOFT,gCursor.y+MAPYOFT);
}

//畫出整個棋盤的方式
void DrawMap(void)
{
	int i,j;

	clrscr();

	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			DrawCross(i,j);
}

//棋盤中任意一個點的顯示方式
void DrawCross(int x,int y)
{
	gotoxy(x+MAPXOFT,y+MAPYOFT);
	//當時格子點的棋子是放CHESS1的棋子時顯示方式
	if(gChessBoard[x][y]==CHESS1)
	{
		textcolor(LIGHTGREEN);
		putch(CHESS1);
		return;
	}
	//當時格子點的棋子是放CHESS2的棋子時顯示方式
	if(gChessBoard[x][y]==CHESS2)
	{
		textcolor(LIGHTRED);
		putch(CHESS2);
		return;
	}

	textcolor(WHITE);

	/*左上角交叉點*/
	if(x==0 && y==0)
	{
		putch(CROSSLU);
		return;
	}

	/*左下角交叉點*/
	if(x==0 && y==18)
	{
		putch(CROSSLD);
		return;
	}

	/*右上角交叉點*/
	if(x==18 && y==0)
	{
		putch(CROSSRU);
		return;
	}

	/*右下角交叉點*/
	if(x==18 && y==18)
	{
		putch(CROSSRD);
		return;
	}

	/*左邊界交叉點*/
	if(x==0)
	{
		putch(CROSSL);
		return;
	}

	/*右邊界交叉點*/
	if(x==18)
	{
		putch(CROSSR);
		return;
	}

	/*上邊界交叉點*/
	if(y==0)
	{
		putch(CROSSU);
		return;
	}

	/*下邊界交叉點*/
	if(y==18)
	{
		putch(CROSSD);
		return;
	}

	//棋盤中間的交叉點
	putch(CROSS);
}

/*交換行棋方*/
int ChangeOrder(void)
{
	if(gPlayOrder==CHESS1)
		gPlayOrder=CHESS2;
	else
		gPlayOrder=CHESS1;

	return(gPlayOrder);
}

/*獲取按鍵值*/
int GetKey(void)
{
	char lowbyte;
	unsigned int press;
	char ch;

	//舊的寫法,用bios.h內的函數,VC6沒有
//	while (bioskey(1) == 0);/*如果用戶沒有按鍵,空循環*/
//	press=bioskey(0);
//	lowbyte=press&0xff;
//	press=press&0xff00 + toupper(lowbyte);

	//新的取鍵盤值的方法
	ch=getch();
	if(('w' == ch) || ('W' == ch)) press =(int) PLAY1UP;
	if(('s' == ch) || ('S' == ch)) press =(int) PLAY1DOWN;
	if(('a' == ch) || ('A' == ch)) press =(int) PLAY1LEFT;
	if(('d' == ch) || ('D' == ch)) press =(int) PLAY1RIGHT;
	if(('z' == ch) || ('Z' == ch)) press =(int) PLAY1DO;
	if(('i' == ch) || ('I' == ch)) press =(int) PLAY2UP;
	if(('k' == ch) || ('K' == ch)) press =(int) PLAY2DOWN;
	if(('j' == ch) || ('J' == ch)) press =(int) PLAY2LEFT;
	if(('l' == ch) || ('L' == ch)) press =(int) PLAY2RIGHT;
	if(('m' == ch) || ('M' == ch)) press =(int) PLAY2DO;
	if(('q' == ch) || ('Q' == ch)) press =(int) ESCAPE;

	return(press);
}

/*落子錯誤處理*/
void DoError(void)
{
	Beep(1200,50);
}

/*贏棋處理*/
void DoWin(int Order)
{
	Beep(1500,100);
	Beep(0,50);
	Beep(800,100);
	Beep(0,50);
	Beep(1500,100);
	Beep(0,50);
	Beep(800,100);
	Beep(0,50);

	textcolor(RED+BLINK);
	gotoxy(25,20);
	if(Order==CHESS1)
		cputs("玩家1 勝利");
	else
		cputs("玩家2 勝利");
	gotoxy(25,21);
	cputs(" \\<^+^>/ ");
	getch();
}

/*走棋*/
int ChessGo(int Order,struct point Cursor)
{
	/*如果當前的格點是空的沒放任何棋子,則可以放棋子*/
	if(gChessBoard[Cursor.x][Cursor.y]==CHESSNULL)
	{
		/*在當前位置放上玩家所代表的棋子*/
		gotoxy(Cursor.x+MAPXOFT,Cursor.y+MAPYOFT);
		if(CHESS1 == Order)
			textcolor(LIGHTGREEN);
		else
			textcolor(LIGHTRED);
		putch(Order);
		gotoxy(Cursor.x+MAPXOFT,Cursor.y+MAPYOFT);
		gChessBoard[Cursor.x][Cursor.y]=Order;
		return TRUE;
	}
	else
		return FALSE;
}

/*判斷當前行棋方落子後是否贏棋*/
int JudgeWin(int Order,struct point Cursor)
{
	int i;
	for(i=0;i<4;i++)
		/*判斷在指定方向上是否有連續5個行棋方的棋子*/
		if(JudgeWinLine(Order,Cursor,i))
			return TRUE;
	return FALSE;
}

/*判斷所下的棋子在選定的方向上,是否有5個行棋方的棋子連成一線*/
int JudgeWinLine(int Order,struct point Cursor,int direction)
{
	int i;
	struct point pos,dpos;
	const int testnum = 5;
	int count;

	switch(direction)
	{
		case 0:/*在水平方向左到右*/
			//設定左方的起始點座標
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y;
			//設定座標值的增長量
			dpos.x=1;
			dpos.y=0;
			break;
		case 1:/*在垂直方向下到上*/
			//設定下方的起始點座標
			pos.x=Cursor.x;
			pos.y=Cursor.y-(testnum-1);
			//設定座標值的增長量
			dpos.x=0;
			dpos.y=1;
			break;
		case 2:/*在左上至右下的斜方向*/
			//設定左上方的起始點座標
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y+(testnum-1);
			//設定座標值的增長量
			dpos.x=1;
			dpos.y=-1;
			break;
		case 3:/*在左下至右上的斜方向*/
			//設定左下方的起始點座標
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y-(testnum-1);
			//設定座標值的增長量
			dpos.x=1;
			dpos.y=1;
			break;
	}

	count=0;
	for(i=0; i<testnum*2-1; i++)	/*測試判斷 i<testnum*2-1 */
	{
		if(pos.x>=0 && pos.x<=18 && pos.y>=0 && pos.y<=18)
		{
			//連續判定期盤上的棋子都跟行棋方的棋子相同,有testnum次,即為真
			if(gChessBoard[pos.x][pos.y]==Order)
			{
				count++;
				if(count>=testnum)
				return TRUE;
			}
			else    //只要有一次不跟行棋方相同,count即清為零
				count=0;
		}
		pos.x+=dpos.x;
		pos.y+=dpos.y;
	}

	return FALSE;
}

/*移動光標*/
void MoveCursor(int Order,int press)
{
	switch(press)
	{
		case PLAY1UP:
			if(Order==CHESS1&&gCursor.y>0)
				gCursor.y--;
			break;
		case PLAY1DOWN:
			if(Order==CHESS1&&gCursor.y<18)
				gCursor.y++;
			break;
		case PLAY1LEFT:
			if(Order==CHESS1&&gCursor.x>0)
				gCursor.x--;
			break;
		case PLAY1RIGHT:
			if(Order==CHESS1&&gCursor.x<18)
				gCursor.x++;
			break;

		case PLAY2UP:
			if(Order==CHESS2&&gCursor.y>0)
				gCursor.y--;
			break;
		case PLAY2DOWN:
			if(Order==CHESS2&&gCursor.y<18)
				gCursor.y++;
			break;
		case PLAY2LEFT:
			if(Order==CHESS2&&gCursor.x>0)
				gCursor.x--;
			break;
		case PLAY2RIGHT:
			if(Order==CHESS2&&gCursor.x<18)
				gCursor.x++;
			break;
	}

	gotoxy(gCursor.x+MAPXOFT,gCursor.y+MAPYOFT);
}

/*遊戲結束處理*/
void EndGame(void)
{
	textcolor(WHITE);
	textmode(C80);
}

/*顯示當前行棋方*/
void ShowOrderMsg(int Order)
{
	gotoxy(6,MAPYOFT+20);
	textcolor(LIGHTRED);
	if(Order==CHESS1)
	{
		textcolor(LIGHTGREEN);
		cputs("玩家1下棋子!");
	}
	else
	{
		textcolor(LIGHTRED);
		cputs("玩家2下棋子!");
	}
	gotoxy(gCursor.x+MAPXOFT,gCursor.y+MAPYOFT);
}

/*落子正確處理*/
void DoOK(void)
{
	//舊的TC2.0電腦嗶嗶聲的寫法
//	sound(500);
//	delay(70);
//	sound(600);
//	delay(50);
//	sound(1000);
//	delay(100);
//	nosound();

	//新的VC6.0電腦嗶嗶聲的寫法
	Beep(500,70);
	Beep(600,50);
	Beep(1000,100);
}

/*檢查用戶的按鍵類別*/
int CheckKey(int press)
{
	if(press==ESCAPE)
		return KEYEXIT;/*是退出鍵*/

	else if( ( press==PLAY1DO && gPlayOrder==CHESS1) ||
		 ( press==PLAY2DO && gPlayOrder==CHESS2))
		return KEYFALLCHESS;/*是落子鍵*/

	else if( press==PLAY1UP || press==PLAY1DOWN ||
		 press==PLAY1LEFT || press==PLAY1RIGHT ||
		 press==PLAY2UP || press==PLAY2DOWN ||
		 press==PLAY2LEFT || press==PLAY2RIGHT)
		return KEYMOVECURSOR;/*是光標移動鍵*/

	else
		return KEYINVALID;/*按鍵無效*/
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

 
//timeout值等於多少豪秒
void delay(unsigned timeout)
{
	timeout += clock();
	while(clock() < timeout) continue;
}

void textmode(int mode)
{
	mode = 0;
}

//清空螢幕畫面
void clrscr(void)
{
	system("cls");
}