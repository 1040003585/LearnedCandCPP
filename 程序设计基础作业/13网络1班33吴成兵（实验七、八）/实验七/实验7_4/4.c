#include<stdio.h>
	int wei=0,length=0,i=0;
	char str[10000];
int main()
{ 
	void maxlen(char x);       //����
	void shuchu(int x,int y);  //����
	printf("������ʺ���\n\n");
	printf("������һ�е��ʣ�\n");
	gets(str);
	maxlen(str);
	shuchu(length,wei);
	return 0;
}

void maxlen(char x)           //�������
{
	for(;str[i]!='\0';i++)
	{   
		if(str[i]==32)
		{
		    if(i-wei>length)
			{
				length=i-wei;wei=i;//ȡ���ո��������length,�͵ڼ���wei
			}
		}
	}

}

void shuchu(int x,int y)      //�������
{
	printf("����ʣ�\n");
	for(i=wei;i<=wei+length;i++)//��λ������length��
		printf("%c",str[i]);
	printf("\n");
}