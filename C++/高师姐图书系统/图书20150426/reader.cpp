#include <iostream>
#include <iomanip>
#include "reader.h"
using namespace std;

void Reader::addreader(int n,char *na)		//增加读者，初始化读者数据 
	{ 
		tag=0;                        
		no=n;
		strcpy(name,na);
		for(int i=0;i<Maxzf;i++)
		zfbook[i]=0;
	};

void Reader::zfrowbook(int bookid)			//借书操作
	{
		for(int i=0;i<Maxzf;i++) 
		{ 
			if (zfbook[i]==0)			//如果还有借书的次数（最多5次）
			{
				zfbook[i]=bookid;		//借书
				return;					//退出循环（只借一本）
			}
		}  
	};

int Reader::retbook(int bookid)				//还书操作
	{ 
		for(int i=0;i<Maxzf;i++)
		{ 
			if(zfbook[i]==bookid)		//如果有借书
			{
				zfbook[i]=0;            //还书
				return 1;               //退出循环（1没什么用）   
			}
		}
		return 0;
	};
void Reader::disp()							//显示读者信息
	{ 
		cout << setw(5) << no <<setw(10) << name<<"    借书编号：[ ";
		for(int i=0;i<Maxzf;i++)
		if(zfbook[i]!=0)
		cout << zfbook[i] << " / ";
		cout << " ]"<<endl;  
	};

void RDatabase::readerdata()
{
    char choice;             
	char rname[20];							//读者名
	int readerid;							//读者编号
	Reader *r;								//读者指针方便下面的操作
	while (choice!='0')
	{   system("cls");
        cout <<"\n\n\t\t\t读   者   维   护\n\n";
		cout<<"\t\t=================================\n"<<endl;
		cout<<"\t\t======\t1   新      增\n";
		cout<<"\n\t\t======\t2   更      改\n";
		cout<<"\n\t\t======\t3   删      除\n";
		cout<<"\n\t\t======\t4   查      找\n";
		cout<<"\n\t\t======\t5   显      示\n";
		cout<<"\n\t\t======\t6   全      删\n";
		cout<<"\n\t\t======\t0   返      回\n"<<endl;
		cout<<"\t\t=================================\n"<<endl;
		cin >> choice;
		switch (choice)
		{
            case '1':
				cout << "输入读者编号:";
				cin >> readerid;
				cout << "输入读者姓名:";
				cin >> rname;
				addreader (readerid,rname);        //调用添加读者函数
				system("pause");break;
            case '2':
				cout << "输入读者编号:";
				cin >> readerid;
				r=query(readerid);                //先调用查找函数看看有没这读者
				if (r==NULL)
				{
					cout << " 该读者不存在  "<<endl;
					break;
				}
				cout << "输入新的姓名:";
				cin >> rname;                     
				r->setname(rname);                 //输入名字.....
				system("pause");break;
            case '3':
				cout << " 输入读者编号:";
                cin >> readerid;
				r=query(readerid);              //先调用查找函数看看有没这读者
				if (r==NULL)
				{
					cout <<" 该读者不存在" << endl;
					break;
				}
				r->delbook();						//调用删除函数              
				system("pause");break;
			case '4':
				cout << "读入读者编号:";
				cin >> readerid;
				r=query(readerid);
				if (r==NULL)
				{
					cout <<"该读者不存在"<< endl;
					break;
				}
				r->disp();							//调用读者类的输出函数   
			system("pause");break;
			case '5':
				disp();                             //调用该类的输出函数（即输出所有读者的信息）
				system("pause");break;
			case '6':
				clear();
				system("pause");break;
			case '0':
				break;
				default:cout<<"输入错误，请重新输入："<<endl;system("pause");break;
		}
	}
}