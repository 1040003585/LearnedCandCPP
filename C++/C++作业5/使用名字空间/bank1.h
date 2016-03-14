#ifndef _bank_h//����ͬbank.h��
#define _bank_h
#include<iomanip>
#include<iostream>
using namespace std;

namespace std_class1{//����ͬ//
	class bank_account{  //*  ������ͬ�ɲ�ͬ
	public:
		bank_account();  //*
		bank_account(int acc_no);
		bank_account(int acc_no,double initial_balance);
		void deposit(double amount);//*��Ա��������ͬ�ɲ�ͬ
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
