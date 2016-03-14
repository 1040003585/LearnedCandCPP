 // Download by http://www.NewXing.com
#include"stdafx.h"
#include"CreateMap.h"
#include<stdlib.h>  
#include<time.h>  
//====================================================================================
int		g_MazeWidth;		//迷宫地图宽度
int		g_MazeHeight;		//迷宫地图高度
int		g_MazeMap[MAX_MAZE_WIDTH+1][MAX_MAZE_HEIGHT+1]={0};	//迷宫地图数组
//=======================迷宫地图的随机创建模块==========================================================
typedef struct 
{
	int tag;   						//在数组里标记的数字
	int x,y;						//在数组中的位置g_MazeMap[x][y];
	int vx,vy;  					//x,y的移动方向
	int step;   					//在一个方向上连续挖地图的长度
	int maxX;						//x的最大值
	int maxY;						//y的最大值
}SDigMap;
//====================================================================
void ClearMap(int w,int h)//将表示迷宫地图的数组置零
{
	g_MazeWidth=w;
	g_MazeHeight=h;
	int i,j;
	for(i=0;i<=w;i++)
		for(j=0;j<=h;j++)
		{
			g_MazeMap[i][j]=0;
		}
		srand(time(0));
}
//=====================================================================================
void DigIt(SDigMap *p)//将该处挖掉，即打标记
{
	g_MazeMap[	p->x  ][ p->y  ] = p->tag;
}
//=====================================================================================
void Walk(SDigMap *p)//挖地图的坐标前移
{
	    p->x	+=	p->vx;
    	p->y	+=	p->vy; 
}
//=====================================================================================
int  IsNextDigged(int x,int y,int vx,int vy,SDigMap *p)//判断下一个坐标是否被给该对象挖掉
{
	if( g_MazeMap[	x + vx  ][ y + vy ]	==	p->tag ) return 1;
	else 	return 0;
}
//==========================================================================================
void HitWall(SDigMap *p)//挖地图的坐标如撞墙，则反向
{
	    if( p->x + p->vx < 1 || p->x + p->vx > p->maxX) 
			p->vx = -p->vx;
    	if( p->y + p->vy < 1 || p->y + p->vy > p->maxY)  
    		p->vy = -p->vy;
}
//======================================================================================
int  CanNextBeDigged(SDigMap *p)//检测下一个点是否可以挖
{
	   int x = p->x + p->vx;
	   int y = p->y + p->vy;             //下一点的坐标
       int vx = p->vy;					//与原方向转弯的方向
       int vy = p->vx;
	   //判断当前点的下一个点的三个邻点是否被自己挖过,如果被自己挖过，下一点不能挖了，否则把自己挖通了
       if( IsNextDigged( x, y, p->vx, p->vy, p ) ) return 0;//前一点是否被挖 
       if( IsNextDigged( x, y, vx, vy, p ) ) return 0;//左一点是否被挖 
       if( IsNextDigged( x, y, -vx, -vy, p ) )	return 0;//右一点是否被挖  
       return 1;		//周围都没被挖,看来可以被挖
}
//====================================================================================
void Jump(SDigMap *p)//跳过下一点，跳到下一点的周围三个点上
{
    	int vx=p->vy;
    	int vy=p->vx;	//与原方向转弯的两个方向
 	    Walk(p);		//先走到下一点上
        if( IsNextDigged( p->x, p->y, p->vx, p->vy, p ) )  //前一点被挖,走过去
        {
        	Walk(p);   
        }
        else if(IsNextDigged( p->x, p->y, vx, vy, p ))  //左一点被挖,走过去
        {
           	p->x += vx;    
        	p->y += vy;   
        }
        else if(IsNextDigged( p->x, p->y, -vx, -vy, p))  //右一点被挖,走过去
        {
           	p->x -= vx;
        	p->y -= vy;  
        }
}
//=====================================================================================
int  IsLinked(SDigMap *p)//检查是否挖通
{
       	int vx=p->vy;
       	int vy=p->vx;//与原方向转弯的两个方向
       	//如果改点的三个邻点，既不是自身标记又不是0，则该点被别的SDigMap挖过,既已经挖通了
    	if( g_MazeMap[ p->x+vy ][ p->y+vx ] != p->tag && g_MazeMap[ p->x+vy ][p->y+vx ] !=0 )  return 1;  //前一个点是否被别的挖
    	if( g_MazeMap[ p->x+vx ][ p->y+vy ] != p->tag && g_MazeMap[ p->x+vx ][ p->y+vy ] != 0 ) return 1; //左一个点是否被别的挖	 
    	if( g_MazeMap[ p->x-vx ][ p->y-vy ] != p->tag && g_MazeMap[ p->x-vx ][ p->y-vy ] != 0 ) return 1;//右一个点是否被别的挖
    	return 0; 
}
//=====================================================================================
void RandomVxy(SDigMap *p)//产生随机方向
{
	    int vx=p->vy;
    	int vy=p->vx;
		int k=rand()%50;
    	//将随机数3个空间，原方向必将改变
    	if( 0<=k && k<10 )// 反方向的概率为发生转弯的概率一半
    	{    p->vx = -vx;
    		p->vy = -vy;
    	} 
    	if( 10<=k && k<30 )//右向
    	{
     		p->vx = -vy;
    		p->vy = -vx;
    	} 
    	if( 30<=k && k<50 )//向左    
    	{
    		p->vx = vy;
    		p->vy = vx;
    	}
}
//=====================================================================================
int  ContinuouslyDig( SDigMap *p )//连续挖
{
    	int i=0; 
    	RandomVxy( p );//产生一个随机方向
 		p->step =1+rand()%2;//随机产生在该方向上挖的连续步长
    	while( i<p->step )
    	{
			 HitWall( p );  //首先检测是否撞墙，如果撞墙方向取反
			 //对于下一点的三种策略:1走过 2走过去挖掉 3跳过去
			if(IsNextDigged(p->x,p->y,p->vx,p->vy,p))//检测下一点是否被自己挖过
				Walk(p);//已经被挖，走过去
			 else if( CanNextBeDigged( p ) )//没有被挖，是否可以挖
				{
					Walk( p );//可以挖，走过去，
        			DigIt( p );//挖掉
        			if( IsLinked( p ) ) return 1;//如果挖通，跳出循环，并返回	
				}
			 else Jump( p );//不可以挖，跳过去	
			i++;
    	}
    	 return 0;
}
//=====================================================================================
int bSeed(int x,int y)//是否可以作为种子
{	//改点和四个邻点都没被挖，则可以从该点开始挖地图
	if( g_MazeMap[x][y] != 0 )		return 0;
	if( g_MazeMap[x-1][y] != 0 )	return 0;
	if( g_MazeMap[x][y-1] != 0 )	return 0;
	if( g_MazeMap[x+1][y] != 0 )	return 0;
	if( g_MazeMap[x][y+1] != 0 )	return 0;
	return 1;
}
//=====================================================================================
void ImproveMap(int w,int h)//改善迷宫
{
	int		i,j;
	int 	tag=3;
	int		bLink=0;       //判断地图是否挖通
	//SDigMap:	tag	x	y	vx	vy	step	maxX	maxY
	SDigMap m={ 3,	1,	1,	1,	0,	1,		w-2,	h-2};//标号为1，从坐标（1，1）开始挖
	for( i=1; i<w-1; i++ )
		for( j=1; j<h-1; j++ )
		{
             if(bSeed( i, j )==1)
			 {
				m.tag=tag;
				m.x=i;
				m.y=j;
				tag++;
				DigIt(&m);
				bLink=0;
				while( !bLink )
                     bLink=ContinuouslyDig( &m );
			 }
		}
}
//=====================================================================================
void RandomExit(SDigMap *p,int w,int h,POINT* pExit)//pExit返回迷宫出口
{	//设置随即出口，随机出口位置可为左上角，坐下角，右上角
	int k=rand()%60;
	if( 0<=k && k<30 )//出口在左上角,概率最大
	{
		p->x=1;
		p->y=1;
		pExit->x=0;
		pExit->y=1;		
	}
	else if( 30<=k && k<45 )//左下角
	{
		p->x=1;
		p->y=h-2;
		pExit->x=0;
		pExit->y=h-2;		
	}
	else if( 45<=k && k<60 )//右上角
	{
		p->x=w-2;
		p->y=1;
		pExit->x=w-2;
		pExit->y=0;
	}
	g_MazeMap[pExit->x][pExit->y]=1;//先将迷宫出口挖掉
}
//========================================================================================
void CreateMap(int w,int h,POINT* pExit)//创建迷宫地图,地图大小为w*h,pExit返回出口坐标
{
	//SDigMap:		tag		x		y		vx		vy		step	maxX		maxY
	SDigMap m1={ 	1,		1,		1,		1,		0,		1,		w-2,		h-2};//标号为1，从坐标（1，1）开始挖
	SDigMap m2={ 	2,		w-2,	h-2,	-1,		0,		1,		w-2,		h-2};//标号为2，从坐标（N，N）开始挖
	int		bLink=0;       //判断地图是否挖通
	ClearMap(w,h);//首先，全部清零			
	RandomExit(&m1,w,h,pExit);//随机设置老鼠出口
	DigIt( &m1 );  	//初始点先挖掉    
	DigIt( &m2 );//老鼠在右下角
	while( !bLink )//从两边同时挖，先挖出从开始处到出口的通路
	{  
		bLink	=	ContinuouslyDig( &m1 );//从入口开始的挖图对象，随机方向，随机步长，返回是否挖通
		if(!bLink)	bLink=ContinuouslyDig( &m2 );//从迷宫最深处开始的挖图对像
	}
	ImproveMap(w,h);//改进地图，将大片没被挖的地方，多挖出一些通道，让地图更加迷人,嘿嘿!
}
