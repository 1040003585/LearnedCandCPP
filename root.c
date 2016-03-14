#include<stdio.h>
int main()
{
	long i,s;
	while(1){
		scanf("%d",&i);
		if(i==0){
			break;
		}
		do{
			s=0;
			while (i>0){
				s+=i%10;
				i/=10;
			}
			i=s;
		}while (i>=10);
		printf("%d\n",s);
	}
}
