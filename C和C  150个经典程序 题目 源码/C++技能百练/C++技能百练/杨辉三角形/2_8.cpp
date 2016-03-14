#include <iostream.h>
void main()
{
	int n,r,c,m,j=0;
	cout<<"请输入行数（小于14）：";
	cin>>m;
	while (m>=14)
	{
		if (j>=2)
		{
			cout<<"你的错误输入已达3次，你无权再输入！"<<endl;
		    return;
		}
		cout<<"你输入的行数超出范围，请重新输入！"<<endl;
        cout<<"请输入行数（小于14）：";
	    cin>>m;
		
		j++;
	}

		for (n=0;n<=m-1;n++)
		{
			for(r=1;r<15-n;r++)
				cout<<"  ";  //2
			c=1;
			cout<<c<<"   ";  //3
			for(r=1;r<=n;r++)
			{
				c=c*(n-r+1)/r;
				if (c<100)
					if(c<10) 
						cout<<c<<"   ";  //3
					else
						cout<<c<<"  ";  //2
				else
					cout<<c<<" ";  //1
			}
			cout<<endl;
		}
}
