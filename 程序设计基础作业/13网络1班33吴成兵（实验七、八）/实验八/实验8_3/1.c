#include<stdio.h>
int main()
{
	int letter,digit,space,others;
    void count(char[],int *p1,int *p2,int *p3,int *p4);
	char text[80];
	letter=digit=space=others=0;
	printf("input string:\n");
	gets(text);
	count(text,&letter,&digit,&space,&others);
	printf("\nletter:%d\ndigit:%d\nspace:%d\nothers:%d\n",letter,digit,space,others);
	return 0;
}

void count(char str[],int *p1,int *p2,int *p3,int *p4)
{
	int i;
	for(i=0;str[i]!='\0';i++)
        if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z')
			(*p1)++;
		else if(str[i]>='0'&&str[i]<='9')
			(*p2)++;
		else if(str[i]==32)
			(*p3)++;
		else 
			(*p4)++;
}
