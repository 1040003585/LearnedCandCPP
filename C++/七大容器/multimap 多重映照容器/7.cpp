#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    multimap<string,double>m;
	multimap<string,double>::iterator it;
	m.insert(pair<string,double>("jack",30.0));
	m.insert(pair<string,double>("kity",20.1));
	m.insert(pair<string,double>("jack",30.1));//
    for(it=m.begin();it!=m.end();it++)
		cout<<(*it).first<<":"<<(*it).second<<endl;
	cout<<"É¾³ı¸öÊı:"<<m.erase("jack")<<endl;
    for(it=m.begin();it!=m.end();it++)
		cout<<(*it).first<<":"<<(*it).second<<endl;
	it=m.find("jack");
	if(it!=m.end())
		cout<<(*it).first<<" "<<(*it).second<<endl;
	else cout<<"not find it\n";
	return 0;

}