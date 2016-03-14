#include<stdio.h>
int main(){
	double sum=0,n=1,i=0;
	for(i=1;i<22;){
		n*=i++;
		n*=i++;
		n*=i++;
		sum+=n;
	}
	printf("%f\n",sum);
	printf("%lf\n",sum);
	printf("%llf\n",sum);
	printf("%.0f\n",sum);
	printf("%e\n",sum);
	return 0;
}//3!+6!+9!+12!+15!+18!+21!
