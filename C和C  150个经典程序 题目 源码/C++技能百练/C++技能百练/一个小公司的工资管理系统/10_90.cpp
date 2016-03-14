#include<iostream.h>
#include<string.h>
class employee
{
protected:
	int no;
	char *name;
	float salary;
	static int totalno;
public:
	virtual void pay()=0;
	virtual void display()=0;
	employee()
	{
		char temname[20];
        no=totalno++;
		cout<<"职工姓名:";
		cin>>temname;
		name=new char[strlen(temname)+1];
		strcpy(name,temname);
		salary=0;
	}
	~employee()
	{ 
		delete[] name;
	}
};
class technician:public employee
{
private:
	float hourlyrate;
	int workhours;
public:
	technician()
	{hourlyrate=100;}
	void pay()
	{
		cout<<name<<"本月工作时数:";
		cin>>workhours;
		salary=hourlyrate*workhours;
	}
	void display()
	{
		cout<<"兼职技术人员"<<name<<"(编号为"<<no\
			<<")"<<"本月工资:"<<salary<<endl;
	}
};
int employee::totalno=100;  //静态数据成员totalno在类外进行初始化
class saleman:virtual public employee
{
protected:
	float commrate;
	float sales;
public:
	saleman()
	{commrate=0.04f;}
	void pay()
	{
		cout<<name<<"本月销售额:";
		cin>>sales;
		salary=sales*commrate;
	}
	void display()
	{
		cout<<"销售员"<<name<<"(编号为"<<no<<")"\
			<<")"<<"本月工资:"<<salary<<endl;
	}
};
class manager:virtual public employee
{
protected:
	float monthlypay;
public:
	manager()
	{ 
		monthlypay=8000; 
	}
	void pay(){salary=monthlypay;}
	void display()
	{
		cout<<"经理"<<name<<"(编号为"<<no<<")"\
			<<")"<<"本月工资:"<<salary<<endl;
	}
};
class salesmanager:public manager,public saleman
{
public:
	salesmanager()
	{
		monthlypay=5000;
		commrate=0.005f;
	}
	void pay()
	{
		cout<<name<<"所管部门月销售量:";
		cin>>sales;
		salary=monthlypay+commrate*sales;
	}
	void display()
	{
		cout<<"销售经理"<<name<<"(编号为"<<no<<")"\
			<<")"<<"本月工资:"<<salary<<endl;
	}
};
void main()
{
	manager m1;
	technician t1;
	saleman s1;
	salesmanager sm1;
	employee* em[4]={&m1,&t1,&s1,&sm1};
	for(int i=0;i<4;i++)
	{
		em[i]->pay();
		em[i]->display();
	}
}
