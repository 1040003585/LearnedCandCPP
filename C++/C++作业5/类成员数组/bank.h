#ifndef _bank_h_
#define _bank_h_
#include<iomanip>//只能在这里
#include<iostream>//只能在这里
using namespace std;//只能在这里

class bank_account{
public:
	bank_account();
	bank_account(int acc_no);
	bank_account(int acc_no,double initial_balance);
	void deposit(double amount);
	void withdraw(double amount);
	void display_balance();
	double get_balance();
private:
	static int next_account_number;
	int account_number;
	double balance;
};//
//int bank_account::next_account_number=1;//不能放在bank.h
#endif
