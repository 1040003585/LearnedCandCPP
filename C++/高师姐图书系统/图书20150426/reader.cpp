#include <iostream>
#include <iomanip>
#include "reader.h"
using namespace std;

void Reader::addreader(int n,char *na)		//���Ӷ��ߣ���ʼ���������� 
	{ 
		tag=0;                        
		no=n;
		strcpy(name,na);
		for(int i=0;i<Maxzf;i++)
		zfbook[i]=0;
	};

void Reader::zfrowbook(int bookid)			//�������
	{
		for(int i=0;i<Maxzf;i++) 
		{ 
			if (zfbook[i]==0)			//������н���Ĵ��������5�Σ�
			{
				zfbook[i]=bookid;		//����
				return;					//�˳�ѭ����ֻ��һ����
			}
		}  
	};

int Reader::retbook(int bookid)				//�������
	{ 
		for(int i=0;i<Maxzf;i++)
		{ 
			if(zfbook[i]==bookid)		//����н���
			{
				zfbook[i]=0;            //����
				return 1;               //�˳�ѭ����1ûʲô�ã�   
			}
		}
		return 0;
	};
void Reader::disp()							//��ʾ������Ϣ
	{ 
		cout << setw(5) << no <<setw(10) << name<<"    �����ţ�[ ";
		for(int i=0;i<Maxzf;i++)
		if(zfbook[i]!=0)
		cout << zfbook[i] << " / ";
		cout << " ]"<<endl;  
	};

void RDatabase::readerdata()
{
    char choice;             
	char rname[20];							//������
	int readerid;							//���߱��
	Reader *r;								//����ָ�뷽������Ĳ���
	while (choice!='0')
	{   system("cls");
        cout <<"\n\n\t\t\t��   ��   ά   ��\n\n";
		cout<<"\t\t=================================\n"<<endl;
		cout<<"\t\t======\t1   ��      ��\n";
		cout<<"\n\t\t======\t2   ��      ��\n";
		cout<<"\n\t\t======\t3   ɾ      ��\n";
		cout<<"\n\t\t======\t4   ��      ��\n";
		cout<<"\n\t\t======\t5   ��      ʾ\n";
		cout<<"\n\t\t======\t6   ȫ      ɾ\n";
		cout<<"\n\t\t======\t0   ��      ��\n"<<endl;
		cout<<"\t\t=================================\n"<<endl;
		cin >> choice;
		switch (choice)
		{
            case '1':
				cout << "������߱��:";
				cin >> readerid;
				cout << "�����������:";
				cin >> rname;
				addreader (readerid,rname);        //������Ӷ��ߺ���
				system("pause");break;
            case '2':
				cout << "������߱��:";
				cin >> readerid;
				r=query(readerid);                //�ȵ��ò��Һ���������û�����
				if (r==NULL)
				{
					cout << " �ö��߲�����  "<<endl;
					break;
				}
				cout << "�����µ�����:";
				cin >> rname;                     
				r->setname(rname);                 //��������.....
				system("pause");break;
            case '3':
				cout << " ������߱��:";
                cin >> readerid;
				r=query(readerid);              //�ȵ��ò��Һ���������û�����
				if (r==NULL)
				{
					cout <<" �ö��߲�����" << endl;
					break;
				}
				r->delbook();						//����ɾ������              
				system("pause");break;
			case '4':
				cout << "������߱��:";
				cin >> readerid;
				r=query(readerid);
				if (r==NULL)
				{
					cout <<"�ö��߲�����"<< endl;
					break;
				}
				r->disp();							//���ö�������������   
			system("pause");break;
			case '5':
				disp();                             //���ø���������������������ж��ߵ���Ϣ��
				system("pause");break;
			case '6':
				clear();
				system("pause");break;
			case '0':
				break;
				default:cout<<"����������������룺"<<endl;system("pause");break;
		}
	}
}