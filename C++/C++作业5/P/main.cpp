#include"bank.h"

int main(){
	bank_account account1;
    bank_account account2(200),account3(300.3,333);//
	class bank_account account4(400);
//	account1.deposit(125.55);
//	account2.deposit(135.75);
//	account3.deposit(100.25);
//	account4.deposit(300.45);
	float total_balance=account1.get_balance()+
		account2.get_balance()+
		account3.get_balance()+
		account4.get_balance();
	cout<<"Total Balance= "<<fixed<<setprecision(2)
		<<total_balance<<endl;
	return 0;
}