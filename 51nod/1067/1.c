#include<stdio.h>
#define NUM 100
int main()
{
	/*	int i;
		int num[NUM]={1,2,1,1};
		for(i=4;i<NUM;i++)
		{
		if(num[i-1]==2 || num[i-3]==2 || num[i-4]==2)
		num[i]=1;
		else
		num[i]=2;
		}
		for(i=0;i<NUM;i++)
		{
		if(i%4==0)printf("\n");
		printf("%d,",num[i]);
		}
		return 0;
		*/
	int a[28]={1,2,1,1,
		1,1,2,1,
		2,1,1,1,
		1,2,1,2,
		1,1,1,1,
		2,1,2,1,
		1,1,1,2};
	int T,N,i;
	scanf("%d",&T);	
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		if(a[(N-1)%28]==1)
			printf("A\n");
		else 
			printf("B\n");

	}
	return 0;
}

