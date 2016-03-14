#include <iostream>
#include <iomanip>
#include <fstream>//����/����ļ�����
using namespace std;
const int Maxr=3000;//���Ķ���
const int Maxzf=5;//ÿλ���������屾��
class Reader       
{   
 private:
	int tag;							//ɾ����� 1:��ɾ 0:δɾ
	int no;								//���߱��
	char name[10];						//��������
	int zfbook[Maxzf];					//����ͼ��
	int ryear[Maxzf];
	int rmonth[Maxzf];
	int rday[Maxzf];
 public:
	Reader() {}							//���캯����û�õģ���˼һ��
    char *getname() {return name;}      //��ȡ����
	int gettag() {return tag;}			//��ȡɾ�����
    int getno() {return no;}			//��ȡ���߱��
    void setname(char na[])				//��������
	{strcpy(name,na); }
	void addreader(int ,char *);		//���Ӷ��ߣ���ʼ���������� 
	void zfrowbook(int);			    //�������
	int retbook(int bookid);			//�������
	void disp();						//��ʾ������Ϣ
	void alsotime(int y,int m,int d,int bookid)
	{
		int i;
		for( i=0;i<Maxzf;i++) 
		{if(zfbook[i]==bookid)		
		break;}
	 ryear[i]=y;rmonth[i]=m;rday[i]=d;
	}
	void showalsotime(int bookid)
	{
		int i;
		for( i=0;i<Maxzf;i++) 
		{
			if(zfbook[i]==bookid)		
				break;
		}
		cout<<"�黹����Ϊ"<<ryear[i]<<"/"<<rmonth[i]<<"/"<<rday[i]<<"��"<<endl;
	}
	int rebook(int bookid)				//ֻΪ�����Ƿ��н��Ȿ��
	{ 
		for(int i=0;i<Maxzf;i++)
		{ 
			if(zfbook[i]==bookid)		
			{
				return 1;                  
			}
		}
		return 0;
	};


	void delbook()	     //���ö���ɾ����� 1:��ɾ 0:δɾ
	{char judge;   
    cout<<"��ȷ��Ҫɾ���õĶ��ߣ�(y/n)"<<endl;
	cin>>judge;
	if(judge=='y'||judge=='Y')
	tag=1;
	else if(judge=='n'||judge=='N')
    {cout<<"δɾ���˶���"<<endl;return;}
	else
	{cout<<"�������"<<endl;
	return;}
	}
};
 
//������⣬ʵ�ֽ������ߵĸ�������
class RDatabase
{  
 private:
	int top;							//���߼�¼ָ��
	Reader read[Maxr];					//���߼�¼
 public:
	RDatabase()   //���캯������reader.txt����read[]�У������󴴽�ʱ���Զ�����
	{
		Reader s;				//����һ�������෽������ļ��Ķ���
		top=-1;					//����ָ�룬-1��û�ж��ߣ�0Ϊ��һ������
		fstream file("reader.txt",ios::in);//��һ�������ļ�
		while (1)				//�����������
		{
			file.read((char *)&s,sizeof(s));
			if (!file)break;
			top++;				//����1���ͼ�һ
			read[top]=s;		//����һ����������
		}
		file.close();			//�ر� reader.txt
	}
    void clear()				//ɾ�����ж�����Ϣ
	{char judge;
    cout<<"��ȷ��Ҫɾ�����еĶ��ߣ�(y/n)"<<endl;
	cin>>judge;
	if(judge=='y'||judge=='Y')
	top=-1;
	else if(judge=='n'||judge=='N')
    {cout<<"δɾ���˶���"<<endl;return;}
	else
	{cout<<"�������"<<endl;
	return;}
	}
	int addreader(int n,char *na)//��Ӷ���ʱ�Ȳ����Ƿ����
	{
		Reader *p=query(n);        //queryΪ���Ҷ��ߣ�nΪ��Ҫ���ҵĶ��ߵı��
		if (p==NULL)               //û�иö��ߣ��������
		{
			top++;                    
			read[top].addreader(n,na);//���һ������
			cout<<"��ӳɹ���"<<endl;
			return 1;                 //ûʲôʵ������
		}
		else
		{
			cout<<"�ö����Ѵ��ڣ�"<<endl;
			return 0;
		}
	}
	Reader *query(int readerid)      //���Ҷ��ߣ�readeridΪ��Ҫ���ҵĶ��ߵı��
	{
		for (int i=0;i<=top;i++)
		if (read[i].getno()==readerid && 
		read[i].gettag()==0)        //��Ŵ��ں�δ��ɾ��
		{
			return &read[i];        //�ҵ��˶���
		}
		return NULL;             //δ�ҵ�
	}
	void disp()          //������ж�����Ϣ
	{
        for (int i=0;i<=top;i++)
		read[i].disp();//disp��������������
	}
	void readerdata();			//�������߿�ά��
	~RDatabase()  //������������read[]д��reader.txt�ļ��У����������ǵ�������Ķ������������ʱ�Ż���õ�
	{
		ofstream file("reader.txt",ios::out);   //�Զ����Ƶķ�ʽд���ļ�
        for (int i=0;i<=top;i++)
		if (read[i].gettag()==0)
		file.write((char *)&read[i],sizeof(read[i]));
		file.close();
	}
};