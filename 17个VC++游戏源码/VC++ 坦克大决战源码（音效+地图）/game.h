//Download by http://www.NewXing.com
/*game.h



  */
#include "��������.h"
//  game��

typedef struct
{
	short int jixu,//���
		HP,//����
		MP,//������
		BP,//������
		exp,//����
		exp2,//�´�����

	w,h,//�ߴ�.
	lv,//�ȼ�
	x,y,//����
	x0,y0,//Ŀ��λ��
	lb,//���
	m0,m1,//��ʼֵ,����ֵ
	gun,//�ڵ�װ��
	js,//��ɫ
	fw,//��λ(1�� 2�� 3�� 4��)
	step,//����
	p,//ͼ�κ�
	z,//ͼ�ο�
	over,//ɾ��
	px,py;//����ƫ����
	char name[256];
	HDC bmp;//ͼƬ
}Obj;




///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
class game
{
	
/////////////////////�ຯ��////////////////////
public:
	game();
	~game();

	BOOL loadbmp(CString cc);//��BMPͼƬ����
	void exit();
	BOOL loadmap(CString mapfile);//�����ͼ����
	void movman(int i);//����ƶ� 
	void TransparentBlt2(HDC hdc0,int nX0,int nY0,int nW0,int nH0,HDC hdc1,					
		int nX1,int nY1,int nW1,int nH1,UINT Tcol);	//͸�����ƺ���
	BOOL init(CString map);//��ʼ��	
	//void Rotate(HDC dcSrc,int SrcWidth,int SrcHeight,double angle);//��תͼ�κ���
	void setobj(int i);//������ʾ
	void getpic(CString cc);//��ͼ����HDC
	void getpicdata(CString cc,int i);//����picֵ
	void sort();//����������ʾǰ��
	void game::Delete(int i);//ɾ������
	BOOL lookit(int i);//������ײ.�е�
	void fire(int i);//����������
	void Sound(CString cc);//����Wav
	void bom(int x,int y);//��ը
	void ai(int i);//�����ж�
	void Music(CString cc);//��������
	bool look(int x,int y,short j);//�鿴�ϰ���
	void getpic2(CString p);//����ڴ�ͼƬ
	void loadbmp2(CString n,CString cc);//����ͼƬ
	bool initDX();//����DX����
//////////////////���������////////////////////
public:
	HWND hMCI;
	HBITMAP bitmap;//����ͼƬ���
	char c[100];
	int w,h;//ͼƬ�Ŀ�͸�
	HDC Back;//��ͼ�豸����
	HDC MainDC;//�������豸
	HDC MemDC;//�����豸����
	HBITMAP oldmak;//�������
    Obj man[SuLiang];//��������ṹ
	CString nextmap;//��һ����ͼ
	char appdir[256];//����·��
	short int pause;//��ͣ��Ϸ
	HDC SDC;//��Ļ�豸
	char dir[256];//Ŀ¼·��
	CString cc;///��ʱ����
	HBITMAP bit0;
	HBITMAP bit1;//�����ݴ�λͼ�ռ�
	char mapname[256];//��ͼ����
	char mapbak[256];//��ͼ������
	short int num;//��������
	HDC dcDst;//��ת����ڴ��豸����
	
	short int bx,by;//��ʱƫ����
	short int over;//��Ϸ����
	short int bmpnum;
	short int sys;//����ϵͳ����
	HBITMAP a;
	short int keyup,keydown,keyleft,keyright,keyspace;//���1����
	short int keyup2,keydown2,keyleft2,keyright2,keyspace2;//���2����
	int player[2];
//8��ͼƬ
	CString bmpname[MAX_BMP];
	HDC bmp[MAX_BMP];
	short int door;//�ؿ�
	HDC tmpbmp;//��ʱͼƬDC
	long int gtime;
	CString mapfile;

	//DirectX
//	LPDIRECTSOUND m_pDirectObject; //DX��������
    DDSURFACEDESC		 ddsd; //ҳ������
	LPDIRECTDRAWSURFACE DXSPrimary;// DXDraw��ҳ��
	HRESULT			 ddrval;
	LPDIRECTDRAW		 DXW;		// DXDraw����
private:



	//������˽��

};
