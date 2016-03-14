#include<iostream.h>
#include<string.h>
int n,k;  //k表示第几条路径，n为所求路径的终点
void path(int n,char s[20])  //s表示结果串
{
	char s1[20];
	s1[0]='-';
	s1[1]=n+48; //将输入的整数值转换为对应字符的ASCII码值
	s1[2]='\0';
	strcat(s1,s);  //字符串连接，返回S1串
	if(n>1) path(n-2,s1);
	if(n>0) path(n-1,s1);
	if(n==0)
	{
		k++;
		cout<<k<<" : 0"<<s<<endl;
	}
}

void main()
{
	do
	{
		cout<<"n=";
		cin>>n;
	}while(!(n>=0&& n<=9));
	k=0;
	path(n,"");
}
