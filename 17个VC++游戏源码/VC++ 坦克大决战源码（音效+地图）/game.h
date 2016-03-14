//Download by http://www.NewXing.com
/*game.h



  */
#include "常数定义.h"
//  game类

typedef struct
{
	short int jixu,//序号
		HP,//体力
		MP,//攻击力
		BP,//防御力
		exp,//经验
		exp2,//下次升级

	w,h,//尺寸.
	lv,//等级
	x,y,//坐标
	x0,y0,//目标位置
	lb,//类别
	m0,m1,//初始值,结束值
	gun,//炮弹装置
	js,//角色
	fw,//方位(1上 2下 3左 4右)
	step,//步长
	p,//图形号
	z,//图形块
	over,//删除
	px,py;//两个偏移量
	char name[256];
	HDC bmp;//图片
}Obj;




///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
class game
{
	
/////////////////////类函数////////////////////
public:
	game();
	~game();

	BOOL loadbmp(CString cc);//调BMP图片函数
	void exit();
	BOOL loadmap(CString mapfile);//调入地图数据
	void movman(int i);//玩家移动 
	void TransparentBlt2(HDC hdc0,int nX0,int nY0,int nW0,int nH0,HDC hdc1,					
		int nX1,int nY1,int nW1,int nH1,UINT Tcol);	//透明复制函数
	BOOL init(CString map);//初始化	
	//void Rotate(HDC dcSrc,int SrcWidth,int SrcHeight,double angle);//旋转图形函数
	void setobj(int i);//对象显示
	void getpic(CString cc);//调图加入HDC
	void getpicdata(CString cc,int i);//调入pic值
	void sort();//对象排序显示前后
	void game::Delete(int i);//删除对象
	BOOL lookit(int i);//对象碰撞.中弹
	void fire(int i);//攻击，放炮
	void Sound(CString cc);//播放Wav
	void bom(int x,int y);//爆炸
	void ai(int i);//自由行动
	void Music(CString cc);//背景音乐
	bool look(int x,int y,short j);//查看障碍物
	void getpic2(CString p);//获得内存图片
	void loadbmp2(CString n,CString cc);//存入图片
	bool initDX();//进入DX环境
//////////////////定义类变量////////////////////
public:
	HWND hMCI;
	HBITMAP bitmap;//对象图片句柄
	char c[100];
	int w,h;//图片的宽和高
	HDC Back;//地图设备场景
	HDC MainDC;//主场景设备
	HDC MemDC;//对象设备场景
	HBITMAP oldmak;//关联句柄
    Obj man[SuLiang];//声明物体结构
	CString nextmap;//下一副地图
	char appdir[256];//本地路径
	short int pause;//暂停游戏
	HDC SDC;//屏幕设备
	char dir[256];//目录路径
	CString cc;///临时变量
	HBITMAP bit0;
	HBITMAP bit1;//两个暂存位图空间
	char mapname[256];//地图名称
	char mapbak[256];//地图块名称
	short int num;//物体数量
	HDC dcDst;//旋转后的内存设备环境
	
	short int bx,by;//临时偏移量
	short int over;//游戏结束
	short int bmpnum;
	short int sys;//操作系统类型
	HBITMAP a;
	short int keyup,keydown,keyleft,keyright,keyspace;//玩家1按键
	short int keyup2,keydown2,keyleft2,keyright2,keyspace2;//玩家2按键
	int player[2];
//8幅图片
	CString bmpname[MAX_BMP];
	HDC bmp[MAX_BMP];
	short int door;//关卡
	HDC tmpbmp;//临时图片DC
	long int gtime;
	CString mapfile;

	//DirectX
//	LPDIRECTSOUND m_pDirectObject; //DX声音对象
    DDSURFACEDESC		 ddsd; //页面描述
	LPDIRECTDRAWSURFACE DXSPrimary;// DXDraw主页面
	HRESULT			 ddrval;
	LPDIRECTDRAW		 DXW;		// DXDraw对象
private:



	//定义类私有

};
