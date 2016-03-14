#include <iostream>
#include <iomanip>
#include <string>
#include "reader.h"
#include "book.h"
#include <fstream>							//输入/输出文件流类
using namespace std;

int maxb=-1;					//定义一全局变量表示当前书的数量

//**************************************************************************
//图书部分

void Book::tinput()										//输入出版时间
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     
 bool flag=false;
 while(!flag)
      {cout<<"请输入一个日期"<<endl;  
       cin>>time.year>>time.mon>>time.day; 
          if(time.year % 4 == 0 && time.year % 100 != 0 ||time.year % 400 == 0)      
	          m[2]++;  
          if(time.year<0||time.mon<0||time.mon>12||time.day>m[time.mon])        
	          cout<<"此日期无效"<<endl;
		  else
			  flag=true;	      
      }
};

void Book::input()										//输入图书信息
{   
	cout<<"书名："<<endl;
	cin>>bname;
	cout<<"作者："<<endl;
	cin>>author;
	cout<<"书的类别："<<endl;
	cin>>classif;
	cout<<"书的价格："<<endl;
	cin>>price;
	cout<<"出版单位："<<endl;
	cin>>pubunit;
	tinput();
};

void Book::tidisplay()									//输出出版时间
{
	cout<<"   出版时间:"<<time.year<<"年"<<time.mon<<"月"<<time.day<<"日"<<endl;
};

void Book::display()										//输出图书信息
{
	cout<<"登录号:"<<num<<"   书名:"<<bname<<"   作者:"<<author<<endl;
	cout<<"书的分类:"<<classif<<"   价格:"<<price<<"    库存量"<<stock<<endl;
	cout<<"出版单位:"<<pubunit;
	tidisplay(); 
};

void openbook(Book b[])
{Book s;  maxb=-1;
	fstream file("book.txt",ios::in);//打开一个输入文件
		while (1)				       //读入图书数据
		{
			file.read((char *)&s,sizeof(s));
			if (!file)break;
			maxb++;				//读入1个就加一
			b[maxb]=s;		//读入一个书本数据
		}
		file.close();			//关闭 book.txt

}


void closebook(Book b[])  //将book[]写到book.txt文件中，
	{
		ofstream file("book.txt",ios::out);   //以二进制的方式写入文件
        for (int i=0;i<=maxb;i++)
		file.write((char *)&b[i],sizeof(b[i]));
		file.close();
	}

	
void inputnu(Book b[],int x)      //输入图书的登录号，因为登录号是唯一的，所以要独立出来
{int i;bool t;                    //既要检验登录号有没重复
 do
 {
 t=true;                          
 cout<<"请输入书的登录号"<<endl;
 cin>>b[x].num;
 for(i=0;i<x;i++)
   if(b[i].num==b[x].num)
   {t=false;cout<<"该登录号已有书使用！请重新输入！"<<endl;}
 }while(t==false);
}

void findbook(Book b[],string na,int x)		//给新书入库使用的函数，作用是检查有没重复的书
{
	int i;
	if(x==0)								//X为当前添加的书的下标
	 ;
	else
	for(i=0;i<x;i++)						//寻找有没与当前要添加的书相同
    {
		if(b[i].getbname()==na)
		{
			b[i].stock++;
			b[x].stock++;
		}
		i++;
	}
}
 
void finda(Book b[],string au)				//按作者查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
}

void findb(Book b[],string bna)				//按书名查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getbname()==bna)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
}

void findc(Book b[],string clf)				//按书类查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
}

void findab(Book b[],string au,string bna)				//按作者和书名查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getbname()==bna)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
} 

void findac(Book b[],string au,string clf)				//按作者和书类查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
} 

void findbc(Book b[],string bna,string clf)				//按书名和书类查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getbname()==bna&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
}                      

void findabc(Book b[],string au,string bna,string clf)				//按作者和书名和分类查找 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getbname()==bna&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
}

                         

void Storage(Book b[])								//新书进库
{  
	int i, n;											//一次要添加的数量
	cout<<"请输入要添加的数量"<<endl;
	cin>>n;      
	for( i=maxb+1;i<maxb+n+1;i++)							//m为当前书的总数，既刚刚读取进来的数量，n为这次要添加的数量   
	{   inputnu(b,i);
		b[i].input();								//调用基类的添加函数
		b[i].stock=1;								//数量默认为1
	}                                             
	for(i=maxb+1;i<maxb+n+1;i++)                 
		findbook(b,b[i].getbname(),i);					//调用该函数是要看有没有与现在要添加的书名相同的
	maxb=maxb+n;											
	closebook(b);
}
void Cancell(Book b[])								        //注销书本
{          
	int i=0,x;int nu;bool t=false;char judge;                            //x为要删除的书的下标                  
	cout<<"请输入要删除的登录号"<<endl;
	cin>>nu;
	while(b[i].num!=0)               
    {
		if(b[i].num==nu)
		{t=true;break;}
		i++;
	}
	if(t==false)
	{cout<<"查无此书"<<endl;return;}
	x=i;
	cout<<"您确定要删除此书？(y/n)"<<endl;
	 cin>>judge;
	if(judge=='y'||judge=='Y')
	{
		if(x==maxb)b[i].num=0;                   //如果要删除的刚好是最后一本，那就直接让他等于0  
		else
		for(i=x;i<=maxb-1;i++)								//X为当前书的下标      
	    b[i]=b[i+1];                                         //不是的话就用X后面的书覆盖前面的					                    
		maxb--;										//总数减一
		closebook(b);
		cout<<"删除成功！"<<endl;
	}
    else if(judge=='n'||judge=='N')
	{cout<<"未删除此书"<<endl;return;}
	else
	{cout<<"输入错误"<<endl;
	return;}
	closebook(b);
}

int beday;                  //变量

void botime(Reader *p,int n)                //借书时间
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int year,month,day,days=30;  
 bool flag=false;
 while(!flag)
      {cout<<"请输入借书的日期"<<endl;  
       cin>>year>>month>>day; 	   
          if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)      
	          m[2]++;  
          if(year<0||month<0||month>12||day>m[month])        
	          cout<<"此日期无效"<<endl;
		  else
			 flag=true;
 }
      cout<<"借书时间为30天"<<endl;
      day=day+days;
	  if(day>m[month])
	  {day=day-m[month];
	  month++;}
	  if(month>12)
	  {month=1;
	  year++;}
	  cout<<"归还日期为"<<year<<"/"<<month<<"/"<<day<<"天"<<endl;
      p->alsotime(year,month,day,n);
	  for(int i=0;i<=month;i++)
      day=day+m[i];
	  beday=day;
	  
}

void altime(Reader *p,int n)             //还书时间与罚款
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int year,month,day,i;  
int biday=0;float fined;
 bool flag=false;
 while(!flag)
      {cout<<"请输入还书的日期"<<endl;  
       cin>>year>>month>>day; 	   
          if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)      
	          m[2]++;  
          if(year<0||month<0||month>12||day>m[month])        
	          cout<<"此日期无效"<<endl;
		  else
			 flag=true;
 }
   p->showalsotime(n);
   
   for(i=0;i<=month;i++)
    day=day+m[i];
    biday=biday+day;
	if(biday-beday>0)
    {cout<<"请输入超出一天的罚金(元)"<<endl;
	cin>>fined;
    cout<<"已经逾期"<<biday-beday<<"天"<<endl;
	cout<<"罚金为"<<fined*(biday-beday)<<"元"<<endl;}
	else
		cout<<"能及时还书，还书成功！"<<endl;

}   



void borrow(Book b[])							//借阅书本
{   
	int n,rn,i=0;bool t=false;		//n为要借的书本编号，rn为要借书的学生编号，s作用看下面
	RDatabase rea;								//rea的定义只是为了对学生类进行操作
	cout<<"输入该学生学号"<<endl;
	cin>>rn;									//输入学生编号
	Reader *p=rea.query(rn);					//查找有没该学生
	if (p==NULL)                                //如果没有
	{
		cout<<"该读者不存在！"<<endl;
		return;
	}											//如果没有就退出了	  
		cout<<"输入该学生所要借的书的编号"<<endl;
		cin>>n;                                 //有就输入书的编号
	     while(b[i].num!=0)                     //找要借的书
		{
			if(b[i].num==n)                   
			{t=true;break;}                     //如果收索到要的书，s就变成true
			i++;	
		}
		if(t==false)                            //如果没有的话
		{cout<<"查无此书！"<<endl;return;}
		if(b[i].mark==false)					//如果书没有借出
		{
			cout<<"该书未借出！信息为"<<endl; 
			b[i].display();
			p->zfrowbook(n);						//在学生类那里关联这本书
			b[i].mark=true;							//书借出
			b[i].stock--;							//库存减一
            botime(p,n);
			cout<<"借书成功！！"<<endl;
		} 
		else
			cout<<"借书失败！该书已被借出！"<<endl;		    	
		 closebook(b);
			return;
}


void alsobook(Book b[])						 //归还书本
{   
	int n,rn,i=0;bool t=false;				 //n为要还的书本编号，rn为要还书的学生编号
	RDatabase rea;							 //rea的定义只是为了对学生类进行操作
	cout<<"输入该学生学号"<<endl;
	cin>>rn;								 //下面都与借书的类似
	Reader *p=rea.query(rn);
	if (p==NULL)
	{cout<<"该读者不存在！"<<endl;return;}	
		cout<<"请输入要还的书的编号"<<endl;
		cin>>n;
		while(b[i].num!=0)
		{
			if(b[i].num==n)
			{t=true;break;}
			i++;
			
		}
		if(t==false)                            //如果没有的话
		{cout<<"查无此书！"<<endl;return;}
		if(b[i].mark==false)
		{cout<<"未有该书出借记录！"<<endl;return;}
		if(p->rebook(n)==1)                    //如果书没还
		{
			cout<<"该书未归还！信息为"<<endl;  
			b[i].display();                    
			b[i].mark=false;                   //书还了        
			b[i].stock++;                      //库存加一
			altime(p,n);
			p->retbook(n);
		}
		else
		cout<<"还书失败！！该书不是该读者借的！！"<<endl;
		closebook(b);
	}

void delall(Book b[])             //删除所有书
{   
	char judge;
   cout<<"您确定要删除所有的书？(y/n)"<<endl;
    cin>>judge;
	if(judge=='y'||judge=='Y')
	{
	for(int i=0;i<=maxb;i++)
	b[i].num=0;
	maxb=-1;
	}
	else if(judge=='n'||judge=='N')
    {cout<<"未删除此书"<<endl;return;}
	else
	{cout<<"输入错误"<<endl;
	return;}
	closebook(b);
}

void Changbo(Book b[])          //更改书本
{    
	int nu,i=0;bool s=false;     //nu为你要更改的书的登录号，s是用来判断有没这本书，false表示没有
	cout<<"请输入要更改的登录号"<<endl;
	cin>>nu;
	while(b[i].num!=0)
    {
		if(b[i].num==nu)
		{   b[i].display();
		cout<<"请输入图书更改后的信息"<<endl;
			b[i].input();
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"查无此书!"<<endl;
	closebook(b);
}

void output(Book b[])          //输出所有的书本                
{
    for(int i=0;i<=maxb;i++)               
	{
		b[i].display();	
		cout<<endl;
		if(b[i].stock>0)
		 cout<<"该图书可供借出"<<endl;
		 else
			cout<<"该图书已借出"<<endl;
		
	 cout<<"----------------------------------------------------------------"<<endl;
	}
}

void bookdata(Book b[])						//图书管理
{
	char choice;
	while(choice!='0')
	{   system("cls");
		cout <<"\n\n\n\t\t\t图  书  管  理\n "<<endl;
		cout<<"\t\t=================================\n"<<endl;
		cout<<"\t\t======\t1   新     增\n";
		cout<<"\n\t\t======\t2   更     改\n";
		cout<<"\n\t\t======\t3   注     销\n";
		cout<<"\n\t\t======\t4   查     找\n";
		cout<<"\n\t\t======\t5   显     示\n";
		cout<<"\n\t\t======\t6   全     删\n";
		cout<<"\n\t\t======\t0   返     回"<<endl;
		cout<<"\n\t\t=================================\n"<<endl;
		cin>>choice;
		switch (choice)
		{
			case '1':
				Storage(b);system("pause");break;
			case '2':
				Changbo(b);system("pause");break;             
			case '3':
				Cancell(b);system("pause");break;
		case '4':
			{
				cout<<"                    1)按 作 者 查 找"<<endl;
				cout<<"                    2)按 书 名 查 找"<<endl;
				cout<<"                    3)按 书 类 查 找"<<endl;
                cout<<"                    4)按 作 者 和 书 名 查 找"<<endl;
				cout<<"                    5)按 作 者 和 书 类 查 找"<<endl;
				cout<<"                    6)按 书 名 和 分 类 查 找"<<endl;
				cout<<"                    7)按 作 者 和 书 名 和 书 类 查 找"<<endl;
				
				char c1;
				string bna;                             //输入了要查找的书名或作者名
				string au;
				string clf;
				cin>>c1;
				if(c1=='1')
				{
					cout<<"请输入作者姓名"<<endl;
					cin>>au;
					finda(b,au);
					system("pause");break;
				}
				else if(c1=='2')
				{
					cout<<"请输入书名"<<endl;
					cin>>bna;
					findb(b,bna);
					system("pause");break;
				}
				else if(c1=='3')
				{
					cout<<"请输入书类"<<endl;
					cin>>clf;
					findc(b,clf);
					system("pause");break;
				}
				else if(c1=='4')
				{
					cout<<"请输入作者和书名"<<endl;
					cin>>au>>bna;
					findab(b,au,bna);
					system("pause");break;
				}
				else if(c1=='5')
				{
					cout<<"请输入作者和书类"<<endl;
					cin>>au>>clf;
					findac(b,au,clf);
					system("pause");break;
				}
				else if(c1=='6')
				{
					cout<<"请输入书名和书类"<<endl;
					cin>>bna>>clf;
					findbc(b,bna,clf);
					system("pause");break;
				}
				else if(c1=='7')
				{
					cout<<"请输入作者和书名和书类"<<endl;
					cin>>au>>bna>>clf;
					findabc(b,au,bna,clf);
					system("pause");break;
				}
				else
				{  
					cout<<"输入错误！！"<<endl;
					system("pause");break;
				}       
			}
			case '5':
				output(b);system("pause");break;
			case '6':
				delall(b);system("pause"); break;              
			case '0':
				break;
			default:
				{
					cout<<"输入错误！！"<<endl;
					system("pause");
					break;
				}
		}
	}
}

void sav()											//这里特地定义一个函数，为了让读者库读写方便
{
	RDatabase rea;                  
	rea.readerdata();
}
int main()
{
	Book b[100];                    //定义100本书
	for(int i=0;i<100;i++)          //初始化这100本书
	{
		b[i].num=0;                  //登录号都为0
		b[i].mark=false;            //未借出
	}
    openbook(b);
		char choice;
		while(choice!='0')
		{       system("cls");
				cout <<endl<<endl<<"\t\t\t图 书 管 理 系 统\n\n\n";
				cout<<"\t\t=================================\n"<<endl;
				cout <<"\t\t=======\t1    借       书\n";
				cout<<"\n\t\t=======\t2    还       书 \n";
				cout<<"\n\t\t=======\t3    图 书 管 理\n";
				cout<<"\n\t\t=======\t4    读 者 管 理\n";
				cout<<"\n\t\t=======\t0    退       出\n"<<endl;
				cout<<"\t\t=================================\n"<<endl;
				cin>>choice;
				switch (choice)
				{
					case '1':
						borrow(b);system("pause");break;				//借书
					case '2':
						alsobook(b);system("pause");break;			  //还书
					case '3':
						bookdata(b);break;					         //图书管理
					case '4':
						sav();break;								//读者管理
					case '0':
						return 0;
						break;

					default:
						cout<<"输入错误！！"<<endl;
						return 0;
				}
			}
			return 0;
}