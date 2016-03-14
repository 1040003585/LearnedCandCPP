#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int r;	char c;
	fstream file;
	char fn[15],buf[100];
	cout<<"Input the file'name:";
	cin>>fn;
	file.open(fn,ios::nocreate|ios::in);  
	//针对文件后缀为（.txt  .h  .cpp .pas等）文件
	if(!file)
	{
		cout<<"The file you wanted open does NOT exist.";
		abort();  //#include<stdlib.h>
	}
	while(!file.eof())
	{
		r=0;
		while(!file.eof() && r<23)
		{
			file.getline(buf,100);
			cout<<buf<<endl;
			r++;
		}
		cout<<"press 'enter' key...";
		c=getchar();  //#include<stdio.h>
	}
	file.close();
}
