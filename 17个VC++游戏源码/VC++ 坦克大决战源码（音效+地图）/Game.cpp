
// Download by http://www.NewXing.com
/*game.cpp
//////////////////////////////////////////��Ϸ��Ҫ///////////
////
*/


#include "stdafx.h"
#include "game.h"
game::game()//���캯��
{}
game::~game()//��������
{}



//***************************************************
//��Ϸ�����
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
	door++;//�ؿ�����
	if(door>1)goto start;

	exit();//ɾ�����л���
	int a;
	tim=::timeGetTime();
	a=tim.GetHour()+tim.GetMinute()*60+tim.GetSecond()*60*60;
	srand(a);
	over=0;//��Ϸ��ʼ
	GetCurrentDirectory(256,appdir);
	//::AfxMessageBox(appdir);
	sys=4;//Windows NT


	keydown=0;keyup=0;keyleft=0;keyright=0;keyspace=0;//�ް���
	keydown2=0;keyup2=0;keyleft2=0;keyright2=0;keyspace2=0;//�ް���

	SDC=CreateDC("DISPLAY",NULL,NULL,NULL);///��Ļ�豸
	bit0  =CreateCompatibleBitmap(SDC,WIDTH,HEIGHT);//�����ݴ�λͼ�ڴ�0	
	bit1  =CreateCompatibleBitmap(SDC,WIDTH,HEIGHT);//�����ݴ�λͼ�ڴ�1	
	Back=CreateCompatibleDC(SDC);//��ͼ�豸,�����豸
	MemDC=CreateCompatibleDC(SDC);//
	MainDC=CreateCompatibleDC(SDC);//�����������豸
	SelectObject(Back,bit0);
	SelectObject(MainDC,bit1);//����λͼ

			font.CreateFont( 12,6,0,0,700,0,0,0, ANSI_CHARSET,OUT_DEFAULT_PRECIS, 
			CLIP_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, 
			DEFAULT_PITCH|FF_DONTCARE, 
			"����"); 
			::SelectObject(MainDC,font);

  	/*Rotate(Back,w,h,90);//��תͼ��TankMain
	Back=dcDst;*/

	SetBkMode(Back,TRANSPARENT);//����͸��
 	cc="̹����Ϸ(�����)";

	SetTextColor(Back,RGB(255,0,0));//����������ɫ
	TextOut(Back,650,0,cc,lstrlen(cc));//�������
start:

	loadmap(map);//�����ͼmap1.txt
	getpic(mapbak);
	for (int i=0;i<=WIDTH/w;i++)
		for(int j=0;j<=HEIGHT/h;j++)
			BitBlt(Back,i*w,j*h,WIDTH,HEIGHT,MemDC,0,0,SRCCOPY);//�����ͼ����


	
	return TRUE;
}
//������DirectX�����////////////////////////////////////
//*************************************************
// ʹ��DirectX ʵ��ȫ��
// ����DX����
//*************************************************
bool game::initDX()
{
//���ܣ���ʼ��DirectDraw������
  ddrval=DirectDrawCreate( NULL, &DXW, NULL );
	if(ddrval!= DD_OK ) return FALSE;//����DirectCraw����ʧ�ܷ���  
    ddrval=DXW->SetCooperativeLevel(GetActiveWindow(),DDSCL_NORMAL);
	if(ddrval!= DD_OK)  return FALSE;// ȡ�ô���ģʽʧ�ܷ���
    
	ddrval=DXW->SetDisplayMode(800,600,16);
	if(ddrval!= DD_OK) return FALSE;//������ʾģʽʧ�ܷ���
	return TRUE;
	/*
	ddsd.dwSize = sizeof( ddsd );// ��������ҳ�� 
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps =DDSCAPS_PRIMARYSURFACE;
	ddsd.dwBackBufferCount=1;
    ddrval = DXW->CreateSurface( &ddsd, &DXSPrimary, NULL );
    if( ddrval != DD_OK )   return FALSE;//��������ҳ��ʧ�ܷ��� 
*/
}
//**************************************************
// ai(int i) //�����ж�
//	
//**************************************************
void game::ai(int i)
{

	if(rand()%2==1)fire(i);
	short int t=(10-man[i].lv)*5+50;//˼���ٶ�
	if (rand()%2==1)
	{
		if (rand()%2==1)
			man[i].x0+=rand()%t;//��
			if(man[i].x0>784)man[i].x0=man[i].y-t;
		else if(rand()%2==1)
			man[i].x0-=rand()%t;//��

	}else {
	
		if (rand()%2==1)
			man[i].y0+=rand()%t;//��
		if(man[i].y0>584)
			man[i].y0=man[i].y-t;
		else if(rand()%2==1)
			man[i].y0-=rand()%t;//��
	}
	if(man[i].js>2)//�������
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
// Bom() //̹�˱�ը
//	
//**************************************************
void game::bom(int x,int y)
{
	//���
	if (num>=SuLiang)return;//����
	strcpy(man[num].name,"��");
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
// Delete() //ɾ��
//	ɾ����Ϸ�еĶ��󡣲��������
//**************************************************
void game::Delete(int i) //ɾ��
{
		for (int j=i;j<num-1;j++)	
		 	man[j]=man[j+1];//ɾ��gno
	 	num--;//��������1
}
//*******************************************
// Music
// ����mid
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
// ����Wav
//****************************************
void game::Sound(CString cc)
{
	SetCurrentDirectory(appdir);
	sndPlaySound("sound/"+cc,SND_ASYNC);
}



//*****************************************
//		�����ƶ�

//***********************************
void game::movman(int i)
{

	if( man[i].lb==3||pause==1)return;//����
	short int *turn=&man[i].fw,step=man[i].step;//�Ƕ�<90
	if ( man[i].jixu==player[0]&&man[i].lb==1)//�����1
	{

		//1�������
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
	if ( man[i].jixu==player[1]&&man[i].lb==1)//�����2
	{

		//2�������
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
	//�ж��Ƿ��������
	if ( man[i].lb==2 ) //���ӵ�
		if ( man[i].x==man[i].x0 && man[i].y==man[i].y0 )//��Ŀ�ĵ�
		{
			man[i].over=1;
			return;
		}



	//***************************************
	//�ƶ�λ��
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
			if(look(man[i].x+step,man[i].y,i))//���ϰ�
				man[i].x+=step;
			else
				man[i].x0=man[i].x;

			*turn=4;
		}
		if(man[i].x0<man[i].x)
		{
			if(look(man[i].x-step,man[i].y,i))//���ϰ�
				man[i].x-=step;
			else
				man[i].x0=man[i].x;
			*turn=3;
		}
	}else{

		if(man[i].y0>man[i].y)
		{
			if(look(man[i].x,man[i].y+step,i))//���ϰ�
				man[i].y+=step;
			else
				man[i].y0=man[i].y;
			*turn=2;
		}
		if(man[i].y0<man[i].y)
		{
			if(look(man[i].x,man[i].y-step,i))//���ϰ�
				man[i].y-=step;
			else
				man[i].y0=man[i].y;
			*turn=1;
		}
	}
	if (x<man[i].step)man[i].x=man[i].x0;
	if (y<man[i].step)man[i].y=man[i].y0;
	
	/*****************************
	// ����̹��װ�ӵ�
	*/
	if (man[i].lb==1)//Tanks
	{
		if(man[i].gun<Okgun-man[i].lv)
			man[i].gun++;
	}
	if (man[i].lb==2)//�ӵ�
	{
		if(man[i].gun<shotmeter)
			man[i].gun++;
	}
	
}


//**************************************************
//  loadbmp(CString cc)//��BMPͼƬ
//  ��ccָ����ͼ��;ȡ�õ�ͼ�����豸���λͼbit��
//  ͼ�εĿ��ߴ���ȫ�ֱ���w,h��
//**************************************************
BOOL game::loadbmp(CString cc)//��BMPͼƬ[2��]
{
	::SetCurrentDirectory(appdir);
	DeleteObject(bitmap);
				//ɾ���ϴε�λͼ�ڴ档
	bitmap=(HBITMAP)LoadImage			//����ccָ����ͼ��
				(AfxGetInstanceHandle(),//
				 cc,IMAGE_BITMAP,		//�ļ���,λͼ��ʽ				 			
				 0,0,					//ͼ�ο�,��
				 LR_LOADFROMFILE|LR_CREATEDIBSECTION//��ʽ
				);
	if(bitmap == NULL) {TextOut(MainDC,0,0,"�Ҳ���ͼƬ"+cc,lstrlen("�Ҳ���ͼƬ"+cc));return FALSE;	}	//��ͼʧ��
	DIBSECTION ds;						//
	BITMAPINFOHEADER &bm = ds.dsBmih;	//
	GetObject(bitmap,sizeof(ds),&ds);	//ȡλͼ����Ϣ->bminfo
	w = bm.biWidth;						//�õ�λͼ���ֵ 
	h = bm.biHeight;					//�õ�λͼ�߶�ֵ

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
//  ��ͼƬ����HDC
//**************************************************
void game::getpic(CString cc)
{
	
	if (loadbmp(cc) == FALSE)
		TextOut(MainDC,10,10,"��ͼʧ��",8); //��ͼʧ��
	else
		SelectObject(MemDC,bitmap);//����λͼ
		//BitBlt(MainDC,1,1,100,100,MemDC,0,0,SRCCOPY);
}

//**************************************************
//  game::getpic(CString cc)
//  ��ͼƬ����HDC
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
	TextOut(MainDC,0,0,"û���ҵ�ͼƬ��",lstrlen("û���ҵ�ͼƬ��"));
}
//**************************************************
//  game::exit()
//  �뿪��Ϸ
//  �ͷ����б���
//**************************************************
void game::exit()
{

	DeleteObject(bitmap);////λͼ����

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
//	�����ͼ����
//	��Դ�ļ�
//  ������ϷĬ��ֵ
//************************************************************
BOOL game::loadmap(CString mapfile)
{
	mapfile="map/"+mapfile;
	FILE *f;
	f=fopen(mapfile,"r");
	if(f == NULL)
	{
		AfxMessageBox("û�е�ͼ�ļ�!!!");
		SetCurrentDirectory(appdir);
		return FALSE;
	}
	fscanf(f,"%s\n",mapname);//��ͼ����
	fscanf(f,"%s\n",mapbak);//��ͼ��
	fscanf(f,"%s\n",nextmap);//������һ����ͼ����
	fscanf(f,"%d\n",&num);//��������
	if(door==1)
	{
		short int num2;
		fscanf(f,"%d",&num2);//�������
		if ( num2==2)
		{
			fscanf(f,"%d",&player[0]);//���1
			fscanf(f,"%d",&player[1]);//���2
		}else
		{
			fscanf(f,"%d",&player[0]);//���1
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
		man[player[0]].step=manStep+man[0].lv/2;//����
		man[player[1]].step=manStep+man[1].lv/2;//����
	}
	
	for(int i=0;i<num;i++)
	{
		/*
		1,1,0,���,1,100,100,0,0,0,10,
���,���(��,��),��ɫ(0��ҿ���),����,�ȼ�,����X,����Y
		,��λ(�Ƕ�),ͼ�κ�(),��ʼֵ,����ֵ,Ŀ��λ��X,*/
		if(door>1&&man[i].lb==1&&(man[i].jixu==player[0]||man[i].jixu==player[1]))continue;
		fscanf(f,"%d ",&man[i].jixu);//�������
		fscanf(f,"%d ",&man[i].lb);//�������
		fscanf(f,"%d ",&man[i].js);//�����ɫ
		fscanf(f,"%s ",man[i].name);//��������
		fscanf(f,"%d ",&man[i].HP);//����
		fscanf(f,"%d ",&man[i].MP);//������
		fscanf(f,"%d ",&man[i].BP);//������
		fscanf(f,"%d ",&man[i].lv);//�ȼ�
		fscanf(f,"%d ",&man[i].x);//����X
		fscanf(f,"%d ",&man[i].y);//����y
		fscanf(f,"%d ",&man[i].fw);//���뷽λ
		if(man[i].lb==1)man[i].z=1;else man[i].z=0;
		man[i].over=0;
		man[i].p=0;//Ĭ��ͼ�κ�
		man[i].exp=0;//����0
		man[i].exp2=50;
		man[i].step=manStep+man[i].lv/2;//����
		if(man[i].x==0)
			man[i].x=rand()%780;
		if(man[i].y==0)
			man[i].y=rand()%550;
		man[i].m1=1;
		man[i].m0=0;
		man[i].p=man[i].m0;//��ʼ��ͼ��.
		man[i].x0=man[i].x;
		man[i].y0=man[i].y;//ֹͣ�߶�.
		man[i].gun=UpGun;//װ�ӵ�
	}
	
	SetCurrentDirectory(appdir);//�õ�ǰĿ¼
	gtime=0;//��Ϸʱ�䣽0
	return TRUE;

}


//**********************************************************
//  sort() ����(ð�ݷ�)
//  ��num���������ж�Yλ�ý�������;��������ʾʱ�ֳ�ǰ��λ�á�
//**********************************************************
void game::sort()//����(ð�ݷ�)
{	Obj man0;
	for(int a=0;a<num-1;a++)
	 for(int b=a+1;b<num;b++)
		if(man[a].y>man[b].y)//ǰ�����ں���
			{man0=man[a];		 //��������
			 man[a]=man[b];
			 man[b]=man0;
			}					 //����������ǰλ��YС����ǰ��							
	//mans=0;						 //��ʾ����������0
}

//**********************************************************************
//  TransparentBlt2 (......)͸����ʾ
//  ���ݹؼ�ɫ����hdc1�е�ͼ����hdc0��
//  �Զ�������ģ��������͸��ͼ�Ρ�
//	ע:TransparentBlt(......)��һ��WIN API���������ܺ��������ͬ��
//	��WIN2000���Ժ��ϵͳ�Ͽ��á���WIN98�������ص���Դй©�����������á�
//  ʹ��TransparentBlt(......)ǰ��������:
//  #include <wingdi.h>
//  #pragma comment (lib,"msimg32.lib")
//**********************************************************************
void game::TransparentBlt2(HDC hdc0,			//Ŀ��DC
				int nX0,int nY0,int nW0,int nH0,//Ŀ��������,Ŀ���߿�
				HDC hdc1,						//ԴDC
				int nX1,int nY1,int nW1,int nH1,//Դ�������,Դ��߿�
				UINT Tcol)						//͸��ɫ,COLORREF����
					 
{	/*
	if(sys>1)//��win98���ϵ�ϵͳ��ֱ�ӵ�API����TransparentBlt()
	{TransparentBlt(hdc0,nX0,nY0,nW0,nH0,hdc1,nX1,nY1,nW1,nH1,Tcol);
	 return;
	}
	*/
	HBITMAP hBMP   =CreateCompatibleBitmap(hdc0,nW0, nH0);	//����λͼ�ڴ�
	HBITMAP mBMP   =CreateBitmap(nW0,nH0,1,1,NULL);			//������ɫ����λͼ
	HDC		hDC    =CreateCompatibleDC(hdc0);				//�����豸���
	HDC		mDC    =CreateCompatibleDC(hdc0);				//�����豸���
	HBITMAP oldBMP =(HBITMAP)SelectObject(hDC, hBMP);
	HBITMAP oldmBMP=(HBITMAP)SelectObject(mDC, mBMP);
	// ��ԴDC�е�λͼ��������ʱDC��
	if (nW0==nW1&&nH0==nH1)
		BitBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,SRCCOPY);
	else
		StretchBlt(hDC,0,0,nW0,nH0,hdc1,nX1,nY1,nW1,nH1,SRCCOPY);
	SetBkColor(hDC, Tcol);// ����͸��ɫ
	BitBlt(mDC,0,0,nW0,nH0,hDC,0,0,SRCCOPY);//����͸������Ϊ��ɫ,��������Ϊ��ɫ������λͼ

	SetBkColor(hDC, RGB(0,0,0));			//����͸������Ϊ��ɫ,�������򱣳ֲ����λͼ
	SetTextColor(hDC, RGB(255,255,255));	//��ɫ
	BitBlt(hDC,0,0,nW0,nH0,mDC,0,0,SRCAND);
	SetBkColor(hdc0,RGB(255,255,255));		//͸�����ֱ�����Ļ����,�������ֱ�ɺ�ɫ
	SetTextColor(hdc0,RGB(0,0,0));			//��ɫ

	BitBlt(hdc0,nX0,nY0,nW0,nH0,mDC,0,0,SRCAND);  //"��"����,��hdc0������ģ
	BitBlt(hdc0,nX0,nY0,nW0,nH0,hDC,0,0,SRCPAINT);//"��"����,��������͸��Ч��	
	SelectObject(hDC,oldBMP);
	SelectObject(mDC,oldmBMP);
	DeleteDC(hDC);
	DeleteDC(mDC);
	DeleteObject(hBMP);
	DeleteObject(mBMP);
}
//********************************************************************
///////////////  �ϰ�  //////////////////
//				Look
//2005.2.13
//**********************************************
bool game::look(int x,int y,short j)
{
	bool x1=man[j].jixu==player[0]||man[j].jixu==player[1];//�����
	if ( man[j].lb!=1)return true;
	for(int i=0;i<num;i++)
	{
		if(abs(man[i].x-x)<man[i].w/2+man[j].w/2 && abs(man[i].y-y)<man[i].h/2+man[j].h/2)
		{
			if(man[i].lb==1&&i!=j)
			{	
					bool x0=man[i].jixu==player[0]||man[i].jixu==player[1];//�����
				if((x0&&x1)||(!x0&&!x1)) continue;
		//		if(abs(man[i].x-man[j].x)<man[j].w || abs(man[i].y-man[j].y)<man[j].h)continue;
				if(abs(x-man[i].x)<man[i].w&&abs(y-man[i].y)<man[i].h)
				return false;
			}
		  	else if(man[i].lb==3&&(y-man[i].y)<man[j].h/2&&man[i].js!=0&&(y-man[i].y)>0)//����
	 	  		return false;
		}
	//	
	}
	if (x>784||x<16||y>584||y<16)return false;
	return true;
}

//********************************************************************
///////////////  ��������  //////////////////
//				LookIt
//2005.2.8
//**********************************************
BOOL game::lookit(int i)
{
	
	if (man[i].lb==3&&man[i].js==0)return FALSE;//�ӵ�FALSE
	for(int q=0;q<num;q++)
	{	if(q==i)continue;				//���Լ�
		 if(man[q].lb==3) continue;		//�Ǿ�
		 int x=man[i].x-man[q].x;	//ȡq,i�����λ�ò�
		 int y=man[i].y-man[q].y;	//
		 if(abs(x)<man[q].w*3 && abs(y)<man[q].h*3)//����
		 {
			 if(man[q].lb==2&&man[q].gun>=shotmeter)//�ӵ�
			 {
				bool x0=man[i].jixu==player[0]||man[i].jixu==player[1];//�����
				bool x1=man[q].jixu!=player[0]&&man[q].jixu!=player[1];//�����
				 if( (x0&&x1&&man[i].z==0) || (!x0&&!x1) )
				 {
						 man[i].HP-=man[q].MP-man[i].BP;
						 man[q].over=1;
					     bom(man[i].x,man[i].y);
						 if(man[i].HP>0)
							 Sound("CBTank.wav");//��ը
						 else {
							 if(x0&&man[i].lb==1)
								 Music("LandMine.wav");
							 else
								 Sound("CBMain.wav");

						if(man[i].lb==1)
						{
							 for(int j=0;j<num;j++)
								if(man[j].jixu==man[q].jixu&&j!=q)//�ڵ��������
								 {
									man[j].exp+=10;//��������
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
///////////////  ����������  //////////////////
//				Fire
//2005.1.8
//**********************************************
void game::fire(int i)
{		
	if(man[i].gun >= Okgun-man[i].lv)
	{	
		man[i].gun=0;
		if (num>=SuLiang)return;//����
		
		strcpy(man[num].name,"gun");
		man[num].step=man[i].lv+GunStep;//����
		man[num].x=man[i].x;//λ�ÿ�ʼ
		man[num].y=man[i].y;
		man[num].x0=man[i].x;
		man[num].y0=man[i].y;
		man[num].jixu=man[i].jixu;//���
		man[num].js=0;//��ɫ0 
		man[num].lb=2;//�ӵ�
		man[num].z=0;//ֻ��һ������
		man[num].p=0;//ͼ�κ�
		man[num].m0=0;//������ʼ
		man[num].m1=0;//��������
		man[num].gun=0;//������ɱ����
		man[num].over=0;
		man[num].fw=1;
		man[num].MP=man[i].MP;//������
		if (man[i].fw==1)//�ж��ӵ���λ
			man[num].y0-=man[i].step*man[i].lv*3+150;
		if (man[i].fw==4)
			man[num].x0+=man[i].step*man[i].lv*3+150;	
		if (man[i].fw==2)
			man[num].y0+=man[i].step*man[i].lv*3+150;
		if (man[i].fw==3)
			man[num].x0-=man[i].step*man[i].lv*3+150;	
		num++;
		Sound("Shot.wav");//����
		//AfxMessageBox("a");
	}
}
	

/*
//********************************************************************
///////////////  ͼ����ת  //////////////////
//				RotateAnyAngle
//2005.1.7
//**********************************************
void game::Rotate(HDC dcSrc,//Ҫ��ת��ͼ�ε�DC
					int SrcWidth,//��
					int SrcHeight,//��
					double angle)//��ת����
{
//AfxMessageBox(angle);
angle = (angle/180.0)*3.14159;//��ת45Degree,��Ϊ����Ƕ�

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
///////////////������ʾ

//				setobj(i)
//*************************************************
void game::setobj(int i)
{

	SetBkMode(MainDC,TRANSPARENT);//͸����ʾ
	
	man[i].p++;
	lookit(i);//��ײ
	movman(i);//�����	
	if (man[i].p>man[i].m1)
		man[i].p=man[i].m0;

	//****************�Ƿ��Ѿ�������̹��
	if(man[i].lb==1)
	{	if(man[i].HP<=0)
		{	man[i].over=1;
			//Sound("CBMain.wav");
			return;
		}

		if(man[i].exp>=man[i].exp2&&man[i].lv<10)
		{
			man[i].lv+=1;//����
			man[i].HP+=20;//��Ѫ
			man[i].MP+=5;//������
			man[i].BP+=2;//����
			man[i].exp=0;//�������
			man[i].exp2+=50;
			Sound("AddLife.wav");
			man[i].z=1;
			gtime=0;
		}
	}
		cc.Format("%d%02d",man[i].lb,man[i].js);//����·��
		//SelectObject(MemDC,bmp[0]);
		getpic2(cc);//����ͼƬ�ļ�
		//MemDC=bmp[1];
		
		sprintf(dir,"pic/%d%02d.txt",man[i].lb,man[i].js);//����·��
		getpicdata(dir,i);//�������ݺ�ƫ����
		//man[i].byx=bx;man[i].byy=by;//��ֵ
	
		//Rotate(MemDC,w,h,man[i].fw);//ִ����ת//MemDC=dcDst;//��ת���DC
		if(man[i].lb==3)
			TransparentBlt2(MainDC,man[i].x-man[i].w/2
		,man[i].y-man[i].h
		,man[i].w+1,man[i].h+1
		,tmpbmp
		,man[i].px
		,man[i].py
		,man[i].w+1
		,man[i].h+1
		,RGB(255,0,0));//��������λͼ
		else
			TransparentBlt2(MainDC,man[i].x-man[i].w/2
		,man[i].y-man[i].h/2
		,man[i].w+1,man[i].h+1
		,tmpbmp
		,man[i].px
		,man[i].py
		,man[i].w+1
		,man[i].h+1
		,RGB(255,0,0));//��������λͼ

	//��ʾ��Ϸ�����Ϣ
		if(man[i].lb==1)//��ʾѪ
		{
			CBrush Brush;
			bool y=man[i].jixu==player[0]||man[i].jixu==player[1];
			if(y)
			{
			//	Brush.CreateSolidBrush(RGB(0,120,0));
				Brush.CreateSolidBrush(RGB(200,0,0));
				SetTextColor(MainDC,RGB(200,0,0));//��ɫ����
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
///////////////��ȡ�ļ�ƫ��ֵ

//				
//*************************************************
void game::getpicdata(CString cc,int i)
{
	::SetCurrentDirectory(appdir);

	int max;//ͼ������
	char c[3],itsc[3];//ͼ�κ���  ����&����&ͼ�κ� X0 Y0 X2 Y2
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
	TextOut(MainDC,0,0,"�Ҳ���ͼƬ����.",lstrlen("�Ҳ���ͼƬ����."));
	fclose(f);
}


