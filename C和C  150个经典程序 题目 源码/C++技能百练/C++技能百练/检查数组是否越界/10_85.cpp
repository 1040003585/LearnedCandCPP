#include<iostream.h>
#include<string.h>
class words
{
	int len;
	char *str;
public:
	int getlen(){return len;}
	words(char *s)
	{
		str=new char[strlen(s)+1];
		strcpy(str,s);
		len=strlen(s);
	}
	~words(){delete str;}
	char operator [](int n)
	{
		static char ch;  //声名空字符
		if(n>len-1)
		{
			cout<<"数组下标越界！";
			return ch;
		}
		else 
			return *(str+n);
	}
	void disp(){cout<<str<<endl;}
};
void main()
{
	words word("Time devours all things!");
	word.disp();
	cout<<"此语句字符数共为："<<word.getlen()<<endl;
	for(int i=0;i<25;i++)
		cout<<word[i]<<" ";
	cout<<endl;
}
