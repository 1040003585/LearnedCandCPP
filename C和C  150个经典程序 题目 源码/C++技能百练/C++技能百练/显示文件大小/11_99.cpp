#include<iostream.h>
#include<fstream.h>
void main()
{
	char fname[20];
	cout<<"输入文件名:";
	cin>>fname;
	ifstream file(fname,ios::nocreate|ios::in);
	try
	{
		if(file.fail())
		//当文件不存在时，file.fail()返回真
			throw "error!";
	}
	catch(char *s)
	{
		cout<<s<<fname<<"文件不存在!"<<endl;
		return;
	}
	file.seekg(0,ios::end);
	//此句意为将文件的读指针移至文件末尾
	cout<<fname<<"文件大小:"<<file.tellg()<<"Bytes"<<endl;
	//tellg()函数返回当前文件指针的位置
}
