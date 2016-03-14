#include <iostream>
#include<string>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	void print_start(int num=4,char c=1);
	string a="I am wu.";
	print_start(33,'8');
	print_start(33,'+');
	print_start(33,'_');
	print_start();
	print_start(33);
	cout<<a<<endl;
	return 0;
}
void print_start(int num=8,char c=2){
	for(int i=0;i<num;i++)
		cout<<c;
	cout<<endl;
}
