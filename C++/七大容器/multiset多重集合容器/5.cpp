#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	multiset<string>ms;
	multiset<string>::iterator it;
	ms.insert("AB");
	ms.insert("123");
	ms.insert("123");
	for(it=ms.begin();it!=ms.end();it++)
		cout<<*it<<" ";
	cout<<"\n删除个数:"<<ms.erase("123")
		<<",大小还是:"<<ms.size();// <-
	cout<<",大小是:"<<ms.size()<<endl;

	for(it=ms.begin();it!=ms.end();it++)
		cout<<*it<<" ";
	it=ms.find("123");
	if(it==ms.end())cout<<"\nnot find it\n";
	return 0;
}
