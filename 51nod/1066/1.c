#include<stdio.h>
int main()
{
	int T;
	unsigned long N,K;
	scanf("%d",&T);
	int i;
	for(i=0;i<T;i++)
	{
		scanf("%lu%lu",&N,&K);
		if(N%(K+1)==0)
		{
			printf("B\n");
		}
		else
			printf("A\n");

	}
}
