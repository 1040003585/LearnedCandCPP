#include<string>
#include<iostream>
#include<set>
using namespace std;
struct myComp{
	bool operator()(const int &a,const int &b){
		/*if(a!=b) return a>b;
		else*/     return a>b;	}};//
struct Info{
	string name;float score;
	bool operator<(const Info &a)const{
		return a.score<score;	}
}info;
int main(){
	set<int>s;
	set<int>::iterator it;
	s.insert(2);
	s.insert(2);//нч╡Е
	s.insert(-3);
	s.insert(0);
	cout<<s.erase(2)<<endl;
    it=s.find(2);
	if(it==s.end())
		cout<<"Not find it\n";
    set<int>::reverse_iterator rit;
	for(rit=s.rbegin();rit!=s.rend();rit++)
		cout<<*rit<<" ";cout<<endl<<endl;
	set<int,myComp>sm;////
	set<int,myComp>::iterator sit;
	sm.insert(22);sm.insert(-3);sm.insert(0);
	for(sit=sm.begin();sit!=sm.end();sit++)
		cout<<*sit<<" ";cout<<endl<<endl;
	set<Info>I;////
	set<Info>::iterator T;
	info.name="Wu";info.score=9;I.insert(info);
    info.name="Li";info.score=8;I.insert(info);
    for(T=I.begin();T!=I.end();T++)
	  cout<<(*T).name<<":"<<(*T).score<<endl;


	return 0;
}
