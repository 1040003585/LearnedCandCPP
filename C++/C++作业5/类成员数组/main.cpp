#include"bank.h"
//#include"³ÉÔ±º¯Êý.cpp"
int main()
{
	class bank_account account11[2];
	class bank_account account22[][4]={{11,111},{22,222},{33,333},{44,444}};
	class bank_account account33[4]={1111,2222,3333,4444};
	for(int i=0;i<2;i++)
		account11[i].display_balance();//1,2
	for(int j=0;j<4;j++)
		account22[j][j].display_balance();//[0][0]11,[1][1]222,[2][2]7,[3][3]10
	for(int k=0;k<4;k++){
	    account33[k].withdraw(k*20000);
		account33[k].display_balance();
	}
	return 0;
}


