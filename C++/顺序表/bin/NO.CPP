#include"seqlist.h"
int main()
{
	SeqList<int> l1;
	l1.input();
	l1.output();
	int x=60;
	l1.Insert (1,x);
	l1.output();
	return 0;
}