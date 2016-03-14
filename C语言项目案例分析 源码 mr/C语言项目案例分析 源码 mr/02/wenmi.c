#include<stdio.h>

#define SIZE 1024
char buffer[SIZE];
 FILE *fp1,*fp2;
double sizef,ev_sizef;


void menu123();
void divide123();
void unite123();
void unitefile123();
                      


main()
{
    menu123();
}
void menu123()            /*主界面的选择菜单*/
{
    int n;
  /* clrscr();/*清除整个当前字符窗口，并且把光标定位于左上角（1,1）处*/
    do
     {
         printf("\nplease choose you needful file: 1.divide file 2.unite file 3.exit :");
    scanf("%d",&n);
         if(n==1)
		 divide123();
         else
         if(n==2)
         unite123();
         else
         if(n==3)
         exit(0);
     }while(n<1||n>3);
}
void unite123()              /*合并文件*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf("\nplease input unite file's  postion:");
  scanf("%s",name);
  if((fp1=fopen(name,"wb"))==NULL)
    {
     printf("\nthe postion is error,whether or not repeate input(Y/N):");
     getchar();
     c=getchar();
     if(c=='Y'||c=='y')
     goto lp1;
     else
     menu123();
     }
  unitefile123();
  printf("\nunitefile successful,whether or not continue to unite the other files(Y/N):");
  getchar();
  c=getchar();
  if(c=='Y'||c=='y')
  goto lp;
  else
  menu123();
}
void unitefile123()      /*合并文件*/
{
  int i=1;
  char name[25],c;
  do
    {
     lp1:
     printf("\nplease input you want to uniting %d new file's postion:",i++);
     scanf("%s",name);
      if((fp2=fopen(name,"rb+"))==NULL)
      {
        printf("\nyou input the file postion is error,whether or not input the new name(Y/N):");
            if(getchar()=='Y'||getchar()=='y')
          goto lp1;
          else
           menu123();
       }
        while(fread(buffer,1,1,fp2))
            fwrite(buffer,1,1,fp1);
      fclose(fp2);
      printf("\nwhether or not continue to unite(Y/press any key): ");
      getchar();
      c=getchar();
    }while(c=='y'||c=='Y');
  fclose(fp1);
}
void divide123()     /*分割文件*/
{
  int n;
  char name[25],c;
  lp:
  lp1:
  printf("\nplease input divide file's postion:");
  scanf("%s",name);
  if((fp2=fopen(name,"rb"))==NULL)
    {
     printf("\nthe postion is error,whether or not repeate input(Y/N):");
     getchar();
     c=getchar();
     if(c=='Y'||c=='y')
     goto lp1;
     else
      menu123(); 
     }
  printf("\nhow many do you want to divide the file:");
  lp2:
  scanf("%d",&n);
  if(n<1)
  { printf("\nsorry,please input the right number:"); goto lp2;}
  else
 sizef=sizefile(fp2);
   ev_sizef=sizef/n;                      /*被分割后每一个子文件的大小*/
  printf("\nthe size:%.0f bite,when dividing every file about:%.0f bite",sizef,ev_sizef);
  dividefile(n);
  printf("\ndivide successful,whether or not continue to divide(Y/N)");
  getchar();
  c=getchar();
  if(c=='Y'||c=='y')
  goto lp;
  else
   menu123();
}
int sizefile(fp)                             /*计算文件的大小*/
FILE *fp;
{
 sizef=0;
 while(!feof(fp))
  { fgetc(fp);
    sizef++;    }
  rewind(fp);
  return sizef-1;
}

dividefile(int n)      /*分割文件*/
{
  int i,d=1;
  char name[25],c;
  for(i=0;i<n;i++)
   {
     lp1:
     printf("\nplease input you want to dividing %d new file's postion:",i+1);
     scanf("%s",name);
      if((fp1=fopen(name,"wb"))==NULL)
      {
        printf("\nyou input the file postion is error,whether or not input the new name(Y/N):");
            if(getchar()=='Y'||getchar()=='y')
          goto lp1;
          else
          { fclose(fp2); menu123();}
       }
       d=1;
     if(i!=n)
        while(d<=ev_sizef)
       { fputc(fgetc(fp2),fp1); d++;}
      else
        while(fread(c,1,1,fp2))
        {
          fwrite(c,1,1,fp1);
           }
     fclose(fp1);
    }
    fclose(fp2);
}
