#include<stdio.h>
int main()
{
	int N,i,j,k,sum=0,sum0=0;
	scanf("%d",&N);
	int num[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",num+i);
		sum0+=num[i];
	}
	sum=sum0/2;
	int a[sum+1];
	for(i=0;i<sum+1;i++)
		a[i]=0;
	for(i=0;i<N;i++)
	{
		for(j=sum;j>=1;j--)
		{
			int a1=j-num[i];
			if(a1>=0)
				a1=a[a1]+num[i];
			else
				a1=0;
			a[j]=a[j]>a1?a[j]:a1;
		}
	}
	printf("%d\n",sum0-2*a[sum]);
}

