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
	cout<<"\nɾ������:"<<ms.erase("123")
		<<",��С����:"<<ms.size();// <-
	cout<<",��С��:"<<ms.size()<<endl;

	for(it=ms.begin();it!=ms.end();it++)
		cout<<*it<<" ";
	it=ms.find("123");
	if(it==ms.end())cout<<"\nnot find it\n";
	return 0;
}
