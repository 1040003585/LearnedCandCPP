#include<string.h>
#include<iostream.h>
#define N 10
class std
{
	int No;
	char name[10];
	float Eng;
	float Chi;
	float Mat;
	float total;	
public:
	void setname(char na[]){strcpy(name,na);};
	void setNo(int n){No=n;};
	void setEng(float e){Eng=e;};
	void setChi(float c){Chi=c;};
	void setMat(float m){Mat=m;};
	void settotal(float t){total=t;};
	char* getname(){return name;};
	int getNo(){return No;};
	float getEng(){return Eng;};
	float getChi(){return Chi;};
	float getMat(){return Mat;};
	float gettotal(){ return total;};
};

class compute
{
	int ns;
	std na[N];
	static float sumEng;
	static float sumChi;
	static float sumMat;
public:
	void getdata();
	void sort();
	void disp();
    float aveEng()
	{
		return sumEng/ns;
	}
    float aveChi()
	{
		return sumChi/ns;
	}
    float aveMat()
	{
		return sumMat/ns;
	}
};

float compute::sumEng=0.0;
float compute::sumChi=0.0;
float compute::sumMat=0.0;
void compute::getdata()
{
	int i,sno;
	float En,Ch,Ma,Tol;
	char tname[10];
	cout<<"Please input the amounts of students!";
	cin>>ns;
	for(i=0;i<ns;i++)
	{
	cout<<"Input the student's NO.:";
	cin>>sno;
	na[i].setNo(sno);
	cout<<"Input the student's name.:";
	cin>>tname;
	na[i].setname(tname);
	cout<<"Input the student's English score:";
	cin>>En;
    sumEng=sumEng+En;
	na[i].setEng(En);
	cout<<"Input the student's Chinese score:";
	cin>>Ch;
    sumChi=sumChi+Ch;
	na[i].setChi(Ch);
	cout<<"Input the student's Maths score:";
	cin>>Ma;
	sumMat=sumMat+Ma;
	na[i].setMat(Ma);
	Tol=En+Ch+Ma;
	na[i].settotal(Tol);
	}
}
void compute::sort()  //÷±Ω”—°‘Ò≈≈–Ú
{
	int i,j,pick;
	std temp;
	for(i=0;i<ns-1;i++)
	{
		pick=i;
		for(j=i+1;j<ns;j++)
		{
			if(na[j].gettotal()>na[pick].gettotal())
				pick=j;
		}
		temp=na[i];
		na[i]=na[pick];
		na[pick]=temp;
	}
}
void compute::disp()
{
	cout<<"List"<<"  NO"<<"  Name"<<"  English"<<"  Chinese"<<"  Maths"<<"  Total "<<endl;
	for(int i=0;i<ns;i++)
	{
		cout<<i+1<<"     "<<na[i].getNo()<<"    "<<na[i].getname()<<"      "<<na[i].getEng()<<"       "
			<<na[i].getChi()<<"      "<<na[i].getMat()<<"    "<<na[i].gettotal()<<endl;
	}
}

void main()
{
	compute obj;
	obj.getdata();
	obj.sort();
	obj.disp();
    cout<<"The average score of English is:"<<obj.aveEng()<<endl;
	cout<<"The average score of Chinese is:"<<obj.aveChi()<<endl;
	cout<<"The average score of Maths is:"<<obj.aveMat()<<endl;
}
