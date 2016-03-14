#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{//	cout<<l[1];
	list<int>ll(5);
	ll.push_back(-2);ll.push_back(-2);
	ll.push_back(-2);ll.push_back(-2);
 	list<int>::iterator lit;
	for(lit=ll.begin();lit!=ll.end();lit++)
		cout<<*lit<<" ";cout<<endl;
	list<int>l;
	list<int>::iterator it;
	l.push_back(2);
	l.push_back(0);
	l.push_back(5);
	l.push_back(0);
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
	l.insert(it,20);
	it=l.begin();//不能+1
	l.insert(++it,40);
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
	l.pop_back();	l.remove(0);//删除值
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
	it=l.begin();it++;
	l.erase(it);//查迭代器删除
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
	it=find(l.begin(),l.end(),5);//find
	if(it!=l.end())	cout<<"find it\n";
	else            cout<<"not find it\n";
	it=find(l.begin(),l.end(),40);
	if(it!=l.end())	cout<<"find it\n";
	else            cout<<"not find it\n";
    l.push_front(10);
	l.push_back(2);
	l.sort();//sort
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
	l.unique();//unique
	for(it=l.begin();it!=l.end();it++)//不能+=1
		cout<<*it<<" ";cout<<endl;
    
	return 0;
}