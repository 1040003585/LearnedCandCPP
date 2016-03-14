#include<iostream.h>
#include<string.h>
#define max 100
class Card
{
	int top;  //当前记录位置标记
	char date[max][11];  //每次交易的日期记录
	int money[max];  //记录每次交易金额
	int rest[max];  //记录每次交易后的余额
	static int sum;  //	静态数据成员,记录累计余额
public:
	Card() {top=0;}
	void Cardin(char d[],int m)
	{
		strcpy(date[top],d);
		money[top]=m;
		sum+=m;
		rest[top]=sum;
		top++;
	}
	void Cardout(char d[],int m)
	{
		if(sum>=m)
		{
			strcpy(date[top],d);
		    money[top]=-m;
		    sum-=m;
		    rest[top]=sum;
	    	top++;
		}
		else
			cout<<"警告："<<d<<"交易失败！您的户面余额已不足！请续存！"<<endl;
	}
	void disp()
	{
		int i;
		cout<<"    日期    存入    取出    余额"<<'\n';
		for(i=0;i<top;i++)
		{
			cout.width(10);
			cout<<date[i];
			if (money[i]<0)
			{
				cout.width(13);
				cout<<-money[i];
                cout.width(9);
			    cout<<rest[i]<<endl;
			}
			else
			{
				cout.width(6);
				cout<<money[i];
				cout.width(16);
			    cout<<rest[i]<<endl;
			}
		}
		cout<<"您的帐户余额为："<<sum<<endl;
	}
};
int Card::sum=0;
void main()
{
	Card obj;
	obj.Cardin("2001.2.5",1000);
	obj.Cardin("2002.12.15",2000);
	obj.Cardout("2002.11.5",500);
	obj.Cardout("2003.3.5",400);
	obj.Cardout("2003.5.15",3000);
	obj.disp();
}
