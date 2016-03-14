#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int rolldice(void);
int die1,die2,worksum;
int main()
{
	enum status{CONTINUE,WON,LOST};
	int sum,mypoint;
	enum status gamestatus;
	sum=rolldice();
	switch (sum)
	{
	case 7:
	case 11: gamestatus=WON;
		     break;
    case 2: 
	case 3:
	case 12: gamestatus=LOST;
		     break;
	default: gamestatus=CONTINUE;
		     mypoint=sum;
			 cout<<"point is "<<mypoint<<endl;
			 break;
	}
	while (gamestatus==CONTINUE)
	{
		sum=rolldice();
		if (sum==mypoint)
			gamestatus=WON;
		else{
			if(sum==7)
				gamestatus=LOST;}
	}
	if (gamestatus==WON)
		cout <<"player wins"<<endl;
	else
		cout<<"player loses"<<endl;
	return 0;
}
int rolldice(void)
{
	time_t timenow;
	srand((unsigned)time(&timenow));
	//srand((unsigned)time(NULL));
	die1=1+rand()%6;
	die2=1+rand()%6;
	worksum=die1+die2;
	cout<<"player rolled  "<<die1<<"+"<<die2<<"="<<worksum<<endl;
	return worksum;
}
