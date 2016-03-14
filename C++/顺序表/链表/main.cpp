#include <iostream.h>
#include"list.h"
int main()
{
	List<int> l1;
	cout<<"以-1作为约定的链表数据输入结束符号"<<endl;
	cout<<"现在开始输入数据："<<endl;
	l1.inputFront(-1);
	l1.output();
	List<int> l2(l1);
	l2.output();
	return 0;
}
