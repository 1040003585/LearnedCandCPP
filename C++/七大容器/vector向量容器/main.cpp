#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool comp(const int &a,const int &b){
	if(a!=b)return a>b;
	else return a>b;
}
int main(){
//创建vector对象 
	vector<int>v;
	vector<double>v1(4);
	vector<double>v2(4,-8.0); //0自动舍去 
//尾部元素扩张 
	v.push_back(2100000000);
	v.push_back(33.3);
	v1.push_back(2100000000);
//下标方式访问vector元素 
	v2[2]=434; 
	cout<<"下标访问vector元素\n"
    	<<v[0]<<" "<<v[1]<<endl;
    cout<<"v2i""v1i"<<endl;//""里不加字.1-2.3-4 
	for(int i=0;i<5;i++)
	    cout<<v2[i]<<" ""#"<<v1[i]<<endl;
//用迭代器访问vector元素
    vector<double>::iterator it;//<>里和v1同型 
	for(it=v1.begin();it!=v1.end();it++)
	     cout<<*it<<" ";
    cout<<"迭代器访问元素\n";
//元素的插入
    cout<<"元素的插入\n";
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
//元素的删除 
    cout<<"\n元素删除\nv1大小："<<v1.size()<<endl;
	v1.erase(v1.begin()+1);//erase[v1[1],v1[3])
	v1.erase(v1.begin()+1,v1.begin()+3);
	for(it=v1.begin();it!=v1.end();it++)
	    cout<<*it<<" ";	cout<<endl<<v1.size()<<" ";
	v1.clear();cout<<"v1 size: "<<v1.size()<<endl;
//用reverse反向排列算法 //algorithm
	reverse(v2.begin(),v2.end());
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"v2 been reversed"<<endl; 
//用sort算法对向量元素排序 //algorithm 
	sort(v2.begin(),v2.end());
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"v2 been sorted."<<endl;
//用comp反向排序 可用 reverse(v2.bvegin(),v2.end());
	sort(v2.begin(),v2.end(),comp);
	for(it=v2.begin();it!=v2.end();it++)
	    cout<<*it<<" "; cout<<"反向排序后、\n";
//向量大小 //没有 <<v2.length()//empty为0 
    cout<<v2.size()<<" "<<" "<<v2.empty()<<endl; 	
	return 0;
} 
