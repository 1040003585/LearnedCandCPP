#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<10>b;
	bitset<10>bb(2);
	b[8]=4;b[0]=-1;//1=!0
	cout<<b<<endl<<bb<<endl;
	b.set();  cout<<b<<endl;
	b.reset();cout<<b<<endl;
	b.set(1); cout<<b<<endl;
	b.set(2,2);cout<<b<<endl;//2Ϊ1 
	b.reset(2);cout<<b<<endl;
	b.flip();cout<<b<<endl;
	b.flip(9);cout<<b<<endl;
	cout<<b.test(1)<<" "<<b.test(2)<<endl;//b[1],b[2]
	cout<<b.none()<<" "<<b.any()<<endl;//1?
	cout<<b.count()<<" "<<b.size()<<endl;
    cout<<b.flip().to_ulong()<<":";
	for(int i=b.size()-1;i>-1;i--)
		cout<<b[i];cout<<endl;
	return 0;
}
