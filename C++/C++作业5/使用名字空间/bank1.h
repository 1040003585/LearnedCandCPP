#ifndef _bank_h//不能同bank.h的
#define _bank_h
#include<iomanip>
#include<iostream>
using namespace std;

namespace std_class1{//不能同//
	class bank_account{  //*  类名可同可不同
	public:
		bank_account();  //*
		bank_account(int acc_no);
		bank_account(int acc_no,double initial_balance);
		void deposit(double amount);//*成员函数名可同可不同
		void withdraw(double amount);
		void display_balance();
		double get_balance();
	private:
		static int next_account_number;
		int account_number;
		double balance;
	};//
}

//int bank_account::next_account_number=1;//不能放在bank.h
#endif
