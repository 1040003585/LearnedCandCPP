#include <string.h>
#include <iostream.h>
class student
{
	public:
		student(char * pName="no name",int ssId=0)
		{
			id=ssId;
			name=new char[strlen(pName)+1];
			strcpy(name,pName);
			cout<<"construct new student "<<pName<<endl;
		}
		//错误！不能如此编写copy函数,因为实现的是前浅拷贝
	/*	void copy(student & s)
		{
			cout<<"construct copy of"<<s.name<<endl;
			strcpy(name,s.name);
			id=s.id;
		}*/
		void copy(student & s)  //资源复制函数
		{
		    if(this==&s)
			{
		    	cout<<"错误:不能将一个对象复制到自己！"<<endl;
		    	return;
			}
	    	else
			{
			    name=new char[strlen(s.name)+1];        // ①分配新的堆内存
		        strcpy(name,s.name);					// ②完成值的复制
		        id=s.id;
		    	cout<<"资源复制函数被调用！"<<endl;
			}
			
		}
		void disp()
		{
			cout<<"Name:"<<name<<"  Id:"<<id<<endl;
		}
		~student()
		{
			cout<<"Destruct "<<name<<endl;
			delete name;
		}
	private:
		int id;
		char * name;
};

void main()
{
	student a("Kevin",12),b("Tom",23);   // 调用普通的构造函数
    a.disp();
	b.disp();
    a.copy(a);
    b.copy(a);      // 调用资源复制函数
	a.disp();
	b.disp();
}
