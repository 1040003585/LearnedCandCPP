#include<iostream>
#include<string>
using namespace std;
int choice;                                  //Ϊʲô������public�
class bank_account{
      public:
		  void password();
		  void open(string name1,double initial_balance1);
		  void deposit (double amount);
		  void withdraw(double amount);
		  int  show_menuANDchoose();
		  void display_balance(){
			  cout<<"�û� "<<name<<" ��ǰ��"<<balance<<" Ԫ "<<endl; 
		  } 
	  private:  
		  string name,input_password,PASS;//password can't be initialized in here
		  double balance; //=0   
      };
void bank_account::password(){
	do{
		PASS="CHINA";//password
		cout<<"�����������û����룺";
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
	cout<<endl<<" �����֣�ѡ�����¹��ܣ�"<<endl;
	cout<<"*--------------------------------------*"<<endl;
	cout<<"-*- -    1������Ǯ��  2����ȡǮ��  - -*-"<<endl;
	cout<<"-*- -    3�����鿴��  0�����˳���  - -*-"<<endl;
	cout<<"*--------------------------------------*"<<endl;
	cin>>choice;
	return choice;
} 

int main(){
	class bank_account personal;//Ϊʲô����ʡbank_account����160ҳʡ�ˣ���
	double balance_main;//
	string name_main;//

//	personal.password();
//	system("cls");              //Ϊʲôһ�������оͻᱬ������

	cout<<"                #### �����û�����ϵͳ ####           "<<endl<<endl;
	cout<<"�������û����ͳ�ʼ��Ԫ����"<<endl;
	getline(cin,name_main);
	cin>>balance_main;//Enter
	personal.open(name_main,balance_main);

	do{
		switch(personal.show_menuANDchoose()){
		case 1:
			cout<<"�������Ǯ��Ԫ����";
			cin>>balance_main;
			personal.deposit(balance_main);break;
		case 2:
			cout<<"������ȡǮ��Ԫ����";
			cin>>balance_main;
			personal.withdraw(balance_main);break;
		case 3:
			personal.display_balance();break;
		}
	}while(choice);
    
    return 0;
}