#ifndef _bank__h
#define _bank__h
#include<iomanip>//ֻ��������
#include<iostream>//ֻ��������
using namespace std;//ֻ��������

namespace std_class{
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
}

//int bank_account::next_account_number=1;//���ܷ���bank.h
#endif
