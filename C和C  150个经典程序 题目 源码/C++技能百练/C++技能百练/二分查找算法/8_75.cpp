#include<iostream.h>
const int max=100;
template <class T>
class Search
{
	T A[max];
	int n;
public:
	Search(){}
	Search(T a[],int i);
	int seek(T b[],int l,int h,T x);
	int seek1(T b[],T x,int m);
	void disp()
	{
		for (int i=0;i<n;i++)
			cout<<A[i]<<"  ";
		cout<<endl;
	}
};
template <class T>
Search<T>::Search(T a[],int i)
{
	n=i;
	for(int j=0;j<i;j++)
		A[j]=a[j];
}
template <class T>
int Search<T>::seek(T b[],int l,int h,T x)
{
	int m;
	if(l>h)
	{
		cout<<endl<<"The data you are searching for does NOT exist!"<<endl;
		return -1;
	}
	else
	{
		m=(l+h)/2;
		if(x<b[m])
			return (seek(b,l,m-1,x));
		else if(x==b[m])
			return m;
		else
			return (seek(b,m+1,h,x));
	}
}
template <class T>
int Search<T>::seek1(T b[],T x,int m)
{
	int i=0;
	while(i<m && b[i]!=x) i++;
	if(i>=m)
		return -1;
	else
		return i;
}
void main()
{
	char a[]="acegkmpwxz",d;
	Search<char> s(a,10);
	cout<<"The original serial:";
	s.disp();
	cout<<"Input the element you want to search:";
	cin>>d;
	cout<<"The position of the element of\'"<<d<< "\'is:";
	cout<<s.seek(a,0,9,d)+1<<endl;

	int c[]={2,9,10,99,55,66,3,88,5,100},e;
	Search<int> ss(c,10);
    cout<<"The original serial:";
	ss.disp();
    cout<<"Input the element you want to search:";
	cin>>e;
	cout<<"The position of the element of\'"<<e<<"\' is:";
//	cout<<ss.seek(c,0,9,e)+1<<endl;  //二分查找法要求序列有序
	cout<<ss.seek1(c,e,10)+1<<endl;
}
