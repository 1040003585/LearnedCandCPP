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
	int x;/*��������y��*/
	int y;/*�������a�y��*/
	int yes;/*�P�_�O�_�n�X�{�������ܶq,1�ݭn�X�{����*/
}food;/*���������c��*/
struct Snake
{
	int x[N];/*�D����y��*/
	int y[N];/*�D���a�y��*/
	int node;/*�D���`��*/
	int direction;/*�D���ʤ�V*/
	int life;/*�D���ͩR,0����,1���`*/
}snake;/*�D�����c��*/

int i,key;
int score=0;/*�o��*/
int gamespeed=500;/*�C���t�צۤv�վ�*/

void Init(void);/*�ϧ��X��*/
void Close(void);/*�ϧε���*/
void DrawK(void);/*�}�l�e��*/
void GameOver(void);/*�����C��*/
void GamePlay(void);/*���C������L�{*/
void PrScore(void);/*��X���Z*/
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

/*�D���*/
void main(void)
{
	Init();/*�ϧ��X��*/
	DrawK();/*�}�l�e��*/
	GamePlay();/*���C������L�{*/
	Close();/*�ϧε���*/
}
/*�ϧ��X��*/
void Init(void)
{
	const char *User_Guide[]=
	{
		" ",
		"�o�O��r�Ҧ����g�Y�D",
		" �ާ@�Ҧ��p�U:",
		" ��W--�D���Y�V�W",
		" ��S--�D���Y�V�U",
		" ��A--�D���Y�V��",
		" ��D--�D���Y�V�k",
		" ��Q--�����C��",
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
/*�}�l�e��,���W���y�Ь�(2,2),�k�U���y�Ь�(43,23)������*/
void DrawK(void)
{
	textcolor(LIGHTBLUE);//�]�m�C��
        for(i=2;i<=43;i++)
	{
		gotoxy(i,2); putch('-'); //�W��
		gotoxy(i,23); putch('-'); //�U��
	}
        for(i=2;i<=23;i++)
	{
		gotoxy(2,i); putch('|'); //����
		gotoxy(43,i); putch('|'); //�k��
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

/*���C������L�{*/
void GamePlay(void)
{
	char ch;
	randomize();/*�H���Ƶo�;�*/
	food.yes=1;/*1��ܻݭn�X�{�s����,0��ܤw�g�s�b����*/
	snake.life=0;/*����*/
	snake.direction=1;/*��V�V�k*/
	snake.x[0]=5;snake.y[0]=12;/*�D�Y*/
	snake.x[1]=4;snake.y[1]=12;
	snake.node=2;/*�`��*/
	PrScore();/*��X�o��*/
	while(1)/*�i�H���ƪ��C��,��ESC�䵲��*/
	{
		while(!kbhit())/*�b�S�����䪺���p�U,�D�ۤv���ʨ���*/
		{
			if(food.yes==1)/*�ݭn�X�{�s����*/
			{
				food.x=rand()%40+3;
				food.y=rand()%20+3;
				food.yes=0;/*�e���W�������F*/
			}
			if(food.yes==0)/*�e���W�������F�N�n���*/
			{
				textcolor(LIGHTGREEN);
				gotoxy(food.x,food.y);
				putch('*');
			}
			for(i=snake.node-1;i>0;i--)/*�D���C�����`���e����,�]�N�g�Y�D�������k*/
			{
				snake.x[i]=snake.x[i-1];
				snake.y[i]=snake.y[i-1];
			}
			/*1,2,3,4��ܥk,��,�W,�U�|�Ӥ�V,�q�L�o�ӧP�_�Ӳ��ʳD�Y*/
			switch(snake.direction)
			{
				case 1: snake.x[0]++;break;
				case 2: snake.x[0]--;break;
				case 3: snake.y[0]--;break;
				case 4: snake.y[0]++;break;
			}
			for(i=3;i<snake.node;i++)/*�q�D���ĥ|�`�}�l�P�_�O�_����ۤv�F,�]���D�Y����`,�ĤT�`���i���L��*/
			{
				if(snake.x[i]==snake.x[0]&&snake.y[i]==snake.y[0])
				{
					GameOver();/*��ܥ���,�����C������*/
					snake.life=1;/*�D��*/
					break;
				}
			}
			if(snake.x[0]<3||snake.x[0]>42||snake.y[0]<3||snake.y[0]>22)/*�D�O�_�������*/
			{
				GameOver();/*��ܥ���,�����C������*/
				snake.life=1; /*�D��*/
			}
			if(snake.life==1)/*�H�W��اP�_�H��,�p�G�D���N���X���`��,���s�}�l*/
				break;
			if(snake.x[0]==food.x&&snake.y[0]==food.y)/*�Y�쭹���H��*/
			{
				//��e���W�������h��
				gotoxy(food.x,food.y);
				putch(' ');
				/*�s���@�`����b�ݤ�������m,�U���`���N���e�@�`����m*/
				snake.node++;/*�D��������@�`*/
				food.yes=1;/*�e���W�ݭn�X�{�s������*/
				DoWin();
				score+=10;
				PrScore();/*��X�s�o��*/
			}
			textcolor(LIGHTRED); //�e�X�D
			for(i=0;i<snake.node;i++)
			{
				gotoxy(snake.x[i],snake.y[i]); putch('O');
			}
			if(1) //if(food.yes==1) //�Ϊťեh���D���̫�@�`
			{
				gotoxy(snake.x[snake.node-1],snake.y[snake.node-1]);
				putch(' ');
			}
			DoError();
			delay(gamespeed);
		}  /*endwhile(! kbhit)*/
		if(snake.life==1)/*�p�G�D���N���X�`��*/
			break;
		ch=getch(); //��������
		if( ('q' == ch) || ('Q' == ch) ) key = ESC;
		else if( ('w' == ch) || ('W' == ch) ) key = UP;
		else if( ('s' == ch) || ('S' == ch) ) key = DOWN;
		else if( ('a' == ch) || ('A' == ch) ) key = LEFT;
		else if( ('d' == ch) || ('D' == ch) ) key = RIGHT;

		if((ESC==key)||(UP==key)||(DOWN==key)||(LEFT==key)||(RIGHT==key))
			DoOK();

		if(key==ESC)/*��ESC��h�X*/
			break;
		/*�P�_�O�_���ۤϪ���V����*/
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
/*�C������*/
void GameOver(void)
{
	clrscr();
	PrScore();
	textcolor(LIGHTBLUE);
	gotoxy(10,10);
	cputs("�C������!");
	getch();
}
/*��X���Z*/
void PrScore(void)
{
	char str[13];
 	sprintf(str,"�o�����G:%d",score);
	textcolor(YELLOW);
	gotoxy(10,1);
	cputs(str);
//	outtextxy(55,20,str);
}
/*�ϧε���*/
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

//timeout�ȵ���h�ֲ@��
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
