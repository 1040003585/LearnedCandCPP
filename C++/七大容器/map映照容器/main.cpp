#include <iostream>
#include <string>
#include <map>
using namespace std;
struct myComp{
	bool operator()(const &a,const &b){
		return a>b;//�Ƚϼ�ֵ
	}};//
struct Info{
	string name;
	float score;
	bool operator<(const Info &a)const{
		return a.score<score;
	}}info;
int main()
{
	map<int,char>m;
	map<int,char>::iterator T;
	m[3]='a';//m[3]������
	m[4]='f';m[3]='b';m[-1]='a';
	for(T=m.begin();T!=m.end();T++)
		cout<<(*T).first<<" "<<(*T).second<<endl;
	cout<<"����:"<<m.erase(-1);//��ֵ
	cout<<",��С:"<<m.size()<<endl;
    map<int,char,myComp>mm;
	map<int,char,myComp>::iterator I;
	mm[22]='b';mm[33]='c';mm[00]='A';
	for(I=mm.begin();I!=mm.end();I++)
		cout<<(*I).first<<" "<<(*I).second<<endl; 
	map<Info,int>M;//����<int,Info>
	map<Info,int>::iterator IT;
	info.name="Li";info.score=8;M[info]=1003;
	info.name="Xi";info.score=9;M[info]=1002;
	info.name="Di";info.score=7;M[info]=1001;
	for(IT=M.begin();IT!=M.end();IT++)
		cout<<(*IT).second<<":"
		<<((*IT).first).name<<" "<<((*IT).first).score<<endl;
//�ַ�ӳ������
	map<char,int>ma;
	for(int i=0;i<10;i++)
		ma[i+'0']=i;
	int sum=0;
	string s="21098";
	for(int j=0;j<s.length();j++)
		sum+=ma[s[j]];
	cout<<"SUM = "<<sum<<endl;
	return 0;
}

