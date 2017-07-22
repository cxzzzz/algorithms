#include<stdio.h>
int main()
{
	long long a,b,c,N,d=1000000000+7;
	scanf("%lld",&N);
	N=N+1;
	a=3;
	long long result=1,tmp=a;
	b=N;
	while(b)
	{
		if(b&1)
		{
			result=(result*tmp)%d;
		}   
		tmp=(tmp*tmp)%d;
		b=b>>1;
	}
	result=(result-1+d)%d;
	if(result%2)
	{
		result=(result+d)/2;
	}
	else
	{
		result=result/2;
	}
	printf("%lld\n",result);
	return 0;
}
