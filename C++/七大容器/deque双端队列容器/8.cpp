#include<iostream>
#include<deque>
using namespace std;
int main()
{
	deque<int>d;
	deque<int>::iterator it=d.begin();
	deque<int>d1(5);
	deque<float>d2(5,5.0);
	d.push_back(2);
	d.push_back(0);
	d.push_back(-1.1);
	d.push_front(11);
	d.insert(d.begin()+2,22);
	for(it=d.begin();it!=d.end();it++)
		cout<<*it<<" ";cout<<endl;
	d.pop_back();
	d.pop_front();
	for(it=d.begin();it!=d.end();it++)
		cout<<*it<<" ";cout<<endl;
	d.erase(d.begin()+1);
	for(it=d.begin();it!=d.end();it+=1)
		cout<<*it<<" ";cout<<endl;
	for(int i=-1;i<5;i++)
		cout<<d[i]<<" ";


	return 0;
}