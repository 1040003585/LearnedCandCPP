
// Download by http://www.NewXing.com
/*game.cpp
//////////////////////////////////////////游戏主要///////////
////
*/


#include "stdafx.h"
#include "game.h"
game::game()//构造函数
{}
game::~game()//析构函数
{}



//***************************************************
//游戏进入口
//game::init()
/*
	LPTSTR c =(LPTSTR)(LPCTSTR)cc;
	::itoa(num,c,10);//man[0].jixu;
	if (man[0].p == 0)
	TextOut(Back,10,10,cc,lstrlen(cc));*/
//******************************************
BOOL game::init(CString map)
{	CTime tim;
	::CFont font;
	door++;//关卡增加
	if(door>1)goto start;

	exit();//删除所有缓存
	int a;
	tim=::timeGetTime();
	a=tim.GetHour()+tim.GetMinute()*60+tim.GetSecond()*60*60;
	srand(a);
	over=0;//游戏开始
	GetCurrentDirectory(256,appdir);
	//::AfxMessageBox(appdir);
	sys=4;//Windows NT


	keydown=0;keyup=0;keyleft=0;keyright=0;keyspace=0;//无按键
	keydown2=0;keyup2=0;keyleft2=0;keyright2=0;keyspace2=0;//无按键

	SDC=CreateDC("DISPLAY",NULL,NULL,NULL);///屏幕设备
	bit0  =CreateCompatibleBitmap(SDC,WIDTH,HEIGHT);//创建暂存位图内存0	
	bit1  =CreateCompatibleBitmap(SDC,WIDTH,HEIGHT);//创建暂存位图内存1	
	Back=CreateCompatibleDC(SDC);//地图设备,背景设备
	MemDC=CreateCompatibleDC(SDC);//
	MainDC=CreateCompatibleDC(SDC);//创建主场景设备
	SelectObject(Back,bit0);
	SelectObject(MainDC,bit1);//关联位图

			font.CreateFont( 12,6,0,0,700,0,0,0, ANSI_CHARSET,OUT_DEFAULT_PRECIS, 
			CLIP_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, 
			DEFAULT_PITCH|FF_DONTCARE, 
			"宋体"); 
			::SelectObject(MainDC,font);

  	/*Rotate(Back,w,h,90);//旋转图形TankMain
	Back=dcDst;*/

	SetBkMode(Back,TRANSPARENT);//北京透明
 	cc="坦克游戏(试玩版)";

	SetTextColor(Back,RGB(255,0,0));//设置字体颜色
	TextOut(Back,650,0,cc,lstrlen(cc));//输出文字
start:

	loadmap(map);//读入地图map1.txt
	getpic(mapbak);
	for (int i=0;i<=WIDTH/w;i++)
		for(int j=0;j<=HEIGHT/h;j++)
			BitBlt(Back,i*w,j*h,WIDTH,HEIGHT,MemDC,0,0,SRCCOPY);//读入地图背景


	
	return TRUE;
}
//以下是DirectX程序段////////////////////////////////////
//*************************************************
// 使用DirectX 实现全屏
// 进入DX环境
//*************************************************
bool game::initDX()
{
//功能：初始化DirectDraw环境。
  ddrval=DirectDrawCreate( NULL, &DXW, NULL );
	if(ddrval!= DD_OK ) return FALSE;//创建DirectCraw对象失败返回  
    ddrval=DXW->SetCooperativeLevel(GetActiveWindow(),DDSCL_NORMAL);
	if(ddrval!= DD_OK)  return FALSE;// 取得窗口模式失败返回
    
	ddrval=DXW->SetDisplayMode(800,600,16);
	if(ddrval!= DD_OK) return FALSE;//设置显示模式失败返回
	return TRUE;
	/*
	ddsd.dwSize = sizeof( ddsd );// 创建主显页面 
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps =DDSCAPS_PRIMARYSURFACE;
	ddsd.dwBackBufferCount=1;
    ddrval = DXW->CreateSurface( &ddsd, &DXSPrimary, NULL );
    if( ddrval != DD_OK )   return FALSE;//创建主显页面失败返回 
*/
}
//**************************************************
// ai(int i) //自由行动
//	
//**************************************************
void game::ai(int i)
{

	if(rand()%2==1)fire(i);
	short int t=(10-man[i].lv)*5+50;//思考速度
	if (rand()%2==1)
	{
		if (rand()%2==1)
			man[i].x0+=rand()%t;//右
			if(man[i].x0>784)man[i].x0=man[i].y-t;
		else if(rand()%2==1)
			man[i].x0-=rand()%t;//左

	}else {
	
		if (rand()%2==1)
			man[i].y0+=rand()%t;//下
		if(man[i].y0>584)
			man[i].y0=man[i].y-t;
		else if(rand()%2==1)
			man[i].y0-=rand()%t;//上
	}
	if(man[i].js>2)//跟踪玩家
		for(int j=0;j<num;j++)
			if(man[j].lb==1&&man[j].jixu==player[0]||man[j].jixu==player[1])
			{
				//if(rand()%2==1)
			//	{
					if(man[j].x>man[i].x)
						man[i].x0+=rand()%t;
					else
						man[i].x0-=rand()%t;
			//	}else
			//	{
					if(man[j].y>man[i].y)

						man[i].y0+=rand()%t;
					else
						man[i].y0-=rand()%t;
			//	}

			}
	if(man[i].x0<0||man[i].y0<0)
	{	
		man[i].x0=abs(man[i].x0);
		man[i].y0=abs(man[i].y0);
	}
}



//**************************************************
// Bom() //坦克爆炸
//	
//**************************************************
void game::bom(int x,int y)
{
	//起火
	if (num>=SuLiang)return;//超数
	strcpy(man[num].name,"火");
	man[num].x=x;
	man[num].y=y;
	man[num].x0=x;
	man[num].y0=y;
	man[num].z=0;
	man[num].lb=3;
	man[num].p=0;
	man[num].m0=0;
	man[num].m1=6;
	man[num].over=1;
	man[num].js=0;
	man[num].jixu=num;
	man[num].fw=1;
	num++;
}
//**************************************************
// Delete() //删除
//	删除游戏中的对象。并重整序号
//**************************************************
void game::Delete(int i) //删除
{
		for (int j=i;j<num-1;j++)	
		 	man[j]=man[j+1];//删除gno
	 	num--;//对象数减1
}
//*******************************************
// Music
// 播放mid
//****************************************
void game::Music(CString cc)
{
	cc="sound/"+cc;
	 hMCI = MCIWndCreate(NULL, NULL,WS_POPUP|//WS_VISIBLE|
								MCIWNDF_NOPLAYBAR|MCIWNDF_NOMENU,
								cc);
	 MCIWndPlay(hMCI);
}

//*******************************************
// Sound
// 播放Wav
//****************************************
void game::Sound(CString cc)
{
	SetCurrentDirectory(appdir);
	sndPlaySound("sound/"+cc,SND_ASYNC);
}



//*****************************************
//		对象移动

//***********************************
void game::movman(int i)
{

	if( man[i].lb==3||pause==1)return;//景物
	short int *turn=&man[i].fw,step=man[i].step;//角度<90
	if ( man[i].jixu==player[0]&&man[i].lb==1)//是玩家1
	{

		//1按键情况
		if( keyup==1)
		{
			//*turn=1;
			man[i].y0-=step;
		//	return;
		
		}
		if( keydown==1)
		{
			//*turn=2;
			man[i].y0+=step;
			//char c[10];
			//itoa(man[i].y0,c,10);
		//	AfxMessageBox(c);
	//		return;

		}
		if(keyleft==1)
		{
			//*turn=3;
			man[i].x0-=step;
	//		return;
		}
		if(keyright==1)
		{
			//*turn=4;
			man[i].x0+=step;
	//		return;
		}
		if(keyspace==1)
		{
		
			fire(i);
		}
	}
	if ( man[i].jixu==player[1]&&man[i].lb==1)//是玩家2
	{

		//2按键情况
		if( keyup2==1)
		{
			//*turn=1;
			man[i].y0-=step;
		//	return;
		
		}
		if( keydown2==1)
		{
			//*turn=2;
			man[i].y0+=step;
			//char c[10];
			//itoa(man[i].y0,c,10);
		//	AfxMessageBox(c);
	//		return;

		}
		if(keyleft2==1)
		{
			//*turn=3;
			man[i].x0-=step;
	//		return;
		}
		if(keyright2==1)
		{
			//*turn=4;
			man[i].x0+=step;
	//		return;
		}
		if(keyspace2==1)
		{
		
			fire(i);
		}
	}


	//****************************************
	//判断是否结束生命
	if ( man[i].lb==2 ) //是子弹
		if ( man[i].x==man[i].x0 && man[i].y==man[i].y0 )//到目的地
		{
			man[i].over=1;
			return;
		}



	//***************************************
	//移动位置
	int x=abs(man[i].x0-man[i].x);
	int y=abs(man[i].y0-man[i].y);
	if (man[i].lb==1&&man[i].jixu!=player[0]&&man[i].jixu!=player[1])
	{
		if (x==0&&y==0)
		{
			ai(i);
			return;
		}
		if(man[i].js>2)
			fire(i);
	}
	if(man[i].x0!=man[i].x)
	{
		if(man[i].x0>man[i].x)
		{
			if(look(man[i].x+step,man[i].y,i))//有障碍
				man[i].x+=step;
			else
				man[i].x0=man[i].x;

			*turn=4;
		}
		if(man[i].x0<man[i].x)
		{
			if(look(man[i].x-step,man[i].y,i))//有障碍
				man[i].x-=step;
			else
				man[i].x0=man[i].x;
			*turn=3;
		}
	}else{

		if(man[i].y0>man[i].y)
		{
			if(look(man[i].x,man[i].y+step,i))//有障碍
				man[i].y+=step;
			else
				man[i].y0=man[i].y;
			*turn=2;
		}
		if(man[i].y0<man[i].y)
		{
			if(look(man[i].x,man[i].y-step,i))//有障碍
				man[i].y-=step;
			else
				man[i].y0=man[i].y;
			*turn=1;
		}
	}
	if (x<man[i].step)man[i].x=man[i].x0;
	if (y<man[i].step)man[i].y=man[i].y0;
	
	/*****************************
	// 给该坦克装子弹
	*/
	if (man[i].lb==1)//Tanks
	{
		if(man[i].gun<Okgun-man[i].lv)
			man[i].gun++;
	}
	if (man[i].lb==2)//子弹
	{
		if(man[i].gun<shotmeter)
			man[i].gun++;
	}
	
}


//**************************************************
//  loadbmp(CString cc)//调BMP图片
//  调cc指定的图形;取得的图形在设备相关位图bit中
//  图形的宽、高存于全局变量w,h中
//**************************************************
BOOL game::loadbmp(CString cc)//调BMP图片[2章]
{
	::SetCurrentDirectory(appdir);
	DeleteObject(bitmap);
				//删除上次的位图内存。
	bitmap=(HBITMAP)LoadImage			//调入cc指定的图形
				(AfxGetInstanceHandle(),//
				 cc,IMAGE_BITMAP,		//文件名,位图方式				 			
				 0,0,					//图形宽,高
				 LR_LOADFROMFILE|LR_CREATEDIBSECTION//方式
				);
	if(bitmap == NULL) {TextOut(MainDC,0,0,"找不到图片"+cc,lstrlen("找不到图片"+cc));return FALSE;	}	//调图失败
	DIBSECTION ds;						//
	BITMAPINFOHEADER &bm = ds.dsBmih;	//
	GetObject(bitmap,sizeof(ds),&ds);	//取位图的信息->bminfo
	w = bm.biWidth;						//得到位图宽度值 
	h = bm.biHeight;					//得到位图高度值

	return TRUE;
}

void game::loadbmp2(CString n,CString c)
{
//	DeleteDC(MemDC);
//	DeleteDC(bmp[bmpnum]);
	bmp[bmpnum]=CreateCompatibleDC(0);
	//bmp[bmpnum]=NULL;
	loadbmp(c);
	SelectObject(bmp[bmpnum],bitmap);
	//DeleteObject(bmp[bmpnum]);
	bmpname[bmpnum]=n;
	//bmp[bmpnum]=MemDC;
	//if(bmp[bmpnum]!=bitmap)AfxMessageBox("Error");
	bmpnum++;
}
/////////////////////////////////////////////////////////////////

//**************************************************
//  game::getpic(CString cc)
//  调图片加入HDC
//**************************************************
void game::getpic(CString cc)
{
	
	if (loadbmp(cc) == FALSE)
		TextOut(MainDC,10,10,"调图失败",8); //调图失败
	else
		SelectObject(MemDC,bitmap);//关联位图
		//BitBlt(MainDC,1,1,100,100,MemDC,0,0,SRCCOPY);
}

//**************************************************
//  game::getpic(CString cc)
//  调图片加入HDC
//**************************************************
void game::getpic2(CString p)
{
	for(int i=0;i<bmpnum;i++)
	{
		if (bmpname[i]==p)
		{
			tmpbmp=bmp[i];
			return;
		}
	}
	TextOut(MainDC,0,0,"没有找到图片。",lstrlen("没有找到图片。"));
}
//**************************************************
//  game::exit()
//  离开游戏
//  释放所有变量
//**************************************************
void game::exit()
{

	DeleteObject(bitmap);////位图对象

	DeleteDC(Back);
	DeleteDC(MemDC);
	DeleteDC(SDC);
	DeleteObject(bit0);
	DeleteObject(bit1);
	DeleteObject(oldmak);
	DeleteDC(dcDst);
	DeleteDC(MainDC);
}


//************************************************************
//	LoadMap
//	调入地图数据
//	来源文件
//  设置游戏默认值
//************************************************************
BOOL game::loadmap(CString mapfile)
{
	mapfile="map/"+mapfile;
	FILE *f;
	f=fopen(mapfile,"r");
	if(f == NULL)
	{
		AfxMessageBox("没有地图文件!!!");
		SetCurrentDirectory(appdir);
		return FALSE;
	}
	fscanf(f,"%s\n",mapname);//地图名字
	fscanf(f,"%s\n",mapbak);//地图块
	fscanf(f,"%s\n",nextmap);//读入下一幅地图名字
	fscanf(f,"%d\n",&num);//物体数量
	if(door==1)
	{
		short int num2;
		fscanf(f,"%d",&num2);//玩家数量
		if ( num2==2)
		{
			fscanf(f,"%d",&player[0]);//玩家1
			fscanf(f,"%d",&player[1]);//玩家2
		}else
		{
			fscanf(f,"%d",&player[0]);//玩家1
			player[1]=player[0];
		}
	}else{
		num+=2;
		man[player[0]].HP+=20;
		man[player[1]].HP+=20;
		man[player[0]].z=1;
		man[player[1]].z=1;
		man[player[0]].x=350;
		man[player[1]].x=420;
		man[player[0]].y=530;
		man[player[1]].y=530;
		man[player[0]].x0=man[player[0]].x;
		man[player[1]].x0=man[player[1]].x;
		man[player[0]].y0=man[player[0]].y;
		man[player[1]].y0=man[player[1]].y;
		man[player[0]].step=manStep+man[0].lv/2;//步长
		man[player[1]].step=manStep+man[1].lv/2;//步长
	}
	
	for(int i=0;i<num;i++)
	{
		/*
		1,1,0,玩家,1,100,100,0,0,0,10,
序号,类别(人,物),角色(0玩家控制),名称,等级,坐标X,坐标Y
		,方位(角度),图形号(),初始值,结束值,目标位置X,*/
		if(door>1&&man[i].lb==1&&(man[i].jixu==player[0]||man[i].jixu==player[1]))continue;
		fscanf(f,"%d ",&man[i].jixu);//读入序号
		fscanf(f,"%d ",&man[i].lb);//读入类别
		fscanf(f,"%d ",&man[i].js);//读入角色
		fscanf(f,"%s ",man[i].name);//读入名称
		fscanf(f,"%d ",&man[i].HP);//体力
		fscanf(f,"%d ",&man[i].MP);//攻击力
		fscanf(f,"%d ",&man[i].BP);//防御力
		fscanf(f,"%d ",&man[i].lv);//等级
		fscanf(f,"%d ",&man[i].x);//读入X
		fscanf(f,"%d ",&man[i].y);//读入y
		fscanf(f,"%d ",&man[i].fw);//读入方位
		if(man[i].lb==1)man[i].z=1;else man[i].z=0;
		man[i].over=0;
		man[i].p=0;//默认图形号
		man[i].exp=0;//经验0
		man[i].exp2=50;
		man[i].step=manStep+man[i].lv/2;//步长
		if(man[i].x==0)
			man[i].x=rand()%780;
		if(man[i].y==0)
			man[i].y=rand()%550;
		man[i].m1=1;
		man[i].m0=0;
		man[i].p=man[i].m0;//初始化图形.
		man[i].x0=man[i].x;
		man[i].y0=man[i].y;//停止走动.
		man[i].gun=UpGun;//装子弹
	}
	
	SetCurrentDirectory(appdir);//置当前目录
	gtime=0;//游戏时间＝0
	return TRUE;

}


//**********************************************************
//  sort() 排序(冒泡法)
//  将num个对象序列对Y位置进行排序;用于在显示时分出前后位置。
//**********************************************************
void game::sort()//排序(冒泡法)
{	Obj man0;
	for(int a=0;a<num-1;a++)
	 for(int b=a+1;b<num;b++)
		if(man[a].y>man[b].y)//前数大于后数
			{man0=man[a];		 //两数交换
			 man[a]=man[b];
			 man[b]=man0;
			}					 //排序结果，当前位置Y小的在前。							
	//mans=0;						 //显示区对象数置0
}

//**********************************************************************
//  TransparentBlt2 (......)透明显示
//  根据关键色，将hdc1中的图形在hdc0中
//  自动生成掩模，并生成透明图形。
//	注:TransparentBlt(......)是一个WIN API函数，功能和这里的相同。
//	在WIN2000和以后的系统上可用。在WIN98中有严重的资源泄漏，根本不能用。
//  使用TransparentBlt(......)前，需引用:
//  #include <wingdi.h>
//  #pragma comment (lib,"msimg32.lib")
//**********************************************************************
void game::TransparentBlt2(HDC hdc0,			//目标DC
				int nX0,int nY0,int nW0,int nH0,//目标左坐标,目标宽高宽
				HDC hdc1,						//源DC
				int nX1,int nY1,int nW1,int nH1,//源起点坐标,源宽高宽
				UINT Tcol)						//透明色,COLORREF类型
					 
{	/*
	if(sys>1)//是win98以上的系统，直接调API函数TransparentBlt()
	{TransparentBlt(hdc0,nX0,nY0,nW0,nH0,hdc1,nX1,nY1,nW1,nH1,Tcol);
	 return;
	}
	*/
	HBITMAP hBMP   =CreateCompatibleBitmap(hdc0,nW0, nH0);	//创建位图内存
	HBITMAP mBMP   =CreateBitmap(nW0,nH0,1,1,NULL);			//创建单色掩码位图
	HDC		hDC    =CreateCompatibleDC(hdc0);				//创建设备句柄
	HDC		mDC    =CreateCompatibleDC(hdc0);				//创建设备句柄
	HBITMAP oldBMP =(HBITMAP)SelectObject(hDC, hBMP);
	HBITMAP oldmBMP=(HBITMAP)SelectObject(mDC, mBMP);
	// 将源DC中的位图拷贝到临时DC中
	if (nW0==nW1&&nH0==nH1)
		BitBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,SRCCOPY);
	else
		StretchBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,nW1,nH1,SRCCOPY);
	SetBkColor(hDC, Tcol);// 设置透明色
	BitBlt(mDC,0,0,nW0,nH0,hDC,0,0,SRCCOPY);//生成透明区域为白色,其它区域为黑色的掩码位图

	SetBkColor(hDC, RGB(0,0,0));			//生成透明区域为黑色,其它区域保持不变的位图
	SetTextColor(hDC, RGB(255,255,255));	//白色
	BitBlt(hDC,0,0,nW0,nH0,mDC,0,0,SRCAND);
	SetBkColor(hdc0,RGB(255,255,255));		//透明部分保持屏幕不变,其它部分变成黑色
	SetTextColor(hdc0,RGB(0,0,0));			//黑色

	BitBlt(hdc0,nX0,nY0,nW0,nH0,mDC,0,0,SRCAND);  //"与"运算,在hdc0生成掩模
	BitBlt(hdc0,nX0,nY0,nW0,nH0,hDC,0,0,SRCPAINT);//"或"运算,生成最终透明效果	
	SelectObject(hDC,oldBMP);
	SelectObject(mDC,oldmBMP);
	DeleteDC(hDC);
	DeleteDC(mDC);
	DeleteObject(hBMP);
	DeleteObject(mBMP);
}
//********************************************************************
///////////////  障碍  //////////////////
//				Look
//2005.2.13
//**********************************************
bool game::look(int x,int y,short j)
{
	bool x1=man[j].jixu==player[0]||man[j].jixu==player[1];//非玩家
	if ( man[j].lb!=1)return true;
	for(int i=0;i<num;i++)
	{
		if(abs(man[i].x-x)<man[i].w/2+man[j].w/2 && abs(man[i].y-y)<man[i].h/2+man[j].h/2)
		{
			if(man[i].lb==1&&i!=j)
			{	
					bool x0=man[i].jixu==player[0]||man[i].jixu==player[1];//是玩家
				if((x0&&x1)||(!x0&&!x1)) continue;
		//		if(abs(man[i].x-man[j].x)<man[j].w || abs(man[i].y-man[j].y)<man[j].h)continue;
				if(abs(x-man[i].x)<man[i].w&&abs(y-man[i].y)<man[i].h)
				return false;
			}
		  	else if(man[i].lb==3&&(y-man[i].y)<man[j].h/2&&man[i].js!=0&&(y-man[i].y)>0)//景物
	 	  		return false;
		}
	//	
	}
	if (x>784||x<16||y>584||y<16)return false;
	return true;
}

//********************************************************************
///////////////  对象相遇  //////////////////
//				LookIt
//2005.2.8
//**********************************************
BOOL game::lookit(int i)
{
	
	if (man[i].lb==3&&man[i].js==0)return FALSE;//子弹FALSE
	for(int q=0;q<num;q++)
	{	if(q==i)continue;				//是自己
		 if(man[q].lb==3) continue;		//是景
		 int x=man[i].x-man[q].x;	//取q,i对象的位置差
		 int y=man[i].y-man[q].y;	//
		 if(abs(x)<man[q].w*3 && abs(y)<man[q].h*3)//相遇
		 {
			 if(man[q].lb==2&&man[q].gun>=shotmeter)//子弹
			 {
				bool x0=man[i].jixu==player[0]||man[i].jixu==player[1];//是玩家
				bool x1=man[q].jixu!=player[0]&&man[q].jixu!=player[1];//非玩家
				 if( (x0&&x1&&man[i].z==0) || (!x0&&!x1) )
				 {
						 man[i].HP-=man[q].MP-man[i].BP;
						 man[q].over=1;
					     bom(man[i].x,man[i].y);
						 if(man[i].HP>0)
							 Sound("CBTank.wav");//爆炸
						 else {
							 if(x0&&man[i].lb==1)
								 Music("LandMine.wav");
							 else
								 Sound("CBMain.wav");

						if(man[i].lb==1)
						{
							 for(int j=0;j<num;j++)
								if(man[j].jixu==man[q].jixu&&j!=q)//炮弹是它打的
								 {
									man[j].exp+=10;//经验增加
									 break;
								 }
						}
						 }
						 return TRUE;
					 //else
					//	 Sound("CBMain2.wav");
				 }
			 }

		 }

	}
	return FALSE;//
	
}

//********************************************************************
///////////////  攻击，放炮  //////////////////
//				Fire
//2005.1.8
//**********************************************
void game::fire(int i)
{		
	if(man[i].gun >= Okgun-man[i].lv)
	{	
		man[i].gun=0;
		if (num>=SuLiang)return;//超数
		
		strcpy(man[num].name,"gun");
		man[num].step=man[i].lv+GunStep;//步长
		man[num].x=man[i].x;//位置开始
		man[num].y=man[i].y;
		man[num].x0=man[i].x;
		man[num].y0=man[i].y;
		man[num].jixu=man[i].jixu;//序号
		man[num].js=0;//角色0 
		man[num].lb=2;//子弹
		man[num].z=0;//只有一个分类
		man[num].p=0;//图形号
		man[num].m0=0;//动作初始
		man[num].m1=0;//动作结束
		man[num].gun=0;//不具有杀伤力
		man[num].over=0;
		man[num].fw=1;
		man[num].MP=man[i].MP;//攻击力
		if (man[i].fw==1)//判断子弹方位
			man[num].y0-=man[i].step*man[i].lv*3+150;
		if (man[i].fw==4)
			man[num].x0+=man[i].step*man[i].lv*3+150;	
		if (man[i].fw==2)
			man[num].y0+=man[i].step*man[i].lv*3+150;
		if (man[i].fw==3)
			man[num].x0-=man[i].step*man[i].lv*3+150;	
		num++;
		Sound("Shot.wav");//发声
		//AfxMessageBox("a");
	}
}
	

/*
//********************************************************************
///////////////  图形旋转  //////////////////
//				RotateAnyAngle
//2005.1.7
//**********************************************
void game::Rotate(HDC dcSrc,//要旋转的图形的DC
					int SrcWidth,//宽
					int SrcHeight,//高
					double angle)//旋转弧度
{
//AfxMessageBox(angle);
angle = (angle/180.0)*3.14159;//旋转45Degree,可为任意角度

 double x1,x2,x3;
 double y1,y2,y3;
 double maxWidth,maxHeight,minWidth,minHeight;
 double srcX,srcY;
 double sinA,cosA;
 double DstWidth;
 double DstHeight;

 HBITMAP newBitmap;
 sinA = sin(angle);
 cosA = cos(angle);
 x1 = -SrcHeight * sinA;
    y1 = SrcHeight * cosA;
    x2 = SrcWidth * cosA - SrcHeight * sinA;
    y2 = SrcHeight * cosA + SrcWidth * sinA;
    x3 = SrcWidth * cosA;
    y3 = SrcWidth * sinA;
 minWidth = x3>(x1>x2?x2:x1)?(x1>x2?x2:x1):x3;
 minWidth = minWidth>0?0:minWidth;
 minHeight = y3>(y1>y2?y2:y1)?(y1>y2?y2:y1):y3;
 minHeight = minHeight>0?0:minHeight;
 maxWidth = x3>(x1>x2?x1:x2)?x3:(x1>x2?x1:x2);
 maxWidth = maxWidth>0?maxWidth:0;
 maxHeight = y3>(y1>y2?y1:y2)?y3:(y1>y2?y1:y2);
 maxHeight = maxHeight>0?maxHeight:0;
 DstWidth = maxWidth - minWidth;
    DstHeight = maxHeight - minHeight;
 dcDst = CreateCompatibleDC(dcSrc);
 newBitmap = CreateCompatibleBitmap(dcSrc,(int)DstWidth,(int)DstHeight);
 SelectObject(dcDst,newBitmap);
 for( int I = 0 ;I<DstHeight;I++)
 {
    for(int J = 0 ;J< DstWidth;J++)
    {
       srcX = (J + minWidth) * cosA + (I + minHeight) * sinA;
       srcY = (I + minHeight) * cosA - (J + minWidth) * sinA;
       if( (srcX >= 0) && (srcX <= SrcWidth) &&(srcY >= 0) && (srcY <= SrcHeight))
      {
              BitBlt(dcDst, J, I, 1, 1, dcSrc,(int)srcX, (int)srcY, SRCCOPY);
      }
   }
 }
 
}
*/



/**************************************************************/
///////////////对象显示

//				setobj(i)
//*************************************************
void game::setobj(int i)
{

	SetBkMode(MainDC,TRANSPARENT);//透明显示
	
	man[i].p++;
	lookit(i);//碰撞
	movman(i);//活动对象	
	if (man[i].p>man[i].m1)
		man[i].p=man[i].m0;

	//****************是否已经死亡的坦克
	if(man[i].lb==1)
	{	if(man[i].HP<=0)
		{	man[i].over=1;
			//Sound("CBMain.wav");
			return;
		}

		if(man[i].exp>=man[i].exp2&&man[i].lv<10)
		{
			man[i].lv+=1;//升级
			man[i].HP+=20;//加血
			man[i].MP+=5;//攻击力
			man[i].BP+=2;//防御
			man[i].exp=0;//经验归零
			man[i].exp2+=50;
			Sound("AddLife.wav");
			man[i].z=1;
			gtime=0;
		}
	}
		cc.Format("%d%02d",man[i].lb,man[i].js);//设置路径
		//SelectObject(MemDC,bmp[0]);
		getpic2(cc);//读入图片文件
		//MemDC=bmp[1];
		
		sprintf(dir,"pic/%d%02d.txt",man[i].lb,man[i].js);//设置路径
		getpicdata(dir,i);//读入数据和偏移量
		//man[i].byx=bx;man[i].byy=by;//赋值
	
		//Rotate(MemDC,w,h,man[i].fw);//执行旋转//MemDC=dcDst;//旋转后得DC
		if(man[i].lb==3)
			TransparentBlt2(MainDC,man[i].x-man[i].w/2
		,man[i].y-man[i].h
		,man[i].w+1,man[i].h+1
		,tmpbmp
		,man[i].px
		,man[i].py
		,man[i].w+1
		,man[i].h+1
		,RGB(255,0,0));//拷贝物体位图
		else
			TransparentBlt2(MainDC,man[i].x-man[i].w/2
		,man[i].y-man[i].h/2
		,man[i].w+1,man[i].h+1
		,tmpbmp
		,man[i].px
		,man[i].py
		,man[i].w+1
		,man[i].h+1
		,RGB(255,0,0));//拷贝物体位图

	//显示游戏相关信息
		if(man[i].lb==1)//显示血
		{
			CBrush Brush;
			bool y=man[i].jixu==player[0]||man[i].jixu==player[1];
			if(y)
			{
			//	Brush.CreateSolidBrush(RGB(0,120,0));
				Brush.CreateSolidBrush(RGB(200,0,0));
				SetTextColor(MainDC,RGB(200,0,0));//红色文字
			}else{
				Brush.CreateSolidBrush(RGB(0,120,0));
				SetTextColor(MainDC,RGB(0,120,0));
			}
			SelectObject(MainDC,Brush);
			PatBlt(MainDC,man[i].x-man[i].w/2,man[i].y+man[i].h/2+4,man[i].HP/4,3,PATCOPY);

			TextOut(MainDC,man[i].x+man[i].w/2+4,man[i].y-man[i].h/2,man[i].name,strlen(man[i].name));
			cc.Format("%d",man[i].lv);
			
			TextOut(MainDC,man[i].x+man[i].w/2+4,man[i].y+8,cc,lstrlen(cc));


		}

}



/**************************************************************/
///////////////获取文件偏移值

//				
//*************************************************
void game::getpicdata(CString cc,int i)
{
	::SetCurrentDirectory(appdir);

	int max;//图形总数
	char c[3],itsc[3];//图形号码  分类&方向&图形号 X0 Y0 X2 Y2
	sprintf(itsc,"%d%d%d",man[i].z,man[i].fw,man[i].p);
	short int x0,x1,y0,y1;
	
	FILE *f;
	f=fopen(cc,"r");
	//TextOut(MainDC,120,120,cc,lstrlen(cc));
	//return;
	fscanf(f,"%d",&max);
	//return;
	for (int j=0;j<max;j++)
	{
		fscanf(f,"%s%d%d%d%d\n",c,&x0,&y0,&x1,&y1);
		if (!strcmp(c,itsc))
		{man[i].px=x0;
			man[i].py=y0;
			man[i].w=x1-x0;
			man[i].h=y1-y0;
			fclose(f);

			return;
		}
	}
	TextOut(MainDC,0,0,"找不到图片数据.",lstrlen("找不到图片数据."));
	fclose(f);
}


