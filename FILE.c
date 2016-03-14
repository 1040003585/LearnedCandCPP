#include <stdio.h>
void main()
{
	int n,a,i,sum;
	FILE *fin,*fout;
	if((fin=fopen("in.txt","r"))==NULL){
		printf("input file open error!\n");
		return ;
	}
	if((fout=fopen("out.txt","w"))==NULL){
		printf("output file open error!\n");
		return ;
	}
	while (!feof(fin)){
		fscanf(fin,"%d",&n);
		for(i=0,sum=0;i<n;i++){
			fscanf(fin,"%d",&a);
			sum+=a;
		}
		fprintf(fout,"%d\n",sum);
	}
	fclose(fin);
	fclose(fout);
}
