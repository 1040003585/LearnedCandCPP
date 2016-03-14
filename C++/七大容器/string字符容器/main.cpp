#include<iostream> 
#include<string>
#include<sstream>
using namespace std;
int main()
{ 
//创建string对象 length empty
	string str; cout<<str.length()<<" "
	                <<str.empty()<<endl; 
//给string对象赋值 
	str="hello C++STL\n";cout<<str;
	char cs1,cs[]="hello,string";        //不能赋值 
	str=cs; cout<<str<<endl;
//string对象尾加字符 
	str+=' ';str=str+'A';cout<<str<<endl;
//string对象尾加字符串 
	str+=" ";str+="12"; cout<<str<<endl;
	str.append("AB",1,1);//可去1or1,1 
//插入字符串,字符（迭代器） 
    string s="abc";
    str.insert(5,str,1,1);cout<<str<<endl;
    str.insert(7,s);cout<<str<<endl;
    str.insert(7,"s");cout<<str<<endl;
    string::iterator it=str.begin()+5; // 
    str.insert(it+2,'S');cout<<str<<endl;
//下标访问string元素 
    cout<<str[7]<<" "<<str<<endl;
    cout<<str[7]-'S'<<" "<<str<<endl;
//删除元素 
    str.erase(7,2);  cout<<str<<endl;
    str.erase(16);   cout<<str<<endl;//[)
    str.erase(it,it+1);cout<<str<<endl;
    str.erase(it); cout<<str<<endl;//{''}
    str="";//clear() erase()0
    cout<<str.length()<<endl;
//replace
	 str="abcd";s="1234";cout<<"cin>>cs:";cin>>cs;
	 cout<<str<<' '<<s<<" "<<cs<<endl;
	 str.replace(1,1,cs,1,0); cout<<str<<endl;
	 str.replace(1,1,"cs",1,2); cout<<str<<endl;
	 str.replace(1,1,s,1,2); cout<<str<<endl;
     str.replace(1,0,"SS"); cout<<str<<endl;
//find搜索元素或子串 
	 str="cat dog cat" ;
	 cout<<str.find('c')<<" "<<str.find("a")<<" "
	 <<str.rfind("g ")<<" "<<str.rfind("gca")<<" "//last
	 <<str.find_last_not_of("oat")<<" "<<
	 str.find_first_of("dog ")<<endl;//or
//compare
     s="Cat dog\n";
	 cout<<s.compare("Cat dog")<<' ' 
 	     <<s.compare(s)<<' ' 
 	     <<s.compare("cat dog\n")<<endl;
//string数字化 
	cout<<"cin>>s数:";cin>>s; 
	int sum=0;
	for(int i=0;i<s.length();i++){
	if(s[i]=='0')sum+=0;else if(s[i]=='1')sum+=1;
	else if(s[i]=='2')sum+=2;else if(s[i]=='3')sum+=3;
	else if(s[i]=='4')sum+=4;else if(s[i]=='5')sum+=5;
	else if(s[i]=='8')sum+=8;else if(s[i]=='6')sum+=6;
	else if(s[i]=='7')sum+=7;else if(s[i]=='9')sum+=9;
	}cout<<sum<<endl;
//string与数组操作	
     str=cs;
     printf("%s ",cs);
     printf(str.c_str());
	 cout<<" "<<str<<" "<<cs<<endl;
//string对象 与sscanf
    char sa[11],sb[11],sc[11];
	string s1,s2,s3; 
	//cin.getline(sc,11);//c //有上bug
	//cin.get(sb,11);    //c
    //getline(cin,s1);   //c++
	//cout<<s1<<' '<<sb<<" "<<sc<<endl;
	sscanf("abc www	111","%s %s%s",sa,sb,sc);//only空格 
	s1=sa;s2=sb;s3=sc;
	cout<<s1<<" "<<sb<<" "<<sc<<endl;
	int x,y,z;    
	sscanf("1,2$ 3","%d,%d$%d",&x,&y,&z );//不能s1.数字 ,or$
	cout<<x<<" "<<y<<" "<<z<<endl;  
//string对象与数值转换	
string convertToString(double x); 
double convertFromString(const string &s);
	sprintf(sa,"\n  %d  n",1975);   //1.c方法 
	sscanf("1976","%s\n n",sb);//\n n传不过来 
	printf("%s %s\n",sa,sb);
	string cc=convertToString(1999);//2.c++方法
	cout<<cc+"AA"<<endl;
	string dd="2006";               //3.c++方法 
	int p=convertFromString(dd+'9')+2;
	cout<<p<<endl;
	return 0;
}
string convertToString(double x){
	ostringstream o;
	if(o<<x) return o.str(); 
	else return "Conversion error\n";
}
double convertFromString(const string &s){
	istringstream i(s);//
	double x; 
	if(i>>x) return x;
	return 0.0;
}
