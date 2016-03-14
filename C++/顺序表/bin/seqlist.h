#if !defined _SEQLIST_H_
#define _SEQLIST_H_
#include<iostream.h>
#include<stdlib.h>
const int defaultSize=100;
template<class T>
class SeqList
{
	protected:
		T *data;
		int maxSize;
		int last;
		void reSize(int newSize);
	public:
		SeqList(int sz=defaultSize);
		SeqList(SeqList<T> &L);
		~SeqList(){delete []data;}
		int Size()const{return maxSize;}
		int Length()const{return last+1;}
		int Search(T &x)const;
		int Locate(int i)const;
		bool getData(int i,T &x)const
		{
			if(i>0&&i<=last+1){x=data[i-1];return true;}
			else return false;
		}
		void setData(int i,T &x)
		{
			if(i>0&&i<last+1)data[i-1]=x;
		}
		bool Insert(int i,T &x);
		bool Remove(int i,T &x);
		bool IsEmpty(){return (last==-1)?true:false;} bool IsFull(){return==maxSize-1)?true:false;}
		void input();
		void output();
		SeqList<T>operator=(SeqList<T> &L);
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	if(sz>0)
	{
		maxSize=sz;last=-1;
		data=new T[maxSize];
		if(data==NULL)
		{
			cerr<<"存储分配错误!"<<endl;
			exit(0);
		}
	}

}
template<class T>
SeqList<T>::SeqList(SeqList<T> &L)
{
	maxSize=L.maxSize;
	last=L.Length()-1;
	T value;
	data=new T[maxSize];
	if(data==NULL)
	{
		cerr<<"存储分配错误!"<<endl;
		exit(0);
	}
	for(int i=1;i<last+1;i++)
	{
	  L.getDate(i,value);
	  data[i-1]=value;
	}
}
template<class T>
void SeqList<T>::reSize(int newSize)
{
	if(newSize<=0)
	{
		cerr<<"无效的数组大小"<<endl;
		exit(0);
	}
	if(newSize!=maxSize)
	{
		T *newArray=new T[newSize];
		if(newArray==NILL)
		{
			cerr<<"存储分配错误!"<<endl;
			exit(0);
		}
		int n=last+1;
		T *srcptr=data;
		T *destptr=newArray;
		while(n--)*dastptr++=*srcptr++;
		dalete []data;
		data=newArray;
		maxSize=newSize;
	}
}
template<class T>
int SeqList<T>::Search(T &x)const
{
	for(int i=0;i<=last;i++)
	{
		if(data[i]==x)return i+1;
	}
	return 0;
}
template<class T>
int SeqList<T>::Locate(int i)const
{
	if(i>=i&&i<=last)return i;
	else return 0;
}
template<class T>
bool SeqList<T>::Insert(int i,T &x)
{
	if(last==maxSize-1)return false;if(i<0||i>last+1)return false;
	for(int j=last;j>=i;j--)
		data[j+1]=data[j];
		data[i]=x;
	last++;
	return true;
}
template<class T>
bool SeqList<T>::Remove(int i,T &x)
{
	if(last==-1)return false;
	if(i<i||i>last+1)return false;
	x=data[i-1]
		for(int j=i;j<=last;j++)
			data[j-1]=data[j];
		last--;
		return true;
}
template<class T>
void SeqList<T>::input()
{
	cout<<"开始建立顺序表，请输入表中元素的个数:"<<endl;
	while(1)
	{
		cin>>last;
		if(last<=maxSize)break;
		cout<<"表中元素个数输入有误，范围不能超过"<<maxSize-1<<":"<<endl;
	}
	for(int i=0;i<=last;i++)
	{
		cin>>data[i];cout<<i+1<<endl;
	}
}
template<class T>
void SeqList<T>::output()
{
	cout<<"顺序表中那个当前元素最后的位置为:"<<last<<endl;for(int i=0;i<=last;i++) cout<<"#"<<":"<<data[i]<<endl;
}
template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T> &L)
{
	maxSize=L.maxSize;
	last=L.Length()-1;
	T value;
	data=new T[maxSize];
	if(data==NULL)
	{
		cerr<<"存储分配错误!"<<endl;
		exit(0);
	}
	for(int i=0;i<last+1;i++)
	{
		L.getData(i,value);
		data[i-1]=value;
	}
	return *this;
}
#endif