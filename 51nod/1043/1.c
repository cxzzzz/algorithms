#include<stdio.h>
#define MAX (1000000000+7)

int main()
{
	int N,i,j,k;
	scanf("%d",&N);
	long long a1[N+1][10*N],a2[N+1][10*N];
	long long sum1=0,sum2=0;
	for(i=0;i<10;i++)
	{
		a1[1][i]=i;
		a2[1][i]=i+1;
	}
	for(i=10;i<10*N;i++)
	{
		a1[1][i]=9;
		a2[1][i]=10;
	}
	for(i=2;i<=N;i++)
	{
		a1[i][0]=0;
		a2[i][0]=a2[i-1][0];
		for(j=1;j<=10*N;j++)
		{
			if(j-10>=0)
			{
				a1[i][j]=(a1[i][j-1]+a1[i-1][j]-a1[i-1][j-10])%(MAX);
				a2[i][j]=(a2[i][j-1]+a2[i-1][j]-a2[i-1][j-10])%(MAX);
			}
			else
			{
				a1[i][j]=(a1[i][j-1]+a1[i-1][j])%MAX;
				a2[i][j]=(a2[i][j-1]+a2[i-1][j])%MAX;
			}
		}
	}
	for(i=10*N-1;i>0;i--)
	{
		a1[N][i]=(a1[N][i]-a1[N][i-1]);
		a2[N][i]=a2[N][i]-a2[N][i-1];
		a1[N][i]=a1[N][i]>=0?a1[N][i]:a1[N][i]%MAX+MAX;
		a2[N][i]=a2[N][i]>=0?a2[N][i]:a2[N][i]%MAX+MAX;
		sum1+=a1[N][i]*a2[N][i];
		sum1=sum1%(1000000000+7);
	}
	printf("%lld\n",sum1);
	return 0;
}

		
	
