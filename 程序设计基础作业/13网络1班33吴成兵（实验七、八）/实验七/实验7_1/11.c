extern
int sushu(int x)             //������������
{
	int i;
	for(i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return printf("%d isn't a sushu.\n",x);
		else
			return printf("%d is a sushu.\n",x);
}