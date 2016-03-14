


#include <graphics.h>
#include<math.h>
#include<time.h>
#include<bios.h>
#define PI 3.1415926
#define ESC 0x011b
float s0=-1,m0=-1,h0=-1;
main()
{
    int gdriver, gmode,key,i=3;
	char H[10];
    float n;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*初始化图形界面*/
    setbkcolor(YELLOW);
	setcolor(BLUE);
	setfillstyle(1,1);
	circle(405,175,22);
	floodfill(405,175,BLUE);
	setfillstyle(1,1);									/*设置填充形式为红色实填充*/
    circle(235,175,22);
	floodfill(235,175,BLUE);
	setfillstyle(1,12);
	circle(320,240,85);
	circle(320, 240, 82);
	floodfill(403,240,BLUE);
    for(n=0;n<=2*PI;n+=PI/30)
	{
		putpixel(320+80 * cos(-n), 240+80 * sin(-n),GREEN); 				/*画标识分钟的小刻度*/
		
    }
    for(n=0;n<=2*PI;n+=PI/6)
	{
		setcolor(BLUE);
		circle(320+80 * cos(-n), 240+80 * sin(-n),1); 				/*画标识小时的大刻度*/
		setfillstyle(SOLID_FILL,LIGHTBLUE);
		floodfill(320+80 * cos(-n), 240+80 * sin(-n),BLUE);
		
    }
	setcolor(GREEN);
    for(n=0;n<=2*PI;n+=PI/6)
	{
		itoa(i,H,10);
		
		outtextxy(317+73 * cos(-n), 237+73 * sin(-n),H);			/*画标识小时的大刻度对应的数字*/
		i--;
		if(i<1)
			i+=12;
    }
	while(!kbhit())
	{
		timer();	
		delay(1000); 
	}
	key=bioskey(0);/*接收键盘按键*/
	if(key==ESC)
	{
		closegraph();
		exit(0);
		
	}	
    getch();
    closegraph();										/*退出图形界面*/
}

timer()
{
	
	struct tm *when;
	float s,m1,h1;
	int h,m;
	time_t now;
	time(&now);
	when= localtime(&now);
	h=when->tm_hour;
	m=when->tm_min;
	s=when->tm_sec;
	h1=(h+(m*60+s)/3600)*PI/6-PI/2;
	m1=(m+s/60)*(PI/30)-PI/2;
	if(s0!=(-1) && m0!=(-1) && h0!=(-1))
	{	setcolor(0);
	line(320,240,320+45*cos(h0),240+45*sin(h0));
	
	line(320,240,320+55*cos(m0),240+55*sin(m0));
	line(320,240,320+65*cos((s0)*(PI/30)+PI/2),240+65*sin((s0)*(PI/30)+PI/2));
	}		
	setcolor(RED);
	line(320,240,320+45*cos(h1),240+45*sin(h1));
	setcolor(LIGHTGRAY);
	line(320,240,320+55*cos(m1),240+55*sin(m1));
	setcolor(BLUE);
	line(320,240,320+65*cos((s)*(PI/30)+PI/2),240+65*sin((s)*(PI/30)+PI/2));
							
	s0=s;
	m0=m1;
	h0=h1;
	
}