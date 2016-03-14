#include <iostream>
#include <iomanip>
#include <string>
#include "reader.h"
#include "book.h"
#include <fstream>							//����/����ļ�����
using namespace std;

int maxb=-1;					//����һȫ�ֱ�����ʾ��ǰ�������

//**************************************************************************
//ͼ�鲿��

void Book::tinput()										//�������ʱ��
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};     
 bool flag=false;
 while(!flag)
      {cout<<"������һ������"<<endl;  
       cin>>time.year>>time.mon>>time.day; 
          if(time.year % 4 == 0 && time.year % 100 != 0 ||time.year % 400 == 0)      
	          m[2]++;  
          if(time.year<0||time.mon<0||time.mon>12||time.day>m[time.mon])        
	          cout<<"��������Ч"<<endl;
		  else
			  flag=true;	      
      }
};

void Book::input()										//����ͼ����Ϣ
{   
	cout<<"������"<<endl;
	cin>>bname;
	cout<<"���ߣ�"<<endl;
	cin>>author;
	cout<<"������"<<endl;
	cin>>classif;
	cout<<"��ļ۸�"<<endl;
	cin>>price;
	cout<<"���浥λ��"<<endl;
	cin>>pubunit;
	tinput();
};

void Book::tidisplay()									//�������ʱ��
{
	cout<<"   ����ʱ��:"<<time.year<<"��"<<time.mon<<"��"<<time.day<<"��"<<endl;
};

void Book::display()										//���ͼ����Ϣ
{
	cout<<"��¼��:"<<num<<"   ����:"<<bname<<"   ����:"<<author<<endl;
	cout<<"��ķ���:"<<classif<<"   �۸�:"<<price<<"    �����"<<stock<<endl;
	cout<<"���浥λ:"<<pubunit;
	tidisplay(); 
};

void openbook(Book b[])
{Book s;  maxb=-1;
	fstream file("book.txt",ios::in);//��һ�������ļ�
		while (1)				       //����ͼ������
		{
			file.read((char *)&s,sizeof(s));
			if (!file)break;
			maxb++;				//����1���ͼ�һ
			b[maxb]=s;		//����һ���鱾����
		}
		file.close();			//�ر� book.txt

}


void closebook(Book b[])  //��book[]д��book.txt�ļ��У�
	{
		ofstream file("book.txt",ios::out);   //�Զ����Ƶķ�ʽд���ļ�
        for (int i=0;i<=maxb;i++)
		file.write((char *)&b[i],sizeof(b[i]));
		file.close();
	}

	
void inputnu(Book b[],int x)      //����ͼ��ĵ�¼�ţ���Ϊ��¼����Ψһ�ģ�����Ҫ��������
{int i;bool t;                    //��Ҫ�����¼����û�ظ�
 do
 {
 t=true;                          
 cout<<"��������ĵ�¼��"<<endl;
 cin>>b[x].num;
 for(i=0;i<x;i++)
   if(b[i].num==b[x].num)
   {t=false;cout<<"�õ�¼��������ʹ�ã����������룡"<<endl;}
 }while(t==false);
}

void findbook(Book b[],string na,int x)		//���������ʹ�õĺ����������Ǽ����û�ظ�����
{
	int i;
	if(x==0)								//XΪ��ǰ��ӵ�����±�
	 ;
	else
	for(i=0;i<x;i++)						//Ѱ����û�뵱ǰҪ��ӵ�����ͬ
    {
		if(b[i].getbname()==na)
		{
			b[i].stock++;
			b[x].stock++;
		}
		i++;
	}
}
 
void finda(Book b[],string au)				//�����߲��� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
}

void findb(Book b[],string bna)				//���������� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getbname()==bna)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
}

void findc(Book b[],string clf)				//��������� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
}

void findab(Book b[],string au,string bna)				//�����ߺ��������� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getbname()==bna)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
} 

void findac(Book b[],string au,string clf)				//�����ߺ�������� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
} 

void findbc(Book b[],string bna,string clf)				//��������������� 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getbname()==bna&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
}                      

void findabc(Book b[],string au,string bna,string clf)				//�����ߺ������ͷ������ 
{
	int i=0;bool s=false;
	while(b[i].num!=0)
    {
		if(b[i].getauthor()==au&&b[i].getbname()==bna&&b[i].getclassif()==clf)
		{
			b[i].display();
			cout<<endl;
			if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
}

                         

void Storage(Book b[])								//�������
{  
	int i, n;											//һ��Ҫ��ӵ�����
	cout<<"������Ҫ��ӵ�����"<<endl;
	cin>>n;      
	for( i=maxb+1;i<maxb+n+1;i++)							//mΪ��ǰ����������ȸոն�ȡ������������nΪ���Ҫ��ӵ�����   
	{   inputnu(b,i);
		b[i].input();								//���û������Ӻ���
		b[i].stock=1;								//����Ĭ��Ϊ1
	}                                             
	for(i=maxb+1;i<maxb+n+1;i++)                 
		findbook(b,b[i].getbname(),i);					//���øú�����Ҫ����û��������Ҫ��ӵ�������ͬ��
	maxb=maxb+n;											
	closebook(b);
}
void Cancell(Book b[])								        //ע���鱾
{          
	int i=0,x;int nu;bool t=false;char judge;                            //xΪҪɾ��������±�                  
	cout<<"������Ҫɾ���ĵ�¼��"<<endl;
	cin>>nu;
	while(b[i].num!=0)               
    {
		if(b[i].num==nu)
		{t=true;break;}
		i++;
	}
	if(t==false)
	{cout<<"���޴���"<<endl;return;}
	x=i;
	cout<<"��ȷ��Ҫɾ�����飿(y/n)"<<endl;
	 cin>>judge;
	if(judge=='y'||judge=='Y')
	{
		if(x==maxb)b[i].num=0;                   //���Ҫɾ���ĸպ������һ�����Ǿ�ֱ����������0  
		else
		for(i=x;i<=maxb-1;i++)								//XΪ��ǰ����±�      
	    b[i]=b[i+1];                                         //���ǵĻ�����X������鸲��ǰ���					                    
		maxb--;										//������һ
		closebook(b);
		cout<<"ɾ���ɹ���"<<endl;
	}
    else if(judge=='n'||judge=='N')
	{cout<<"δɾ������"<<endl;return;}
	else
	{cout<<"�������"<<endl;
	return;}
	closebook(b);
}

int beday;                  //����

void botime(Reader *p,int n)                //����ʱ��
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int year,month,day,days=30;  
 bool flag=false;
 while(!flag)
      {cout<<"��������������"<<endl;  
       cin>>year>>month>>day; 	   
          if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)      
	          m[2]++;  
          if(year<0||month<0||month>12||day>m[month])        
	          cout<<"��������Ч"<<endl;
		  else
			 flag=true;
 }
      cout<<"����ʱ��Ϊ30��"<<endl;
      day=day+days;
	  if(day>m[month])
	  {day=day-m[month];
	  month++;}
	  if(month>12)
	  {month=1;
	  year++;}
	  cout<<"�黹����Ϊ"<<year<<"/"<<month<<"/"<<day<<"��"<<endl;
      p->alsotime(year,month,day,n);
	  for(int i=0;i<=month;i++)
      day=day+m[i];
	  beday=day;
	  
}

void altime(Reader *p,int n)             //����ʱ���뷣��
{int m[] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int year,month,day,i;  
int biday=0;float fined;
 bool flag=false;
 while(!flag)
      {cout<<"�����뻹�������"<<endl;  
       cin>>year>>month>>day; 	   
          if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)      
	          m[2]++;  
          if(year<0||month<0||month>12||day>m[month])        
	          cout<<"��������Ч"<<endl;
		  else
			 flag=true;
 }
   p->showalsotime(n);
   
   for(i=0;i<=month;i++)
    day=day+m[i];
    biday=biday+day;
	if(biday-beday>0)
    {cout<<"�����볬��һ��ķ���(Ԫ)"<<endl;
	cin>>fined;
    cout<<"�Ѿ�����"<<biday-beday<<"��"<<endl;
	cout<<"����Ϊ"<<fined*(biday-beday)<<"Ԫ"<<endl;}
	else
		cout<<"�ܼ�ʱ���飬����ɹ���"<<endl;

}   



void borrow(Book b[])							//�����鱾
{   
	int n,rn,i=0;bool t=false;		//nΪҪ����鱾��ţ�rnΪҪ�����ѧ����ţ�s���ÿ�����
	RDatabase rea;								//rea�Ķ���ֻ��Ϊ�˶�ѧ������в���
	cout<<"�����ѧ��ѧ��"<<endl;
	cin>>rn;									//����ѧ�����
	Reader *p=rea.query(rn);					//������û��ѧ��
	if (p==NULL)                                //���û��
	{
		cout<<"�ö��߲����ڣ�"<<endl;
		return;
	}											//���û�о��˳���	  
		cout<<"�����ѧ����Ҫ�����ı��"<<endl;
		cin>>n;                                 //�о�������ı��
	     while(b[i].num!=0)                     //��Ҫ�����
		{
			if(b[i].num==n)                   
			{t=true;break;}                     //���������Ҫ���飬s�ͱ��true
			i++;	
		}
		if(t==false)                            //���û�еĻ�
		{cout<<"���޴��飡"<<endl;return;}
		if(b[i].mark==false)					//�����û�н��
		{
			cout<<"����δ�������ϢΪ"<<endl; 
			b[i].display();
			p->zfrowbook(n);						//��ѧ������������Ȿ��
			b[i].mark=true;							//����
			b[i].stock--;							//����һ
            botime(p,n);
			cout<<"����ɹ�����"<<endl;
		} 
		else
			cout<<"����ʧ�ܣ������ѱ������"<<endl;		    	
		 closebook(b);
			return;
}


void alsobook(Book b[])						 //�黹�鱾
{   
	int n,rn,i=0;bool t=false;				 //nΪҪ�����鱾��ţ�rnΪҪ�����ѧ�����
	RDatabase rea;							 //rea�Ķ���ֻ��Ϊ�˶�ѧ������в���
	cout<<"�����ѧ��ѧ��"<<endl;
	cin>>rn;								 //���涼����������
	Reader *p=rea.query(rn);
	if (p==NULL)
	{cout<<"�ö��߲����ڣ�"<<endl;return;}	
		cout<<"������Ҫ������ı��"<<endl;
		cin>>n;
		while(b[i].num!=0)
		{
			if(b[i].num==n)
			{t=true;break;}
			i++;
			
		}
		if(t==false)                            //���û�еĻ�
		{cout<<"���޴��飡"<<endl;return;}
		if(b[i].mark==false)
		{cout<<"δ�и�������¼��"<<endl;return;}
		if(p->rebook(n)==1)                    //�����û��
		{
			cout<<"����δ�黹����ϢΪ"<<endl;  
			b[i].display();                    
			b[i].mark=false;                   //�黹��        
			b[i].stock++;                      //����һ
			altime(p,n);
			p->retbook(n);
		}
		else
		cout<<"����ʧ�ܣ������鲻�Ǹö��߽�ģ���"<<endl;
		closebook(b);
	}

void delall(Book b[])             //ɾ��������
{   
	char judge;
   cout<<"��ȷ��Ҫɾ�����е��飿(y/n)"<<endl;
    cin>>judge;
	if(judge=='y'||judge=='Y')
	{
	for(int i=0;i<=maxb;i++)
	b[i].num=0;
	maxb=-1;
	}
	else if(judge=='n'||judge=='N')
    {cout<<"δɾ������"<<endl;return;}
	else
	{cout<<"�������"<<endl;
	return;}
	closebook(b);
}

void Changbo(Book b[])          //�����鱾
{    
	int nu,i=0;bool s=false;     //nuΪ��Ҫ���ĵ���ĵ�¼�ţ�s�������ж���û�Ȿ�飬false��ʾû��
	cout<<"������Ҫ���ĵĵ�¼��"<<endl;
	cin>>nu;
	while(b[i].num!=0)
    {
		if(b[i].num==nu)
		{   b[i].display();
		cout<<"������ͼ����ĺ����Ϣ"<<endl;
			b[i].input();
			s=true;
		}
		i++;
	}
	if(s==false)
		cout<<"���޴���!"<<endl;
	closebook(b);
}

void output(Book b[])          //������е��鱾                
{
    for(int i=0;i<=maxb;i++)               
	{
		b[i].display();	
		cout<<endl;
		if(b[i].stock>0)
		 cout<<"��ͼ��ɹ����"<<endl;
		 else
			cout<<"��ͼ���ѽ��"<<endl;
		
	 cout<<"----------------------------------------------------------------"<<endl;
	}
}

void bookdata(Book b[])						//ͼ�����
{
	char choice;
	while(choice!='0')
	{   system("cls");
		cout <<"\n\n\n\t\t\tͼ  ��  ��  ��\n "<<endl;
		cout<<"\t\t=================================\n"<<endl;
		cout<<"\t\t======\t1   ��     ��\n";
		cout<<"\n\t\t======\t2   ��     ��\n";
		cout<<"\n\t\t======\t3   ע     ��\n";
		cout<<"\n\t\t======\t4   ��     ��\n";
		cout<<"\n\t\t======\t5   ��     ʾ\n";
		cout<<"\n\t\t======\t6   ȫ     ɾ\n";
		cout<<"\n\t\t======\t0   ��     ��"<<endl;
		cout<<"\n\t\t=================================\n"<<endl;
		cin>>choice;
		switch (choice)
		{
			case '1':
				Storage(b);system("pause");break;
			case '2':
				Changbo(b);system("pause");break;             
			case '3':
				Cancell(b);system("pause");break;
		case '4':
			{
				cout<<"                    1)�� �� �� �� ��"<<endl;
				cout<<"                    2)�� �� �� �� ��"<<endl;
				cout<<"                    3)�� �� �� �� ��"<<endl;
                cout<<"                    4)�� �� �� �� �� �� �� ��"<<endl;
				cout<<"                    5)�� �� �� �� �� �� �� ��"<<endl;
				cout<<"                    6)�� �� �� �� �� �� �� ��"<<endl;
				cout<<"                    7)�� �� �� �� �� �� �� �� �� �� ��"<<endl;
				
				char c1;
				string bna;                             //������Ҫ���ҵ�������������
				string au;
				string clf;
				cin>>c1;
				if(c1=='1')
				{
					cout<<"��������������"<<endl;
					cin>>au;
					finda(b,au);
					system("pause");break;
				}
				else if(c1=='2')
				{
					cout<<"����������"<<endl;
					cin>>bna;
					findb(b,bna);
					system("pause");break;
				}
				else if(c1=='3')
				{
					cout<<"����������"<<endl;
					cin>>clf;
					findc(b,clf);
					system("pause");break;
				}
				else if(c1=='4')
				{
					cout<<"���������ߺ�����"<<endl;
					cin>>au>>bna;
					findab(b,au,bna);
					system("pause");break;
				}
				else if(c1=='5')
				{
					cout<<"���������ߺ�����"<<endl;
					cin>>au>>clf;
					findac(b,au,clf);
					system("pause");break;
				}
				else if(c1=='6')
				{
					cout<<"����������������"<<endl;
					cin>>bna>>clf;
					findbc(b,bna,clf);
					system("pause");break;
				}
				else if(c1=='7')
				{
					cout<<"���������ߺ�����������"<<endl;
					cin>>au>>bna>>clf;
					findabc(b,au,bna,clf);
					system("pause");break;
				}
				else
				{  
					cout<<"������󣡣�"<<endl;
					system("pause");break;
				}       
			}
			case '5':
				output(b);system("pause");break;
			case '6':
				delall(b);system("pause"); break;              
			case '0':
				break;
			default:
				{
					cout<<"������󣡣�"<<endl;
					system("pause");
					break;
				}
		}
	}
}

void sav()											//�����صض���һ��������Ϊ���ö��߿��д����
{
	RDatabase rea;                  
	rea.readerdata();
}
int main()
{
	Book b[100];                    //����100����
	for(int i=0;i<100;i++)          //��ʼ����100����
	{
		b[i].num=0;                  //��¼�Ŷ�Ϊ0
		b[i].mark=false;            //δ���
	}
    openbook(b);
		char choice;
		while(choice!='0')
		{       system("cls");
				cout <<endl<<endl<<"\t\t\tͼ �� �� �� ϵ ͳ\n\n\n";
				cout<<"\t\t=================================\n"<<endl;
				cout <<"\t\t=======\t1    ��       ��\n";
				cout<<"\n\t\t=======\t2    ��       �� \n";
				cout<<"\n\t\t=======\t3    ͼ �� �� ��\n";
				cout<<"\n\t\t=======\t4    �� �� �� ��\n";
				cout<<"\n\t\t=======\t0    ��       ��\n"<<endl;
				cout<<"\t\t=================================\n"<<endl;
				cin>>choice;
				switch (choice)
				{
					case '1':
						borrow(b);system("pause");break;				//����
					case '2':
						alsobook(b);system("pause");break;			  //����
					case '3':
						bookdata(b);break;					         //ͼ�����
					case '4':
						sav();break;								//���߹���
					case '0':
						return 0;
						break;

					default:
						cout<<"������󣡣�"<<endl;
						return 0;
				}
			}
			return 0;
}