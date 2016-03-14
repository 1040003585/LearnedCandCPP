#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
static int n=0;
int comp(char*,char*);
class MyFriend
{
	unsigned int age;
	char name[12];
	char TelNo[12];
public:
	void getdata()
	{
		cout<<"(年龄 姓名 电话):";
		cin>>age>>name>>TelNo;
	}
	void disp()
	{
		cout<<setiosflags(ios::left)
		 <<setw(6)<<age<<setw(10)<<name<<setw(7)<<TelNo<<endl;
	}
	char *getname()
	{
		return name;
	}
};
void func1()
{
	ofstream output("MyFrd.dat");
	MyFriend s;
	
	cout<<"输入数据"<<endl;
	cout<<"我的朋友人数:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"第"<<i+1<<"个我的朋友";
		s.getdata();
		output.write((char *)&s,sizeof(s));
	};
	output.close();
}
void func2()
{
	ifstream input("MyFrd.dat");
	MyFriend s;
	cout<<"输入数据"<<endl;
	cout<<setiosflags(ios::left)
	<<setw(6)<<"年龄"<<setw(10)<<"姓名"<<setw(7)<<"电话"<<endl;
	input.read((char *)&s,sizeof(s));
	while(input)
	{
		s.disp();
		input.read((char*)&s,sizeof(s));
	};
	input.close();
}
void func3()
{
	char sname[10];
	fstream file("MyFrd.dat",ios::in);
	MyFriend one;
	file.seekg(0);
	cout<<"输入要查询的姓名（可只输入姓氏）:";
	cin>>sname;
	cout<<"输出查询结果:"<<endl;
	cout<<setw(6)<<"年龄"<<setw(10)<<"姓名"<<setw(6)<<"电话"<<endl;
    for(int i=0;i<n;i++)
	{
		file.read((char *)&one,sizeof(MyFriend));
		if(comp(one.getname(),sname)==1)
			one.disp();
	}
	file.close();
}
int comp(char s1[],char s2[])
{
	int i=0;
	while(s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i])
		i++;
	if(s1[i]=='\0' || s2[i]=='\0')
		return 1;
    else
		return 0;
}

void main()
{
	int sel;
	do
	{
		cout<<"选择（1:输入数据 2：输出数据 3:按姓名查询 其它退出）：";
		cin>>sel;
		switch(sel)
		{
         case 1:func1();break;
         case 2:func2();break;
		 case 3:func3();break;
		}
	}while(sel==1||sel==2||sel==3);
}
