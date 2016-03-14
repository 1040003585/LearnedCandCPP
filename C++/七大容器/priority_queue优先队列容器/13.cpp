#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct Info{
	string name;
	float score;
	bool operator<(const Info &a) const{
		return a.score<score;
	}
}info;
struct myComp{
	bool operator()(const int &a,const int &b){
		return a>b;
	}
};
int main(){
	priority_queue<int>pq;
	pq.push(11);pq.push(0);
	pq.push(-3);pq.push(9);
    while(pq.empty()!=true){
		cout<<pq.top()<<" ";
		pq.pop();
	}cout<<endl;
	priority_queue<Info>q;////
	info.name="Di";info.score=9;q.push(info);
	info.name="Xi";info.score=8;q.push(info);
	while(q.empty()!=true){
		cout<<q.top().name<<" "<<q.top().score<<endl;
		q.pop();
	}
	priority_queue<int,vector<int>,myComp>p;
	p.push(-3);p.push(0);
	p.push(02);p.push(1);
	while(p.empty()!=true){
		cout<<p.top()<<" ";
		p.pop();
	}


	
	return 0;
}