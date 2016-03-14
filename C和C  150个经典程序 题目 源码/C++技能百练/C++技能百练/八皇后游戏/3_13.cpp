# include <iostream.h>

 int col[8],Left[15],Right[15];
 int queen[8];
 int n=0;
 int sum=0;

 void generate()
{
	int h,i;
	for(h=0;h<=7;h++)
	{
		if(col[h]&& Left[n+h] && Right[n-h+7])
		{
			queen[n]=h;
			col[h]=false;
			Left[n+h]=false;
			Right[n-h+7]=false;
			n+=1;
			if(n==8)
			{
				sum++;
				cout<<"  "<<sum;
				for(i=0;i<=7;i++)
				 cout<<"\t"<<queen[i];
				cout<<endl;
			}
			else generate();
			n--;
			Left[n+h]=true;
			Right[n-h+7]=true;
			col[h]=true;
		}
	}
}
void main()
{  
	int c,s;
	for(c=0;c<=7;++c)
		col[c]=true;
	for(s=0;s<=14;++s)
	{
		Left[s]=true;
		Right[s]=true;
	}
	cout<<"行数：\t0\t1\t2\t3\t4\t5\t6\t7"<<endl;
	 generate();
	cout<<"八皇后摆法总数:"<<sum<<endl;
}
