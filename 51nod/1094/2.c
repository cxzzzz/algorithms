#include<stdio.h>

int main()
{
	int N,K,i,j,k;
	scanf("%d%d",&N,&K);
	long long A[N+1];
	A[0]=0;
	for(i=1;i<=N;i++)
	{
		scanf("%d",&k);
		A[i]=A[i-1]+k;
	}
	for(i=0;i<N;i++)
		for(j=i+1;j<=N;j++)
		{
			if(A[j]-A[i]==K)
			{
				printf("%d %d\n",i+1,j);
				return 0;
			}
		}
			
	printf("No Solution\n");
	return 0;
}
