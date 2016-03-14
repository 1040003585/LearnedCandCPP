#include<iostream.h>
int day_tab[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},\
{31,29,31,30,31,30,31,31,30,31,30,31}};
class student
{
	int year,month,day;
	int leap(int);
	int dton(student &);
	student ntod(int);
public:
	student(){}
	student(int y,int m,int d)
	{
		year=y;month=m;day=d;
	}
	int operator-(student &);
	void disp()
	{
		cout<<year<<"/"<<month<<"/"<<day<<endl;
	}
};
int student::leap(int year)
{
	if(year%4==0 && year%100!=0 ||year%400==0)
		return 1;
	else
		return 0;
}
int student::dton(student &d)
{
	int y,m,days=0;
	for(y=1;y<=d.year;y++)
		if(leap(y))
			days+=366;
		else
			days+=365;
	for(m=0;m<d.month-1;m++)
		if(leap(d.year))
			days+=day_tab[1][m];
		else
			days+=day_tab[0][m];
	days+=d.day;
	return days;
}
student student::ntod(int n)
{
	int y=1,m=1,d,rest=n,lp;
	while(1)
	{
		if(leap(y))
		{
			if(rest<=366)
				break;
			else
				rest-=366;
		}
		else
		{
			if(rest<=365)
				break;
			else
				rest-=365;
		}
		y++;
	}
	y--;
	lp=leap(y);
	while(1)
	{
		if(lp)
		{
			if(rest>day_tab[1][m-1])
				rest-=day_tab[1][m-1];
			else
				break;
		}
		else
		{
			if(rest>day_tab[0][m-1])
				rest-=day_tab[0][m-1];
			else
				break;
		}
		m++;
	}
	d=rest;
	return student(y,m,d);
}
int student::operator-(student & b)
{
	int days=dton(*this)-dton(b);
	return days;
}
void main()
{
	student Henry(1980,11,12),Tom(1976,3,25);
	cout<<"Henry's birthday is ";Henry.disp(); 
	cout<<"Tom's birthday is ";Tom.disp();
	if((Henry-Tom)>0)
	    cout<<"Tom is older than Henry "<<Henry-Tom<<" days."<<endl;
	else
		cout<<"Henry is older than Tom "<<Tom-Henry<<" days."<<endl;
}
