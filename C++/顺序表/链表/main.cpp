#include <iostream.h>
#include"list.h"
int main()
{
	List<int> l1;
	cout<<"��-1��ΪԼ�����������������������"<<endl;
	cout<<"���ڿ�ʼ�������ݣ�"<<endl;
	l1.inputFront(-1);
	l1.output();
	List<int> l2(l1);
	l2.output();
	return 0;
}
