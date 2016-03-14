#include<iostream.h>
#include<string.h>
#include<iomanip.h>
#define N 4
void main()
{
	int a,b,c,d;
	char name[4][8];
	for(a=1;a<=N;a++)
		for(b=1;b<=N;b++)
		{
		if(a!=b)
			for(c=1;c<=N;c++)
				if(a!=c && b!=c)
				{
				d=10-a-b-c;
				if((a==1)+(b==4)+(c==3)==1 &&
					(b==1)+(a==4)+(c==2)+(d==3)==1 &&
					(c==1)+(d==4)+(b==2)+(a==3)==1 &&
					(b==4)+(a==3)==1)
				{
				strcpy(name[a-1],"Canada");
				strcpy(name[b-1],"America");
				strcpy(name[c-1],"Russia");
				strcpy(name[d-1],"China");
				cout<<setiosflags(ios::left)<<setw(15)<<"The first :"
					<<setw(10)<<name[0]<<endl;
				cout<<setw(15)<<"The second :"<<setw(10)<<name[1]<<endl;
				cout<<setw(15)<<"The third :"<<setw(10)<<name[2]<<endl;
				cout<<setw(15)<<"The last :"<<setw(10)<<name[3]<<endl;
				}
				}
		}
}
