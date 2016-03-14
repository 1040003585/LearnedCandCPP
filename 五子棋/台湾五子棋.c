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
#define CROSSRU 0xbf //�k�W���I
#define CROSSLU 0xda //���W���I
#define CROSSLD 0xc0 //���U���I
#define CROSSRD 0xd9 //�k�U���I
#define CROSSL 0xc3  //����
#define CROSSR 0xb4  //�k��
#define CROSSU 0xc2  //�W��
#define CROSSD 0xc1  //�U��
#define CROSS 0xc5   //�Q�r��e�I
*/

/*�w�q�ѽL���W���I�b�̹��W����m*/
#define MAPXOFT 5
#define MAPYOFT 2

/*�w�q1�����a���ާ@����X*/
#define PLAY1UP    0x1157/*�W��--'W'*/
#define PLAY1DOWN  0x1f53/*�U��--'S'*/
#define PLAY1LEFT  0x1e41/*����--'A'*/
#define PLAY1RIGHT 0x2044/*�k��--'D'*/
#define PLAY1DO    0x3920/*���l--�ť���*/

/*�w�q2�����a���ާ@����X*/
#define PLAY2UP    0x4800/*�W��--��V��up*/
#define PLAY2DOWN  0x5000/*�U��--��V��down*/
#define PLAY2LEFT  0x4b00/*����--��V��left*/
#define PLAY2RIGHT 0x4d00/*�k��--��V��right*/
#define PLAY2DO    0x1c0d/*���l--�^����Enter*/

/*�Y�Q�b�C�����~�h�X,�i��Esc��*/
#define ESCAPE 0x011b

/*�w�q�ѽL�W��e�I�����A,�Y���I���L�Ѥl*/
/*�Y���Ѥl,��������X�O���Ӫ��a���Ѥl*/
#define CHESSNULL 0 /*�S���Ѥl*/
#define CHESS1 'O'/*�@�����a���Ѥl*/
#define CHESS2 'X'/*�G�����a���Ѥl*/

/*�w�q�������O*/
#define KEYEXIT 0/*�h�X��*/
#define KEYFALLCHESS 1/*���l��*/
#define KEYMOVECURSOR 2/*���в�����*/
#define KEYINVALID 3/*�L����*/

/*�w�q�Ÿ��`�q:�u,��---�u��1,����0*/
#define TRUE 1
#define FALSE 0

/*----------------------------------------*/
//�ݭn�ۦ�w�q�U���C�⪺�ƭ�,�_�h�P�_�{���줣���
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
/* �w�q�ƾڵ��c */

/*�ѽL��e�I�y�Ъ��ƾڵ��c*/
struct point
{
	int x,y;
};

/**********************************************************/
/*�۩w�q��ƭ쫬����*/
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
//�ɧUTC2.0��,��VC6.0�S�������
void gotoxy( int column, int line );
void textcolor(int fontcolor);
void delay(unsigned timeout);
void textmode(int mode);
void clrscr(void);
/*------------------------------------------------------*/

/**********************************************************/

/**********************************************************/
/*�w�q�����ܶq*/
int gPlayOrder; /*���ܷ�e��Ѥ�*/
struct point gCursor; /*���Цb�ѽL�W����m*/
char gChessBoard[19][19]; /*�Ω�����ѽL�W�U�I�����A*/
/**********************************************************/

/**********************************************************/
/*�D���*/
void main()
{
	int press;
	int bOutWhile=FALSE; /*�h�X�`���лx*/
	printf("�w��j�a�ӨϥΤ��l�ѵ{��!");
	delay(1000);
	Init();/*��l�ƹϹ�,�ƾ�*/

	while(1)
	{
		press=GetKey();/*����Τ᪺�����*/
		switch(CheckKey(press))/*�P�_�������O*/
		{
			/*�O�h�X��*/
			case KEYEXIT:
				clrscr();/*�M��*/
				bOutWhile = TRUE;
				break;

			/*�O���l��*/
			case KEYFALLCHESS:
				if(ChessGo(gPlayOrder,gCursor)==FALSE)/*����*/
					DoError();/*���l���~*/
				else
				{
					DoOK();/*���l���T*/

					/*�p�G��e��Ѥ�Ĺ*/
					if(JudgeWin(gPlayOrder,gCursor)==TRUE)
					{
						DoWin(gPlayOrder);
						bOutWhile = TRUE;/*�h�X�`���лx�m���u*/
					}
					/*�_�h*/
					else
						/*�洫��Ѥ�*/
						ChangeOrder();
					ShowOrderMsg(gPlayOrder);
				}
				break;

			/*�O���в�����*/
			case KEYMOVECURSOR:
				MoveCursor(gPlayOrder,press);
				break;

			/*�O�L����*/
			case KEYINVALID:
				break;
		}

		if(bOutWhile==TRUE)
			break;
	}

	/*�C������*/
	EndGame();
}
/**********************************************************/

/*������l��,�ƾڪ�l��*/
void Init(void)
{
	int i,j;
	char *Msg[]=
	{
		" ",
		"���a1 �ާ@����:",
		" �W��--W",
		" �U��--S",
		" ����--A",
		" �k��--D",
		" ����ʧ@--Z",
		"",
		"���a2 �ާ@����:",
		" �W��--I",
		" �U��--K",
		" ����--J",
		" �k��--L",
		" ����ʧ@--M",
		"",
		"���X�{�������F:",
		" Q",
		NULL,
	};

	/*����謰1�����a*/
	gPlayOrder = CHESS1;

	/*�ѽL�ƾڪ�l��,�ϴѽL�W�Ҧ����I�M�ŰO�Ь��ŴѤl*/
	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			gChessBoard[i][j]=CHESSNULL;

	/*���Ъ�l��m*/
	gCursor.x=gCursor.y=0;

	/*�e�ѽL*/
	textmode(C40);
	DrawMap();

	/*��ܾާ@�仡��*/
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

	/*��ܷ�e��Ѥ�*/
	ShowOrderMsg(gPlayOrder);
	/*���в��ܴѽL�����W���I�B*/
	gotoxy(gCursor.x+MAPXOFT,gCursor.y+MAPYOFT);
}

//�e�X��ӴѽL���覡
void DrawMap(void)
{
	int i,j;

	clrscr();

	for(i=0;i<19;i++)
		for(j=0;j<19;j++)
			DrawCross(i,j);
}

//�ѽL�����N�@���I����ܤ覡
void DrawCross(int x,int y)
{
	gotoxy(x+MAPXOFT,y+MAPYOFT);
	//��ɮ�l�I���Ѥl�O��CHESS1���Ѥl����ܤ覡
	if(gChessBoard[x][y]==CHESS1)
	{
		textcolor(LIGHTGREEN);
		putch(CHESS1);
		return;
	}
	//��ɮ�l�I���Ѥl�O��CHESS2���Ѥl����ܤ覡
	if(gChessBoard[x][y]==CHESS2)
	{
		textcolor(LIGHTRED);
		putch(CHESS2);
		return;
	}

	textcolor(WHITE);

	/*���W����e�I*/
	if(x==0 && y==0)
	{
		putch(CROSSLU);
		return;
	}

	/*���U����e�I*/
	if(x==0 && y==18)
	{
		putch(CROSSLD);
		return;
	}

	/*�k�W����e�I*/
	if(x==18 && y==0)
	{
		putch(CROSSRU);
		return;
	}

	/*�k�U����e�I*/
	if(x==18 && y==18)
	{
		putch(CROSSRD);
		return;
	}

	/*����ɥ�e�I*/
	if(x==0)
	{
		putch(CROSSL);
		return;
	}

	/*�k��ɥ�e�I*/
	if(x==18)
	{
		putch(CROSSR);
		return;
	}

	/*�W��ɥ�e�I*/
	if(y==0)
	{
		putch(CROSSU);
		return;
	}

	/*�U��ɥ�e�I*/
	if(y==18)
	{
		putch(CROSSD);
		return;
	}

	//�ѽL��������e�I
	putch(CROSS);
}

/*�洫��Ѥ�*/
int ChangeOrder(void)
{
	if(gPlayOrder==CHESS1)
		gPlayOrder=CHESS2;
	else
		gPlayOrder=CHESS1;

	return(gPlayOrder);
}

/*��������*/
int GetKey(void)
{
	char lowbyte;
	unsigned int press;
	char ch;

	//�ª��g�k,��bios.h�������,VC6�S��
//	while (bioskey(1) == 0);/*�p�G�Τ�S������,�Ŵ`��*/
//	press=bioskey(0);
//	lowbyte=press&0xff;
//	press=press&0xff00 + toupper(lowbyte);

	//�s������L�Ȫ���k
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

/*���l���~�B�z*/
void DoError(void)
{
	Beep(1200,50);
}

/*Ĺ�ѳB�z*/
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
		cputs("���a1 �ӧQ");
	else
		cputs("���a2 �ӧQ");
	gotoxy(25,21);
	cputs(" \\<^+^>/ ");
	getch();
}

/*����*/
int ChessGo(int Order,struct point Cursor)
{
	/*�p�G��e�����I�O�Ū��S�����Ѥl,�h�i�H��Ѥl*/
	if(gChessBoard[Cursor.x][Cursor.y]==CHESSNULL)
	{
		/*�b��e��m��W���a�ҥN���Ѥl*/
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

/*�P�_��e��Ѥ踨�l��O�_Ĺ��*/
int JudgeWin(int Order,struct point Cursor)
{
	int i;
	for(i=0;i<4;i++)
		/*�P�_�b���w��V�W�O�_���s��5�Ӧ�Ѥ誺�Ѥl*/
		if(JudgeWinLine(Order,Cursor,i))
			return TRUE;
	return FALSE;
}

/*�P�_�ҤU���Ѥl�b��w����V�W,�O�_��5�Ӧ�Ѥ誺�Ѥl�s���@�u*/
int JudgeWinLine(int Order,struct point Cursor,int direction)
{
	int i;
	struct point pos,dpos;
	const int testnum = 5;
	int count;

	switch(direction)
	{
		case 0:/*�b������V����k*/
			//�]�w���誺�_�l�I�y��
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y;
			//�]�w�y�ЭȪ��W���q
			dpos.x=1;
			dpos.y=0;
			break;
		case 1:/*�b������V�U��W*/
			//�]�w�U�誺�_�l�I�y��
			pos.x=Cursor.x;
			pos.y=Cursor.y-(testnum-1);
			//�]�w�y�ЭȪ��W���q
			dpos.x=0;
			dpos.y=1;
			break;
		case 2:/*�b���W�ܥk�U���פ�V*/
			//�]�w���W�誺�_�l�I�y��
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y+(testnum-1);
			//�]�w�y�ЭȪ��W���q
			dpos.x=1;
			dpos.y=-1;
			break;
		case 3:/*�b���U�ܥk�W���פ�V*/
			//�]�w���U�誺�_�l�I�y��
			pos.x=Cursor.x-(testnum-1);
			pos.y=Cursor.y-(testnum-1);
			//�]�w�y�ЭȪ��W���q
			dpos.x=1;
			dpos.y=1;
			break;
	}

	count=0;
	for(i=0; i<testnum*2-1; i++)	/*���էP�_ i<testnum*2-1 */
	{
		if(pos.x>=0 && pos.x<=18 && pos.y>=0 && pos.y<=18)
		{
			//�s��P�w���L�W���Ѥl�����Ѥ誺�Ѥl�ۦP,��testnum��,�Y���u
			if(gChessBoard[pos.x][pos.y]==Order)
			{
				count++;
				if(count>=testnum)
				return TRUE;
			}
			else    //�u�n���@�������Ѥ�ۦP,count�Y�M���s
				count=0;
		}
		pos.x+=dpos.x;
		pos.y+=dpos.y;
	}

	return FALSE;
}

/*���ʥ���*/
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

/*�C�������B�z*/
void EndGame(void)
{
	textcolor(WHITE);
	textmode(C80);
}

/*��ܷ�e��Ѥ�*/
void ShowOrderMsg(int Order)
{
	gotoxy(6,MAPYOFT+20);
	textcolor(LIGHTRED);
	if(Order==CHESS1)
	{
		textcolor(LIGHTGREEN);
		cputs("���a1�U�Ѥl!");
	}
	else
	{
		textcolor(LIGHTRED);
		cputs("���a2�U�Ѥl!");
	}
	gotoxy(gCursor.x+MAPXOFT,gCursor.y+MAPYOFT);
}

/*���l���T�B�z*/
void DoOK(void)
{
	//�ª�TC2.0�q���͹��n���g�k
//	sound(500);
//	delay(70);
//	sound(600);
//	delay(50);
//	sound(1000);
//	delay(100);
//	nosound();

	//�s��VC6.0�q���͹��n���g�k
	Beep(500,70);
	Beep(600,50);
	Beep(1000,100);
}

/*�ˬd�Τ᪺�������O*/
int CheckKey(int press)
{
	if(press==ESCAPE)
		return KEYEXIT;/*�O�h�X��*/

	else if( ( press==PLAY1DO && gPlayOrder==CHESS1) ||
		 ( press==PLAY2DO && gPlayOrder==CHESS2))
		return KEYFALLCHESS;/*�O���l��*/

	else if( press==PLAY1UP || press==PLAY1DOWN ||
		 press==PLAY1LEFT || press==PLAY1RIGHT ||
		 press==PLAY2UP || press==PLAY2DOWN ||
		 press==PLAY2LEFT || press==PLAY2RIGHT)
		return KEYMOVECURSOR;/*�O���в�����*/

	else
		return KEYINVALID;/*����L��*/
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

 
//timeout�ȵ���h�ֻ���
void delay(unsigned timeout)
{
	timeout += clock();
	while(clock() < timeout) continue;
}

void textmode(int mode)
{
	mode = 0;
}

//�M�ſù��e��
void clrscr(void)
{
	system("cls");
}