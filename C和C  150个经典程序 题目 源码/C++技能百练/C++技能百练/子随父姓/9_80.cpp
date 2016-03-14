#include<iostream.h>
#include<string.h>
class father
{
protected:
	char* fname;
	char* sname;
	int age;
public:
	father()
	{cout<<"father默认构造函数调用!"<<endl;fname=NULL;sname=NULL;}
	father(char *fn,char *sn,int a)
	{
		cout<<"father构造函数调用!"<<endl;
		fname=new char[strlen(fn)+1];
		strcpy(fname,fn);
		sname=new char[strlen(sn)+1];
		strcpy(sname,sn);
		age=a;
	}
	~father()
	{
		cout<<"father析构函数调用!"<<endl;
		delete fname;
		delete sname;
	}
	char *getfname(){return fname;}
	void show(){cout<<fname<<sname<<"  年龄:"<<age;}
};
class mother
{
protected:
	char* fname;
	char* sname;
	int age;
public:
	mother()
	{cout<<"mother默认构造函数调用!"<<endl;fname=NULL;sname=NULL;}
	mother(char *fn,char *sn,int a)
	{
		cout<<"mother构造函数调用!"<<endl;
		fname=new char[strlen(fn)+1];
		strcpy(fname,fn);
        sname=new char[strlen(sn)+1];
		strcpy(sname,sn);
		age=a;
	}
	~mother()
	{
		cout<<"mother析构函数调用!"<<endl;
		delete fname;
		delete sname;
	}
	char *getfname(){return fname;}  //此句可省略
	void show(){cout<<fname<<sname<<"  年龄:"<<age;}
};
class child:public mother,public father
{
private:
	father* myfather;
	mother* mymother;
public:
	child(){cout<<"child构造函数调用!"<<endl;}
	child(father& fa,mother &mo,char *na,int a)
		:myfather(&fa),mymother(&mo)
	{
		cout<<"child构造函数调用!"<<endl;
      //不能省略mother::否则出现二义性
		mother::fname=new char[strlen(fa.getfname())+1];  
	//如子随母姓，则改为strcpy(mother::fname,mo.getfname());
		strcpy(mother::fname,fa.getfname());
        mother::sname=new char[strlen(na)+1];
		strcpy(mother::sname,na);
		mother::age=a;  //不能写成age=a; 
	}
	~child(){cout<<"child析构函数调用!"<<endl;}
	void show()
	{
		cout<<"  姓名:"; mother::show();
		cout<<endl;
		cout<<"父亲:"; myfather->show();
		cout<<endl;
		cout<<"母亲:"; mymother->show();
		cout<<endl;
	}
};
void main()
{
	father fa1("欧阳","东海",50),fa2("张","伟大",40);
	mother mo1("李","超丽",47),mo2("许","英",35);
	child ch1(fa1,mo1,"智超",23),ch2(fa2,mo2,"宁",10);
	cout<<"输出结果:"<<endl;
	ch1.show();
	ch2.show();
}
