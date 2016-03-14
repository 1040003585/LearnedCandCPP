#include<stdio.h>
int main()
{
	int n,i,tm,to,from;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		tm=0;
		from=0;
		for(i=0;i<n;i++){
			scanf("%d",&to);
			if(to>from){
				tm +=(to-from)*6+5;			
			}
			else
				tm +=(from-to)*4+5;
			from=to;
		}
		printf("%d\n",tm);
	}
}
