//Download by http://www.NewXing.com


/*常数定义*/
///////////////////////////////////////////////////

///
#define HEIGHT 600//游戏显示区高
#define WIDTH 800//游戏显示区宽
#define Timer 100//定时器
#define SuLiang 200
#define GunStep 9//子弹速度
#define shotmeter 4//子弹无效射程
#define manStep 4//步长
#define UpGun 3 //装弹速度
#define Okgun 13
#define MAX_BMP 50
#include <math.h>

/**********************************/
#include <mmsystem.h>
#pragma comment (lib,"winmm.lib")//时间函数库
#include <wingdi.h>
#pragma comment (lib,"gdi32.lib")
#pragma comment (lib,"msimg32.lib")//透明显示库
#include <vfw.h>//
#pragma comment (lib,"vfw32.lib")/////是声音类库定义
#include <ddraw.h>
//#include <dsound.h>
#pragma comment (lib,"ddraw.lib")//DirectX库