/*Chengbing Wu*/
/*The big number multiply by the small number*/
#include<stdio.h>
int a[100000000]={0},b=0,res[100000010]={0};
int main()
{
  char c;
  int i=0,k=0,car=0,pro;
//input big number greater than int
  while((c=getchar())!='\n' && c!=' '){
    a[++i]=c-48;     
  }
//input small number less than int
  scanf("%d",&b);  
  while(i){     
    pro=a[i--]*b; //car means carry bit
    res[++k]=(pro+car)%10;
    car=(pro+car)/10;
  }
  if(car)printf("%d",car);
  while(k)
    printf("%d",res[k--]);
  printf("\n");
  return 0;
}

