#include<stdio.h>
#define NUM 100
int main()
{
	int T;
	scanf("%d",&T);
	int num[NUM]={0,1};
	int i;
	for(i=2;i<NUM;i++)
	{
		if(i%2)
		{
			num[i]=num[i/2]+num[i/2+1];
		}
		else
			num[i]=num[i/2];
		printf("%d:%d\n",i,num[i]);
	}
/*	for(i=0;i<T;i++)
	{
		int nu;
		scanf("%d",&nu);
		int max=0,j;
		for(j=0;j<=nu;j++)
		{
			max=max>num[j]?max:num[j];
		}
		printf("%d\n",max);
	}
	return 0;
	*/
}
	

