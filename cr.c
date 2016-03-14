#include<stdio.h>
void main()
{
	int n,i;
       short nfeet;
	scanf("%d",&n);
 	for (i=0;i<n;i++){
		scanf("%d",&nfeet);
		if(nfeet%2 != 0){
			printf("0 0\n");
		}
		else if(nfeet%4 !=0){
			printf("%d %d\n",nfeet/4+1,nfeet/2);
		}
		else{
			printf("%d %d\n",nfeet/4,nfeet/2);
		}
	}
}
