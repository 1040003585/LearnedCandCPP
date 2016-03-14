#include"bank1.h"
using namespace std_class1;

bank_account::bank_account(){          //*
	account_number=next_account_number++;
	balance=0.0;
}
bank_account::bank_account(int acc_no){
	balance=0.0;
	account_number=acc_no;
}
bank_account::bank_account(int acc_no,double initial_balance){
	balance=initial_balance;
	account_number=acc_no;
}
void bank_account::deposit(double amount){
	balance+=amount;
}
void bank_account::withdraw(double amount){
	balance-=amount;
}
void bank_account::display_balance(){
	cout<<"Balance IN ACCOUNT "<< account_number << " is "
		<<fixed<<setprecision(2)<<balance<<endl;
}
double bank_account::get_balance(){
	return balance;
}
int bank_account::next_account_number=1;//
