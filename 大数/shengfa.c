#include<stdio.h>
int a[100]={0},b=0,res[200]={0};
int main()
{
  char c;
  int i=0,k=0,carry=0,pro;
  while((c=getchar())!='\n' && c!=' '){
    a[++i]=c-48;
  }
  scanf("%d",&b);
  while(i){
    pro=a[i--]*b;
    res[++k]=(pro+carry)%10;
    carry=(pro+carry)/10;
  }
  if(carry)printf("%d",carry);
  while(k)
    printf("%d",res[k--]);
  printf("\n");
  return 0;
}
