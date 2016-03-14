#include<stdio.h>
int a[100]={0},b[100]={0},res[200]={0};
int main()
{
  char c;
  int i=0,j=0,k=0,m,n,carry,pro,sys=1;
  while((c=getchar())!='\n' && c!=' '){
    a[++i]=c-48;
  }
  while((c=getchar())!='\n' && c!=' '){
    b[++j]=c-48;
  }
  for(n=j;n>0;n--){
    carry=0;sys*=10;
    for(m=i;m>0;m--){
      pro=a[m]*b[n];
      if(pro<10){res[++k]=pro+carry;carry=pro/10;}
      else   {res[++k]=pro%10+carry;carry=pro/10;}
    }
  }
  if(carry)printf("%d",carry);
  for(m=k;m>0;m--)
    printf("%d",res[m]);
  printf("\n");
  return 0;
}
