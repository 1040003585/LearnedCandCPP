#include<graphics.h>
#include<math.h>
#include<conio.h>
void flower(int x,int y, COLORREF c){
	int x1,x2,y1,y2;
	int d =15;
	double e;
	setcolor(c);
	for(double a=0;a<2*PI;a+=PI/360)
	{
		e=d*(1+sin(a*5));
		x1=int(x+e*cos(a));
		y1=int(y+e*sin(a));
		x2=int(x+e*cos(a+PI/5));
		y2=int(y+e*sin(a+PI/5));
		line(x1,y1,x2,y2);
	}
} 
void tie(int x,int y,COLORREF c){
	int x1,x2,y1,y2;
	int d=80;
	double e;
	setcolor(c);
	for(double a=0;a<2*PI;a+=PI/360)
	{
		e=d*(1+sin(a*5));
		x1=int(x+e*cos(a));
		y1=int(y+e*sin(a));
		x2=int(x+e*cos(a+PI/9));
		y2=int(y+e*sin(a+PI/9)/4.5);
		line(x1,y1,x2,y2);
	}
}
void main()
{
	initgraph(640,480);
	//»­Ö¦¸É
	setcolor(GREEN);
	line(189,3372,180,400); 
	line(310,160,325,68); 
	line(310,160,325,374); 
	line(150,140,189,374); 
	line(430,176,190,374); 
	line(370,110,187,374); 
	line(250,72,189,372); 
	line(253,192,190,374); 
	line(189,372,287,400); 
	line(189,372,182,400);
	line(189,372,200,120); 
	
	//»­»¨¶ä
	flower(320,160,RED); 
	flower(200,120,YELLOW); 
	flower(150,140,LIGHTRED); 
	flower(430,176,RGB(255,127,0)); 
	flower(370,110,RGB(239,179,52)); 
	flower(250,72,RGB(235,95,186)); 
	flower(325,68,RGB(228,119,98)); 
	flower(253,68,RGB(247,169,117)); 
	
	//»­ºûµû½á
	tie(195,354,LIGHTMAGENTA);
	
	//ÍË³ö 
	getch() ;
	closegragh();

}
