#include<stdio.h>
int main()
{
	int n,i,j,max=0;
	scanf("%d",&n);
	while(n!=0)
	{
		i=n%10;
		n=n/10;
		max=max>i?max:i;
	}
	printf("%d",max);
	return 0;
}
