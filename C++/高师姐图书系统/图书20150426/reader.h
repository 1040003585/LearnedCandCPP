#include <iostream>
#include <iomanip>
#include <fstream>//输入/输出文件流类
using namespace std;
const int Maxr=3000;//最多的读者
const int Maxzf=5;//每位读者最多借五本书
class Reader       
{   
 private:
	int tag;							//删除标记 1:已删 0:未删
	int no;								//读者编号
	char name[10];						//读者姓名
	int zfbook[Maxzf];					//所借图书
	int ryear[Maxzf];
	int rmonth[Maxzf];
	int rday[Maxzf];
 public:
	Reader() {}							//构造函数，没用的，意思一下
    char *getname() {return name;}      //获取姓名
	int gettag() {return tag;}			//获取删除标记
    int getno() {return no;}			//获取读者编号
    void setname(char na[])				//设置姓名
	{strcpy(name,na); }
	void addreader(int ,char *);		//增加读者，初始化读者数据 
	void zfrowbook(int);			    //借书操作
	int retbook(int bookid);			//还书操作
	void disp();						//显示读者信息
	void alsotime(int y,int m,int d,int bookid)
	{
		int i;
		for( i=0;i<Maxzf;i++) 
		{if(zfbook[i]==bookid)		
		break;}
	 ryear[i]=y;rmonth[i]=m;rday[i]=d;
	}
	void showalsotime(int bookid)
	{
		int i;
		for( i=0;i<Maxzf;i++) 
		{
			if(zfbook[i]==bookid)		
				break;
		}
		cout<<"归还日期为"<<ryear[i]<<"/"<<rmonth[i]<<"/"<<rday[i]<<"天"<<endl;
	}
	int rebook(int bookid)				//只为检验是否有借这本书
	{ 
		for(int i=0;i<Maxzf;i++)
		{ 
			if(zfbook[i]==bookid)		
			{
				return 1;                  
			}
		}
		return 0;
	};


	void delbook()	     //设置读者删除标记 1:已删 0:未删
	{char judge;   
    cout<<"您确定要删除该的读者？(y/n)"<<endl;
	cin>>judge;
	if(judge=='y'||judge=='Y')
	tag=1;
	else if(judge=='n'||judge=='N')
    {cout<<"未删除此读者"<<endl;return;}
	else
	{cout<<"输入错误"<<endl;
	return;}
	}
};
 
//读者类库，实现建立读者的个人资料
class RDatabase
{  
 private:
	int top;							//读者记录指针
	Reader read[Maxr];					//读者记录
 public:
	RDatabase()   //构造函数，将reader.txt读到read[]中，当对象创建时就自动调用
	{
		Reader s;				//定义一个读者类方便读者文件的读入
		top=-1;					//读者指针，-1既没有读者，0为第一个读者
		fstream file("reader.txt",ios::in);//打开一个输入文件
		while (1)				//读入读者数据
		{
			file.read((char *)&s,sizeof(s));
			if (!file)break;
			top++;				//读入1个就加一
			read[top]=s;		//读入一个读者数据
		}
		file.close();			//关闭 reader.txt
	}
    void clear()				//删除所有读者信息
	{char judge;
    cout<<"您确定要删除所有的读者？(y/n)"<<endl;
	cin>>judge;
	if(judge=='y'||judge=='Y')
	top=-1;
	else if(judge=='n'||judge=='N')
    {cout<<"未删除此读者"<<endl;return;}
	else
	{cout<<"输入错误"<<endl;
	return;}
	}
	int addreader(int n,char *na)//添加读者时先查找是否存在
	{
		Reader *p=query(n);        //query为查找读者，n为所要查找的读者的编号
		if (p==NULL)               //没有该读者，即可添加
		{
			top++;                    
			read[top].addreader(n,na);//添加一个读者
			cout<<"添加成功！"<<endl;
			return 1;                 //没什么实际作用
		}
		else
		{
			cout<<"该读者已存在！"<<endl;
			return 0;
		}
	}
	Reader *query(int readerid)      //查找读者，readerid为所要查找的读者的编号
	{
		for (int i=0;i<=top;i++)
		if (read[i].getno()==readerid && 
		read[i].gettag()==0)        //编号存在和未被删除
		{
			return &read[i];        //找到了读者
		}
		return NULL;             //未找到
	}
	void disp()          //输出所有读者信息
	{
        for (int i=0;i<=top;i++)
		read[i].disp();//disp读者类的输出函数
	}
	void readerdata();			//声明读者库维护
	~RDatabase()  //析构函数，将read[]写到reader.txt文件中，析构函数是到所定义的对象的生命结束时才会调用的
	{
		ofstream file("reader.txt",ios::out);   //以二进制的方式写入文件
        for (int i=0;i<=top;i++)
		if (read[i].gettag()==0)
		file.write((char *)&read[i],sizeof(read[i]));
		file.close();
	}
};