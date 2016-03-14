#include <stdio.h>
main(int a,char **date)
{
	int year=0,month=0,day=0,week;
    int d,i,dm,dy,m2;
    char WEEK[9];
    if (a==1)
    {
     printf ("\n ERROR! you forgot to enter the date you want to view\n");
     exit (0);
    }
   i=0; d=-1;
   while (date[1][i])/*遍历传入的参数日期，计算出year，month，day*/
    {
     if ((date[1][i]=='/'||date[1][i]=='.')&&d==-1) { d=0; i++; continue; }
     if ((date[1][i]=='/'||date[1][i]=='.')&&d==0) { d=1; i++; continue; }
     if (d==-1) year=year*10+(date[1][i]-'0');
     if (d==0) month=month*10+(date[1][i]-'0');
     if (d==1) day=day*10+(date[1][i]-'0');
     i++;
    }
   if (month<1||month>12)/*若月份传入错误数字*/
   {
	   printf ("\n ERROR! the entered MONTH is invalid\n"); 
	   exit (0); 
   }
   if (year==2000)
   {
	   dy=0;				/*年引起的星期差为0个*/
	   m2=1;				/*2月引起的星期差为1个*/
	   goto la_100;
   }
   if (year>2000)
	   d=(year-1-2000)/4-(year-1-2000)/100+(year-1-2000)/400+1;
   else 
	   d=(year-2000)/4-(year-2000)/100+(year-2000)/400;
   dy=(year-2000)+d;     /*** 该年 1月1号 到2000年1月1号的 " 星期差 " ***/
   if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
    m2=1; 
   else 
	   m2=0;  /*** 该年是否润 ***/
la_100:                    /**** la_100 ****/
          /*** 该月以前的月所引起的 " 星期差 " ***/
   switch (month)
    {
     case 1: dm=0; month=31; break;   /*** month 在此存放该月天数 ***/
     case 2: dm=3; month=d==1? 29:28; break;
     case 3: dm=3+m2; month=31; break;
     case 4: dm=6+m2; month=30; break;
     case 5: dm=1+m2; month=31; break;
     case 6: dm=4+m2; month=30; break;
     case 7: dm=6+m2; month=31; break;
     case 8: dm=2+m2; month=31; break;
     case 9: dm=5+m2; month=30; break;
     case 10: dm=m2; month=31; break;
     case 11: dm=3+m2; month=30; break;
     case 12: dm=5+m2; month=31; break;
    }
   if (day<0||day>month)
    { 
	   printf ("\n ERROR! the entered DAY is invalid\n"); 
	   exit (0);
   }
   week=(dy+dm+day-1+6)%7;
   if(week<0)
	   week+=7;
   if (day>0)       /*** 判定查看类型 ***/
   {
     switch (week)
      {
       case 0: strcpy (WEEK,"SUNDAY"); break;
       case 1: strcpy (WEEK,"MONDAY"); break;
       case 2: strcpy (WEEK,"TUESDAY"); break;
       case 3: strcpy (WEEK,"WEDNESDAY"); break;
       case 4: strcpy (WEEK,"THURSDAY"); break;
       case 5: strcpy (WEEK,"FRIDAY"); break;
       case 6: strcpy (WEEK,"SATURDAY"); break;
      }
     printf ("\n this day is %s  \( %d \)\n\n OK!\n",WEEK,week);
  }
   else
   {
     week=++week%7;
     printf ("\n the calender of this month as following\n");
     printf ("\n *********************************\n");
     printf (" SUN  MON  TUE  WEN  THU  FRI  STA\n");
     for (i=0;i<week;i++) 
		 printf ("     ");
     for (i=1;i<=month;i++)
     {
		 printf (" %2d  ",i);
		 week++;
		 if (week%7==0&&i!=month) 
			 printf ("\n");
	 }
     printf ("\n *********************************\n");
     printf ("\n OK!\n");
   }
}
