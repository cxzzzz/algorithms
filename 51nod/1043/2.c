#include<stdio.h>
#define MAX (1000000000+7)

int main()
{
	int N,i,j,k;
	scanf("%d",&N);
	long long a11[10*N],a12[10*N],a21[10*N],a22[10*N];
	long long sum1=0,sum2=0;
	long long  *a1_old=a11,*a2_old=a21,*a1_new=a12,*a2_new=a22,*tmp;
	for(i=0;i<10;i++)
	{
		a1_old[i]=i;
		a2_old[i]=i+1;
	}
	for(i=10;i<10*N;i++)
	{
		a1_old[i]=9;
		a2_old[i]=10;
	}
	for(i=2;i<=N;i++)
	{
		a1_new[0]=0;
		a2_new[0]=a2_old[0];
		for(j=1;j<=10*N;j++)
		{
			if(j-10>=0)
			{
				a1_new[j]=(a1_new[j-1]+a1_old[j]-a1_old[j-10]+MAX)%(MAX);
				a2_new[j]=(a2_new[j-1]+a2_old[j]-a2_old[j-10]+MAX)%(MAX);
			}
			else
			{
				a1_new[j]=(a1_new[j-1]+a1_old[j])%MAX;
				a2_new[j]=(a2_new[j-1]+a2_old[j])%MAX;
			}
		}
		tmp=a1_new;
		a1_new=a1_old;
		a1_old=tmp;

		tmp=a2_new;
		a2_new=a2_old;
		a2_old=tmp;
	}
	for(i=10*N-1;i>0;i--)
	{
		a1_old[i]=(a1_old[i]-a1_old[i-1]);
		a2_old[i]=a2_old[i]-a2_old[i-1];
		a1_old[i]=a1_old[i]>=0?a1_old[i]:(a1_old[i]%MAX+MAX);
		a2_old[i]=a2_old[i]>=0?a2_old[i]:(a2_old[i]%MAX+MAX);
		sum1+=(a1_old[i])*(a2_old[i]);
		sum1=sum1%(1000000000+7);
	}
	printf("%lld\n",sum1);
	return 0;
}

		
	
