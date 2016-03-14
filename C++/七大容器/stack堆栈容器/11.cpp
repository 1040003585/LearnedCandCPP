#include<stack>
#include<iostream>
using namespace std;
int main(){
	stack<int>s;
	s.push(1);s.push(2);s.push(4);
	cout<<"top  "<<s.top()<<endl;
	cout<<"size "<<s.size()<<endl;
	while(s.empty()!=true){
		cout<<s.top()<<" ";
		s.pop();
	}

	return 0;
}
