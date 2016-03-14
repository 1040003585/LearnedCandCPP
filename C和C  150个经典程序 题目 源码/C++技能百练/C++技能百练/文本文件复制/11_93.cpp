#include<iostream.h>
#include<fstream.h>
void main()
{
	fstream file1,file2;
	char fn1[10],fn2[10],ch;
	cout<<"请输入源文件名:";
	cin>>fn1;
	cout<<"请输入目标文件名:";
	cin>>fn2;
	file1.open(fn1,ios::in);
	file2.open(fn2,ios::out);
	while((ch=file1.get())!=EOF)
	{
		cout<<ch;
		file2.put(ch);
	}
	file1.close();
	file2.close();  
}
/*第二种按行逐一复制的程序为：
#include<iostream.h>
#include<fstream.h>
void main()
{
	fstream file1,file2;
	char fn1[10],fn2[10],buf[100];
	cout<<"请输入源文件名:";
	cin>>fn1;
	cout<<"请输入目标文件名:";
	cin>>fn2;
	file1.open(fn1,ios::in);
	file2.open(fn2,ios::out);
	while(!file1.eof())
	{
		file1.getline(buf,100);
		file2<<buf;
		file2<<"\n";
	}
	file1.close();
	file2.close();
}  */
