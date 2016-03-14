#include<iostream>
#include<queue>
using namespace std;
int main(){
	queue<int>q;
	q.push(1);q.push(0);
	q.push(2);q.push(9);
	cout<<"队首:"<<q.front()<<endl;
	cout<<"队尾:"<<q.back()<<endl;
	cout<<"大小:"<<q.size()<<endl;
	while(q.empty()!=true){
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}