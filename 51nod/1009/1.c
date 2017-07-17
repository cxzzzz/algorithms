#include<stdio.h>
int main()
{
	int N,i,j,k,l,sum=0;
	scanf("%d",&N);
	i=1;while(i<=N)i*=10;
	for(i/=10;i>=1;i/=10)
	{
		j=N/i;
		k=j*i-i*10*(N/(i*10))+N%i;
		l=N/(i*10)+1;
		if(i<=k && k<i*2)//该位为1 
		{
			sum+=(k-i)+1;
			l--;
		}
		else if(k<i)//该位为0
		{
			l--;
		}
		sum+=l*i;
		
	}
	printf("%d",sum);
}
	
