#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool comp(const int &a,const int &b){
	if(a!=b)return a>b;
	else return a>b;
}
int main(){
//����vector���� 
	vector<int>v;
	vector<double>v1(4);
	vector<double>v2(4,-8.0); //0�Զ���ȥ 
//β��Ԫ������ 
	v.push_back(2100000000);
	v.push_back(33.3);
	v1.push_back(2100000000);
//�±귽ʽ����vectorԪ�� 
	v2[2]=434; 
	cout<<"�±����vectorԪ��\n"
    	<<v[0]<<" "<<v[1]<<endl;
    cout<<"v2i""v1i"<<endl;//""�ﲻ����.1-2.3-4 
	for(int i=0;i<5;i++)
	    cout<<v2[i]<<" ""#"<<v1[i]<<endl;
//�õ���������vectorԪ��
    vector<double>::iterator it;//<>���v1ͬ�� 
	for(it=v1.begin();it!=v1.end();it++)
	     cout<<*it<<" ";
    cout<<"����������Ԫ��\n";
//Ԫ�صĲ���
    cout<<"Ԫ�صĲ���\n";
    v2.insert(v2.begin(),88);
	v2.insert(v2.begin()+2,1.1);
	v2.insert(v2.end(),22.09);
	v.insert(v.end(),2.9);
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<' ';
	cout<<endl;
	vector<int>::iterator intt;
	for(intt=v.begin();intt!=v.end();intt++)
	    cout<<*intt<<" "; 
//Ԫ�ص�ɾ�� 
    cout<<"\nԪ��ɾ��\nv1��С��"<<v1.size()<<endl;
	v1.erase(v1.begin()+1);//erase[v1[1],v1[3])
	v1.erase(v1.begin()+1,v1.begin()+3);
	for(it=v1.begin();it!=v1.end();it++)
	    cout<<*it<<" ";	cout<<endl<<v1.size()<<" ";
	v1.clear();cout<<"v1 size: "<<v1.size()<<endl;
//��reverse���������㷨 //algorithm
	reverse(v2.begin(),v2.end());
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"v2 been reversed"<<endl; 
//��sort�㷨������Ԫ������ //algorithm 
	sort(v2.begin(),v2.end());
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"v2 been sorted."<<endl;
//��comp�������� ���� reverse(v2.bvegin(),v2.end());
	sort(v2.begin(),v2.end(),comp);
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"���������\n";
//������С //û�� <<v2.length()//emptyΪ0 
    cout<<v2.size()<<" "<<" "<<v2.empty()<<endl; 	
	return 0;
} 
