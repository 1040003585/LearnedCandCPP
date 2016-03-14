/*------------------------------宏定义-------------------------------------*/
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
/*-----------------------------函数声明--------------------------------------*/
void print(int);						/*显示信息个数和页数*/
void SHOW(int,int );					/*显示记录*/
void Init();							/*初始化图形模式*/
void Drawwin(int,int,int,int,int);		/*画图*/
void Load();							/*初始化数据*/
void Pwd();								/*输入登陆密码*/
void Key();								/*关键算法*/
void Draw();							/*画图*/
void Win(int x,int y,int l,int w);		/*画3D*/
void HELP();							/*帮助函数*/
void EDIT();							/*编辑函数*/
void DELETE();							/*删除函数*/
int ADD();								/*添加函数*/
void SORT();							/*排序函数*/
void SEARCH();							/*检索函数*/
void Loadfile();						/*初始化文件*/
void Savesm() ;							/*记录总数*/
void Quick( );							/*冒泡排序*/
int PAGEUP(int page,int);				/*上翻页函数*/
int PAGEDw(int page,int );				/*下翻页函数*/

#define Move printf("\n\n\n\n\n\n\n\n\n")  /*换行*/
#define ON 1      /*定义开关*/
#define OFF 0
/*-------------------------------定义热键----------------------------------*/
#define ESC 27
#define F2 60
#define A 97
#define S 115
#define O 111
#define H 104
#define E 101
#define D 100
#define Pageup 73
#define Pagedw  81
#define ALL 100      /*文件个数*/

char *red[]={"A","D","E","S","o","H"};                    /*热键显示*/
char *f[]={"Add","Delete","Edit","Search","Sort","Help"};   /*显示菜单*/
char *Hel[]={"ESC:QUIT",                             /*Help内容*/
    "A  : ADD",
    "D  : DELETE",
    "E  : EDIT",
    "S  : SEARCH",
    "O  : SORT",
    "H  : HELP",
    "PAGEDOWN:            ",
    "PAGEUP:              ",
    "Fuction sort:        ",
    "ESC: restore"   };
typedef struct Tel                                       /*建立数组*/
{
 char name[15];
 char telnum[15];
 char Email[20];
 char workpl[30];
}Message;
int sum[1],pg=1;                                               /*文件个数*/
void *buffer,*buff;                                            /*记录画面指针*/

Message msg[ALL],msgtem[ALL];   /*msg为记录文件数组，msgtem为暂时记录排序数组*/
/*-------------------------------主函数---------------------------------*/
main()
{
 Pwd();                                                   /*读入并检验密码*/
 Init();                                                     /*初始文件和界面*/
 Key();                                                   /*核心*/
}
/*-----------------------------初始化图形模式-----------------------------------*/
void Init()
{
 int driver=DETECT,gmode,gcode;
 int i;
 initgraph(&driver,&gmode,"");
 gcode=graphresult();
 if(gcode!=grOk)
 {
  printf("\nGraphics System Error:%s\n",grapherrormsg(gcode));
  getch();
  exit(0);
 }
 Drawwin(100,100,439,250,ON);           /*画图*/
 Drawwin(120,120,399,210,OFF);
 Drawwin(350,150,150,150,ON);
 setcolor(DARKGRAY);
 settextstyle(0,0,8);
 outtextxy(145,179,"TBS");
 setcolor(RED);
 outtextxy(140,173,"TBS");
 setcolor(LIGHTBLUE);
 settextstyle(0,0,2);
 outtextxy(145,310,"Telephone Book System");
 setcolor(RED);
 settextstyle(0,0,1);
 outtextxy(260,245,"Version 1.0");
 setcolor(BLUE);
 settextstyle(0,0,1);
 outtextxy(360,175,"MingriSoft");
 /*outtextxy(380,190,"03 Computer 2");*/
 outtextxy(387,205,"2011-04-26");
 outtextxy(380,220,"CaoFeifei");
 Load();                  /*初始化数据*/
 while(!kbhit());                                         /*按键退出*/
 closegraph();                /*关闭图形模式*/
}

/*-----------------------------3D界面------------------------------------------------*/
void Drawwin(int x,int y,int l,int w,int sta)
{
 setfillstyle(1,LIGHTGRAY);
 bar(x+1,y+1,x+l-1,y+w-1);

 setcolor((sta==ON)?WHITE:DARKGRAY);
 moveto(x,y+w);
 lineto(x,y);
 lineto(x+l,y);
 setcolor((sta==OFF)?WHITE:DARKGRAY);
 moveto(x,y+w);
 lineto(x+l,y+w);
 lineto(x+l,y);
}
/*-------------------------------文件读入-----------------------------------------*/
void Load()
{
 int i,tem=0;
 FILE* fp;
 setcolor(RED);
 outtextxy(365,265,"Load......");
 setfillstyle(1,GREEN);
 bar(351,280,498,290);
 if((fp=fopen("sum.dat","rb"))==NULL)    /*打开sum[0]文件，无，建立*/
 {
  fp=fopen("sum.dat","wb");
  sum[0]=0;
  fwrite(&sum,sizeof(sum[0]),1,fp);
  fp=fopen("sum.dat","rb");
 }
 fread(&sum[0],sizeof(sum),1,fp);
 fclose(fp);
 if((fp=fopen("TBS.dat","rb"))==NULL)    /*打开TBS文件，无，建立*/
 {
  fp=fopen("TBS.dat","wb");
  fp=fopen("TBS.dat","rb");
 }
 for(i=0;i<147;i++)
 {
  setfillstyle(1,LIGHTGREEN);
  bar(351,280,351+i,290);
  delay(1000+tem*100);
  if(tem<sum[0])
  {
   fread(&msg[tem],sizeof(msg),1,fp);  /*初始化数据*/
   tem++;
  }
  }
 fclose(fp);
 setfillstyle(1,LIGHTGRAY);
 bar(351,260,498,290);
 settextstyle(0,0,1);
 setcolor(RED);
 outtextxy(375,260,"Press any key!");
 while(!kbhit());
}
/*--------------------------------输入密码---------------------------------*/
void Pwd()
{
 char *passwrd,*Right="12345";
 char temp[9];
 int i=0;
 Move;                    /*换行*/
 printf("                     Thank you for using this system!\n\n");
 passwrd=getpass("                      Input a password (Not show):");
 strcpy(temp,passwrd);
 while(1)
 {
  Move;
  if(strcmp(temp,Right)!=0)
  {
   i++;
   clrscr();
   Move;
   passwrd=getpass("                         Don't worry!Input again:");
   strcpy(temp,passwrd);
  }
  else
  {
   clrscr();
   break;
  }
  clrscr();
  if(i==3)
  {
   Move;
   printf("                    Sorry!You have enter three times password!\n");
   printf("                         Press any key!");
   getch();
   exit(0);
  }

 }
}
/*-------------------------------核心算法----------------------------------*/
void Key()
{
 char Key;                  /*记录按键*/
 int page=1,i;
 FILE *fp;
 Draw();                   /*画图*/
 buffer=(void *)malloc(2*80*23);
 gettext(1,1,80,23,buffer);             /*记录画面*/
 buff=(void *)malloc(2*80*2);
 gettext(1,23,80,23,buff);
 if(sum[0]%19==0&&sum[0]!=0)            /*计算总页数*/
  pg=sum[0]/19;                /*刚好满页*/
 else
  pg=sum[0]/19+1;               /*不够一页，当一页*/
 SHOW(page,ON);                 /*显示信息，ON为msg，OFF为排序用的*/
 while(1)                   /*进入循环*/
 {
  SHOW(page,ON);
  print(page);

  while(!kbhit());                 /*获取按键*/
  Key=getch();
  switch(Key)
  {
   case A:page=ADD();break;
   case D:DELETE();break;
   case S:SEARCH();break;
   case O:SORT();break;
   case E:EDIT();break;
   case H:HELP();break;
   case Pageup:page=PAGEUP(page,ON);break;
   case Pagedw:page=PAGEDw(page,ON);break;
   case ESC:
    fp=fopen("TBS.dat","wb");
    for(i=0;i<sum[0];i++)
     fwrite(&msg[i],sizeof(Message),1,fp);
    fclose(fp);
    free(buffer);
    free(buff);
    clrscr();
    exit(0);
    break;
  }
  }

}
/*----------------------------文本模式下的画面----------------------------*/
void Draw()
{
 int x,y,i,l;
 textmode(C80);/*文本模式80列彩色的*/
   textbackground(BLACK);/*文本的背景颜色*/
 window(1,1,80,23);/*画矩形*/
 textbackground(WHITE);
 window(1,24,80,24);
 clrscr();

 for(i=0;i<6;i++)
 {
  x=wherex();
  y=wherey();
  textcolor(BLACK);
  cprintf("%s",f[i]);
  l=strlen(f[i]);
  gotoxy(x,y);
  textcolor(RED);
  if(i==4)
  {
   gotoxy(x+1,y);
   cprintf("%s",red[i]);
  }
  else
   cprintf("%s",red[i]);
  x=x+l+8;
  gotoxy(x,y);
 }
 textbackground(BLACK);
 window(1,1,80,23);
 Win(1,1,78,21);
 textcolor(YELLOW);
 gotoxy(7,2);
 cprintf("Name");
 gotoxy(22,2);
 cprintf("Telphone");
 gotoxy(43,2);
 cprintf("QQ");
 gotoxy(60,2);
 cprintf("Workplace");
 textcolor(WHITE);

}
/*---------------------------文本模式下的作图-------------------------------*/
void Win(int x,int y,int l,int w)
{
 int i,j;
 gotoxy(x,y);
 putch(213);
 for(j=0;j<2;j++)
 {
  for(i=0;i<15;i++)       putch(205);
  putch(209);
 }
 for(i=0;i<20;i++) putch(205);
 putch(209);
 for(i=0;i<25;i++) putch(205);
 putch(184);
 for(i=0;i<20;i++)
 {
  gotoxy(x,y+1+i);
  putch(179);
  gotoxy(17,y+1+i);
  putch(179);
  gotoxy(33,y+1+i);
  putch(179);
  gotoxy(54,y+1+i);
  putch(179);
  gotoxy(x+l+1,y+1+i);
  putch(179);
 }
 gotoxy(x,y+w);
 putch(192);
 for(j=0;j<2;j++)
 {
  for(i=0;i<15;i++)       putch(196);
  putch(193);
 }
 for(i=0;i<20;i++) putch(196);
 putch(193);
 for(i=0;i<25;i++) putch(196);
   putch(217);
 textcolor(WHITE);
}
/*--------------------------------显示帮助信息-----------------------------*/
void HELP()
{
 void *buf;
 int i;
 buf=(void *)malloc(2*80*24);
 gettext(1,1,80,23,buf);
 puttext(1,1,80,23,buffer);
 textcolor(YELLOW);
 textbackground(BLUE);
 for(i=0;i<11;i++)
 {
  gotoxy(27,7+i);
  cprintf("%s",Hel[i]);
 }
 while(!kbhit());
 textbackground(BLACK);
 puttext(1,1,80,23,buf);
 textcolor(WHITE);
 free(buf);
}
/*----------------------------------修改函数------------------------------*/
void EDIT()
{
 char name[20];
 Message t[1];
 FILE* fp=fopen("TBS.dat","wb");
 int i,find=0,num=0;
   gotoxy(1,23);
 delline();
 cprintf("Name:");                                             /*读取要编辑的名字*/
 cscanf("%s",&name);                                           /*比较文件*/
 for(i=0;i<sum[0];i++)
 {
  if(strcmp(name,msg[i].name)==0)
  {                                                          /*找到 find＝1*/
   find=1;                                                 /*num记录位置*/
   num=i;
  }
 }
 puttext(1,23,80,23,buff);
 if(find!=1)
 {
  gotoxy(1,23);
  delline();
  cprintf("Not found");
  while(!kbhit() );
 }
 else
 {
  gotoxy(1,23);                                              /*重新输入*/
  cprintf("New name:");
  cscanf("%s",t[0].name);
  delline();
  cprintf("Telphone number:");
  cscanf("%s",t[0].telnum);
  delline();
  cprintf("QQ:");
  cscanf("%s",t[0].Email);
  delline();
  cprintf("Work place:");
  cscanf("%s",t[0].workpl);
  delline();
  strcpy(msg[num].name,t[0].name);                          /*复制*/
  strcpy(msg[num].telnum,t[0].telnum);
  strcpy(msg[num].workpl,t[0].workpl);
  strcpy(msg[num].Email,t[0].Email);
  for(i=0;i<sum[0];i++)                                     /*写入文件*/
  fwrite(&msg[i],sizeof(Message),1,fp);
  fclose(fp);
  cprintf("success!");
  while(!kbhit());
  SHOW(1,ON);
 }
}
/*-----------------------------删除函数-----------------------------------*/
void DELETE()
{
 FILE *fp;
 char name[20];
 int i,num=0,find=0;
 gotoxy(1,23);
 delline();
 cprintf("Name:");
 cscanf("%s",&name);                                        /*读取要删除的名字*/
 for(i=0;i<sum[0];i++)
 {                                                          /*搜索*/
  if(strcmp(name,msg[i].name)==0)
  {
   find=1;
   num=i;
   break;
  }
 }
 if(find!=1)
 {
  gotoxy(1,23);
  delline();
  cprintf("Not found");
  while(!kbhit() );
 }
 else
 if(num==sum[0]&&sum[0]>0)
 {
  sum[0]--;
 }
 else
 {
  for(i=num;i<sum[0];i++)                                 /*写入文件*/
  {
   strcpy(msg[i].name,msg[i+1].name);
   strcpy(msg[i].telnum,msg[i+1].telnum);
   strcpy(msg[i].workpl,msg[i+1].workpl);
   strcpy(msg[i].Email,msg[i+1].Email);
  }
  sum[0]--;
 }
 fp=fopen("TBS.dat","wb");
 for(i=0;i<sum[0];i++)
  fwrite(&msg[i],sizeof(Message),1,fp);
 fclose(fp);
 Savesm();
 SHOW(1,ON);
}
/*---------------------------------添加函数-------------------------------*/
int ADD()
{
 FILE* fp;
 int i;
 Message t[1];

 puttext(1,23,80,23,buff);
 gotoxy(1,23);                                               /*读取信息*/
 cprintf("New name:");
 cscanf("%s",t[0].name);
 delline();
 cprintf("Telphone number:");
 cscanf("%s",t[0].telnum);
 delline();
 cprintf("QQ:");
 cscanf("%s",t[0].Email);
 delline();
 cprintf("Work place:");
 cscanf("%s",t[0].workpl);
 delline();
 sum[0]++;
 strcpy(msg[sum[0]-1].name,t[0].name);
 strcpy(msg[sum[0]-1].Email,t[0].Email);
 strcpy(msg[sum[0]-1].workpl,t[0].workpl);
 strcpy(msg[sum[0]-1].telnum,t[0].telnum);
 fp=fopen("TBS.dat","wb");
 for(i=0;i<sum[0];i++)
  fwrite(&msg[i],sizeof(Message),1,fp);
 fclose(fp);
 Savesm();
 cprintf("Success!");
 while(!kbhit());
 puttext(1,1,80,23,buffer);
 if(sum[0]%19==0&&sum[0]!=0)
  pg=sum[0]/19;
 else
  pg=sum[0]/19+1;
 return pg;
}
/*----------------------------排序函数-----------------------------------*/
void SORT()
{
 int Key,i,p=1;
 FILE *fp=fopen("TBS.dat","rb");
 for(i=0;i<sum[0];i++)
  fread(&msgtem[i],sizeof(Message),1,fp);              /*更新信息，写入msgtem*/
 fclose(fp);
 Quick();                                                /*排序*/
 while(1)
 {
  SHOW(p,OFF);
  print(p);
  while(!kbhit());
  Key=getch();
  switch(Key)
  {
   case Pageup:p=PAGEUP(p,OFF);break;
   case Pagedw:p=PAGEDw(p,OFF);break;
   case ESC:goto AA;
  }
 }
 AA:;
}
/*----------------------------搜索函数-----------------------------------*/
void SEARCH()
{
  char name[20];
   int i,find=0,num=0;
 FILE* fp=fopen("TBS.dat","rb");
 for(i=0;i<sum[0];i++)
  fread(&msg[i],sizeof(Message),1,fp);
 fclose(fp);
 fp=fopen("sum.dat","rb");
 fread(&sum[0],sizeof(Message),1,fp);
 fclose(fp);
 gotoxy(1,23);
 delline();
 cprintf("Name or Telphone:");
 cscanf("%s",&name);
 for(i=0;i<sum[0];i++)
 {
  if(strcmp(name,msg[i].name)==0||strcmp(name,msg[i].telnum)==0)
  {
   find=1;
   num=i;
   break;
  }
 }
 if(find!=1)
 {
  gotoxy(1,23);
  delline();
  cprintf("Not found");
  while(!kbhit() );
 }
 else
 {
  gotoxy(1,23);
  delline();
  cprintf("Result:");
  cprintf("    %s",msg[num].name);
  cprintf("       %s",msg[num].telnum);
  cprintf("       %s",msg[num].Email);
  cprintf("       %s",msg[num].workpl);
  while(!kbhit());
 }
}
/*----------------------------显示电话本信息---------------------------------*/
void SHOW(int page,int sta)
{
 int i,pages=0,n,n1,j=0;
   FILE* fp=fopen("TBS.dat","rb");
   for(i=0;i<sum[0];i++)
  fread(&msg[i],sizeof(Message),1,fp);
   fclose(fp);

 n=sum[0]%19;                                        /*该页行数*/
 pages=sum[0]/19+1;                    /*页数*/
 puttext(1,1,80,23,buffer);
 textcolor(WHITE);
 if(n==0&&sum[0]!=0)
 {
  n=19;
  pages--;
 }
 if(pg==1)
 {
  i=0;
  n1=n;
 }
 else
 if(page<pg)
 {
  i=(page-1)*19;
  n1=(page-1)*19+19;
 }
 else
 if(page==pg)
 {
  i=(page-1)*19;
  n1=(page-1)*19+n;
 }
 if(sta==ON)                                           /*ON为文件内容，off为排序后的内容*/
 {
  if(sum[0]!=0)
  for(;i<n1;i++)
  {
   gotoxy(2,3+j);
   cprintf("%s",msg[i].name);
   gotoxy(18,3+j);
   cprintf("%s",msg[i].telnum);
   gotoxy(34,3+j);
   cprintf("%s",msg[i].Email);
   gotoxy(55,3+j);
   cprintf("%s",msg[i].workpl);
   j++;
  }
 }
 else
 {
  if(sum[0]!=0)
   for(;i<n1;i++)
   {
    gotoxy(2,3+j);
    cprintf("%s",msgtem[i].name);
    gotoxy(18,3+j);
    cprintf("%s",msgtem[i].telnum);
    gotoxy(34,3+j);
    cprintf("%s",msgtem[i].Email);
    gotoxy(55,3+j);
    cprintf("%s",msgtem[i].workpl);
    j++;
   }
 }
}
/*－－－－－－－－－－－－－－－－显示信息－－－－－－－－－－－－－－－－－*/
void print(int apg)
{
 if(sum[0]%19==0&&sum[0]!=0)
  pg=sum[0]/19;
 else
  pg=sum[0]/19+1;
 gotoxy(1,23);
 cprintf("Total:%d     Page :%d/%d   ",sum[0],apg,pg);
}
/*------------------------------记录sum-------------------------------------*/
void Savesm()
{
 FILE* fp;
 fp=fopen("sum.dat","wb");
 fwrite(&sum[0],sizeof(sum),1,fp);
 fclose(fp);
}
/*-------------------------------冒泡排序------------------------------------*/
void Quick()
{
 int i,j;
 char name[20];
 Message tem[1];
 for(j=0;j<sum[0]-1;j++)
  for(i=0;i<sum[0]-1-j;i++)
  {
   if(strcmp(msgtem[i].name,msgtem[i+1].name)>0)
   {
    strcpy(tem[0].name,msgtem[i].name);
    strcpy(tem[0].telnum,msgtem[i].telnum);
    strcpy(tem[0].Email,msgtem[i].Email);
    strcpy(tem[0].workpl,msgtem[i].workpl);
    strcpy(msgtem[i].name,msgtem[i+1].name);
    strcpy(msgtem[i].telnum,msgtem[i+1].telnum);
    strcpy(msgtem[i].Email,msgtem[i+1].Email);
    strcpy(msgtem[i].workpl,msgtem[i+1].workpl);
    strcpy(msgtem[i+1].name,tem[0].name);
    strcpy(msgtem[i+1].telnum,tem[0].telnum);
    strcpy(msgtem[i+1].Email,tem[0].Email);
    strcpy(msgtem[i+1].workpl,tem[0].workpl);
   }
  }
}


int PAGEUP(int page,int sta)
{
 int n=page;
 if(pg==page)
  goto AA;
 else
 {
  page++;
  n++;
 }
 puttext(1,1,80,23,buffer);
 AA:SHOW(n,sta);
 return page;
}

int PAGEDw(int page,int sta)
{
 int n=page;
 if(page==1)
  goto AA;
 else
 {
  page--;
  n--;
 }
 puttext(1,1,80,23,buffer);
 AA:SHOW(n,sta);
 return page;
}
