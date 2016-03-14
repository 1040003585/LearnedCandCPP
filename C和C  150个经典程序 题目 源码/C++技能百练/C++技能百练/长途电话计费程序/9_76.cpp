#include<iostream.h>
#include<string.h>
#define Max 20
class Destination
{
protected:
	char from[Max];
	char to[Max];
public:
	Destination()
	{
		strcpy(from,"");strcpy(to,"");
	}
	Destination(char f[],char t[])
	{
		strcpy(from,f);strcpy(to,t);
	}
	void getdata()
	{
		cout<<"输入发话地点 收话地点:";
		cin>>from>>to;
	}
	void disp()
	{
		cout<<"计费从"<<from<<"到"<<to;
	}
};
class Time
{
protected:
	int hour,minute,second;
	double time;
public:
	Time(){time=0;}
	Time(double t){time=t;}
	void getdata()
	{
		cout<<"输入通话时间:时 分 秒";
		cin>>hour>>minute>>second;
		time=(double)(hour*3600+minute*60+second);
	}
	void disp()
	{
		cout<<"通话时间是"<<time<<"秒";
	}
};
class Price:public Destination,public Time
{
	double price;
public:
	Price():Destination(),Time()
	{price=0;}
	Price(char f[],char t[],double tt):Destination(f,t),Time(tt)
	{
		price=(int)((tt+5)/6)*0.06;
	}
	void getdata()
	{
		Destination::getdata();
		Time::getdata();
		price=(int)((time+5)/6)*0.06;
	}
	void disp()
	{
		cout<<"  ";
		Destination::disp();
		Time::disp();
		cout<<",话费是"<<price<<"元"<<endl;
	}
};
void main()
{
	Price A;
	A.getdata();
	Price B("AAA","BBB",123);
	cout<<"输出结果:"<<endl;
	A.disp();
	B.disp();
}
