#include<iostream>
#include<string>
using namespace std;
int choice;                                  //为什么不能在public里？
class bank_account{
      public:
		  void password();
		  void open(string name1,double initial_balance1);
		  void deposit (double amount);
		  void withdraw(double amount);
		  int  show_menuANDchoose();
		  void display_balance(){
			  cout<<"用户 "<<name<<" 当前余额："<<balance<<" 元 "<<endl; 
		  } 
	  private:  
		  string name,input_password,PASS;//password can't be initialized in here
		  double balance; //=0   
      };
void bank_account::password(){
	do{
		PASS="CHINA";//password
		cout<<"请输入银行用户密码：";
		cin>>input_password;
	}while(!(input_password==PASS));
}
void bank_account::open(string name1,double initial_balance1){
	name=name1;
	balance=initial_balance1;
}
void bank_account::deposit(double amount){
	balance+=amount;
}
void bank_account::withdraw(double amount){
	balance-=amount;
}
int bank_account::show_menuANDchoose(){
	cout<<"##############################################################";
	cout<<endl<<" 按数字，选择如下功能："<<endl;
	cout<<"*--------------------------------------*"<<endl;
	cout<<"-*- -    1——存钱；  2——取钱；  - -*-"<<endl;
	cout<<"-*- -    3——查看；  0——退出。  - -*-"<<endl;
	cout<<"*--------------------------------------*"<<endl;
	cin>>choice;
	return choice;
} 

int main(){
	class bank_account personal;//为什么不能省bank_account，书160页省了？？
	double balance_main;//
	string name_main;//

//	personal.password();
//	system("cls");              //为什么一用这两行就会爆掉？？

	cout<<"                #### 银行用户管理系统 ####           "<<endl<<endl;
	cout<<"请输入用户名和初始金额（元）："<<endl;
	getline(cin,name_main);
	cin>>balance_main;//Enter
	personal.open(name_main,balance_main);

	do{
		switch(personal.show_menuANDchoose()){
		case 1:
			cout<<"请输入存钱金额（元）：";
			cin>>balance_main;
			personal.deposit(balance_main);break;
		case 2:
			cout<<"请输入取钱金额（元）：";
			cin>>balance_main;
			personal.withdraw(balance_main);break;
		case 3:
			personal.display_balance();break;
		}
	}while(choice);
    
    return 0;
}