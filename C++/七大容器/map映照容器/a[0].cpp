#pragma warning(disable:4786)
#include<map>
#include<set>
#include<string>
#include<deque>
#include<iostream>
#define a 12
using namespace std;

#if a
/#pragma message("fdf  fd")
#endif

#pragma warning(disable:4081)
#pragma code_seg(["section_name"])

//#pragma once
#include<vector>

int main()
{
	map<int,char>m;
	map<int,char>::iterator it;
	m[3]='4';
	m[4]='f';
	cout<<m[0]<<" "<<m[1]<<" "<<m[3]<<endl<<endl;
	for(it=m.begin();it!=m.end();it++)
		cout<<(*it).first<<" "<<(*it).second<<endl;
	return 0;
}
