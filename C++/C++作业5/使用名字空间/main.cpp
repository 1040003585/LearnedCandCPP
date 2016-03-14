#include"bank.h"
#include"bank1.h"
int main()
{
	using std_class::bank_account;     //1
	using namespace std_class1;        //2
	std_class1::bank_account account88;//3

	 bank_account account0;
	 bank_account account1(100);//ø… °class
	class bank_account account2(2,200);//*
	
	account2.deposit(300);

	account0.display_balance();
	account1.display_balance();
	account2.display_balance();
	
	account88.display_balance();

	return 0;
}

//dfdfj\\
   fdf
//warning C4010: single-line comment contains line-continuation character
